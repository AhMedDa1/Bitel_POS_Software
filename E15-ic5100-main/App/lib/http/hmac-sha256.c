/*
 * Copyright 2006 Apple Computer, Inc.  All rights reserved.
 *
 * iTunes U Sample Code License
 * IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc. ("Apple")
 * in consideration of your agreement to the following terms, and your use,
 * installation, modification or distribution of this Apple software constitutes
 * acceptance of these terms.  If you do not agree with these terms, please do not use,
 * install, modify or distribute this Apple software.
 *
 * In consideration of your agreement to abide by the following terms and subject to
 * these terms, Apple grants you a personal, non-exclusive, non-transferable license,
 * under Apple's copyrights in this original Apple software (the "Apple Software"):
 *
 * (a) to internally use, reproduce, modify and internally distribute the Apple
 * Software, with or without modifications, in source and binary forms, within your
 * educational organization or internal campus network for the sole purpose of
 * integrating Apple's iTunes U software with your internal campus network systems; and
 *
 * (b) to redistribute the Apple Software to other universities or educational
 * organizations, with or without modifications, in source and binary forms, for the
 * sole purpose of integrating Apple's iTunes U software with their internal campus
 * network systems; provided that the following conditions are met:
 *
 * 	-  If you redistribute the Apple Software in its entirety and without
 *     modifications, you must retain the above copyright notice, this entire license
 *     and the disclaimer provisions in all such redistributions of the Apple Software.
 * 	-  If you modify and redistribute the Apple Software, you must indicate that you
 *     have made changes to the Apple Software, and you must retain the above
 *     copyright notice, this entire license and the disclaimer provisions in all
 *     such redistributions of the Apple Software and/or derivatives thereof created
 *     by you.
 *     -  Neither the name, trademarks, service marks or logos of Apple may be used to
 *     endorse or promote products derived from the Apple Software without specific
 *     prior written permission from Apple.
 *
 * Except as expressly stated above, no other rights or licenses, express or implied,
 * are granted by Apple herein, including but not limited to any patent rights that may
 * be infringed by your derivative works or by other works in which the Apple Software
 * may be incorporated.  THE APPLE SOFTWARE IS PROVIDED BY APPLE ON AN "AS IS" BASIS.
 * APPLE MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AND HEREBY DISCLAIMS ALL WARRANTIES,
 * INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE
 * OR ITS USE AND OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS OR SYSTEMS.
 * APPLE IS NOT OBLIGATED TO PROVIDE ANY MAINTENANCE, TECHNICAL OR OTHER SUPPORT FOR
 * THE APPLE SOFTWARE, OR TO PROVIDE ANY UPDATES TO THE APPLE SOFTWARE.  IN NO EVENT
 * SHALL APPLE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
 * OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Rev.  120806
 *
 * This source code file contains a self-contained ANSI C program with no
 * external dependencies except for standard ANSI C libraries. On Mac OS X, it
 * can be compiled and run by executing the following commands in a terminal
 * window:
 *     gcc -o seconds seconds.c
 *     ./seconds
 */

// Compile note added by RKW
//    gcc -o hmac-sha256 hmac-sha256.c
// should work on latter-day gcc installs, but c99 can be made explicit this way:
//    gcc -std=c99 -o hmac-sha256 hmac-sha256.c
#include "system.h"
#include "extern.h"

/******************************************************************************
 * SHA-256.
 */

//typedef struct {
//    unsigned char		hash[32];	// Changed by RKW, unsigned char becomes unsigned char
//    unsigned int	buffer[16];	// Changed by RKW, unsigned long becomes unsigned int
//    unsigned int	state[8];	// Changed by RKW, unsinged long becomes unsigned int
//    unsigned char		length[8];	// Changed by RKW, unsigned char becomes unsigned char
//} sha256;

void sha256_initialize(sha256 *sha) {
    int i;
    for (i = 0; i < 17; ++i) sha->buffer[i] = 0;
    sha->state[0] = 0x6a09e667;
    sha->state[1] = 0xbb67ae85;
    sha->state[2] = 0x3c6ef372;
    sha->state[3] = 0xa54ff53a;
    sha->state[4] = 0x510e527f;
    sha->state[5] = 0x9b05688c;
    sha->state[6] = 0x1f83d9ab;
    sha->state[7] = 0x5be0cd19;
    for (i = 0; i < 8; ++i) sha->length[i] = 0;
}

