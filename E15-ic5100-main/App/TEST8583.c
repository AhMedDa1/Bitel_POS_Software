
#include "system.h"
#include "extern.h"


void Test_iso8583(void);

void Test_chr2hex(void);
void Test_hex2chr(void);
void Test_zchr2hex(void);
void Test_hex2zchr(void);

void Test_asc2bcd(void);
void Test_bcd2asc(void);
void Test_zasc2bcd(void);
void Test_bcd2zasc(void);

void Test_int2LL(void);
void Test_int2LLL(void);
void Test_LL2int(void);
void Test_LLL2int(void);

void Test_num_to_num(void);
void Test_asc_to_num(void);
void Test_num_to_asc(void);
void Test_str_to_num(void);
void Test_num_to_str(void);

void Test_nL2_to_nL2(void);
void Test_nL3_to_nL3(void);
void Test_str_to_nL2(void);
void Test_nL2_to_str(void);

void Test_xnu_to_xnu(void);
void Test_asc_to_xnu(void);
void Test_xnu_to_asc(void);
void Test_str_to_xnu(void);
void Test_xnu_to_str(void);

void Test_str_to_zL2(void);
void Test_zL2_to_str(void);
void Test_str_to_zL3(void);
void Test_zL3_to_str(void);

void Test_asc_to_asc(void);
void Test_str_to_asc(void);
void Test_asc_to_str(void);

void Test_aL2_to_aL2(void);
void Test_str_to_aL2(void);
void Test_aL2_to_str(void);
void Test_aL3_to_aL3(void);
void Test_str_to_aL3(void);
void Test_aL3_to_str(void);

void Test_bin_to_bin(void);
void Test_hst_to_bin(void);
void Test_bin_to_hst(void);

void Test_bL2_to_bL2(void);
void Test_hst_to_bL2(void);
void Test_bL2_to_hst(void);
void Test_bL3_to_bL3(void);
void Test_hst_to_bL3(void);
void Test_bL3_to_hst(void);



void Test_iso8583(void)
{
	int key;
	
	while (1) {
		key = KEYSCAN() & 0xFF;
		if (key == BTKEY_ENTER)
			break;
	}
	
	Test_chr2hex();
	Test_hex2chr();
	Test_zchr2hex();
	Test_hex2zchr();
	
	Test_asc2bcd();
	Test_bcd2asc();
	Test_zasc2bcd();
	Test_bcd2zasc();
	
	Test_int2LL();
	Test_int2LLL();
	Test_LL2int();
	Test_LLL2int();
	
	Test_num_to_num();
	Test_asc_to_num();
	Test_num_to_asc();
	Test_str_to_num();
	Test_num_to_str();
	
	Test_nL2_to_nL2();
	Test_nL3_to_nL3();
	Test_str_to_nL2();
	Test_nL2_to_str();
	
	Test_xnu_to_xnu();
	Test_asc_to_xnu();
	Test_xnu_to_asc();
	Test_str_to_xnu();
	Test_xnu_to_str();
	
	Test_str_to_zL2();
	Test_zL2_to_str();
	Test_str_to_zL3();
	Test_zL3_to_str();
	
	Test_asc_to_asc();
	Test_str_to_asc();
	Test_asc_to_str();
	
	Test_aL2_to_aL2();
	Test_str_to_aL2();
	Test_aL2_to_str();
	Test_aL3_to_aL3();
	Test_str_to_aL3();
	Test_aL3_to_str();
	
	Test_bin_to_bin();
	Test_hst_to_bin();
	Test_bin_to_hst();
	
	Test_bL2_to_bL2();
	Test_hst_to_bL2();
	Test_bL2_to_hst();
	Test_bL3_to_bL3();
	Test_hst_to_bL3();
	Test_bL3_to_hst();
	
	while (1) {
		Wait1MS(1000);
	}
}

