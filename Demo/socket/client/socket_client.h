/*
 * socketclient.h
 *
 *  Created on: 2018年8月31日
 *  Author: TIAN FENG
 */

#ifndef DEMO_SOCKET_CLIENT_SOCKET_CLIENT_H_
#define DEMO_SOCKET_CLIENT_SOCKET_CLIENT_H_

#define ADRESS "10.10.25.53"
#define PORT 8888
#define BUFF_SIZE 128


#include <winsock.h>
#include <stdio.h>
#include <pthread.h>


// 初始化WSA动态库
void InitWSA_();

// 创建socket句柄
void CreateSocket_();

// 连接socket
void ConnectSocket();


// 交互
void SendOrRead();


#endif /* DEMO_SOCKET_CLIENT_SOCKET_CLIENT_H_ */
