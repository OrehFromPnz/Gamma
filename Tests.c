#include "Tests.h"

void test1(void) {
	char str[] = "A1";
	char corAns[3] = "A2";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING)== 0)
		if (strcmp(corAns, result) == 0)
			printf("test1 is Ok\t");
		else
			printf("test1 is fail\t");
	printf("%s -> \t\t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}

void test2() {
	char str[3] = "A9";
	char corAns[3] = "B1";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test2 is Ok\t");
		else
			printf("test2 is fail\t");
	printf("%s -> \t\t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}

void test3() {
	char str[3] = "C9";
	char corAns[3] = "E1";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test3 is Ok\t");
		else
			printf("test3 is fail\t");
	printf("%s -> \t\t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}

void test4() {
	char str[3] = "E9";
	char corAns[3] = "H1";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING) == 0);
		if (strcmp(corAns, result) == 0)
			printf("test4 is Ok\t");
		else
			printf("test4 is fail\t");
		printf("%s -> \t\t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}

void test5() {
	char str[3] = "Z9";
	char corAns[] = "A1-A1";
	char result[MAXSIZESTRING];
	if (convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test5 is Ok\t");
		else
			printf("test5 is fail\t");
	printf("%s -> \t\t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}

void test6() {
	char str[] = "A1-Z9";
	char corAns[] = "A2-A1";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test6 is Ok\t");
		else
			printf("test6 is fail\t");
	printf("%s -> \t\t\t%s \t\t\t\t(%s)\n", str, result, corAns);
}
void test7() {
	char str[] = "Z9-Z9";
	char corAns[] = "A1-A1-A1";
	char result[MAXSIZESTRING];
	if(convertID(str, result,MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test7 is Ok\t");
		else
			printf("test7 is fail\t");
	printf("%s -> \t\t\t%s \t\t\t(%s)\n", str, result, corAns);
}
void test8() {
	char str[] = "W9-Z9-Z9";
	char corAns[] = "X1-A1-A1";
	char result[MAXSIZESTRING];
	if(convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test8 is Ok\t");
		else
			printf("test8 is fail\t");
	printf("%s -> \t\t\t%s \t\t\t(%s)\n", str, result, corAns);
}
void test9() {
	char str[] = "Y9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
	char corAns[] = "Z1-A1-A1-A1-A1-A1-A1-A1-A1-A1";
	char result[MAXSIZESTRING + 1];
	if (convertID(str, result, MAXSIZESTRING) == 0)
		if (strcmp(corAns, result) == 0)
			printf("test9 is Ok\t");
		else
			printf("test9 is fail\t");
	printf("%s -> %s  (%s)\n", str, result, corAns);
} 

void test10() {
	char str[] = "Y9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
	char corAns[] = "Z1-A1-A1-A1-A1-A1-A1-A1-A1-A1";
	char* result = malloc(sizeof(char) * MAXSIZESTRING);
	if (result) {
		if (convertID(str, result, MAXSIZESTRING+2) == 0)
			if (strcmp(corAns, result) == 0)
				printf("test10 is Ok\t");
			else
				printf("test10 is fail\t");
		printf("%s -> %s  (%s)\n", str, result, corAns);
	}
	else printf("the test wasn't performed because the memory wasn't allocated");
	free(result);
	result = NULL;
}
void test11() {
	char str[] = "1A-1A";
	char result[MAXSIZESTRING];
	if (convertID(str, result, MAXSIZESTRING) == -3)
		printf("test11 is Ok\t");
	else
		printf("test11 is fail\t");
	printf("%s\t", str);
	printf("\t\t\t\tnon-valid symbol inside string\n");
}
void test12() {
	char str[] = "";
	char result[MAXSIZESTRING];
	if (convertID(str, result, MAXSIZESTRING) == -1)
		printf("test12 is Ok\t");
	else
		printf("test12 is fail\t");
	printf("%s\t", str);
	printf("\t\t\t\tinvalid src string\n");
}
void test13() {
	char str[] = "A1BAC1";
	char result[MAXSIZESTRING];
	if (convertID(str, result,MAXSIZESTRING) == -1)
		printf("test13 is Ok\t");
	else
		printf("test13 is fail\t");
	printf("%s\t\t\t\t", str);
	printf("\tstring without delimeter\n");
}

void test14() {
	char str[] = "Y9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
	char corAns[] = "Z1-A1-A1-A1-A1-A1-A1-A1-A1-A1";
	char* result = malloc(sizeof(char) * 6);
	if (result) {
		if (convertID(str, result, 6) == -2)
			printf("test14 is Ok\t");
		else
			printf("test14 is fail\t");
		printf("%s\t\tdst string less than src\n", str);
		free(result);
		result = NULL;
	}
	else printf("the test wasn't performed because the memory wasn't allocated");

}

void test15() {
	char str[] = "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
	char corAns[] = "Z1-A2-A1-A1-A1-A1-A1-A1-A1-A1-A1";
	char result[MAXSIZESTRING];
	if (convertID(str, result, MAXSIZESTRING) == -4)
		printf("test15 is Ok\t");
	else
		printf("test15 is fail\t");
	printf("%s\t\texceeded the maximum allowed string size\n", str);
}

void test16() {
	char str[] = "Y9-A1-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
	char* result = malloc(sizeof(char) * MAXSIZESTRING);
	if (result) {
		if (convertID(str, result, MAXSIZESTRING) == -1)
			printf("test16 is Ok\t");
		else
			printf("test16 is fail\t");
		printf("%s\tinvalid src string\n", str);
	}
	else printf("the test was not performed because the memory was not allocated");
	free(result);
	result = NULL;
}