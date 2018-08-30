/*
 * csocket.cpp
 *
 *  Created on: 2018��8��29��
 *  Author: TIAN FENG
 */

#include "csocket.h"

#define PORT 8888
#define BACKLOG 5
#define BUFFER_SIZE 100

#define HIGHT_VER 2
#define LOW_VER 2

int create_socket_server(){
	// 1. ��ʼ���׽��ֿ�
	// 2.�����׽���
	// 3.���׽��ֵ����ص�ַ�Ͷ˿�
	// 4.�����׽���Ϊ����״̬
	// 5.�����������ӵ�����
	// 6.ͨ��
	// 7.ͨ������ͷ��׽���

	// �汾��
	WORD mVersionRequest;
	// ��汾��Ϣ�ṹ
	WSADATA wsaData;

	// ��ʼ���汾��
	mVersionRequest = MAKEWORD(HIGHT_VER,LOW_VER);

	// ����WS_32��̬��
	if(WSAStartup(mVersionRequest, &wsaData)){
		printf("����WS_32��̬��ʧ��\n");
		return ERROR;
	}

	// �жϰ汾���Ƿ���ȷ
	if(HIBYTE(wsaData.wVersion)!=2||LOBYTE(wsaData.wVersion)!=2){
		WSACleanup();
		printf("WS_32 �汾����   height:%d  low:%d \n",HIBYTE(wsaData.wVersion),LOBYTE(wsaData.wVersion));
		return ERROR;
	}

	// ��������ַ��Ϣ�ṹ
	SOCKADDR_IN Server_add;
	Server_add.sin_family = AF_INET;
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(PORT);


	// ��Ҫ��ʼ�����׽���
	SOCKET server_socket;
	server_socket = socket(AF_INET,SOCK_STREAM,0);

	// ���׽����ڱ���ĳһ��ַ�˿���
	if(bind(server_socket,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR){
		printf("��ʧ��\n");
		return ERROR;
	}

	// �����׽���Ϊ����״̬
	if(listen(server_socket,BACKLOG)<0){
		printf("����ʧ��\n");
		return ERROR;
	}

	// ��������
	int length = sizeof(SOCKADDR);
	SOCKADDR_IN Client_add;
	// ���ӵ�socket
	SOCKET socket_client;
	socket_client = accept(server_socket,(SOCKADDR*)&Client_add,&length);

	if(socket_client==SOCKET_ERROR){
		printf("��������ʧ��\n");
		return ERROR;
	}


	// ��ȡ��buff
	char receive_buf[BUFFER_SIZE]={0};
	// ��ȡ���ĳ���
	int receive_len;
	// ��Ϣ����
	while(1){

		// ��������
		receive_len = recv(socket_client,receive_buf,BUFFER_SIZE,0);

		if(receive_len<0){
			printf("����ʧ�ܣ�%d\n",receive_len);
			printf("�����˳�\n");
			break;
		}else{
			printf("���ճ���Ϊ%d������:%s\n",receive_len,receive_buf);
			memset(receive_buf,0,BUFFER_SIZE);
		}
	}

	// �ͷ��׽��� �رն�̬��
	closesocket(server_socket);
	closesocket(socket_client);

	WSACleanup();

	return 0;


}
