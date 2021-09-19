#ifndef CRYPTO_H_
#define CRYPTO_H_

//#include <stddef.h>

void HexEncode(unsigned char *data, int data_length, unsigned char *result);
void HexDecode(unsigned char *data,unsigned char *result); 
char *Get_PIN_BLOCK(const char *clear_pin, const char *clear_pan); 

//typedef unsigned char BYTE;             // 8-bit byte

#endif /*CRYPTO_H_*/

