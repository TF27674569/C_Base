/*
 *  Application.cpp
 *
 *  Created on: 2018��8��23��
 *  Author
 */

#include <iostream>
#include <stdio.h>
#include "socket/client/socket_client.h"

using namespace std;

int main(int argc, char **argv) {
	InitWSA_();
	CreateSocket_();
	ConnectSocket();
	SendOrRead();
	system("pause");
	return 0;
}