//  Changed by RKW, formal args are now const unsigned char, uint_32
//    from const unsigned char, unsigned long respectively
void sha256_update(sha256 *sha,
                   const unsigned char *message,
                   unsigned int length) {
    int i, j;
    /* Add the length of the received message, counted in
     * bytes, to the total length of the messages hashed to
     * date, counted in bits and stored in 8 separate bytes. */
    for (i = 7; i >= 0; --i) {
        int bits;
		if (i == 7)
			bits = length << 3;
		else if (i == 0 || i == 1 || i == 2)
			bits = 0;
		else
			bits = length >> (53 - 8 * i);
		bits &= 0xff;
        if (sha->length[i] + bits > 0xff) {
            for (j = i - 1; j >= 0 && sha->length[j]++ == 0xff; --j);
        }
        sha->length[i] += bits;
    }
    /* Add the received message to the SHA buffer, updating the
     * hash at each block (each time the buffer is filled). */
    while (length > 0) {
        /* Find the index in the SHA buffer at which to
         * append what's left of the received message. */
        int index = sha->length[6] % 2 * 32 + sha->length[7] / 8;
        index = (index + 64 - length % 64) % 64;
        /* Append the received message bytes to the SHA buffer until
         * we run out of message bytes or until the buffer is filled. */
        for (;length > 0 && index < 64; ++message, ++index, --length) {
            sha->buffer[index / 4] |= *message << (24 - index % 4 * 8);
        }
        /* Update the hash with the buffer contents if the buffer is full. */
        if (index == 64) {
            /* Update the hash with a block of message content. See FIPS 180-2
             * (<csrc.nist.gov/publications/fips/fips180-2/fips180-2.pdf>)
             * for a description of and details on the algorithm used here. */
			// Changed by RKW, const unsigned long becomes const unsigned int
            const unsigned int k[64] = {
                0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
            };
			// Changed by RKW, unsigned long becomes unsigned int
            unsigned int w[64], a, b, c, d, e, f, g, h;
            int t;
            for (t = 0; t < 16; ++t) {
                w[t] = sha->buffer[t];
                sha->buffer[t] = 0;
            }
            for (t = 16; t < 64; ++t) {
				// Changed by RKW, unsigned long becomes unsigned int
                unsigned int s0, s1;
                s0 = (w[t - 15] >> 7 | w[t - 15] << 25);
                s0 ^= (w[t - 15] >> 18 | w[t - 15] << 14);
                s0 ^= (w[t - 15] >> 3);
                s1 = (w[t - 2] >> 17 | w[t - 2] << 15);
                s1 ^= (w[t - 2] >> 19 | w[t - 2] << 13);
                s1 ^= (w[t - 2] >> 10);
                w[t] = (s1 + w[t - 7] + s0 + w[t - 16]) & 0xffffffffU;
            }
            a = sha->state[0];
            b = sha->state[1];
            c = sha->state[2];
            d = sha->state[3];
            e = sha->state[4];
            f = sha->state[5];
            g = sha->state[6];
            h = sha->state[7];
            for (t = 0; t < 64; ++t) {
				// Changed by RKW, unsigned long becomes unsigned int
                unsigned int e0, e1, t1, t2;
                e0 = (a >> 2 | a << 30);
                e0 ^= (a >> 13 | a << 19);
                e0 ^= (a >> 22 | a << 10);
                e1 = (e >> 6 | e << 26);
                e1 ^= (e >> 11 | e << 21);
                e1 ^= (e >> 25 | e << 7);
                t1 = h + e1 + ((e & f) ^ (~e & g)) + k[t] + w[t];
                t2 = e0 + ((a & b) ^ (a & c) ^ (b & c));
                h = g;
                g = f;
                f = e;
                e = d + t1;
                d = c;
                c = b;
                b = a;
                a = t1 + t2;
            }
            sha->state[0] = (sha->state[0] + a) & 0xffffffffU;
            sha->state[1] = (sha->state[1] + b) & 0xffffffffU;
            sha->state[2] = (sha->state[2] + c) & 0xffffffffU;
            sha->state[3] = (sha->state[3] + d) & 0xffffffffU;
            sha->state[4] = (sha->state[4] + e) & 0xffffffffU;
            sha->state[5] = (sha->state[5] + f) & 0xffffffffU;
            sha->state[6] = (sha->state[6] + g) & 0xffffffffU;
            sha->state[7] = (sha->state[7] + h) & 0xffffffffU;
        }
    }
}

//  Changed by RKW, formal args are now const unsigned char, uint_32
//    from const unsigned char, unsigned long respectively
void sha256_finalize(sha256 *sha,
                     const unsigned char *message,
                     unsigned int length) {
    int i;
	// Changed by RKW, unsigned char becomes unsigned char
    unsigned char terminator[64 + 8] = { 0x80 };
    /* Hash the final message bytes if necessary. */
    if (length > 0) sha256_update(sha, message, length);
    /* Create a terminator that includes a stop bit, padding, and
     * the the total message length. See FIPS 180-2 for details. */
    length = 64 - sha->length[6] % 2 * 32 - sha->length[7] / 8;
    if (length < 9) length += 64;
    for (i = 0; i < 8; ++i) terminator[length - 8 + i] = sha->length[i];
    /* Hash the terminator to finalize the message digest. */
    sha256_update(sha, terminator, length);
    /* Extract the message digest. */
    for (i = 0; i < 32; ++i) {
        sha->hash[i] = (sha->state[i / 4] >> (24 - 8 * (i % 4))) & 0xff;
    }
}

