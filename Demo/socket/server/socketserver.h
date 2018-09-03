/*
 * socketserver.h
 *
 *  Created on: 2018��8��31��
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

// ��ʼ��WSA��̬��
void InitWSA();

// ����socket���
void CreateSocket();

// ��socket�������˿�
void BindSocket();

// ����socket״̬
void ListenSocket();

// ���ӿͻ���socket
void AcceptClientSocket();

// ����
void SendOrRecv();


#endif /* DEMO_SOCKET_SERVER_SOCKETSERVER_H_ */
