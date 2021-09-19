
#include "system.h"
#include "extern.h"

#define USER_DEBUG 1
#define SETUP_PREFIX		0x100E

_st_Setup stf_Setup, st_Setup;

void LoadSetup(void);
void InitializeSetup(void);
void SaveSetup(char check_mode);



void LoadSetup(void)
{
#ifdef USER_DEBUG
	Rprintf("\r\nLoad POS Setup\r\n");
#endif
	LoadCfg();
	if (stf_Setup.sPrefix != SETUP_PREFIX || memcmp(stf_Setup.c16ProgramVersion, tbl_ProgramVersion, 16))
		InitializeSetup();
	else
		memcpy(&st_Setup, &stf_Setup, sizeof(st_Setup));
}

void InitializeSetup(void)
{
#ifdef USER_DEBUG
	Rprintf("Initialize POS Setup\r\n");
#endif
	memset(&st_Setup, 0x00, sizeof(st_Setup));
	st_Setup.sPrefix = SETUP_PREFIX;
	
	st_Setup.cComDevice = 0;
	
	st_Setup.cPABXUse = 0;
	strcpy(st_Setup.sz6PABXCode, "9");
	strcpy(st_Setup.sz17TelNo, "142");
	st_Setup.ucDialingTimeout = 30;
	st_Setup.ucCommTimeout = 30;
	st_Setup.cModemSpeed = 0;
	st_Setup.cSyncMode = 1;
	st_Setup.cBellMode = 0;
	st_Setup.cBlindMode = 0;
	st_Setup.cPulseDial = 0;
	
	st_Setup.cMSRTrack3 = 0;
	
	st_Setup.cLANComPort = 1;
	strcpy(st_Setup.sz16LocalIP, "211.63.70.185");
	strcpy(st_Setup.sz16SubnetMask, "255.255.255.224");
	strcpy(st_Setup.sz16Gateway, "211.63.70.161");
	strcpy(st_Setup.sz6LocalPort, "8080");
	strcpy(st_Setup.sz5TimeOut, "10");
	strcpy(st_Setup.sz16ServerIP, "192.168.101.200");
	strcpy(st_Setup.sz6ServerPort, "8181");
	
	strcpy(st_Setup.sz3CountryCode, "59");		/* Italy */
	
	memcpy(st_Setup.c16ProgramVersion, tbl_ProgramVersion, sizeof(tbl_ProgramVersion));
	
	memcpy(&stf_Setup, &st_Setup, sizeof(st_Setup));
	memcpy(&st_Setup, &stf_Setup, sizeof(st_Setup));
	
	//InitializeRTCDateTime();
}

void SaveSetup(char check_mode)
{
	if (!check_mode || memcmp(&st_Setup, &stf_Setup, sizeof(st_Setup))) {
#ifdef USER_DEBUG
	Rprintf("Save POS Setup\r\n");
#endif
		//FLASH_WRITE(( char *)0x30000000 , sizeof(st_Setup),(char *)&st_Setup);
		memcpy(&stf_Setup, &st_Setup, sizeof(st_Setup));
		memcpy(&st_Setup, &stf_Setup, sizeof(st_Setup));
	}
}
int FlashWrite(U08 *pdst, U08 *psrc, long size)
{

	FLASH_WRITE(pdst, size, psrc);
	return size;
}
/* */
