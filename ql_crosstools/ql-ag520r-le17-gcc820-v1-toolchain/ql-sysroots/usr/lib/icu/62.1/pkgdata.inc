GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.62.1
COMPILE=arm-oe-linux-gnueabi-gcc  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -fstack-protector-strong -pie -fPIE -D_FORTIFY_SOURCE=2 -Wa,--noexecstack -Wformat -Wformat-security -Werror=format-security  -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_ATOMIC=1 -DU_HAVE_STRTOD_L=1 -DU_HAVE_XLOCALE_H=0  -DU_ATTRIBUTE_DEPRECATED= -O2 -fomit-frame-pointer    -Wa,--noexecstack -fexpensive-optimizations   -frename-registers -ftree-vectorize   -finline-functions -finline-limit=64   -Wno-error=maybe-uninitialized -Wno-error=unused-result     -std=c11 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=arm-oe-linux-gnueabi-gcc  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -fstack-protector-strong -pie -fPIE -D_FORTIFY_SOURCE=2 -Wa,--noexecstack -Wformat -Wformat-security -Werror=format-security  -O2 -fomit-frame-pointer    -Wa,--noexecstack -fexpensive-optimizations   -frename-registers -ftree-vectorize   -finline-functions -finline-limit=64   -Wno-error=maybe-uninitialized -Wno-error=unused-result     -std=c11 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -Wl,-O1 -Wl,--hash-style=gnu  -Wl,-z,relro,-z,now,-z,noexecstack  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=arm-oe-linux-gnueabi-ar
ARFLAGS=r
RANLIB=arm-oe-linux-gnueabi-ranlib
INSTALL_CMD=install -c
