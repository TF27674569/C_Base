/*
 *  Application.cpp
 *
 *  Created on: 2018��8��23��
 *  Author
 */

#include <iostream>
#include <stdio.h>
#include "socket/csocket.h"

using namespace std;

int main(int argc, char **argv) {

	int status = create_socket_server();

	cout<<status<<endl;

	return 0;
}
