#include "system.h"
#include "extern.h"

_ebs_response  RESPONSE_BODY;

char class_no[65];
char num_rec[65];
char num_rec1[65];
//char num_rec2[65];
char num_rec2[65];
 char num_rec3[65];
 char num_rec4[129];
 char num_rec5[65];
 char num_rec6[65];
 char num_rec7[65];
 char num_rec8[65];
 char num_rec9[65];
 char num_rec10[65];
 char num_rec11[65];
 char num_rec12[65];
 char num_rec13[65];
 char num_rec14[65];
 char num_rec15[65];
 char num_rec16[65];
 char num_rec17[65];
char fees[65];
char fees1[65];
char fees2[65];
char fees3[65];
char fees4[65];
char fees5[65];
char fees6[65];
char fees7[65];
char fees8[65];
char fees9[65];
char fees10[65];
char fees11[65];
char fees12[65];
char fees13[65];
char fees14[65];
char fees15[65];

  char classn1[65];
  char classn1_1[65];
  char classn1_2[65];
  char classn2[65];
  char classn2_1[65];
  char classn2_2[65];
  char classn3[65];
  char classn3_1[65];
  char classn3_2[65];
  char classn4[65];
  char classn4_1[65];
  char classn4_2[65];
  char classn5[65];
  char classn5_1[65];
  char classn5_2[65];
  char classn6[65];
  char classn6_1[65];
  char classn6_2[65];
  char classn7[65];
  char classn7_1[65];
  char classn7_2[65];
  char classn8[65];
  char classn8_1[65];
  char classn8_2[65];
  char classn9[65];
  char classn9_1[65];
  char classn9_2[65];
  char classn10[65];
  char classn10_1[65];
  char classn10_2[65];
  char classn11[65];
  char classn11_1[65];
  char classn11_2[65];
  char classn12[65];
  char classn12_1[65];
  char classn12_2[65];
  char classn13[65];
  char classn13_1[65];
  char classn13_2[65];
  char classn14[65];
  char classn14_1[65];
  char classn14_2[65];
  char classn15[65];
  char classn15_1[65];
  char classn15_2[65];
  char classn16[65];
  char classn16_1[65];
  char classn16_2[65];
  char classn17[65];
  char classn17_1[65];
  char classn17_2[65];
  char feesn1[65];
  char feesn1_1[65];
  char feesn1_2[65];
  char feesn2[65];
  char feesn2_1[65];
  char feesn2_2[65];
  char feesn3[65];
  char feesn3_1[65];
  char feesn3_2[65];
  char feesn4[65];
  char feesn4_1[65];
  char feesn4_2[65];
  char feesn5[65];
  char feesn5_1[65];
  char feesn5_2[65];
  char feesn6[65];
  char feesn6_1[65];
  char feesn6_2[65];
  char feesn7[65];
  char feesn7_1[65];
  char feesn7_2[65];
  char feesn8[65];
  char feesn8_1[65];
  char feesn8_2[65];
  char feesn9[65];
  char feesn9_1[65];
  char feesn9_2[65];
  char feesn10[65];
  char feesn10_1[65];
  char feesn10_2[65];
  char feesn11[65];
  char feesn11_1[65];
  char feesn11_2[65];
  char feesn12[65];
  char feesn12_1[65];
  char feesn12_2[65];
  char feesn13[65];
  char feesn13_1[65];
  char feesn13_2[65];
  char feesn14[65];
  char feesn14_1[65];
  char feesn14_2[65];
  char feesn15[65];
  char feesn15_1[65];
  char feesn15_2[65];
  char feesn16[65];
  char feesn16_1[65];
  char feesn16_2[65];
  char feesn17[65];
  char feesn17_1[65];
  char feesn17_2[65];

void jsmn_init(jsmn_parser *parser);
int jsmn_parse(jsmn_parser *parser, const char *js, size_t len,jsmntok_t *tokens, unsigned int num_tokens);
int json_parse(char* body);

