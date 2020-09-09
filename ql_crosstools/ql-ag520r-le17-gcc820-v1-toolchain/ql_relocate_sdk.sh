#!/bin/bash
# Copyright (c) 2018 Quectel Wireless Solutions Co., Ltd. All rights reserved.
# Quectel Wireless Solutions Proprietary and Confidential.
# Running.qain,2018.12.27
# Tyler.kuang,2019.06.24 : 

if ! xargs --version > /dev/null 2>&1; then
	echo "xargs is required by the relocation script, please install it first. Abort!"
	exit 1
fi

WORK_DIR=`pwd`
TOOLCHAIN_DIR=${WORK_DIR}/gcc

# fix dynamic loader paths in all ELF SDK binaries
#native_sysroot=$($SUDO_EXEC cat $env_setup_script |grep 'OECORE_NATIVE_SYSROOT='|cut -d'=' -f2|tr -d '"')
#############################################quectel define start#############################################
PRE_TOOLCHAIN_DIR=$(sed -n 's/old_prefix = re.compile(b("//p' ${WORK_DIR}/relocate_sdk.py | sed -n 's/"))//p')

if [ "${DEST_TOOLCHAIN_DIR}" == "" ]; then
    DEST_TOOLCHAIN_DIR=${TOOLCHAIN_DIR}
fi

while getopts "d:" opt
do
    case $opt in
        d)
            DEST_TOOLCHAIN_DIR=${OPTARG}
            ;;
        ?)
            echo "Usage : exe [-b dest tool chain dir]"
            exit 1;;
    esac
done

echo "PRE_TOOLCHAIN_DIR=${PRE_TOOLCHAIN_DIR}"
echo "DEST_TOOLCHAIN_DIR=${DEST_TOOLCHAIN_DIR}"

#if [ "${DEST_TOOLCHAIN_DIR}" == "${PRE_TOOLCHAIN_DIR}" ]; then
#    exit 0
#fi



cd ${TOOLCHAIN_DIR}/lib
dl_name=$(ls |grep ld-linux)
cd ${WORK_DIR}
if [ "$dl_name" = "" ] ; then
	echo "SDK could not be set up. Relocate script unable to find ld-linux.so. Abort!"
	exit 1
fi

dl_path=${DEST_TOOLCHAIN_DIR}/lib/${dl_name}

executable_files=$($SUDO_EXEC find ${TOOLCHAIN_DIR} -type f \
	\( -perm -0100 -o -perm -0010 -o -perm -0001 \) -printf "%h/%f ")
if [ "x$executable_files" = "x" ]; then
   echo "SDK relocate failed, could not get executalbe files"
   exit 1
fi


# tdir=`mktemp -d`
# if [ x$tdir = x ] ; then
#    echo "SDK relocate failed, could not create a temporary directory"
#    exit 1
# fi
# cat <<EOF >> $tdir/relocate_sdk.sh
# #!/bin/sh
# for py in python python2 python3
# do
# 	PYTHON=\`which \${py} 2>/dev/null\`
# 	if [ \$? -eq 0 ]; then
# 		break;
# 	fi
# done
# 
# if [ x\${PYTHON} = "x"  ]; then
# 	echo "SDK could not be relocated.  No python found."
# 	exit 1
# fi
# \${PYTHON} ${env_setup_script%/*}/relocate_sdk.py $new_sdk_install_dir $dl_path $executable_files
# EOF
# 
# $SUDO_EXEC mv $tdir/relocate_sdk.sh ${env_setup_script%/*}/relocate_sdk.sh
# $SUDO_EXEC chmod 755 ${env_setup_script%/*}/relocate_sdk.sh
# rm -rf $tdir
# if [ $relocate = 1 ] ; then
# 	$SUDO_EXEC ${env_setup_script%/*}/relocate_sdk.sh
# 	if [ $? -ne 0 ]; then
# 		echo "SDK could not be set up. Relocate script failed. Abort!"
# 		exit 1
# 	fi
# fi

#############################################quectel define start#############################################
#relocate
printf "Relocating ..."

${WORK_DIR}/relocate_sdk.py ${DEST_TOOLCHAIN_DIR} $dl_path $executable_files
if [ $? -ne 0 ]; then
    echo "SDK could not be set up. Relocate script failed. Abort!"
    cd - > /dev/null
    exit 1
fi
newprefix=$(echo ${DEST_TOOLCHAIN_DIR} | sed -n 's/\//\\\//gp')
eval sed -i 's/compile\(b\(\".*/compile\(b\(\"${newprefix}\"\)\)/' ${WORK_DIR}/relocate_sdk.py
#############################################quectel define end#############################################

printf "..."
# replace @SDKPATH@ with the new prefix in all text files: configs/scripts/etc.
# replace the host perl with SDK perl.
for replace in "${WORK_DIR} -maxdepth 1" "${TOOLCHAIN_DIR}"; do
	$SUDO_EXEC find $replace -type f
done | xargs -n100 file | grep ":.*\(ASCII\|script\|source\).*text" | \
    awk -F':' '{printf "\"%s\"\n", $1}' | \
    grep -Ev "${WORK_DIR}/(environment-setup-*|relocate_sdk*|${0##*/})" | \
    xargs -n100 $SUDO_EXEC sed -i \
        -e "s:${PRE_TOOLCHAIN_DIR}:${DEST_TOOLCHAIN_DIR}:g" \
        -e "s:^#! */usr/bin/perl.*:#! /usr/bin/env perl:g" \
        -e "s: /usr/bin/perl: /usr/bin/env perl:g"

if [ $? -ne 0 ]; then
	echo "Failed to replace perl. Relocate script failed. Abort!"
	exit 1
fi

printf "..."
# change all symlinks pointing to @SDKPATH@
for l in $($SUDO_EXEC find ${TOOLCHAIN_DIR} -type l); do
	$SUDO_EXEC ln -sfn $(readlink $l|$SUDO_EXEC sed -e "s:${PRE_TOOLCHAIN_DIR}:${DEST_TOOLCHAIN_DIR}:") $l
	if [ $? -ne 0 ]; then
		echo "Failed to setup symlinks. Relocate script failed. Abort!"
		exit 1
    fi
done

echo done

#############################################quectel define start#############################################
if [ -d "${TOOLCHAIN_DIR}/pseudo" ]; then
    echo "Remove old ql-ol-rootfs"
    rm -rf ${TOOLCHAIN_DIR}/pseudo
fi
#############################################quectel define end#############################################