void Test_chr2hex(void)
{
	int i;
	unsigned char ch;
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("char chr2hex(unsigned char ch);\r\n\r\n");
	Rprintf("Convert a hexadecimal ASCII character to a hexadecimal digit\r\n");
	Rprintf("ch\r\n");
	Rprintf("- a hexadecimal ASCII character\r\n");
	Rprintf("return value\r\n");
	Rprintf("- 0x00-0x0F ('0'-'9':0x00-0x09, 'A'-'F' or 'a'-'f':0x0A-0x0F, else:0x00)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: 0x00 to 0xFF\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	for (i = 0; i < 256; i++) {
		ch = chr2hex(i);
		Rprintf("%02X ", ch);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_hex2chr(void)
{
	int i;
	unsigned char ch;
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("char hex2chr(unsigned char ch);\r\n\r\n");
	Rprintf("Convert a hexadecimal digit to a hexadecimal ASCII character\r\n");
	Rprintf("ch\r\n");
	Rprintf("- a hexadecimal digit\r\n");
	Rprintf("return value\r\n");
	Rprintf("- '0'-'9', 'A'-'F' (0x00-0x09:'0'-'9', 0x0A-0x0F:'A'-'F', else:'0')\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: 0x00 to 0xFF\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	for (i = 0; i < 256; i++) {
		ch = hex2chr(i);
		Rprintf("%02X ", ch);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_zchr2hex(void)
{
	int i;
	unsigned char ch;
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("char zchr2hex(unsigned char ch);\r\n\r\n");
	Rprintf("Convert a ASCII character of Track 2 or 3 data to a hexadecimal digit\r\n");
	Rprintf("ch\r\n");
	Rprintf("- a ASCII character of Track 2 or 3 data\r\n");
	Rprintf("return value\r\n");
	Rprintf("- 0x00-0x0F ('0'-'?':0x00-0x0F, else:0x00)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: 0x00 to 0xFF\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	for (i = 0; i < 256; i++) {
		ch = zchr2hex(i);
		Rprintf("%02X ", ch);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_hex2zchr(void)
{
	int i;
	unsigned char ch;
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("char hex2zchr(unsigned char ch);\r\n\r\n");
	Rprintf("Convert a hexadecimal digit to a ASCII character of Track 2 or 3 data\r\n");
	Rprintf("ch\r\n");
	Rprintf("- a hexadecimal digit to be converted to a character of Track 2 or 3 data\r\n");
	Rprintf("return value\r\n");
	Rprintf("- '0'-'?' (0x00-0x0F:'0'-'?', else:'0')\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: 0x00 to 0xFF\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	for (i = 0; i < 256; i++) {
		ch = hex2zchr(i);
		Rprintf("%02X ", ch);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_asc2bcd(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void asc2bcd(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a hexadecimal ASCII string to hexadecimal digits with a trailing zero\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a hexadecimal ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123");
	asc2bcd(dst, src, strlen(src));
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1234567890ABCDEF\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890ABCDEF");
	asc2bcd(dst, src, strlen(src));
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bcd2asc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void bcd2asc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert hexadecimal digits to a hexadecimal ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of hexadecimal digits\r\n");
	Rprintf("len\r\n");
	Rprintf("- length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23", 2);
	bcd2asc(dst, src, 3);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\x34\\x56\\x78\\x90\\xAB\\xCD\\xEF\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\x34\x56\x78\x90\xAB\xCD\xEF", 8);
	bcd2asc(dst, src, 16);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_zasc2bcd(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void zasc2bcd(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a ASCII string of Track 2 or 3 data to digithexadecimal digits with a trailing zero\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a ASCII string of Track 2 or 3 data\r\n");
	Rprintf("len\r\n");
	Rprintf("- length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123");
	zasc2bcd(dst, src, strlen(src));
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"0123456789:;<=>?\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "0123456789:;<=>?");
	zasc2bcd(dst, src, strlen(src));
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bcd2zasc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void bcd2zasc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert hexadecimal digits to a ASCII string of Track 2 or 3 data\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of hexadecimal digits\r\n");
	Rprintf("len\r\n");
	Rprintf("- length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23", 2);
	bcd2zasc(dst, src, 3);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\\x45\\x67\\x89\\xAB\\xCD\\xEF\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23\x45\x67\x89\xAB\xCD\xEF", 8);
	bcd2zasc(dst, src, 16);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_int2LL(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void int2LL(char *dst, int len);\r\n\r\n");
	Rprintf("Convert integer to 1-byte BCD for length of variable data element\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("len\r\n");
	Rprintf("- integer for length of variable data element (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: len = 1\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(dst, 1);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(dst, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_int2LLL(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void int2LLL(char *dst, int len);\r\n\r\n");
	Rprintf("Convert integer to 2-byte BCD for length of variable data element\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("len\r\n");
	Rprintf("- integer for length of variable data element (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: len = 1\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(dst, 1);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(dst, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_LL2int(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("int LL2int(char *src);\r\n\r\n");
	Rprintf("Convert 1-byte BCD for length of variable data element to integer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of source buffer (01 up to 99)\r\n");
	Rprintf("return value\r\n");
	Rprintf("- integer for length of variable data element\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\"\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01", 1);
	Rprintf("return values: %d\r\n", LL2int(src));
	Rprintf("--------------------------------------------------------------------------------\r\n");
	
	Rprintf("test inputs: src = \"\\x99\"\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x99", 1);
	Rprintf("return values: %d\r\n", LL2int(src));
	Rprintf("--------------------------------------------------------------------------------\r\n");
}

void Test_LLL2int(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("int LLL2int(char *src);\r\n\r\n");
	Rprintf("Convert 2-byte BCD for length of variable data element to integer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of source buffer (0001 up to 0999)\r\n");
	Rprintf("return value\r\n");
	Rprintf("- integer for length of variable data element\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x00\\x01\"\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x00\x01", 2);
	Rprintf("return values: %d\r\n", LLL2int(src));
	Rprintf("--------------------------------------------------------------------------------\r\n");
	
	Rprintf("test inputs: src = \"\\x09\\x99\"\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x09\x99", 2);
	Rprintf("return values: %d\r\n", LLL2int(src));
	Rprintf("--------------------------------------------------------------------------------\r\n");
}

void Test_num_to_num(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void num_to_num(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("copy a numeric digit string from source to destination\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digit string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23", 2);
	num_to_num(dst, src, 3);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\x34\\x56\\x78\\x90\\x12\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\x34\x56\x78\x90\x12", 6);
	num_to_num(dst, src, 12);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_asc_to_num(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void asc_to_num(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a numeric ASCII string to a right justified numeric digit string with a leading zero\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "123", 3);
	asc_to_num(dst, src, 3);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123456789012\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "123456789012", 12);
	asc_to_num(dst, src, 12);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_num_to_asc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void num_to_asc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a right justified numeric digit string with a leading zero to a numeric ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digit string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23", 2);
	num_to_asc(dst, src, 3);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\x34\\x56\\x78\\x90\\x12\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\x34\x56\x78\x90\x12", 6);
	num_to_asc(dst, src, 12);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_num(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_num(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a null-terminated numeric ASCII string to a right justified numeric digit string with a leading zeroes\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated numeric ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123");
	str_to_num(dst, src, strlen(src));
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123");
	str_to_num(dst, src, 12);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123456789012\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123456789012");
	str_to_num(dst, src, strlen(src));
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_num_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void num_to_str(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a right justified numeric digit string with a leading zero to a null-terminated numeric ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digit string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x23\", len = 3\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x23", 2);
	num_to_str(dst, src, 3);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\x34\\x56\\x78\\x90\\x12\", len = 12\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\x34\x56\x78\x90\x12", 6);
	num_to_str(dst, src, 12);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_nL2_to_nL2(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void nL2_to_nL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 1-byte counted hexadecimal digit string from source to destination\r\n");
	Rprintf("The 1-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of 1-byte counted hexadecimal digit string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x10\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 1);
	for (i = 0; i < 1; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[1], temp, 1);
	nL2_to_nL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x99\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\"\r\n");
	Rprintf("\tmax_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 99);
	for (i = 0; i < 99; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[1], temp, 99);
	nL2_to_nL2(dst, src, 99);
	for (i = 0; i < 64; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_nL3_to_nL3(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void nL3_to_nL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 2-byte counted hexadecimal digit string from source to destination\r\n");
	Rprintf("The 2-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted hexadecimal digit string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x10\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 1);
	for (i = 0; i < 1; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[2], temp, 1);
	nL3_to_nL3(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x09\\x99\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\"\r\n");
	Rprintf("\tmax_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 999);
	for (i = 0; i < 999; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[2], temp, 999);
	nL3_to_nL3(dst, src, 999);
	for (i = 0; i < 512; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_nL2(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_nL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated numeric ASCII string to a left justified LLVAR numeric digit string with a trailing zero\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated numeric ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	for (i = 0; i < 1; i++)
		src[i] = ((i+1) % 10) + '0';
	src[i] = '\0';
	str_to_nL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"12345678901234567890123456789012345678901234567890\r\n");
	Rprintf("\t       1234567890123456789012345678901234567890123456789\"\r\n");
	Rprintf("\tmax_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	for (i = 0; i < 99; i++)
		src[i] = ((i+1) % 10) + '0';
	src[i] = '\0';
	str_to_nL2(dst, src, 99);
	for (i = 0; i < 64; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_nL2_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void nL2_to_str(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLVAR numeric digit string with trailing zeroes to a null-terminated numeric ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of 2-byte counted numeric digit string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x01\\x10\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 1);
	for (i = 0; i < 1; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[1], temp, 1);
	nL2_to_str(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x99\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\x78\\x90\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\"\r\n");
	Rprintf("\tmax_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 99);
	for (i = 0; i < 99; i++)
		temp[i] = ((i+1) % 10) + '0';
	asc2bcd(&src[1], temp, 99);
	nL2_to_str(dst, src, 99);
	for (i = 0; i < 128; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_xnu_to_xnu(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void xnu_to_xnu(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Copy a numeric digit string with a prefix \"C\" or \"D\" from source to destination\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digit string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("(\"C\": Credit, \"D\": Debit)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"C\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "C\x12\x34\x56\x78\x90\x12\x34\x56", 9);
	xnu_to_xnu(dst, src, 16);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_asc_to_xnu(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void asc_to_xnu(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a numeric ASCII string with a prefix \"C\" or \"D\" to a numeric digit string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric ASCII string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("(\"C\": Credit, \"D\": Debit)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"C1234567890123456\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "C1234567890123456", 17);
	asc_to_xnu(dst, src, 16);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_xnu_to_asc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void xnu_to_asc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a numeric digit string with a prefix \"C\" or \"D\" to a numeric ASCII string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digits with a prefix \"C\" or \"D\"\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("(\"C\": Credit, \"D\": Debit)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"C\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "C\x12\x34\x56\x78\x90\x12\x34\x56", 9);
	xnu_to_asc(dst, src, 16);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_xnu(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_xnu(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a null-terminated numeric ASCII string with a prefix \"C\" or \"D\" to a numeric digit string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated numeric ASCII string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("(\"C\": Credit, \"D\": Debit)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"C1234567890123456\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "C1234567890123456");
	str_to_xnu(dst, src, 16);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_xnu_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void xnu_to_str(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a numeric digit string with a prefix \"C\" or \"D\" to a null-terminated numeric ASCII string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a numeric digit string with a prefix \"C\" or \"D\"\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of digits\r\n");
	Rprintf("(\"C\": Credit, \"D\": Debit)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"C\\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\", len = 16\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "C\x12\x34\x56\x78\x90\x12\x34\x56", 9);
	xnu_to_str(dst, src, 16);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_zL2(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_zL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated ASCII string of track 2 data to a left justified LLVAR hexadecimal digit string with trailing 'F'\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated ASCII string of Track 2 data\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (37)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1234567890123456=1701:;<=>?000000000\", max_len = 37\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890123456=1701:;<=>?000000000");
	str_to_zL2(dst, src, 37);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1234567890123456=1701:;<=>?0000000000\", max_len = 37\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890123456=1701:;<=>?0000000000");
	str_to_zL2(dst, src, 37);
	for (i = 0; i < 32; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_zL2_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void zL2_to_str(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLVAR hexadecimal digit string with trailing 'F' to a null-terminated ASCII string of track 2 data\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 1-byte counted hexadecimal digit string of Track 2 data\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (37)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x36\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\xD1\\x70\\x1A\\xBC\\xDE\\xF0\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\"\r\n");
	Rprintf("\tmax_len = 37\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x36\x12\x34\x56\x78\x90\x12\x34\x56\xD1\x70\x1A\xBC\xDE\xF0\x00\x00\x00\x00", 19);
	zL2_to_str(dst, src, 37);
	for (i = 0; i < 48; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x37\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\xD1\\x70\\x1A\\xBC\\xDE\\xF0\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x0F\"\r\n");
	Rprintf("\tmax_len = 37\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x37\x12\x34\x56\x78\x90\x12\x34\x56\xD1\x70\x1A\xBC\xDE\xF0\x00\x00\x00\x00\x0F", 20);
	zL2_to_str(dst, src, 37);
	for (i = 0; i < 48; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_zL3(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_zL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated ASCII string of track 3 data to a left justified LLLVAR hexadecimal digit string with trailing 'F'\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated ASCII string of track 3 data\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (104)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"1234567890123456=1701:;<=>?00000000000000000000000\r\n");
	Rprintf("\t       00000000000000000000000000000000000000000000000000\r\n");
	Rprintf("\t       000\"\r\n");
	Rprintf("\tmax_len = 104\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890123456=1701:;<=>?0000000000000000000000000000000000000000000000000000000000000000000000000000");
	str_to_zL3(dst, src, 104);
	for (i = 0; i < 64; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:r\n");
	Rprintf("\tsrc = \"1234567890123456=1701:;<=>?00000000000000000000000\r\n");
	Rprintf("\t       00000000000000000000000000000000000000000000000000\r\n");
	Rprintf("\t       0000\"\r\n");
	Rprintf("\tmax_len = 104\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890123456=1701:;<=>?00000000000000000000000000000000000000000000000000000000000000000000000000000");
	str_to_zL3(dst, src, 104);
	for (i = 0; i < 64; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_zL3_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void zL3_to_str(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLLVAR hexadecimal digit string with trailing 'F' to a null-terminated ASCII string of track 3 data\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted hexadecimal digit string of track 3 data\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of digits (104)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x01\\x03\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\xD1\\x70\\x1A\\xBC\\xDE\\xF0\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x0F\"\r\n");
	Rprintf("\tmax_len = 104\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x03\x12\x34\x56\x78\x90\x12\x34\x56\xD1\x70\x1A\xBC\xDE\xF0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0F", 54);
	zL3_to_str(dst, src, 104);
	for (i = 0; i < 128; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x01\\x04\r\n");
	Rprintf("\t       \\x12\\x34\\x56\\x78\\x90\\x12\\x34\\x56\\xD1\\x70\\x1A\\xBC\\xDE\\xF0\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\r\n");
	Rprintf("\t       \\x00\\x00\\x00\\x00\"\r\n");
	Rprintf("\tmax_len = 104\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x01\x04\x12\x34\x56\x78\x90\x12\x34\x56\xD1\x70\x1A\xBC\xDE\xF0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 54);
	zL3_to_str(dst, src, 104);
	for (i = 0; i < 128; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_asc_to_asc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void asc_to_asc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Copy a n bytes string from source to destination\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a n bytes string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of charcters\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = 0x00 to 0xFF, len = 256\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	for (i = 0; i < 256; i++)
		src[i] = i;
	asc_to_asc(dst, src, 256);
	for (i = 0; i < 256; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_asc(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_asc(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a null-terminated ASCII string to a left justified ASCII string with trailing spaces\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of charcters\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1234567890\", len = 15\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "1234567890");
	str_to_asc(dst, src, 15);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123456789012345\", len = 15\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "123456789012345");
	str_to_asc(dst, src, 15);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_asc_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void asc_to_str(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a left justified ASCII string with trailing spaces to a null-terminated ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of charcters\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"1234567890     \", len = 15\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "1234567890      ", 15);
	asc_to_str(dst, src, 15);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"123456789012345\", len = 15\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "1234567890123456", 15);
	asc_to_str(dst, src, 15);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_aL2_to_aL2(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void aL2_to_aL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 1-byte counted string from source to destination\r\n");
	Rprintf("The 1-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of 1-byte counted string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x05BITEL\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 5);
	memcpy(&src[1], "BITEL", 5);
	aL2_to_aL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x99\r\n");
	Rprintf("\t       \\x00\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x0B\\x0C\\x0D\\x0E\\x0F\r\n");
	Rprintf("\t       \\x10\\x11\\x12\\x13\\x14\\x15\\x16\\x17\\x18\\x19\\x1A\\x1B\\x1C\\x1D\\x1E\\x1F\r\n");
	Rprintf("\t        !\"#$\%&'()*+,-./\r\n");
	Rprintf("\t       0123456789:;<=>?\r\n");
	Rprintf("\t       @ABCDEFGHIJKLMNO\r\n");
	Rprintf("\t       PQRSTUVWXYZ[\\]^_\r\n");
	Rprintf("\t       `ab\"\r\n");
	Rprintf("\tmax_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 99);
	for (i = 0; i < 99; i++)
		src[1+i] = i;
	aL2_to_aL2(dst, src, 99);
	for (i = 0; i < 128; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_aL2(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_aL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated ASCII string to a left justified LLVAR ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"BITEL\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "BITEL");
	str_to_aL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_aL2_to_str(void)
{
	int i;
	char src[1002], dst[1002], temp[1002];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void aL2_to_str(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLVAR ASCII string to a null-terminated ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 1-byte counted ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x05BITEL\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 5);
	memcpy(&src[1], "BITEL", 5);
	aL2_to_str(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_aL3_to_aL3(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void aL3_to_aL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 2-byte counted string from source to destination\r\n");
	Rprintf("The 2-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x00\\x05BITEL\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 5);
	memcpy(&src[2], "BITEL", 5);
	aL3_to_aL3(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs:\r\n");
	Rprintf("\tsrc = \"\\x09\\x99\r\n");
	Rprintf("\t       \\x00\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x0B\\x0C\\x0D\\x0E\\x0F\r\n");
	Rprintf("\t       \\x10\\x11\\x12\\x13\\x14\\x15\\x16\\x17\\x18\\x19\\x1A\\x1B\\x1C\\x1D\\x1E\\x1F\r\n");
	Rprintf("\t        !\"#$%&'()*+,-./\r\n");
	Rprintf("\t       0123456789:;<=>?\r\n");
	Rprintf("\t       @ABCDEFGHIJKLMNO\r\n");
	Rprintf("\t       PQRSTUVWXYZ[\\]^_\r\n");
	Rprintf("\t       `abcdefghijklmno\r\n");
	Rprintf("\t       pqrstuvwxyz{|}~\\x7F\r\n");
	Rprintf("\t       \\x80\\x81\\x82\\x83\\x84\\x85\\x86\\x87\\x88\\x89\\x8A\\x8B\\x8C\\x8D\\x8E\\x8F\r\n");
	Rprintf("\t       \\x90\\x91\\x92\\x93\\x94\\x95\\x96\\x97\\x98\\x99\\x9A\\x9B\\x9C\\x9D\\x9E\\x9F\r\n");
	Rprintf("\t       \\xA0\\xA1\\xA2\\xA3\\xA4\\xA5\\xA6\\xA7\\xA8\\xA9\\xAA\\xAB\\xAC\\xAD\\xAE\\xAF\r\n");
	Rprintf("\t       \\xB0\\xB1\\xB2\\xB3\\xB4\\xB5\\xB6\\xB7\\xB8\\xB9\\xBA\\xBB\\xBC\\xBD\\xBE\\xBF\r\n");
	Rprintf("\t       \\xC0\\xC1\\xC2\\xC3\\xC4\\xC5\\xC6\\xC7\\xC8\\xC9\\xCA\\xCB\\xCC\\xCD\\xCE\\xCF\r\n");
	Rprintf("\t       \\xD0\\xD1\\xD2\\xD3\\xD4\\xD5\\xD6\\xD7\\xD8\\xD9\\xDA\\xDB\\xDC\\xDD\\xDE\\xDF\r\n");
	Rprintf("\t       \\xE0\\xE1\\xE2\\xE3\\xE4\\xE5\\xE6\\xE7\\xE8\\xE9\\xEA\\xEB\\xEC\\xED\\xEE\\xEF\r\n");
	Rprintf("\t       \\xF0\\xF1\\xF2\\xF3\\xF4\\xF5\\xF6\\xF7\\xF8\\xF9\\xFA\\xFB\\xFC\\xFD\\xFE\\xFF\r\n");
	Rprintf("\t       \\x00\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x0B\\x0C\\x0D\\x0E\\x0F\r\n");
	Rprintf("\t       \\x10\\x11\\x12\\x13\\x14\\x15\\x16\\x17\\x18\\x19\\x1A\\x1B\\x1C\\x1D\\x1E\\x1F\r\n");
	Rprintf("\t        !\"#$%&'()*+,-./\r\n");
	Rprintf("\t       0123456789:;<=>?\r\n");
	Rprintf("\t       @ABCDEFGHIJKLMNO\r\n");
	Rprintf("\t       PQRSTUVWXYZ[\\]^_\r\n");
	Rprintf("\t       `abcdefghijklmno\r\n");
	Rprintf("\t       pqrstuvwxyz{|}~\\x7F\r\n");
	Rprintf("\t       \\x80\\x81\\x82\\x83\\x84\\x85\\x86\\x87\\x88\\x89\\x8A\\x8B\\x8C\\x8D\\x8E\\x8F\r\n");
	Rprintf("\t       \\x90\\x91\\x92\\x93\\x94\\x95\\x96\\x97\\x98\\x99\\x9A\\x9B\\x9C\\x9D\\x9E\\x9F\r\n");
	Rprintf("\t       \\xA0\\xA1\\xA2\\xA3\\xA4\\xA5\\xA6\\xA7\\xA8\\xA9\\xAA\\xAB\\xAC\\xAD\\xAE\\xAF\r\n");
	Rprintf("\t       \\xB0\\xB1\\xB2\\xB3\\xB4\\xB5\\xB6\\xB7\\xB8\\xB9\\xBA\\xBB\\xBC\\xBD\\xBE\\xBF\r\n");
	Rprintf("\t       \\xC0\\xC1\\xC2\\xC3\\xC4\\xC5\\xC6\\xC7\\xC8\\xC9\\xCA\\xCB\\xCC\\xCD\\xCE\\xCF\r\n");
	Rprintf("\t       \\xD0\\xD1\\xD2\\xD3\\xD4\\xD5\\xD6\\xD7\\xD8\\xD9\\xDA\\xDB\\xDC\\xDD\\xDE\\xDF\r\n");
	Rprintf("\t       \\xE0\\xE1\\xE2\\xE3\\xE4\\xE5\\xE6\\xE7\\xE8\\xE9\\xEA\\xEB\\xEC\\xED\\xEE\\xEF\r\n");
	Rprintf("\t       \\xF0\\xF1\\xF2\\xF3\\xF4\\xF5\\xF6\\xF7\\xF8\\xF9\\xFA\\xFB\\xFC\\xFD\\xFE\\xFF\r\n");
	Rprintf("\t       \\x00\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x0B\\x0C\\x0D\\x0E\\x0F\r\n");
	Rprintf("\t       \\x10\\x11\\x12\\x13\\x14\\x15\\x16\\x17\\x18\\x19\\x1A\\x1B\\x1C\\x1D\\x1E\\x1F\r\n");
	Rprintf("\t        !\"#$%&'()*+,-./\r\n");
	Rprintf("\t       0123456789:;<=>?\r\n");
	Rprintf("\t       @ABCDEFGHIJKLMNO\r\n");
	Rprintf("\t       PQRSTUVWXYZ[\\]^_\r\n");
	Rprintf("\t       `abcdefghijklmno\r\n");
	Rprintf("\t       pqrstuvwxyz{|}~\\x7F\r\n");
	Rprintf("\t       \\x80\\x81\\x82\\x83\\x84\\x85\\x86\\x87\\x88\\x89\\x8A\\x8B\\x8C\\x8D\\x8E\\x8F\r\n");
	Rprintf("\t       \\x90\\x91\\x92\\x93\\x94\\x95\\x96\\x97\\x98\\x99\\x9A\\x9B\\x9C\\x9D\\x9E\\x9F\r\n");
	Rprintf("\t       \\xA0\\xA1\\xA2\\xA3\\xA4\\xA5\\xA6\\xA7\\xA8\\xA9\\xAA\\xAB\\xAC\\xAD\\xAE\\xAF\r\n");
	Rprintf("\t       \\xB0\\xB1\\xB2\\xB3\\xB4\\xB5\\xB6\\xB7\\xB8\\xB9\\xBA\\xBB\\xBC\\xBD\\xBE\\xBF\r\n");
	Rprintf("\t       \\xC0\\xC1\\xC2\\xC3\\xC4\\xC5\\xC6\\xC7\\xC8\\xC9\\xCA\\xCB\\xCC\\xCD\\xCE\\xCF\r\n");
	Rprintf("\t       \\xD0\\xD1\\xD2\\xD3\\xD4\\xD5\\xD6\\xD7\\xD8\\xD9\\xDA\\xDB\\xDC\\xDD\\xDE\\xDF\r\n");
	Rprintf("\t       \\xE0\\xE1\\xE2\\xE3\\xE4\\xE5\\xE6\\xE7\\xE8\\xE9\\xEA\\xEB\\xEC\\xED\\xEE\\xEF\r\n");
	Rprintf("\t       \\xF0\\xF1\\xF2\\xF3\\xF4\\xF5\\xF6\\xF7\\xF8\\xF9\\xFA\\xFB\\xFC\\xFD\\xFE\\xFF\r\n");
	Rprintf("\t       \\x00\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x0B\\x0C\\x0D\\x0E\\x0F\r\n");
	Rprintf("\t       \\x10\\x11\\x12\\x13\\x14\\x15\\x16\\x17\\x18\\x19\\x1A\\x1B\\x1C\\x1D\\x1E\\x1F\r\n");
	Rprintf("\t        !\"#$%&'()*+,-./\r\n");
	Rprintf("\t       0123456789:;<=>?\r\n");
	Rprintf("\t       @ABCDEFGHIJKLMNO\r\n");
	Rprintf("\t       PQRSTUVWXYZ[\\]^_\r\n");
	Rprintf("\t       `abcdefghijklmno\r\n");
	Rprintf("\t       pqrstuvwxyz{|}~\\x7F\r\n");
	Rprintf("\t       \\x80\\x81\\x82\\x83\\x84\\x85\\x86\\x87\\x88\\x89\\x8A\\x8B\\x8C\\x8D\\x8E\\x8F\r\n");
	Rprintf("\t       \\x90\\x91\\x92\\x93\\x94\\x95\\x96\\x97\\x98\\x99\\x9A\\x9B\\x9C\\x9D\\x9E\\x9F\r\n");
	Rprintf("\t       \\xA0\\xA1\\xA2\\xA3\\xA4\\xA5\\xA6\\xA7\\xA8\\xA9\\xAA\\xAB\\xAC\\xAD\\xAE\\xAF\r\n");
	Rprintf("\t       \\xB0\\xB1\\xB2\\xB3\\xB4\\xB5\\xB6\\xB7\\xB8\\xB9\\xBA\\xBB\\xBC\\xBD\\xBE\\xBF\r\n");
	Rprintf("\t       \\xC0\\xC1\\xC2\\xC3\\xC4\\xC5\\xC6\\xC7\\xC8\\xC9\\xCA\\xCB\\xCC\\xCD\\xCE\\xCF\r\n");
	Rprintf("\t       \\xD0\\xD1\\xD2\\xD3\\xD4\\xD5\\xD6\\xD7\\xD8\\xD9\\xDA\\xDB\\xDC\\xDD\\xDE\\xDF\r\n");
	Rprintf("\t       \\xE0\\xE1\\xE2\\xE3\\xE4\\xE5\\xE6\"\r\n");
	Rprintf("\tmax_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 999);
	for (i = 0; i < 999; i++)
		src[2+i] = i;
	aL3_to_aL3(dst, src, 999);
	for (i = 0; i < 1024; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_str_to_aL3(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void str_to_aL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated ASCII string to a left justified LLLVAR ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of null-terminated ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"BITEL\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "BITEL");
	str_to_aL3(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_aL3_to_str(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("void aL3_to_str(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLLVAR ASCII string to a null-terminated ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of characters (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x00\\x05BITEL\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 5);
	memcpy(&src[2], "BITEL", 5);
	aL3_to_str(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bin_to_bin(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bin_to_bin(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Copy a n bytes binary string from source to destination\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a binary string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of binary string\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\xAB\\x00\\xCD\", len = 4\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\xAB\x00\xCD", 4);
	bin_to_bin(dst, src, 4);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_hst_to_bin(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("hst_to_bin(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a null-terminated hexadecimal ASCII string to a left justified binary string with trailing zeroes\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of binary string\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00C\", len = 4\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00C");
	hst_to_bin(dst, src, 4);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00CD\", len = 4\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00CD");
	hst_to_bin(dst, src, 4);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bin_to_hst(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bin_to_hst(char *dst, char *src, int len);\r\n\r\n");
	Rprintf("Convert a left justified binary string with trailing zeroes to a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a binary string\r\n");
	Rprintf("len\r\n");
	Rprintf("- fixed length of binary string\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x12\\xAB\\x00\\xCD\", len = 4\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	memcpy(src, "\x12\xAB\x00\xCD", 4);
	bin_to_hst(dst, src, 4);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bL2_to_bL2(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bL2_to_bL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 1-byte counted binary string from source to destination\r\n");
	Rprintf("The 1-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 1-byte counted binary string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x04\\x12\\xAB\\x00\\xCD\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 4);
	memcpy(&src[1], "\x12\xAB\x00\xCD", 4);
	bL2_to_bL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_hst_to_bL2(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("hst_to_bL2(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated hexadecimal ASCII string to a left justified LLVAR binary string with trailing zeroes\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00C\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00C");
	hst_to_bL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00CD\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00CD");
	hst_to_bL2(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bL2_to_hst(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bL2_to_hst(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLVAR binary string with trailing zeroes to a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 1-byte counted binary string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 99)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x04\\x12\\xAB\\x00\\xCD\", max_len = 99\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LL(src, 4);
	memcpy(&src[1], "\x12\xAB\x00\xCD", 4);
	bL2_to_hst(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bL3_to_bL3(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bL3_to_bL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Copy a 2-byte counted binary string from source to destination\r\n");
	Rprintf("The 2-byte count is in BCD format\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted binary string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x00\\x04\\x12\\xAB\\x00\\xCD\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 4);
	memcpy(&src[2], "\x12\xAB\x00\xCD", 4);
	bL3_to_bL3(dst, src, 99);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_hst_to_bL3(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("hst_to_bL3(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a null-terminated hexadecimal ASCII string to a left justified LLLVAR binary string with trailing zeroes\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00C\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00C");
	hst_to_bL3(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
	
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"12AB00CD\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	strcpy(src, "12AB00CD");
	hst_to_bL3(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

void Test_bL3_to_hst(void)
{
	int i;
	char src[1024], dst[1024], temp[1024];
	
	Rprintf("\r\n\r\n");
	Rprintf("================================================================================\r\n");
	Rprintf("bL3_to_hst(char *dst, char *src, int max_len);\r\n\r\n");
	Rprintf("Convert a left justified LLLVAR binary string with trailing zeroes to a null-terminated hexadecimal ASCII string\r\n");
	Rprintf("dst\r\n");
	Rprintf("- pointer of destination buffer\r\n");
	Rprintf("src\r\n");
	Rprintf("- pointer of a 2-byte counted binary string\r\n");
	Rprintf("max_len\r\n");
	Rprintf("- maximum length of binary string (1 up to 999)\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("test inputs: src = \"\\x00\\x04\\x12\\xAB\\x00\\xCD\", max_len = 999\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	Rprintf("return values\r\n");
	Rprintf("--------------------------------------------------------------------------------\r\n");
	memset(src, 0xFF, sizeof(src));
	memset(dst, 0xFF, sizeof(dst));
	int2LLL(src, 4);
	memcpy(&src[2], "\x12\xAB\x00\xCD", 4);
	bL3_to_hst(dst, src, 999);
	for (i = 0; i < 16; i++) {
		Rprintf("%02X ", (unsigned char)dst[i]);
		if (i % 16 == 15)
			Rprintf("\r\n");
	}
}

/* */
