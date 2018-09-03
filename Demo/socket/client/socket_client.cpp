/*
 * socketclient.cpp
 *
 *  Created on: 2018��8��31��
 *  Author: TIAN FENG
 */

#include "socket_client.h"

SOCKET socket_send;

void* read_runable_(void* obj);
void* send_runable_(void* obj);

// ��ʼ��WSA��̬��
void InitWSA_() {

	WORD wVersionRequier = MAKEWORD(2, 2);
	WSAData wsaData;

	if (WSAStartup(wVersionRequier, &wsaData)) {
		printf("����WSAʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
		return;
	}

	if (HIBYTE(wsaData.wVersion) != 2 || LOBYTE(wsaData.wVersion) != 2) {
		printf("����WSA�汾ʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
	}
}

// ����socket���
void CreateSocket_() {
	socket_send = socket(AF_INET, SOCK_STREAM, 0);
}

// ����socket
void ConnectSocket() {
	SOCKADDR_IN Addr_Server;
	Addr_Server.sin_family = AF_INET;
	Addr_Server.sin_addr.S_un.S_addr = inet_addr(ADRESS);
	Addr_Server.sin_port = htons(PORT);

	if (connect(socket_send, (SOCKADDR*) &Addr_Server,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		printf("connectʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
		closesocket(socket_send);
	}
}

// ����
void SendOrRead() {
	pthread_t read_th, send_th;
	if (pthread_create(&read_th, NULL, read_runable_, NULL) != 0) {
		printf("�̴߳���ʧ��\n");
		return;
	}
	//	if(pthread_create(&send_th,NULL,send_runable,NULL)!=0){
	//		printf("�̴߳���ʧ��\n");
	//	}

	// �����߳�  ֱ�������̴߳���
	send_runable_(NULL);
}

void close_end_() {
	closesocket(socket_send);
	WSACleanup();
}

/**
 * ��ȡ����
 */
void* read_runable_(void* obj) {
	char buf[BUFF_SIZE] = { 0 };
	while (1) {
		if (recv(socket_send, buf, BUFF_SIZE, 0) < 0) {
			printf("��ȡʧ��\n");
			printf("�����˳�\n");
			break;
		}
		printf("����-> %s\n", buf);
		memset(buf, 0, BUFF_SIZE);
	}
	close_end_();
	return 0;
}

/**
 * ���Ͳ���
 */
void* send_runable_(void* obj) {
	char buf[BUFF_SIZE];
	while (1) {
		memset(buf, 0, BUFF_SIZE);
		scanf("%s", buf);
		printf("speek %s\n", buf);
		if (send(socket_send, buf, BUFF_SIZE, 0) < 0) {
			printf("����ʧ��\n");
		}
	}
	close_end_();
	return 0;
}
