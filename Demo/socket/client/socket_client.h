/*
 * socketclient.h
 *
 *  Created on: 2018��8��31��
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


// ��ʼ��WSA��̬��
void InitWSA_();

// ����socket���
void CreateSocket_();

// ����socket
void ConnectSocket();


// ����
void SendOrRead();


#endif /* DEMO_SOCKET_CLIENT_SOCKET_CLIENT_H_ */