#define USER_DEBUG 1

int jsoneq(const char *json, jsmntok_t *tok, const char *s);

//	js[strlen(js)]='';
 int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

int test_issue_22(void) {
	int ro;
	jsmn_parser po;
	jsmntok_t tokens[128];
	const char *jso;

	jso = "{ \"height\":10, \"layers\":[ { \"data\":[6,6], \"height\":10, "
		"\"name\":\"Calque de Tile 1\", \"opacity\":1, \"type\":\"tilelayer\", "
		"\"visible\":true, \"width\":10, \"x\":0, \"y\":0 }], "
		"\"orientation\":\"orthogonal\", \"properties\": { }, \"tileheight\":32, "
		"\"tilesets\":[ { \"firstgid\":1, \"image\":\"..\\/images\\/tiles.png\", "
		"\"imageheight\":64, \"imagewidth\":160, \"margin\":0, \"name\":\"Tiles\", "
		"\"properties\":{}, \"spacing\":0, \"tileheight\":32, \"tilewidth\":32 }], "
		"\"tilewidth\":32, \"version\":1, \"width\":10 }";
	jsmn_init(&po);
	ro = jsmn_parse(&po, jso, strlen(jso), tokens, 128);
	
	if (ro < 0) {
		Rprintf("Failed to parse JSON: %d\n", ro);
		return 1;
	}
	if (ro < 1 || tokens[0].type == JSMN_OBJECT) {
		Rprintf("Object expected\n");
		Rprintf("Ro: %d\n", ro);
	
		return 1;
	}
	return ro;
}
int json_parse(char* body) {
	int i,j,k,size;
	int r , calss_0;
	char *additionaldata,*pequal, *psemi, *pstart;
	char *o;
	int count ;
	char *a;
	jsmn_parser p;
	const char *js;
	char tmp[30];

	jsmn_init(&p);
	jsmntok_t t[1024];

	r = jsmn_parse(&p, body, strlen(body), t, 1024);

	if (r < 0) {
		Rprintf("Failed to parse JSON: %d\n", r);
			
		return 1;
	}
	if (r < 1 || t[0].type == JSMN_OBJECT) {
		Rprintf("Object expected\n");
		Rprintf("r: %d\n", r);
	
	}
/* Loop over all keys of the root object */

	count = 1;
	for (i = 1 ; i < r ; i++) {
		
		if (jsoneq(body, &t[i], "workingKey") == 0) {

			Rprintf("workingKey: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.workingkey, body + t[i+1].start, t[i+1].end-t[i+1].start );
			strcpy(E15_CONFIGURATION.EBS_TWK,RESPONSE_BODY.workingkey);
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			Rprintf("workingKey: %s\r\n",E15_CONFIGURATION.EBS_TWK);
			i++;
		}
		else if (jsoneq(body, &t[i], "responseCode") == 0) {

			Rprintf("responseCode: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			//memset(&tmp[0], '\0', sizeof(tmp));
			memcpy(RESPONSE_BODY.responseCode, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//RESPONSE_BODY.responseCode = atoi(tmp);
			Rprintf("workingKey: %s\r\n",E15_CONFIGURATION.EBS_TWK);
			i++;
		}
	   	else if (jsoneq(body, &t[i], "ReferenceId") == 0) {

			Rprintf("ReferenceId: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.ReferenceId, body + t[i+1].start, t[i+1].end-t[i+1].start );
			Rprintf("ReferenceId: %s\r\n",RESPONSE_BODY.ReferenceId);
			i++;
		}
		else if (jsoneq(body, &t[i], "PAN") == 0) {

			Rprintf("PAN: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.PAN, body + t[i+1].start, t[i+1].end-t[i+1].start );
			Rprintf("RESPONSE_BODY.PAN: %s\r\n",RESPONSE_BODY.PAN);
			i++;
		}
		else if (jsoneq(body, &t[i], "approvalCode") == 0) {

			Rprintf("approvalCode: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.approvalCode, body + t[i+1].start, t[i+1].end-t[i+1].start );
			Rprintf("approvalCode: %s\r\n",RESPONSE_BODY.approvalCode);
			i++;
		}
		else if (jsoneq(body, &t[i], "systemTraceAuditNumber") == 0) {

			Rprintf("systemTraceAuditNumber: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.systemTraceAuditNumber, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			i++;
		}
		else if (jsoneq(body, &t[i], "referenceNumber") == 0) {

			Rprintf("referenceNumber: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.referenceNumber, body + t[i+1].start, t[i+1].end-t[i+1].start );
			Rprintf("referenceNumber",RESPONSE_BODY.referenceNumber);
			i++;
		}
		else if (jsoneq(body, &t[i], "responseStatus") == 0) {

			Rprintf("responseStatus: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.responseStatus, body + t[i+1].start, t[i+1].end-t[i+1].start );
			Rprintf("RESPONSE_BODY.responseStatus: %s\r\n",RESPONSE_BODY.responseStatus);
			i++;
		}
		else if (jsoneq(body, &t[i], "responseMessage") == 0) {

			Rprintf("responseMessage: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.responseMessage, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			i++;
		}
		else if (jsoneq(body, &t[i], "tranAmount") == 0) {

			Rprintf("tranAmount: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.tranAmount, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			i++;
		}
		else if (jsoneq(body, &t[i], "tranFee") == 0) {

			Rprintf("tranFee: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			strncpy(RESPONSE_BODY.tranFee, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			i++;
		}
		
		else if (jsoneq(body, &t[i], "additionalData") == 0) {

			Rprintf("additionalData: %.*s\r\n", t[i+1].end-t[i+1].start, body + t[i+1].start);
			//strncpy(RESPONSE_BODY.additionalData, body + t[i+1].start, t[i+1].end-t[i+1].start );
			additionaldata = pstart = body + t[i+1].start;
		//	Rprintf("additionalData: %s\r\n",RESPONSE_BODY.additionalData);
			for(j = 0; j < (t[i+1].end-t[i+1].start); j++){
				
				if(*(additionaldata + j) == ';'){
					psemi = additionaldata + j;
					size = psemi - pstart;
					
					//Rprintf("token size=%d\r\n", size);
					//Rprintf("token %s\r\n", pstart);
					for(k=0;k < size; k++){
						if(*(pstart + k) == '='){
							pequal = pstart + k;
							//Rprintf("key size: %d; value size: %d\r\n", k, psemi - pequal - 1);
							if ((k == 8) && !memcmp((char *)pstart, "UnitName", 8)){
								memcpy(RESPONSE_BODY.UnitName, pequal+1, psemi - pequal - 1 );
								
								Rprintf("UnitName: %s\r\n", RESPONSE_BODY.UnitName);
							}
							else if(k == 11 && !memcmp((char *)pstart, "ServiceName", 11)){
								memcpy(RESPONSE_BODY.ServiceName, pequal+1, psemi - pequal - 1 );
							Rprintf("ServiceName: %s\r\n", RESPONSE_BODY.ServiceName);
							}
							else if(k == 9 && !memcmp((char *)pstart, "PayerName", 9)){
								memcpy(RESPONSE_BODY.PayerName, pequal+1, psemi - pequal - 1 );
							Rprintf("PayerName: %s\r\n", RESPONSE_BODY.PayerName);
							}
							else if(k == 11 && !memcmp((char *)pstart, "TotalAmount", 11)){
								//memset(&tmp[0], '\0', sizeof(tmp));
								memcpy(RESPONSE_BODY.TotalAmount, pequal+1, psemi - pequal - 1 );
							//	RESPONSE_BODY.TotalAmount = atof(tmp);
							Rprintf("TotalAmount: %s\r\n", RESPONSE_BODY.TotalAmount);
							}
							else if(k == 9 && !memcmp((char *)pstart, "DueAmount", 9)){
					//	memcpy(RESPONSE_BODY.DueAmount, pequal+1, psemi - pequal - 1 );
								Rprintf("UnitName: %s\r\n", RESPONSE_BODY.DueAmount);
							}
							else if(k == 13 && !memcmp((char *)pstart, "InvoiceExpiry", 13)){
							//	memcpy(RESPONSE_BODY.InvoiceExpiry, pequal+1, psemi - pequal - 1 );
								//Rprintf("UnitName: %s\r\n", RESPONSE_BODY.InvoiceExpiry);
							}
							else if(k == 13 && !memcmp((char *)pstart, "invoiceStatus", 13)){
						//		memcpy(RESPONSE_BODY.invoiceStatus, pequal+1, psemi - pequal - 1 );
						//		Rprintf("UnitName: %s\r\n", RESPONSE_BODY.invoiceStatus);
							}
						}
					}
					pstart = psemi + 1;
				}
			}
			//strncpy(RESPONSE_BODY.responseMessage, body + t[i+1].start, t[i+1].end-t[i+1].start );
			//Rprintf("workingKey: %s\r\n",RESPONSE_BODY.workingkey);
			i++;
		}
		
		
								


		
	}
	
}
		
		



/* UTF-8 to ISO-8859-1/ISO-8859-15 mapper.
 * Return 0..255 for valid ISO-8859-15 code points, 256 otherwise.
*/
unsigned int to_latin9(unsigned int code)
{
    /* Code points 0 to U+00FF are the same in both. */
    if (code < 256U)
        return code;
    switch (code) {
    case 0x0627U: return 0xB0; 	/* ا */
    case 0x0628U: return 0xB3; 	/* ب */
    case 0x062AU: return 0xB7;	/* ت */
    case 0x062BU: return 0xB9;	/* ث */
    case 0x062CU: return 0xBA; 	/* ج */
    case 0x062DU: return 0xBE; 	/* ? */
    case 0x062EU: return 0xC0; 	/* ? */
    case 0x062FU: return 0xC2;	/* ? */
    case 0x0630U: return 0xC3; 	/* ? */
    case 0x0631U: return 0xC4; 	/* ? */
    case 0x0632U: return 0xC5;	/* ? */
    case 0x0633U: return 0xC7;	/* ? */
    case 0x0634U: return 0xC9; 	/* ? */
    case 0x0635U: return 0xCB; 	/* ? */
    case 0x0636U: return 0xCD; 	/* ? */
    case 0x0637U: return 0xCF; 	/* ? */
    case 0x0638U: return 0xD0; 	/* ? */
    case 0x0639U: return 0xD1; 	/* ? */
    case 0x063AU: return 0xD5;	/* ? */
    case 0x0641U: return 0xD9;	/* ? */
    case 0x0642U: return 0xDB; 	/* ? */
    case 0x0643U: return 0xDD; 	/* ? */
    case 0x0644U: return 0xE1; 	/* ? */
    case 0x0645U: return 0xE4; 	/* ? */
    case 0x0646U: return 0xE6;	/* ? */
    case 0x0648U: return 0xE8;	/* ? */
    case 0x0647U: return 0xE9; 	/* ? */
    case 0x0649U: return 0xED; 	/* ? */
    case 0x064AU: return 0xEE; 	/* ? */
    
    default:      return 256U;
    }
}
static inline unsigned int to_arabicc(const unsigned int code) {
	/* Code points 0 to U+00FF are the same in both. */
	if (code < 127U)
		return code;
	else if ((code >= 0x0621U && code <= 0x063AU)
			|| (code >= 0x0640U && code <= 0x0652U))
		return code - 1376;

	switch (code) {
	case 0x00A0U:
		return 160U;
	case 0x00A4U:
		return 164U;
	case 0x060CU:
		return 172U;
	case 0x00ADU:
		return 173U;
	case 0x061BU:
		return 187U;
	case 0x061FU:
		return 191U;
	default:
		return 256U;
	}
}

/* Convert an UTF-8 string to ISO-8859-15.
 * All invalid sequences are ignored.
 * Note: output == input is allowed,
 * but   input < output < input + length
 * is not.
 * Output has to have room for (length+1) chars, including the trailing NUL byte.
*/
size_t utf8_to_farsi(char *output, char *input, size_t length)
{
    unsigned char *out = (unsigned char *)output;
    unsigned int c;
    unsigned char *in = (unsigned char *)input;
    unsigned char *end = (unsigned char *)in + length;
    

    while (in < end)
        if (*in < 128){      
        	*(out++) = *(in++); /* Valid codepoint */}
        else
        if (*in < 192){
            in++;               /* 10000000 .. 10111111 are invalid */
        }
        else
        if (*in < 224) {        /* 110xxxxx 10xxxxxx */
            if (in + 1 >= end)
                break;
            if ((in[1] & 192U) == 128U) {
                c = to_latin9( (((unsigned int)(in[0] & 0x1FU)) << 6U)
                             |  ((unsigned int)(in[1] & 0x3FU)) );
#ifdef USER_DEBUG
			Rprintf("INPUT < 224 =%02X \r\n", c);
#endif
                if (c < 256)
                    *(out++) = c;
            }
            in += 2;

        } else
        if (*in < 240) {        /* 1110xxxx 10xxxxxx 10xxxxxx */
            if (in + 2 >= end)
                break;
            if ((in[1] & 192U) == 128U &&
                (in[2] & 192U) == 128U) {
                c = to_latin9( (((unsigned int)(in[0] & 0x0FU)) << 12U)
                             | (((unsigned int)(in[1] & 0x3FU)) << 6U)
                             |  ((unsigned int)(in[2] & 0x3FU)) );
                   #ifdef USER_DEBUG
			Rprintf("INPUT < 240 =%02X \r\n", c);
#endif          
                if (c < 256)
                    *(out++) = c;
            }
            in += 3;

        } else
        if (*in < 248) {        /* 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */
            if (in + 3 >= end)
                break;
            if ((in[1] & 192U) == 128U &&
                (in[2] & 192U) == 128U &&
                (in[3] & 192U) == 128U) {
                c = to_latin9( (((unsigned int)(in[0] & 0x07U)) << 18U)
                             | (((unsigned int)(in[1] & 0x3FU)) << 12U)
                             | (((unsigned int)(in[2] & 0x3FU)) << 6U)
                             |  ((unsigned int)(in[3] & 0x3FU)) );
                             #ifdef USER_DEBUG
			Rprintf("INPUT 248 =%02X \r\n", c);
#endif
                if (c < 256)
                    *(out++) = c;
            }
            in += 4;

        } else
        if (*in < 252) {        /* 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx */
            if (in + 4 >= end)
                break;
            if ((in[1] & 192U) == 128U &&
                (in[2] & 192U) == 128U &&
                (in[3] & 192U) == 128U &&
                (in[4] & 192U) == 128U) {
                c = to_latin9( (((unsigned int)(in[0] & 0x03U)) << 24U)
                             | (((unsigned int)(in[1] & 0x3FU)) << 18U)
                             | (((unsigned int)(in[2] & 0x3FU)) << 12U)
                             | (((unsigned int)(in[3] & 0x3FU)) << 6U)
                             |  ((unsigned int)(in[4] & 0x3FU)) );
                             #ifdef USER_DEBUG
			Rprintf("INPUT 252 =%02X \r\n", c);
#endif
                if (c < 256)
                    *(out++) = c;
            }
            in += 5;

        } else
        if (*in < 254) {        /* 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx */
            if (in + 5 >= end)
                break;
            if ((in[1] & 192U) == 128U &&
                (in[2] & 192U) == 128U &&
                (in[3] & 192U) == 128U &&
                (in[4] & 192U) == 128U &&
                (in[5] & 192U) == 128U) {
                c = to_latin9( (((unsigned int)(in[0] & 0x01U)) << 30U)
                             | (((unsigned int)(in[1] & 0x3FU)) << 24U)
                             | (((unsigned int)(in[2] & 0x3FU)) << 18U)
                             | (((unsigned int)(in[3] & 0x3FU)) << 12U)
                             | (((unsigned int)(in[4] & 0x3FU)) << 6U)
                             |  ((unsigned int)(in[5] & 0x3FU)) );
                             #ifdef USER_DEBUG
			Rprintf("INPUT 254 =%02X \r\n", c);
#endif
                if (c < 256)
                    *(out++) = c;
            }
            in += 6;

        } else
            in++;               /* 11111110 and 11111111 are invalid */

    /* Terminate the output string. */
    *out = '\0';

    return (size_t)(out - (unsigned char *)output);
}
int utf8_to_iso_8859_66(char * const output,const char * const input,
		const int length) {
	unsigned char *out = (unsigned char *) output;
	const unsigned char *in = (const unsigned char *) input;
	const unsigned char * const end = (const unsigned char *) input + length;
	unsigned int c;

	while (in < end)
		if (*in < 128){
			*(out++) = *(in++); /* Valid codepoint */
		}
		else if (*in < 192){
			in++; /* 10000000 .. 10111111 are invalid */
		}
		else if (*in < 224) { /* 110xxxxx 10xxxxxx */
			if (in + 1 >= end)
				break;
			if ((in[1] & 192U) == 128U) {
				c = to_arabicc(
						(((unsigned int) (in[0] & 0x1FU)) << 6U)
								| ((unsigned int) (in[1] & 0x3FU)));
				if (c < 256)
					*(out++) = c;
			}
			in += 2;

		} else if (*in < 240) { /* 1110xxxx 10xxxxxx 10xxxxxx */
			if (in + 2 >= end)
				break;
			if ((in[1] & 192U) == 128U && (in[2] & 192U) == 128U) {
				c = to_arabicc(
						(((unsigned int) (in[0] & 0x0FU)) << 12U)
								| (((unsigned int) (in[1] & 0x3FU)) << 6U)
								| ((unsigned int) (in[2] & 0x3FU)));
				if (c < 256)
					*(out++) = c;
			}
			in += 3;

		} else if (*in < 248) { /* 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */
			if (in + 3 >= end)
				break;
			if ((in[1] & 192U) == 128U && (in[2] & 192U) == 128U
					&& (in[3] & 192U) == 128U) {
				c = to_arabicc(
						(((unsigned int) (in[0] & 0x07U)) << 18U)
								| (((unsigned int) (in[1] & 0x3FU)) << 12U)
								| (((unsigned int) (in[2] & 0x3FU)) << 6U)
								| ((unsigned int) (in[3] & 0x3FU)));
				if (c < 256)
					*(out++) = c;
			}
			in += 4;

		} else if (*in < 252) { /* 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx */
			if (in + 4 >= end)
				break;
			if ((in[1] & 192U) == 128U && (in[2] & 192U) == 128U
					&& (in[3] & 192U) == 128U && (in[4] & 192U) == 128U) {
				c = to_arabicc(
						(((unsigned int) (in[0] & 0x03U)) << 24U)
								| (((unsigned int) (in[1] & 0x3FU)) << 18U)
								| (((unsigned int) (in[2] & 0x3FU)) << 12U)
								| (((unsigned int) (in[3] & 0x3FU)) << 6U)
								| ((unsigned int) (in[4] & 0x3FU)));
				if (c < 256)
					*(out++) = c;
			}
			in += 5;

		} else if (*in < 254) { /* 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx */
			if (in + 5 >= end)
				break;
			if ((in[1] & 192U) == 128U && (in[2] & 192U) == 128U
					&& (in[3] & 192U) == 128U && (in[4] & 192U) == 128U
					&& (in[5] & 192U) == 128U) {
				c = to_arabicc(
						(((unsigned int) (in[0] & 0x01U)) << 30U)
								| (((unsigned int) (in[1] & 0x3FU)) << 24U)
								| (((unsigned int) (in[2] & 0x3FU)) << 18U)
								| (((unsigned int) (in[3] & 0x3FU)) << 12U)
								| (((unsigned int) (in[4] & 0x3FU)) << 6U)
								| ((unsigned int) (in[5] & 0x3FU)));
				if (c < 256)
					*(out++) = c;
			}
			in += 6;

		} else{
			in++; /* 11111110 and 11111111 are invalid */

		}

	/* Terminate the output string. */
	*out = '\0';

	return (out - (unsigned char *) output);
}

int iso_8859_6_to_utf88(char * const output,const char * const input,
		const int length) {
	unsigned char *out = (unsigned char *) output;
	const unsigned char *in = (const unsigned char *) input;
	const unsigned char * const end = (const unsigned char *) input + length;
	unsigned int high, low;
	while (in < end){
		if (*in < 128){
			*(out++) = *(in++); /* Valid codepoint */
		} else if((*in > 192 && *in < 219) ||(*in > 223 && *in < 235)){
			*(out++) = ((*in + 1376) / 64)+ 192;
			*(out++) = ((*in + 1376) & 63)+ 128;
			in++;
		} else{
			in++; /* 10000000 .. 10111111 are invalid */
		}
	}

	*out = '\0';
	return (out - (unsigned char *) output);

}

int fix_connected_charss(unsigned char* stream){

	int i,j, len;

	len  = strlen(stream);
	for(i=0; i<len; i++){
		if(stream[i] == 228U && (stream[i +1] == 194U ||stream[i +1] == 195U ||stream[i +1] == 197U ||stream[i +1] == 199U )){
			stream[i] = stream[i +1 ] + 42U;

			for(j=i +1; j <len;j++){
				stream[j] = stream[j +1 ];
			}
		}else if(((stream[i +1] > 193U && stream[i +1] < 197U) ||
			(stream[i +1] > 197U && stream[i +1] < 219U) ||
			(stream[i +1] > 224U && stream[i +1] < 235U)) &&
			(stream[i] == 198U || stream[i] == 200U || stream[i] == 234U ||
			(stream[i] > 201U && stream[i] < 207U) ||
			(stream[i] > 210U && stream[i] < 219U) ||
			(stream[i] > 224U && stream[i] < 232U))){
			if (stream[i+1] == 194U ||
					 stream[i+1] == 195U ||
					 stream[i+1] == 197U ||
					 stream[i+1] == 199U ){
				stream[i+1] = stream[i+1] +49U;
			}
			if(i > 0 && (stream[i] == 217U || stream[i] == 218U)){
				if(stream[i-1] == 138U || stream[i-1] == 140U || stream[i-1] == 174U ||
						(stream[i-1] > 141U && stream[i-1] < 147U) ||
						(stream[i-1] > 150U && stream[i-1] < 155U) ||
						(stream[i-1] > 156U && stream[i-1] < 159U) ||
						(stream[i-1] > 164U && stream[i-1] < 172U)){
					stream[i] = stream[i] - 60U;
				} else{
					stream[i] = stream[i] + 2U;
				}
			}else if(stream[i] != 215U && stream[i] != 216U){
				stream[i] = stream[i] - 60U;
			}
		}

	}
	return 0;
}
char *right2leftt( const char *stream)
{
	char *result , temp;
    //result = calloc(24,sizeof(*stream));
	int i,j;
	for (i = 0; i < strlen(stream); i++) {
		for (j=i+1;j<strlen(stream);j++){
			
		 if (i < j){
                temp =  result[i];
                result[i] = result[j];
                result[j] = temp;
            }
            }
//		result[strlen(stream)- i] = stream[i];
//	result[i]=stream[strlen(stream)-i];
	}
    return result;
}

