/*
 *  Application.cpp
 *
 *  Created on: 2018Äê8ÔÂ23ÈÕ
 *  Author
 */

#include <iostream>
#include <stdio.h>
#include "classes/sort/Sort.h"

using namespace std;

int main(int argc, char **argv) {

	int num[] = { 9, 6, 3, 5, 7, 8, 1 };
	int length = sizeof(num) / sizeof(int);
	bubbleSort(num, length);

	for (int i = 0; i < length; i++) {
		printf("%d",num[i]);
	}

	return 0;
}
