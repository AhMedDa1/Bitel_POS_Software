/*
 * utf8_2_iso_8859_6.h
 *
 *  Created on: Jun 16, 2017
 *      Author: Mohamed
 */

#ifndef SRC_CRYPTO_INCLUDE_UTF8_2_ISO_8859_6_H_
#define SRC_CRYPTO_INCLUDE_UTF8_2_ISO_8859_6_H_
extern char *GET_SHA1(const char *string);
extern int utf8_to_iso_8859_6(char *const output,const char *const input, const int length);

//static inline unsigned int to_arabic(const unsigned int code);

extern int iso_8859_6_to_utf8(char *const output,const char * const input,	const int length);
extern char *right2left( const char *stream);
//char *align_right(const char *stream);
 void * calloc (size_t count, size_t eltsize);
int fix_connected_chars(unsigned char* stream);
extern char *align_right(const char *stream);
extern char *align_right16(const char *stream);
extern char fix( const char *stream);
#endif /* SRC_CRYPTO_INCLUDE_UTF8_2_ISO_8859_6_H_ */
