/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   hmac-sha256.h
 * Author: Mohamed
 *
 * Created on April 24, 2017, 12:01 PM
 */

#ifndef HMAC_SHA256_H
#define HMAC_SHA256_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char		hash[32];	// Changed by RKW, unsigned char becomes unsigned char
    unsigned int	buffer[16];	// Changed by RKW, unsigned long becomes unsigned int
    unsigned int	state[8];	// Changed by RKW, unsinged long becomes unsigned int
    unsigned char		length[8];	// Changed by RKW, unsigned char becomes unsigned char
} sha256;

void sha256_initialize(sha256 *sha);

//  Changed by RKW, formal args are now const unsigned char, uint_32
//    from const unsigned char, unsigned long respectively
void sha256_update(sha256 *sha,
                   const unsigned char *message,
                   unsigned int length);

//  Changed by RKW, formal args are now const unsigned char, uint_32
//    from const unsigned char, unsigned long respectively
void sha256_finalize(sha256 *sha,
                     const unsigned char *message,
                     unsigned int length);

//  Changed by RKW, formal args are now unsigned char, const uint_8
//    from unsigned char, const unsigned char respectively
void sha256_get(unsigned char hash[32],
                const unsigned char *message,
                int length);

/******************************************************************************
 * HMAC-SHA256.
 */

typedef struct _hmac_sha256 {
    unsigned char	digest[32];	// Changed by RKW, unsigned char becomes uint_8
    unsigned char	key[64];	// Changed by RKW, unsigned char becomes uint_8
    sha256	sha;
} hmac_sha256;

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_initialize(hmac_sha256 *hmac,
                            const unsigned char *key, int length);

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_update(hmac_sha256 *hmac,
                        const unsigned char *message, int length);

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_finalize(hmac_sha256 *hmac,
                          const unsigned char *message, int length);

//  Changed by RKW, formal args are now unsigned char, const unsigned char
//    from unsinged char, const unsigned char respectively
extern void hmac_sha256_get(unsigned char digest[32],
                     const unsigned char *message, int message_length,
                     const unsigned char *key, int key_length);


#ifdef __cplusplus
}
#endif

#endif /* HMAC_SHA256_H */

