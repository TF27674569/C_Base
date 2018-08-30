/*
 * csocket.cpp
 *
 *  Created on: 2018年8月29日
 *  Author: TIAN FENG
 */

#include "csocket.h"

#define PORT 8888
#define BACKLOG 5
#define BUFFER_SIZE 100

#define HIGHT_VER 2
#define LOW_VER 2

int create_socket_server(){
	// 1. 初始化套接字库
	// 2.创建套接字
	// 3.绑定套接字到本地地址和端口
	// 4.设置套接字为监听状态
	// 5.接收请求链接的请求
	// 6.通信
	// 7.通信完毕释放套接字

	// 版本号
	WORD mVersionRequest;
	// 库版本信息结构
	WSADATA wsaData;

	// 初始化版本号
	mVersionRequest = MAKEWORD(HIGHT_VER,LOW_VER);

	// 加载WS_32动态库
	if(WSAStartup(mVersionRequest, &wsaData)){
		printf("加载WS_32动态库失败\n");
		return ERROR;
	}

	// 判断版本号是否正确
	if(HIBYTE(wsaData.wVersion)!=2||LOBYTE(wsaData.wVersion)!=2){
		WSACleanup();
		printf("WS_32 版本不对   height:%d  low:%d \n",HIBYTE(wsaData.wVersion),LOBYTE(wsaData.wVersion));
		return ERROR;
	}

	// 服务器地址信息结构
	SOCKADDR_IN Server_add;
	Server_add.sin_family = AF_INET;
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(PORT);


	// 需要开始创建套接字
	SOCKET server_socket;
	server_socket = socket(AF_INET,SOCK_STREAM,0);

	// 绑定套接字在本地某一地址端口上
	if(bind(server_socket,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR){
		printf("绑定失败\n");
		return ERROR;
	}

	// 设置套接字为监听状态
	if(listen(server_socket,BACKLOG)<0){
		printf("监听失败\n");
		return ERROR;
	}

	// 接受连接
	int length = sizeof(SOCKADDR);
	SOCKADDR_IN Client_add;
	// 链接的socket
	SOCKET socket_client;
	socket_client = accept(server_socket,(SOCKADDR*)&Client_add,&length);

	if(socket_client==SOCKET_ERROR){
		printf("接受连接失败\n");
		return ERROR;
	}


	// 读取的buff
	char receive_buf[BUFFER_SIZE]={0};
	// 读取到的长度
	int receive_len;
	// 信息发送
	while(1){

		// 接受数据
		receive_len = recv(socket_client,receive_buf,BUFFER_SIZE,0);

		if(receive_len<0){
			printf("接收失败：%d\n",receive_len);
			printf("程序退出\n");
			break;
		}else{
			printf("接收长度为%d的数据:%s\n",receive_len,receive_buf);
			memset(receive_buf,0,BUFFER_SIZE);
		}
	}

	// 释放套接字 关闭动态库
	closesocket(server_socket);
	closesocket(socket_client);

	WSACleanup();

	return 0;


}
