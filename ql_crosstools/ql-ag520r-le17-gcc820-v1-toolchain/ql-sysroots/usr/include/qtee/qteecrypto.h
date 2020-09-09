/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

            Quectel TEE Library Functions

GENERAL DESCRIPTION
  Contains the library functions for trustzone crypto

Copyright (c) 2019 Quectel Wireless Solutions Co., Ltd 2017.
All Rights Reserved.

when        who                what,where,why
----------  ---             -------------------------
24/05/19    Darren           Initial version
25/05/19    Darren           Add RSA Padding mode(oaep,raw,pkcs1.etc)
30/05/19    Darren           Add Import openssl RSA key to TrustZone
05/06/19    Darren           Add AES Feature in TrustZone
19/06/19    Darren           Add RAW Flash Secure Storge Feature
29/04/20    Darren           Add RSA tzhash mode

*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __QTEE_CRYPTO_H_
#define __QTEE_CRYPTO_H_

#include <inttypes.h>
#include <openssl/evp.h>

#define QTEE_RSA_MIN_SIZE     2048

typedef struct QTEE_RSA QTEE_RSA;

typedef enum {
    //PKCS V1.5 PADDING
    QTEE_RSA_PAD_PKCS1_V1_5 = 0,
    //PKCS V1.5 SIGNATURE PADDING
    QTEE_RSA_PAD_PKCS1_V1_5_SIG = 1,
    //PKCS V1.5 ENCRYPT PADDING
    QTEE_RSA_PAD_PKCS1_V1_5_ENC = 2,
    //OAEP ENCRYPT PADDING
    QTEE_RSA_PAD_PKCS1_OAEP = 3,
    //PSS SIGNATURE PADDING
    QTEE_RSA_PAD_PKCS1_PSS = 4,
    //NO PADDING
    QTEE_RSA_NO_PAD = 5,
    QTEE_RSA_PAD_PKCS1_PSS_AUTORECOVER_SALTLEN = 6,
    QTEE_RSA_PAD_INVALID = 0X7FFFFFFF,
}QTEE_RSA_PADDING_TYPE;

typedef enum {
    //in this mode need normal world to caculate sha256 value for data to be signed
    QTEE_RSA_NORMAL_WORLD_SHA256 = 0,
    //in this mode,TrustZone will caculate sha256 for data to be signed.
    QTEE_RSA_TZ_SHA256 = 1,
}QTEE_RSA_SIGN_MODE;

typedef enum {
    QTEE_RSA_E_TYPE_3 = 0,
    QTEE_RSA_E_TYPE_65537 = 1,
    QTEE_RSA_E_TYPE_MAX,
}QTEE_RSA_E_TYPE;

typedef enum {
    QTEE_RSA_FLAGS_NULL = 0x0000,
    /*If you set this flags, TrustZone automatically searches for RSA private keys*/
    QTEE_RSA_FLAGS_SRC_TZ = 0x0001,
    QTEE_RSA_FLAGS_MAX,
}QTEE_RSA_FLAGS;

typedef struct {
    /* RSA e Value*/
    uint32_t pub_e_type;
    /*RSA key bits*/
    uint32_t rsabits;
    /*Output TrustZone RSA key (output RSA public key PEM format )*/
    uint8_t *outbuf;
    /*length of key export from TrustZone*/
    uint32_t outlen;
    /*Import RSA key to TrustZone (input QTEE_RSA format)*/
    uint8_t *inbuf;
    /*length of key import to TrustZone*/
    uint32_t inlen;
}QTEE_GENRSA_CTX;

typedef struct {
    uint32_t padding_type;
    uint8_t *inbuf;
    uint32_t inlen;
    uint8_t *outbuf;
    uint32_t outlen;
    /*when we use dgst to verify a file signture, we need input the file and its signature file*/
    uint8_t *sigbuf;
    uint32_t siglen;
    uint32_t sigmode;
    /*Quectel RSA Format for TrustZone and linux communication*/
    QTEE_RSA  *inkey;
}QTEE_RSA_CTX;

/**
 * @brief this fuction set RSA key default value
 *
 * @return QTEE_RSA memory pointer on success, NULL on failure
 */
QTEE_RSA *QTEE_RSA_init(void);

/**
 * @brief this fuction will get QTEE_RSA struct size
 *
 * @return the size of QTEE_RSA
 */
