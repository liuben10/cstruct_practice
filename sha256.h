/*********************************************************************
* Filename:   sha256.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/
#ifndef SHA256_H
#define SHA256_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte
typedef unsigned int  WORD;             // 32-bit word, change to "long" for 16-bit machines

typedef struct {
	BYTE data[64];
	WORD datalen;
	unsigned long long bitlen;
	WORD state[8];
} SHA256_CTX;

typedef struct Crypto {
  struct SHA256_CTX *shaCtx;
  BYTE *(*sha256)(BYTE *text);
  struct T *this;
  struct T *(*new)();
} Crypto;

/*********************** FUNCTION DECLARATIONS **********************/
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);
BYTE *sha256_eval(Crypto *this, BYTE text[]);
struct Crypto *construct_Crypto();

struct Crypto *construct_Crypto() {
  Crypto *crypto = malloc(sizeof(Crypto));
  crypto->this = crypto;
  crypto->new = &construct_Crypto;
  crypto->sha256 = &sha256_eval;
  SHA256_CTX ctx;
  sha256_init(&ctx);
  crypto->shaCtx = &ctx;
}


#endif   // SHA256_H
