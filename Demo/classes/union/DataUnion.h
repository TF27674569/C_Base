/*
 * DataUnion.h
 *
 *  Created on: 2018��8��28��
 *  Author: TIAN FENG
 */

#ifndef DEMO_CLASSES_UNION_DATAUNION_H_
#define DEMO_CLASSES_UNION_DATAUNION_H_

/**
 * ĳ��������һ��ʡ�ڴ�Ľṹ
 * ��������������Ϊ�ڴ����DataUnionΪint�Ĵ�С
 * ��ĳһ��ֵ�ı�ʱ����Ҳ�͸ı���
 *  union DataUnion dataUnion;
	dataUnion.iInt = 10;
	printf("%d\n",dataUnion.iInt);// 10
	dataUnion.cChar = 'A';
	printf("%c\n",dataUnion.cChar);// 65
	printf("%d\n",dataUnion.iInt); //65
 * ��һ��ֵ�ı�ʱ��Ӱ�쵽������ֵ
 * ����оƬ�����ȵͶ˿���������Э��ջ��ʱ���õķǳ��Ķ�
 */
union DataUnion {
	int iInt;
	char cChar;
};

#endif /* DEMO_CLASSES_UNION_DATAUNION_H_ */
