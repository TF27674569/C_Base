#include <winsock.h>

/**
 * socket 常用函数介绍
 */

void description() {

	WORD wVersionRequest;

	/*库版本的信息结构*/
	WSADATA wsaData;

	/*
	 * 表示版本号
	 * MAKEWORD宏的作用表示，根据两个无符号字节，创建一个16位的无符号整形 用来表示版本号
	 */
	wVersionRequest = MAKEWORD(2, 2);

	/*加载套接字用来初始化Ws2_32动态库的*/
	WSAStartup(wVersionRequest, &wsaData);

	SOCKET socket_server;
	/**
	 * socket(int af,int type,int protocol);
	 * af:地址家族 通常AF_INET
	 * type:套接字类型通常为SOCK_STREAM
	 * 		SOCK_STREAM：表示创建链接的流式套接字
	 * 		SOCK_DGRAM:面向无链接的数据包套接字
	 * 		SOCK_RAW:创建原始套接字
	 * protocol：表示套接字接口所用的协议，用户不指定可以设置为0
	 */

	// AF_INET:地址簇
	// SOCK_STREAM：流式套接字TCP，特定的地址家族相关协议
	socket_server = socket(AF_INET, SOCK_STREAM, 0);

	// 将套接字绑定在指定端口和地址上
	// int bind(SOCKET s,const struct sockaddr* name,int namelen)
	// s:套接字表示
	// name：封装地址和端口的结构体
	// namelen：确定name缓冲区的长度
	// 返回值：执行成功返回0，失败返回SOCKET_ERROR

	// 服务器地址信息结构
	SOCKADDR_IN Server_add;
	// 地址家族
	Server_add.sin_family = AF_INET;
	// 主机地址
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(8888);

	// 链接socket
	if (bind(socket_server, (SOCKADDR*) &Server_add,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		// printf("socket open error !  \n");
		return;
	}

	// listen(SOCKET s,int backlog) 函数将套接字设置成监听模式 对于流式套接字必须处于监听模式才能接收客户端的套接字链接
	// s:套接字表示
	// backlog：等待链接的最大连接长度，如果backlog设置为2，此时有3个客户端同时发起请求，前两个客户端会放置等待队列中，第三个客户端后收到错误信息
	// 此时 为连接做准备 最大等待数目为5
	listen(socket_server, 5);

	// accept(SOCKET s,struct sockaddr* addr,int* addrlen);
	// 该函数的功能是接收客户端的链接，在流式套接字中，只有套接字处于监听模式，才能接收客户端连接
	// s：套接字标示
	// addr ：包含一组客户端的 端口号 IP地址等信息
	// addrlen ：addr的长度
	// 返回值：一个新的套接字
	SOCKADDR_IN Client_add;
	Client_add.sin_family = AF_INET;
	// 主机地址
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(8888);
	// 接收的客户端的链接
	SOCKET socket_receive;
	int length = sizeof(SOCKADDR);
	socket_receive = accept(socket_server, (SOCKADDR*) &Client_add, &length);

	//closesocket(SOCKET s) 关闭套接字流
	// 如果s设置了SO_DONTLINGER,则调用该函数立即返回
	// 但是如果此时传输尚未完成，则会继续传输，然后关闭套接字

	// int connect(SOCKET s,const struct sockaddr* addr,int addrlen);
	// 发送一个链接请求
	// s：套接字
	// addr ： 需要链接的主机和端口
	// addrlen：addr长度
	// 返回值：执行成功返回0，否则SOCKET_ERROR 用户可以通过WSAGETLASTERROR得到错误描述

	// htons(u_short h) 将一个16位无符号短整形数据由主机排列方式转为网络排列方式，返回16位网络排列方式
	// htonl(u_long) 将一个无符号长整形数据由主机排列方式转为网络排列方式，返回32位网络排列方式
	// inet_addr(const char* ip) 将字符串表示的地址转换成32位的无符号长整形

	// recv(SOCKET s,char* buf,int len,int flags) 从套接字中接收数据
	// s：表示套接字
	// buf：表示接收数据的缓冲区
	// len：表示buf的长度
	// flags：表示调用方式。如果为MG_PEEK,则表示查看传来的数据，在序列前端的数据会被复制一份到返回缓冲区中，但是这个数据不会从序列中移走
	// 如果为：MSG_OOB，则表示出来处理Out_of_Band数据，也就是外带数据

	// send(SOCKET s,const char* buf,int len,int flags);

	// recvfrom(SOCKET s,char* buf,int len,int flags,struct sockaddr* from,int* fromlen)
	// 接收一个数据报信息并保存其源地址
	// s：套接字
	// buf： 指向缓冲区的指针，用来存数据
	// len :缓冲区的长度
	// flags ： 通过设置这个值可以影响函数的调用行为
	// from：指向地址结构的指针，用来接收发送数据方的地址信息
	// fromlen：缓冲区的长度

	// sendto(SOCKET s,const char* buf,int len,int flag,const struct sockaddr* to ,int tolen)
	// to：指定目标套接字的地址
	// tolen：to的长度

	// WSACleanup() 释放Ws2_32动态库
}
