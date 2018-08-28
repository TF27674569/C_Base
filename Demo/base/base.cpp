/*
 * base.cpp
 *
 *  Created on: 2018Äê8ÔÂ27ÈÕ
 *  Author: TIAN FENG
 */

#include "base.h"

// eg:1

void example1(){
	int num = 345;
	printf("%d\n",num);
}


void example2(){
	char* str = "Fine day";
	printf("%s\n",str);
}

void example(){
	static int num = 3;
	num*=3;
	printf("%d\n",num);
}

void example3(){
	example();
	example();
	example();
}
