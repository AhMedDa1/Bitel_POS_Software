
#include "system.h"
#include "extern.h"


const char ALP_tbl[][3] =
{
	{'-', ',', ' '},	/* 0 */
	{'Q', 'Z', '.'},	/* 1 */
	{'A', 'B', 'C'},	/* 2 */
	{'D', 'E', 'F'},	/* 3 */
	{'G', 'H', 'I'},	/* 4 */
	{'J', 'K', 'L'},	/* 5 */
	{'M', 'N', 'O'},	/* 6 */
	{'P', 'R', 'S'},	/* 7 */
	{'T', 'U', 'V'},	/* 8 */
	{'X', 'Y', 'Z'},	/* 9 */
};

char cALPInputMode, cALPKeyInputFlag, cPreALPKey, cALPIndex;

void OneCharInput(char YPos, char XPos, char MinInputKey, char MaxInputKey, char InputKey, char *str);
void InputIPAddress(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);
void InputAlpNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);
void InputCETelephoneNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);



void OneCharInput(char YPos, char XPos, char MinInputKey, char MaxInputKey, char InputKey, char *str)
{
	if (InputKey < MinInputKey  || InputKey > MaxInputKey)
		return;
	
	CursorOff();
   	if (InputKey == BTKEY_ASTERISK)
   		str[0] = '*';
   	else if (InputKey == BTKEY_SHARP)
   		str[0] = '#';
   	else
   		str[0] = InputKey + '0';
   	Lprint_1(YPos, XPos, str[0]);
	str[1] = 0x00;
	
	CursorOn(YPos, XPos);
}

void InputIPAddress(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str)
{
	int i;
	char ch;
	
	if (InputKey > BTKEY_9 && InputKey != BTKEY_ASTERISK && InputKey != BTKEY_CLEAR)
		return;
	
   	CursorOff();
	switch (InputKey) {
		case BTKEY_CLEAR:	/* Back Space Key */
			if (strlen(str)) {
				ucKeyCnt = strlen(str) - 1;
				Lprint_1(YPos, XPos + ucKeyCnt, ' ');
			}
			else
				ucKeyCnt = 0;
			break;
			
		default:
			if (ucKeyCnt >= MaxInputCnt)
				break;
			
			if (ucKeyCnt == 0) {
				for (i = 0; i < MaxInputCnt; i++)
					Lprint_1(YPos, XPos+i, ' ');
				
				memset(str, 0x00, MaxInputCnt+1);
			}
			
			if (InputKey != BTKEY_ASTERISK)
				ch = InputKey + '0';
			else
				ch = '.';
			Lprint_1(YPos, XPos + ucKeyCnt, ch);
			str[ucKeyCnt++] = ch;
			break;
	}
	str[ucKeyCnt] = 0x00;
	
	if (ucKeyCnt < MaxInputCnt)
		CursorOn(YPos, XPos + ucKeyCnt);
}

void InputAlpNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str)
{
	int i;
	char ch;
	
#ifndef BITEL_IC6000P
	if (InputKey > BTKEY_9 && InputKey != BTKEY_CLEAR && InputKey != BTKEY_SFUNC)
#else
	if (InputKey > BTKEY_9 && InputKey != BTKEY_CLEAR && InputKey != BTKEY_A)
#endif
		return;
		
	if (cALPInputMode) {
#ifndef BITEL_IC6000P
		if ((InputKey < BTKEY_2 || InputKey > BTKEY_3) && InputKey != BTKEY_CLEAR && InputKey != BTKEY_SFUNC)
#else
		if ((InputKey < BTKEY_2 || InputKey > BTKEY_3) && InputKey != BTKEY_CLEAR && InputKey != BTKEY_A)
#endif
			return;
	}
	
   	CursorOff();
	switch (InputKey) {
		case BTKEY_CLEAR:	/* Back Space Key */
			i = strlen(str);
			if (i) {
				ucKeyCnt = i - 1;
				Lprint_1(YPos, XPos + ucKeyCnt, ' ');
			}
			else
				ucKeyCnt = 0;
			
			if (cALPInputMode) {
				cALPKeyInputFlag = 0;
				cALPIndex = 0;
			}
			
			str[ucKeyCnt] = 0x00;
			break;
			
#ifndef BITEL_IC6000P
		case BTKEY_SFUNC:	/* Special Function Key */
#else
		case BTKEY_A:
#endif
			if (cALPInputMode && cALPKeyInputFlag) {
				if (ucKeyCnt < MaxInputCnt)
					ucKeyCnt++;
			}
			
			if (ucKeyCnt == 0) {
				for (i = 0; i < MaxInputCnt; i++)
					Lprint_1(YPos, XPos+i, ' ');
				
				memset(str, 0x00, MaxInputCnt+1);
			}
			
			cALPInputMode ^= 0x01;	/* cALPInputMode=0: Number, cALPInputMode=1: Aplabet */
			if (cALPInputMode) {
				cALPKeyInputFlag = 0;
				cALPIndex = 0;
				Lprint_n(YPos, 11, 5, "[ALP]");
			}
			else {
				Lprint_n(YPos, 11, 5, "[NUM]");
			}
			str[ucKeyCnt] = 0x00;
			break;
			
		default:
			if (ucKeyCnt >= MaxInputCnt)
				break;
			
			if (cALPInputMode) {							/* Alpabet key inupt mode */
				if (!cALPKeyInputFlag) {					/* First alpabet key input */
					cALPKeyInputFlag = 1;
					cPreALPKey = InputKey;
					ch = ALP_tbl[cPreALPKey][cALPIndex];
					Lprint_1(YPos, XPos + ucKeyCnt, ch);
					str[ucKeyCnt] = ch;
					str[ucKeyCnt+1] = 0x00;
				}
				else {										/* Not first alpabet key input */
					if (InputKey == cPreALPKey) {			/* Key input value is the same of previous key value */
						cALPIndex++;
						if (cALPIndex > 2)
							cALPIndex = 0;
						ch = ALP_tbl[cPreALPKey][cALPIndex];
						Lprint_1(YPos, XPos + ucKeyCnt, ch);
						str[ucKeyCnt] = ch;
						str[ucKeyCnt+1] = 0x00;
					}
					else {									/* Key input value is not the same of previous key value */
						ucKeyCnt++;
						str[ucKeyCnt] = 0x00;
						if (ucKeyCnt < MaxInputCnt) {
							cPreALPKey = InputKey;
							ch = ALP_tbl[cPreALPKey][cALPIndex];
							Lprint_1(YPos, XPos + ucKeyCnt, ch);
							str[ucKeyCnt] = ch;
							str[ucKeyCnt+1] = 0x00;
						}
					}
				}
			}
			else {											/* Numeric key input */
				if (ucKeyCnt == 0) {
					for (i = 0; i < MaxInputCnt; i++)
						Lprint_1(YPos, XPos+i, ' ');
					
					memset(str, 0x00, MaxInputCnt+1);
				}
				
				ch = InputKey + '0';
				Lprint_1(YPos, XPos + ucKeyCnt, ch);
				str[ucKeyCnt++] = ch;
				str[ucKeyCnt] = 0x00;
			}
			break;
	}
	
	if (ucKeyCnt < MaxInputCnt)
		CursorOn(YPos, XPos + ucKeyCnt);
}

void InputCETelephoneNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str)
{
	int i;
	char ch;
	
	if (InputKey > BTKEY_SHARP && InputKey != BTKEY_CLEAR)
		return;
	
   	CursorOff();
	switch (InputKey) {
		case BTKEY_CLEAR:	/* Back Space Key */
			if (strlen(str)) {
				ucKeyCnt = strlen(str) - 1;
				Lprint_1(YPos, XPos + ucKeyCnt, ' ');
			}
			else
				ucKeyCnt = 0;
			break;
			
		default:
			if (ucKeyCnt >= MaxInputCnt)
				break;
			
			if (ucKeyCnt == 0) {
				for (i = 0; i < MaxInputCnt; i++)
					Lprint_1(YPos, XPos+i, ' ');
				
				memset(str, 0x00, MaxInputCnt+1);
			}
			
			if (InputKey == BTKEY_ASTERISK)
				ch = '*';
			else if (InputKey == BTKEY_SHARP)
				ch = '#';
			else
				ch = InputKey + '0';
			Lprint_1(YPos, XPos + ucKeyCnt, ch);
			str[ucKeyCnt++] = ch;
			break;
	}
	str[ucKeyCnt] = 0x00;
	
	if (ucKeyCnt < MaxInputCnt)
		CursorOn(YPos, XPos + ucKeyCnt);
}

/* */