int get_qtee_rsa_size(void);

/**
 * @brief this fuction will set RSA key type
 *
 * @return 0 on success, negative on failure.
 */
int set_qtee_pk_type(QTEE_RSA *qtee_rsa, QTEE_RSA_FLAGS flags);

/**
 * @brief this function will free QTEE_RSA
 *
 * @return void
 */
void QTEE_RSA_deinit(QTEE_RSA *rsa);

/**
 * @brief this fuction set QTEE RSA API Argument CTX Default value
 *
 * @param[in,out] ctx    Setting QTEE RSA API CTX member variable
 * @return 0 on success, negative on failure
 */
void QTEE_RSA_CTX_init(QTEE_RSA_CTX *ctx);

/**
 * @brief this fuction set QTEE GENRSA API Argument CTX Default value
 *
 * @param[in,out] ctx    Setting QTEE GENRSA API CTX member variable
 * @return 0 on success, negative on failure
 */
void QTEE_GENRSA_CTX_init(QTEE_GENRSA_CTX *ctx);

/**
 * @brief this fuction will genrate TrustZone RSA key, RSA public key will release
 * RSA private key will store in TrustZone(the feature need /persist dict can read and write)
 *
 * @param[in,out] genrsa_arg     see data struct QTEE_GENRSA_CTX
 *
 * @return 0 on success, negative on failure
 */
int qtee_gen_rsakey(QTEE_GENRSA_CTX *genrsa_arg);

/**
 * @brief this fuction will import openssl RSA Private Key to TrustZone
 * openssl RSA private key will store in TrustZone(the feature need /persist dict can read and write)
 *
 * @param[in,out] genrsa_arg     see data struct QTEE_GENRSA_CTX
 *
 * @return 0 on success, negative on failure
 */
int qtee_import_rsakey(QTEE_GENRSA_CTX *genrsa_arg);


/**
 * @brief This function will sign signature
 *
 * @param[in]rsa_arg->padding_type      type of padding
 * @param[in]rsa_arg->inbuf             the input data to sign
 * @param[in]rsa_arg->inlen             the length of input data
 * @param[out]rsa_arg->outbuf           the signature
 * @param[in,out]rsa_arg->outlen        [in]the length of rsa_arg->outbuf.[out]the length of output signature data.
 * @param[N/A]rsa_arg->sigbuf           NULL(don't need)
 * @param[N/A]rsa_arg->siglen           NULL(don't need)
 * @param[in]rsa_arg->sigmod            refer enum QTEE_RSA_SIGN_MODE
 * @param[in]rsa_arg->inkey             input RSA KEY(QTEE RSA Format)
 *
 * @return 0 on success, negative on failure
 */
int qtee_rsa_sign(QTEE_RSA_CTX *rsa_arg);

/**
 * @brief This function will verify signature
 *
 * @param[in]rsa_arg->padding_type      type of padding
 * @param[in]rsa_arg->inbuf             the input data to verify
 * @param[in]rsa_arg->inlen             the length of input data
 * @param[N/A]rsa_arg->outbuf           NULL(don't need)
 * @param[N/A]rsa_arg->outlen           NULL(don't need)
 * @param[in]rsa_arg->sigbuf            the signature data
 * @param[in]rsa_arg->siglen            the length of signature
 * @param[in]rsa_arg->sigmod            Refer enum QTEE_RSA_SIGN_MODE
 * @param[in]rsa_arg->inkey             input RSA KEY(QTEE RSA Format)
 *
 * @return 0 on success, negative on failure
 */
int qtee_rsa_verify(QTEE_RSA_CTX *rsa_arg);

/**
 * @brief This function will encrypt input plaintext in RSA
 *
 * @param[in]rsa_arg->padding_type        type of padding
 * @param[in]rsa_arg->inbuf             the input plaintext to encrypt
 * @param[in]rsa_arg->inlen             the length of plaintext
 * @param[out]rsa_arg->outbuf           output ciphertext
 * @param[in,out]rsa_arg->outlen        [in]the length of rsa_arg->outbuf.[out]the length of output ciphertext.
 * @param[N/A]rsa_arg->sigbuf           NULL(don't need)
 * @param[N/A]rsa_arg->siglen           NULL(don't need)
 * @param[in]rsa_arg->inkey             input RSA KEY(QTEE RSA Format)
 *
 * @return 0 on success, negative on failure
 */
