/*
 * Sort.cpp
 *
 *  Created on: 2018年8月28日
 *  Author: TIAN FENG
 */

#include "Sort.h"

void print(int num[],int length){
	for (int i = 0; i < length; i++) {
			printf("%d ",num[i]);
		}
	printf("\n");
}

void selectSort(int num[], int length) {
	// 第一次从第一个开始找出最小的和第一个交换
	// 第一次从第二个开始找出最小的和第二个交换

	// 最小值得位置
	int pos;

	for (int i = 0; i < length; i++) {
		// 拿到第几次的数
		int temp = num[i];
		// 每次位置需要重新复制
		pos = i;

		// 用来找出最小的值和最小值所在的位置
		for (int j = i + 1; j < length; j++) {
			// 找出最小的值
			if (temp > num[j]) {
				temp = num[pos = j];
			}
		}

		// 此时temp是最小的值
		num[pos] = num[i];
		num[i] = temp;
	}
}

// 冒泡排序
// 在排序时，比较相邻两个数字，将较小的数排在较大数的前面
void bubbleSort(int num[], int length) {
	for (int i = 1; i < length; i++) {
		for (int j = length - 1; j >= i; j--) {
			if (num[j] < num[j - 1]) {
				int temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
		}
	}
}

// 交换排序法
// 每次从第一个数比较到最后一个符合条件就交换
void swapSort(int num[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (num[j] < num[i]) {
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}


//插入排序
void insertSort(int num[],int length){
	// 源 9, 6, 3, 5, 7, 8, 1
	//  9
	//  6 9
	//  3 6 9
	//  3 5 6 9
	//  3 5 6 7 9
	//  3 5 6 7 8 9
	//  1 3 5 6 7 8 9
	int pos;
	for (int i = 1; i < length; i++) {
		int temp = num[i];
		pos = i-1;

		// 寻找插入的位置
		while(pos>=0&&temp<num[pos]){
			num[pos+1] = num[pos];
			pos--;
		}

		print(num,length);
		printf("temp %d \n",temp);
		num[pos+1] = temp;
	}
}



