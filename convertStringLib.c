
#include "convertStringLib.h"

const char validSymbol[] = "ABCEHIKLNOPRSTUWXYZ\0";
const char validDigit[] = "12345679\0";



__declspec(dllexport) int convertID(const char* src, char* dst, size_t size) {
	//провер€ем длину входной строки, должна быть не менее 3х символов и кратна 3м
	size_t len = strlen(src);
	if (len < 2 || len > MAXSIZESTRING || (len + 1) % 3 ) {
		return -1; //invalid src string
	}
	if (dst == NULL) return -2;		//invalid dst string
	if (size < 29) return -2;

	char carry = 0;
	char nextDigit = 0;

	for (size_t i = 0; i != len; ++i) { //копируем в обратном пор€дке
		dst[i] = src[len - 1 - i];
	}
	dst[len] = '\0';
	
	if (strchr(validDigit, dst[0]) == NULL) return -3; //invalid symbol in the string
	dst[0] += 1;
	if (dst[0] == ('9' + 1)) {
		dst[0] = '1';
		carry = 1;
		for (size_t i = 1; i != len; ++i) {
			if ((i + 1) % 3 == 0) {
				if (dst[i] == '-' ) {
					nextDigit = 1;
					continue;
				}
				else return -3; //invalid symbol in the string
			}
			if (i == 29 && carry == 1) return -4;
			if (carry == 0) break;
			if (nextDigit) {
				nextDigit = 0;
				if (strchr(validDigit, dst[i]) == NULL) return -3; //invalid symbol in the string
				dst[i] += carry;
				if (dst[i] == ('9' + 1)) {
					dst[i] = '1';
					carry = 1;
				}
				else {
					carry = 0;
				}
				while (strchr(validDigit, dst[i]) == NULL) dst[i]++;
			}
			else {
				if (strchr(validSymbol, dst[i]) == NULL) return -3; //invalid symbol in the string
				dst[i] += carry;
				if (dst[i] == ('Z' + 1)) {
					carry = 1;
					dst[i] = 'A';
					if (i == 28 ) return -4; // not enough memory for dst string
					if (dst[i + 1] == '\0') {
						dst[i + 1] = '-';
						dst[i + 2] = '1';
						dst[i + 3] = 'A';
						dst[i + 4] = '\0';
						carry = 0;
						break;
					}
				}
				else carry = 0;
				while (strchr(validSymbol, dst[i]) == NULL) dst[i]++;
			}

		}
	}

	char tmp;
	size_t lenDst = strlen(dst);
	for (size_t i = 0; i != lenDst / 2; ++i) {
		tmp = dst[i];
		dst[i] = dst[lenDst - 1 - i];
		dst[lenDst - 1 - i] = tmp;
	}
	dst[lenDst] = '\0';
	return 0;
}