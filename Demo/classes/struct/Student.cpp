/*
 * Student.cpp
 *
 *  Created on: 2018年8月24日
 *  Author: TIAN FENG
 */

#include "Student.h"

// 链表个数
int iCount;

// 链表头
Student* pHead = NULL;

void add(struct Student* student) {
	if (student != NULL) {
		student->pNext = pHead;
		pHead = student;
		iCount++;
	}
}

int remove(struct Student* student) {
	struct Student* temp = pHead;
	// 前一位
	struct Student* pPre;

	while (temp != student) {
		pPre = temp;
		temp = temp->pNext;
	}

	if (temp == NULL) {
		return -1;
	}

	pPre->pNext = temp->pNext;

	free(temp);
	temp = NULL;
	iCount--;

	return 0;
}

int getCount() {
	return iCount;
}

int getStudentHead(struct Student** head) {
	(*head) = pHead;
	return pHead == NULL ? -1 : 0;
}

void Free(struct Student* student) {

	struct Student* temp;

	while (student != NULL) {
		temp = student->pNext;
		free(student);
		student = temp;
	}
}

void print(struct Student* student) {
	if (student != NULL) {
		printf("name:%s  age:%d \n", student->cName, student->iAge);
	}
}



// 测试
void test() {
	char name[20] = "张三";
	struct Student* student1 = (struct Student*) malloc(sizeof(struct Student));

	if (student1 == NULL) {
		printf("申请失败\n");
	}

	strcpy(student1->cName, name);
	student1->iAge = 1;
	add(student1);

	struct Student* student2 = (struct Student*) malloc(sizeof(struct Student));
	strcpy(student2->cName, name);
	student2->iAge = 2;
	add(student2);

	struct Student* student3 = (struct Student*) malloc(sizeof(struct Student));
	strcpy(student3->cName, name);
	student3->iAge = 3;
	add(student3);

	struct Student* student4 = (struct Student*) malloc(sizeof(struct Student));
	strcpy(student4->cName, name);
	student4->iAge = 4;
	add(student4);

	struct Student* student5 = (struct Student*) malloc(sizeof(struct Student));
	strcpy(student5->cName, name);
	student5->iAge = 5;
	add(student5);

	struct Student* student;
	getStudentHead(&student);

	if (student == NULL) {
		printf("赋值失败");
	}

	remove(student3);
	printf("size is %d\n",iCount);

	do {
		print(student);
	} while ((student = student->pNext) != NULL);

	Free(student);
}