int qtee_rsa_encrypt(QTEE_RSA_CTX *rsa_arg);

/**
 * @brief This function will decrypt input ciphertext in RSA
 *
 * @param[in]rsa_arg->padding_type      type of padding
 * @param[in]rsa_arg->inbuf             the input ciphertext to decrypt
 * @param[in]rsa_arg->inlen             the length of ciphertext
 * @param[out]rsa_arg->outbuf           output plaintext
 * @param[in,out]rsa_arg->outlen        [in]the length of rsa_arg->outbuf.[out]the length of output plaintext.
 * @param[N/A]rsa_arg->sigbuf           NULL(don't need)
 * @param[N/A]rsa_arg->siglen           NULL(don't need)
 * @param[in]rsa_arg->inkey             input RSA KEY(QTEE RSA Format)
 *
 * @return 0 on success, negative on failure
 */
int qtee_rsa_decrypt(QTEE_RSA_CTX *rsa_arg);

/**
 * @brief  This function will translates OpenSSL RSA Public key into QTEE RSA
 *
 * @param[in] rsa         openssl RSA struct (contains RSA public key)
 * @param[out] key      output QTEE RSA format
 *
 * @return 0 on success, negative on failure
 */
int pkcs1_rsapub_to_qtee(const RSA *rsa, QTEE_RSA *key);
int pkcs1_qtee_to_rsapub(const QTEE_RSA *qtee_rsa, RSA *rsa);

/**
 * @brief  This function will translates OpenSSL RSA Private key into QTEE RSA
 *
 * @param[in] rsa       openssl RSA struct (contains RSA private key)
 * @param[out] key      output QTEE RSA format
 *
 * @return 0 on success, negative on failure
 */
int pkcs1_rsapri_to_qtee(const RSA *rsa, QTEE_RSA *key);

/**
 * FOR QTEE AES
 */
#define QTEE_AES_MAGIC         "#QLAES#"
#define QTEE_AES_TOKEN         "514c414553"
#define QTEE_AES_MAX_BITS      256
#define QTEE_AES_MAX_LENGTH    (QTEE_AES_MAX_BITS/8)

#define QTEE_AES128_IV_SIZE     16
#define QTEE_AES256_IV_SIZE     16
#define QTEE_AES128_KEY_SIZE    16
#define QTEE_AES256_KEY_SIZE    32

typedef enum {
    /*Default FLags*/
    QTEE_AES_FLAGS_NULL = 0x0000,
    /*Indicates that Using AES key encryption in TrustZone*/
    QTEE_AES_FLAGS_SRC_TZ = 0x0001,
    /*Indicates that Using Secure Storge Key*/
    QTEE_AES_FLAGS_SRC_SS = 0x0002,
}QTEE_AES_FLAGS;

typedef struct {
    uint8_t  num[QTEE_AES_MAX_LENGTH];
    uint32_t num_len;
}QTEE_AES_NUM;

typedef struct {
    uint8_t  num[QTEE_AES_MAX_LENGTH+32];
    uint32_t num_len;
}QTEE_AES_ENC;

typedef struct {
     char  magic[8];
     uint32_t flags;
     /*AES Key for 128bits or 256bits*/
     QTEE_AES_NUM key;
     /*AES IV Value just for cbc mode*/
     QTEE_AES_NUM iv;
     /*Reservd for TrustZone SKEY*/
     QTEE_AES_ENC enc;
     /*AES index info if AES key store in TrustZone*/
     char token[65];
}QTEE_AES_KEY;

 typedef enum {
     QTEE_AES_ENCRYPT = 0,
     QTEE_AES_DECRYPT = 1,
}AES_ENC_FLAGS;

typedef enum
{
    QTEE_CIPHER_ALGO_AES_128 = 0,
    QTEE_CIPHER_ALGO_AES_256 = 1,
    QTEE_CIPHER_ALGO_TRIPLE_DES = 3,
    QTEE_cipher_ALGO_MAX
}AES_CHIPER_ALGO;

typedef enum
{
   QTEE_CIPHER_MODE_ECB  = 0,
   QTEE_CIPHER_MODE_CBC  = 1,
   QTEE_CIPHER_MODE_CTR  = 2,
   QTEE_CIPHER_MODE_XTS  = 3,
   QTEE_CIPHER_MODE_CCM  = 4,
   QTEE_CIPHER_MODE_CTS  = 5,
   QTEE_CIPHER_MODE_IDSA = 6,
   QTEE_CIPHER_MODE_MAX,
}AES_CHIPER_MODE;

