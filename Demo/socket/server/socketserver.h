/*
 * socketserver.h
 *
 *  Created on: 2018年8月31日
 *  Author: TIAN FENG
 */

#ifndef DEMO_SOCKET_SERVER_SOCKETSERVER_H_
#define DEMO_SOCKET_SERVER_SOCKETSERVER_H_

#define BUFF_SIZE 128
#define PORT 8888
#define BACK_LOG 8


#include <winsock.h>
#include <stdio.h>
#include <pthread.h>

// 初始化WSA动态库
void InitWSA();

// 创建socket句柄
void CreateSocket();

// 绑定socket到本机端口
void BindSocket();

// 监听socket状态
void ListenSocket();

// 链接客户端socket
void AcceptClientSocket();

// 交互
void SendOrRecv();


#endif /* DEMO_SOCKET_SERVER_SOCKETSERVER_H_ */
