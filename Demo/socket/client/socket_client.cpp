/*
 * socketclient.cpp
 *
 *  Created on: 2018年8月31日
 *  Author: TIAN FENG
 */

#include "socket_client.h"

SOCKET socket_send;

void* read_runable_(void* obj);
void* send_runable_(void* obj);

// 初始化WSA动态库
void InitWSA_() {

	WORD wVersionRequier = MAKEWORD(2, 2);
	WSAData wsaData;

	if (WSAStartup(wVersionRequier, &wsaData)) {
		printf("加载WSA失败\n");
		printf("程序退出\n");
		WSACleanup();
		return;
	}

	if (HIBYTE(wsaData.wVersion) != 2 || LOBYTE(wsaData.wVersion) != 2) {
		printf("加载WSA版本失败\n");
		printf("程序退出\n");
		WSACleanup();
	}
}

// 创建socket句柄
void CreateSocket_() {
	socket_send = socket(AF_INET, SOCK_STREAM, 0);
}

// 连接socket
void ConnectSocket() {
	SOCKADDR_IN Addr_Server;
	Addr_Server.sin_family = AF_INET;
	Addr_Server.sin_addr.S_un.S_addr = inet_addr(ADRESS);
	Addr_Server.sin_port = htons(PORT);

	if (connect(socket_send, (SOCKADDR*) &Addr_Server,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		printf("connect失败\n");
		printf("程序退出\n");
		WSACleanup();
		closesocket(socket_send);
	}
}

// 交互
void SendOrRead() {
	pthread_t read_th, send_th;
	if (pthread_create(&read_th, NULL, read_runable_, NULL) != 0) {
		printf("线程创建失败\n");
		return;
	}
	//	if(pthread_create(&send_th,NULL,send_runable,NULL)!=0){
	//		printf("线程创建失败\n");
	//	}

	// 不开线程  直接在主线程处理
	send_runable_(NULL);
}

void close_end_() {
	closesocket(socket_send);
	WSACleanup();
}

/**
 * 读取操作
 */
void* read_runable_(void* obj) {
	char buf[BUFF_SIZE] = { 0 };
	while (1) {
		if (recv(socket_send, buf, BUFF_SIZE, 0) < 0) {
			printf("读取失败\n");
			printf("程序退出\n");
			break;
		}
		printf("接收-> %s\n", buf);
		memset(buf, 0, BUFF_SIZE);
	}
	close_end_();
	return 0;
}

/**
 * 发送操作
 */
void* send_runable_(void* obj) {
	char buf[BUFF_SIZE];
	while (1) {
		memset(buf, 0, BUFF_SIZE);
		scanf("%s", buf);
		printf("speek %s\n", buf);
		if (send(socket_send, buf, BUFF_SIZE, 0) < 0) {
			printf("发送失败\n");
		}
	}
	close_end_();
	return 0;
}