typedef enum
{
  QTEE_CIPHER_PAD_ISO10126 = 0,
  QTEE_CIPHER_PAD_PKCS7 = 1,
  QTEE_CIPHER_PAD_NO_PAD = 2,
  QTEE_CIPHER_PAD_MAX,
} AES_PADDING_TYPE;

typedef struct {
    /*decide whether to perform encryption or decryption*/
    uint32_t enc;
    /*AES padding type*/
    uint32_t padding_type;
    /*QTEE AES api input data*/
    uint8_t *inbuf;
    /*QTEE AES api length of input data(plaintext or ciphertext)*/
    uint32_t inlen;
    /*QTEE AES api out memory data*/
    uint8_t *outbuf;
    /*QTEE AES api length of out data*/
    uint32_t outlen;
    /*QTEE AES KEY*/
    QTEE_AES_KEY *inkey;
}QTEE_AES_CTX;

/**
 * @brief this fuction set AES API CTX default value
 *
 * @param[in,out] ctx    The QTEE_AES_CTX (QTEE AES API ARGUMENT)
 *
 * @return 0 on success, negative on failure
 */
int QTEE_AES_CTX_init(QTEE_AES_CTX *ctx);

/**
 * @brief this fuction set AES key default value
 *
 * @param[in,out] aeskey    Setting AES key member variable
 * @param[in] key           Hex value to set AES key(length of key only support 128bits or 256bits)
 * @param[in] keylen        the lenght of key
 * @param[in] iv            set iv value
 * @param[in] ivlen         the length of iv
 * @return 0 on success, negative on failure
 */
int QTEE_AES_KEY_init(QTEE_AES_KEY *aeskey, const uint8_t *key, uint32_t keylen, const uint8_t *iv, uint32_t ivlen);

/**
 * @brief this fuction will genrate AES key in TrustZone.and TrustZone will encrypt
 * AES key and store it.
 *
 * @param[in] keybits    The AES key bits(only support 128 bits and 256 bits)
 * @param[out] outkey    outkey param contains index information for AES key
 *
 * @return 0 on success, negative on failure
 */
int qtee_gen_aeskey(uint32_t keybits, QTEE_AES_KEY *outkey);

/**
 * @brief this fuction will import a key to TrustZone, and TrustZone will encrypt
 * the AES key and store it.
 *
 * @param[in] key         Pointer to AES key
 * @param[in] keylen     length of the AES key
 * @param[out] outkey    outkey param contains index information for AES key
 *
 * @return 0 on success, negative on failure
 */
int qtee_import_aeskey(const uint8_t *key, uint32_t keylen, QTEE_AES_KEY *outkey);

/**
 * @brief this fuction use AES 128bits and cbc mode to encrypt or decrypt data
 *
 * @param[in,out] ctx              Pointer to AES API ARGUMENT
 * @param[in] ctx->enc             Refer enum AES_ENC_FLAGS
 * @param[in] ctx->padding_type    Refer enum AES_PADDING_TYPE
 * @param[in] ctx->inbuf           Input data buffer needed to be encrypted or decrypted.
 * @param[in] ctx->inlen           The length of input data Buffer
 * @param[out] ctx->outbuf         The memory buffer that store output data.
 * @param[in,out] ctx->outlen      [in]The length of ctx->outbuf in bytes.[out]The length of output data
 * @param[in] ctx->inkey           Pointer to QTEE_AES_KEY
 *
 * @return 0 on success, negative on failure
 */
int qtee_aes_128_cbc(QTEE_AES_CTX *ctx);

/**
 * @brief this fuction use AES 128bits and ecb mode to encrypt or decrypt data
 *
 * @param[in,out] ctx              Pointer to AES API ARGUMENT
 * @param[in] ctx->enc             Refer enum AES_ENC_FLAGS
 * @param[in] ctx->padding_type    Refer enum AES_PADDING_TYPE
 * @param[in] ctx->inbuf           Input data buffer needed to be encrypted or decrypted.
 * @param[in] ctx->inlen           The length of input data Buffer
 * @param[out] ctx->outbuf         The memory buffer that store output data.
 * @param[in,out] ctx->outlen      [in]The length of ctx->outbuf in bytes.[out]The length of output data
 * @param[in] ctx->inkey           Pointer to QTEE_AES_KEY
 *
 * @return 0 on success, negative on failure
 */
