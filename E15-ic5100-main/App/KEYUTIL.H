
/* KEYUTIL.H */

extern const char ALP_tbl[][3];

extern char cALPInputMode, cALPKeyInputFlag, cPreALPKey, cALPIndex;

extern void OneCharInput(char YPos, char XPos, char MinInputKey, char MaxInputKey, char InputKey, char *str);
extern void InputIPAddress(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);
extern void InputAlpNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);
extern void InputCETelephoneNoString(char YPos, char XPos, char MaxInputCnt, char InputKey, char *str);

/* */
