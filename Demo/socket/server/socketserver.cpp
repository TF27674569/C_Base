/*
 * socketserver.cpp
 *
 *  Created on: 2018��8��31��
 *  Author: TIAN FENG
 */

#include "socketserver.h"

SOCKET socket_server;
SOCKET socket_client;

void* read_runable(void* obj);
void* send_runable(void* obj);


// ��ʼ��WSA��̬��
void InitWSA() {

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
void CreateSocket() {
	/**
	 * ����1����ַ����
	 * ����2������������ʽ
	 * ����3��Ĭ��0
	 */
	socket_server = socket(AF_INET, SOCK_STREAM, 0);
}

// ��socket�������˿�
void BindSocket() {
	SOCKADDR_IN Addr_Server;
	Addr_Server.sin_family = AF_INET;
	Addr_Server.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //������ַ
	Addr_Server.sin_port = htons(PORT);

	/**
	 * ����2����ַ
	 * ����3����ַ����ռ�ô�С
	 */
	if (bind(socket_server, (SOCKADDR*) &Addr_Server,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		printf("��ʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
		return;
	}
}

// ����socket״̬
void ListenSocket() {
	/**
	 * ����2���������ͻ��˽���
	 */
	if (listen(socket_server, BACK_LOG) < 0) {
		printf("����ʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
		return;
	}
}

// ���ӿͻ���socket
void AcceptClientSocket() {
	printf("�ȴ��ͻ��˽���\n");
	SOCKADDR_IN Addr_Client;
	int len = sizeof(SOCKADDR);
	socket_client = accept(socket_server, (SOCKADDR*) &Addr_Client, &len);
	if (socket_client == SOCKET_ERROR) {
		printf("���ӿͻ���ʧ��\n");
		printf("�����˳�\n");
		WSACleanup();
		return;
	}
	printf("�ͻ������ӳɹ�\n");
}

// ����
void SendOrRecv() {
	pthread_t read_th,send_th;
	if(pthread_create(&read_th,NULL,read_runable,NULL)!=0){
		printf("�̴߳���ʧ��\n");
		return;
	}
//	if(pthread_create(&send_th,NULL,send_runable,NULL)!=0){
//		printf("�̴߳���ʧ��\n");
//	}

	// �����߳�  ֱ�������̴߳���
	send_runable(NULL);
}

void close_end(){
	closesocket(socket_server);
	closesocket(socket_client);
	WSACleanup();
}

/**
 * ��ȡ����
 */
void* read_runable(void* obj) {
	char buf[BUFF_SIZE]={0};
	while (1) {
		if (recv(socket_client, buf, BUFF_SIZE, 0) < 0) {
			printf("��ȡʧ��\n");
			printf("�����˳�\n");
			break;
		}
		printf("����-> %s\n",buf);
		memset(buf,0,BUFF_SIZE);
	}
	close_end();
	return 0;
}

/**
 * ���Ͳ���
 */
void* send_runable(void* obj) {
	char buf[BUFF_SIZE];
	while (1) {
		memset(buf,0,BUFF_SIZE);
		scanf("%s",buf);
		printf("speek %s\n",buf);
		if (send(socket_client,buf,BUFF_SIZE,0)<0){
			printf("����ʧ��\n");
		}
	}
	close_end();
	return 0;
}
