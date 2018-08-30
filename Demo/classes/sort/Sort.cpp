/*
 * Sort.cpp
 *
 *  Created on: 2018��8��28��
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
	// ��һ�δӵ�һ����ʼ�ҳ���С�ĺ͵�һ������
	// ��һ�δӵڶ�����ʼ�ҳ���С�ĺ͵ڶ�������

	// ��Сֵ��λ��
	int pos;

	for (int i = 0; i < length; i++) {
		// �õ��ڼ��ε���
		int temp = num[i];
		// ÿ��λ����Ҫ���¸���
		pos = i;

		// �����ҳ���С��ֵ����Сֵ���ڵ�λ��
		for (int j = i + 1; j < length; j++) {
			// �ҳ���С��ֵ
			if (temp > num[j]) {
				temp = num[pos = j];
			}
		}

		// ��ʱtemp����С��ֵ
		num[pos] = num[i];
		num[i] = temp;
	}
}

// ð������
// ������ʱ���Ƚ������������֣�����С�������ڽϴ�����ǰ��
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

// ��������
// ÿ�δӵ�һ�����Ƚϵ����һ�����������ͽ���
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


//��������
void insertSort(int num[],int length){
	// Դ 9, 6, 3, 5, 7, 8, 1
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

		// Ѱ�Ҳ����λ��
		while(pos>=0&&temp<num[pos]){
			num[pos+1] = num[pos];
			pos--;
		}

		print(num,length);
		printf("temp %d \n",temp);
		num[pos+1] = temp;
	}
}



