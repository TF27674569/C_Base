/*
 * socketserver.cpp
 *
 *  Created on: 2018年8月31日
 *  Author: TIAN FENG
 */

#include "socketserver.h"

SOCKET socket_server;
SOCKET socket_client;

void* read_runable(void* obj);
void* send_runable(void* obj);


// 初始化WSA动态库
void InitWSA() {

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
void CreateSocket() {
	/**
	 * 参数1：地址家族
	 * 参数2；类型流的形式
	 * 参数3；默认0
	 */
	socket_server = socket(AF_INET, SOCK_STREAM, 0);
}

// 绑定socket到本机端口
void BindSocket() {
	SOCKADDR_IN Addr_Server;
	Addr_Server.sin_family = AF_INET;
	Addr_Server.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //本机地址
	Addr_Server.sin_port = htons(PORT);

	/**
	 * 参数2：地址
	 * 参数3：地址对象占用大小
	 */
	if (bind(socket_server, (SOCKADDR*) &Addr_Server,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		printf("绑定失败\n");
		printf("程序退出\n");
		WSACleanup();
		return;
	}
}

// 监听socket状态
void ListenSocket() {
	/**
	 * 参数2：允许几个客户端接入
	 */
	if (listen(socket_server, BACK_LOG) < 0) {
		printf("监听失败\n");
		printf("程序退出\n");
		WSACleanup();
		return;
	}
}

// 链接客户端socket
void AcceptClientSocket() {
	printf("等待客户端接入\n");
	SOCKADDR_IN Addr_Client;
	int len = sizeof(SOCKADDR);
	socket_client = accept(socket_server, (SOCKADDR*) &Addr_Client, &len);
	if (socket_client == SOCKET_ERROR) {
		printf("链接客户端失败\n");
		printf("程序退出\n");
		WSACleanup();
		return;
	}
	printf("客户端连接成功\n");
}

// 交互
void SendOrRecv() {
	pthread_t read_th,send_th;
	if(pthread_create(&read_th,NULL,read_runable,NULL)!=0){
		printf("线程创建失败\n");
		return;
	}
//	if(pthread_create(&send_th,NULL,send_runable,NULL)!=0){
//		printf("线程创建失败\n");
//	}

	// 不开线程  直接在主线程处理
	send_runable(NULL);
}

void close_end(){
	closesocket(socket_server);
	closesocket(socket_client);
	WSACleanup();
}

/**
 * 读取操作
 */
void* read_runable(void* obj) {
	char buf[BUFF_SIZE]={0};
	while (1) {
		if (recv(socket_client, buf, BUFF_SIZE, 0) < 0) {
			printf("读取失败\n");
			printf("程序退出\n");
			break;
		}
		printf("接收-> %s\n",buf);
		memset(buf,0,BUFF_SIZE);
	}
	close_end();
	return 0;
}

/**
 * 发送操作
 */
void* send_runable(void* obj) {
	char buf[BUFF_SIZE];
	while (1) {
		memset(buf,0,BUFF_SIZE);
		scanf("%s",buf);
		printf("speek %s\n",buf);
		if (send(socket_client,buf,BUFF_SIZE,0)<0){
			printf("发送失败\n");
		}
	}
	close_end();
	return 0;
}
