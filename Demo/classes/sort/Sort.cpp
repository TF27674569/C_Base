/*
 * Sort.cpp
 *
 *  Created on: 2018��8��28��
 *  Author: TIAN FENG
 */

#include "Sort.h"

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