int qtee_aes_128_ecb(QTEE_AES_CTX *ctx);

/**
 * @brief this fuction use AES 256bits and cbc mode to encrypt or decrypt data
 *
 * @param[in,out] ctx              Pointer to AES API ARGUMENT
 * @param[in] ctx->enc             Refer enum AES_ENC_FLAGS
 * @param[in] ctx->padding_type    Refer enum AES_PADDING_TYPE
 * @param[in] ctx->inbuf           Input data buffer needed to be encrypted or decrypted.
 * @param[in] ctx->inlen           The length of input data Buffer
 * @param[out] ctx->outbuf         The memory buffer that store output data.
 * @param[in,out] ctx->outlen      [in]The length of ctx->outbuf in bytes.[out]The length of output data
 * @param[in] ctx->inkey           Pointer to QTEE_AES_KEY
 *
 * @return 0 on success, negative on failure
 */
int qtee_aes_256_cbc(QTEE_AES_CTX *ctx);

/**
 * @brief this fuction use AES 256bits and ecb mode to encrypt or decrypt data
 *
 * @param[in,out] ctx              Pointer to AES API ARGUMENT
 * @param[in] ctx->enc             Refer enum AES_ENC_FLAGS
 * @param[in] ctx->padding_type    Refer enum AES_PADDING_TYPE
 * @param[in] ctx->inbuf           Input data buffer needed to be encrypted or decrypted.
 * @param[in] ctx->inlen           The length of input data Buffer
 * @param[out] ctx->outbuf         The memory buffer that store output data.
 * @param[in,out] ctx->outlen      [in]The length of ctx->outbuf in bytes.[out]The length of output data in bytes.
 * @param[in] ctx->inkey           Pointer to QTEE_AES_KEY
 *
 * @return 0 on success, negative on failure
 */
int qtee_aes_256_ecb(QTEE_AES_CTX *ctx);

//For Secure Storge
#define QTEE_RAWSS_PROCESSINFO      "QuectelProcess"
#define QTEE_SS_MAXSIZE              0x2000

/**
 * @brief this function will encrypt input data by TrustZone and store ciphertext in nandflash
 *
 * @param[in] partname         NandFlash partition name(Use "secdata")
 * @param[in] filename         Input data identifier
 * @param[in] processinfo      Process information for storing this data
 * @param[in] inbuf            Pointer to input data(Input data should < QTEE_SS_MAXSIZE)
 * @param[in] inlen            length of the input data 
 *
 * @return 0 on success, negative on failure
 */
int qtee_ss_write(const char *partname, const char *filename, const char *processinfo,
                  const uint8_t *inbuf, uint32_t inlen);

/**
* @brief this function will read plaintext in Secure Storge
*
* @param[in] partname        NandFlash partition name(Use "secdata")
* @param[in] filename        The SS file name you want to read
* @param[in] processinfo     Process information for storing this data
* @param[out] outbuf         Pointer to out memory
* @param[in,out] outlen      length of the out data
*
* @return 0 on success, negative on failure
*/
int qtee_ss_read(const char *partname, const char *filename, const char *processinfo,
                 uint8_t *outbuf, uint32_t *outlen);

 /**
 * @brief this function will delete data from Secure Storge
 *
 * @param[in] partname       NandFlash partition name(Use "secdata")
 * @param[in] filename       Delete data identifier
 * @param[in] processinfo    Process information for storing this data
 *
 * @return 0 on success, negative on failure
 */
int qtee_ss_delete(const char *partname, const char *filename, const char *processinfo);

//Error Code
typedef enum {
    QTEE_SUCCESS       = 0,
    QTEE_ERR_FAILURE   = 1,
    QTEE_ERR_INVAL     = 2,//Invalid argument
    QTEE_ERR_NOMEM     = 3,//Memory is not enough
    QTEE_ERR_VERIFY    = 4,
    QTEE_ERR_DEVICE    = 5,
    QTEE_ERR_NOSPACE   = 6,
    QTEE_ERR_NOEXIT    = 7,
    QTEE_ERR_INTEGRITY = 8,
}QTEE_ERROR_TYPE;

#endif