//  Changed by RKW, formal args are now unsigned char, const uint_8
//    from unsigned char, const unsigned char respectively
void sha256_get(unsigned char hash[32],
                const unsigned char *message,
                int length) {
    int i;
    sha256 sha;
    sha256_initialize(&sha);
    sha256_finalize(&sha, message, length);
    for (i = 0; i < 32; ++i) hash[i] = sha.hash[i];
}

/******************************************************************************
 * HMAC-SHA256.
 */

//typedef struct _hmac_sha256 {
//    unsigned char	digest[32];	// Changed by RKW, unsigned char becomes uint_8
//    unsigned char	key[64];	// Changed by RKW, unsigned char becomes uint_8
//    sha256	sha;
//} hmac_sha256;

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_initialize(hmac_sha256 *hmac,
                            const unsigned char *key, int length) {
    int i;
    /* Prepare the inner hash key block, hashing the key if it's too long. */
    if (length <= 64) {
        for (i = 0; i < length; ++i) hmac->key[i] = key[i] ^ 0x36;
        for (; i < 64; ++i) hmac->key[i] = 0x36;
    } else {
        sha256_initialize(&(hmac->sha));
        sha256_finalize(&(hmac->sha), key, length);
        for (i = 0; i < 32; ++i) hmac->key[i] = hmac->sha.hash[i] ^ 0x36;
        for (; i < 64; ++i) hmac->key[i] = 0x36;
    }
    /* Initialize the inner hash with the key block. */
    sha256_initialize(&(hmac->sha));
    sha256_update(&(hmac->sha), hmac->key, 64);
}

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_update(hmac_sha256 *hmac,
                        const unsigned char *message, int length) {
    /* Update the inner hash. */
    sha256_update(&(hmac->sha), message, length);
}

//  Changed by RKW, formal arg is now const unsigned char
//    from const unsigned char
void hmac_sha256_finalize(hmac_sha256 *hmac,
                          const unsigned char *message, int length) {
    int i;
    /* Finalize the inner hash and store its value in the digest array. */
    sha256_finalize(&(hmac->sha), message, length);
    for (i = 0; i < 32; ++i) hmac->digest[i] = hmac->sha.hash[i];
    /* Convert the inner hash key block to the outer hash key block. */
    for (i = 0; i < 64; ++i) hmac->key[i] ^= (0x36 ^ 0x5c);
    /* Calculate the outer hash. */
    sha256_initialize(&(hmac->sha));
    sha256_update(&(hmac->sha), hmac->key, 64);
    sha256_finalize(&(hmac->sha), hmac->digest, 32);
    /* Use the outer hash value as the HMAC digest. */
    for (i = 0; i < 32; ++i) hmac->digest[i] = hmac->sha.hash[i];
}

//  Changed by RKW, formal args are now unsigned char, const unsigned char
//    from unsinged char, const unsigned char respectively
void hmac_sha256_get(unsigned char digest[32],
                     const unsigned char *message, int message_length,
                     const unsigned char *key, int key_length) {
    int i;
    hmac_sha256 hmac;
    hmac_sha256_initialize(&hmac, key, key_length);
    hmac_sha256_finalize(&hmac, message, message_length);
    for (i = 0; i < 32; ++i) digest[i] = hmac.digest[i];
}


/*int GET_BtHMAC_SHA256(const unsigned char* data,unsigned char *signed_data) {
    int i;
	int ret = 0;
    int len;
    const unsigned char *src;
    unsigned char sha256sum[32] = {0};
    unsigned char dec_buffer[32]= {0}, enc_buffer[45]= {0};
	//E15_config *e15_config = E15_GetConfiguration();
//	E15_LoadConfiguration(e15_config, sizeof(E15_config));

    const mbedtls_md_info_t *md_info;
	mbedtls_md_context_t ctx;

	int data_size = strlen(data);
	src = e15_config->shared_key;
	mbedtls_base64_decode( dec_buffer, sizeof( dec_buffer ), &len, src, strlen(src));

	unsigned char *decoded_key = dec_buffer;
	int decoded_key_size = strlen(decoded_key);
    mbedtls_md_init( &ctx );
	md_info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA256);
	ret = mbedtls_md_init_ctx(&ctx, md_info);
	if (ret != 0)
	{
		return 1;
	}
    mbedtls_md_hmac_starts( &ctx, decoded_key, decoded_key_size );

    mbedtls_md_hmac_update( &ctx, data, data_size );
    mbedtls_md_hmac_finish( &ctx, sha256sum );
    src = (unsigned char*)sha256sum;
    mbedtls_base64_encode( enc_buffer, sizeof( enc_buffer ), &len, &sha256sum, sizeof(sha256sum));
    unsigned char *encoded_result = enc_buffer;
    strcpy((char*)signed_data,(char*)encoded_result);
    return 0;
}*/
