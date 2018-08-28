/*
 * DataUnion.h
 *
 *  Created on: 2018年8月28日
 *  Author: TIAN FENG
 */

#ifndef DEMO_CLASSES_UNION_DATAUNION_H_
#define DEMO_CLASSES_UNION_DATAUNION_H_

/**
 * 某种意义下一种省内存的结构
 * 按声明最大的类型为内存打下DataUnion为int的大小
 * 当某一个值改变时整个也就改变了
 *  union DataUnion dataUnion;
	dataUnion.iInt = 10;
	printf("%d\n",dataUnion.iInt);// 10
	dataUnion.cChar = 'A';
	printf("%c\n",dataUnion.cChar);// 65
	printf("%d\n",dataUnion.iInt); //65
 * 当一个值改变时会影响到其他的值
 * 网络芯片开发等低端开发和网络协议栈的时候用的非常的多
 */
union DataUnion {
	int iInt;
	char cChar;
};

#endif /* DEMO_CLASSES_UNION_DATAUNION_H_ */
