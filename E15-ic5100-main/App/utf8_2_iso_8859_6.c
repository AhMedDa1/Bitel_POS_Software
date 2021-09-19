

/* UTF-8 to ISO-8859-1/ISO-8859-6 mapper.
 * Return 0..255 for valid ISO-8859-6 code points, 256 otherwise.
 */
 char *GET_SHA1(const char *string) {
	char result[21];
	char *hexresult ;//= calloc(100, sizeof(char));
	int offset;
	/* calculate hash */
	SHA1(result, string, strlen(string));

	/* format the hash for comparison */
	for (offset = 0; offset < 20; offset++) {
		sprintf((hexresult + (2 * offset)), "%02x", result[offset] & 0xff);
	}
	return hexresult;
}
static inline unsigned int to_arabic(const unsigned int code) {
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

/* Convert an UTF-8 string to ISO-8859-6.
 * All invalid sequences are ignored.
 * Note: output == input is allowed,
 * but   input < output < input + length
 * is not.
 * Output has to have room for (length+1) chars, including the trailing NUL byte.
 */
int utf8_to_iso_8859_6(char * const output,const char * const input,
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
				c = to_arabic(
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
				c = to_arabic(
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
				c = to_arabic(
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
				c = to_arabic(
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
				c = to_arabic(
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

int iso_8859_6_to_utf8(char * const output,const char * const input,
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




int fix_connected_chars(unsigned char* stream){

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
char *align_right(const char *stream){
    char res_stream[64];
	int i, empty_spaces, l_id;
	empty_spaces=0;
	if(strlen(stream) < 32){
		for(i = 0; i < 32 - strlen(stream) ; i++){
			res_stream[i] = ' ';
			empty_spaces++;
		}
		sprintf(res_stream,"%s%s",res_stream,stream);
	}else {
		sprintf(res_stream,"%s",stream);
	}

	strcpy(stream,res_stream);
    return stream;
}
char *align_right16(const char *stream){
    char res_stream[64];
	int i, empty_spaces, l_id;
	empty_spaces=0;
	if(strlen(stream) < 16){
		for(i = 0; i < 16 - strlen(stream) ; i++){
			res_stream[i] = ' ';
			empty_spaces++;
		}
		sprintf(res_stream,"%s%s",res_stream,stream);
	}else {
		sprintf(res_stream,"%s",stream);
	}

	strcpy(stream,res_stream);
    return stream;
}
char *right2left( const char *stream)
{
	char *result , temp;
	char r2l_stream[64];
    //result = calloc(24,sizeof(*stream));
	int i,j;
	for (i = 0; i < strlen(stream); i++) {
		//for (j=i+1;j<strlen(stream);j++){
			
		 //if (i < j){
           //     temp =  result[i];
                //result[strlen-i] = result[j];
                //result[j] = temp;
            //}
            
	//	result[strlen(stream)- i] = stream[i];
	r2l_stream[i]=stream[strlen(stream)-i-1];
	//}
	}
	r2l_stream[strlen(stream)]='\0';
	strcpy(stream,r2l_stream);
    return stream;
}

    char fix( const char *stream)
{
	    utf8_to_iso_8859_6(stream,stream, strlen(stream));
    	fix_connected_chars(stream);
	    right2left(stream);
	
return stream;	
}