#include <stdio.h>
#include <string.h>

#include "base_cstring.h"

// �ַ�����
void str_copy() {
	char string[10];
	char* str = "asdfghjkl;";
	strcpy(string, str);

	printf(string);
}

// ���ֿ���
void str_copy2() {
	char string[10];
	char* str = "asdfghjkl;";

	// ��str��ǰ3���ַ�������string����
	strncpy(string, str, 3);
	printf(string);
}

// ƴ���ַ�
void str_cat() {
	char string[25];
	char* str1 = "hello";
	char* str2 = "world";
	strcpy(string, str1);
	strcat(string, str2);
	printf("%s\n", string);
}

void str_ncat() {
	char string[25];
	char* str1 = "hello";
	char* str2 = "world";
	strcpy(string, str1);
	strncat(string, str2, 2);
	printf("%s\n", string);
}

void str_chr() {
	char *s = "0123456789012345678901234567890";
	char *p;
	p = strchr(s, '5');
	printf("%ld\n", s);
	printf("%ld\n", p);// ���ص�һ�γ���'5'�ĵ�ַ
	p = strrchr(s, '5');
	printf("%ld\n", p);// �������һ�γ���'5'�ĵ�ַ

}

