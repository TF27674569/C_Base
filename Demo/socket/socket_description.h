#include <winsock.h>

/**
 * socket ���ú�������
 */

void description() {

	WORD wVersionRequest;

	/*��汾����Ϣ�ṹ*/
	WSADATA wsaData;

	/*
	 * ��ʾ�汾��
	 * MAKEWORD������ñ�ʾ�����������޷����ֽڣ�����һ��16λ���޷������� ������ʾ�汾��
	 */
	wVersionRequest = MAKEWORD(2, 2);

	/*�����׽���������ʼ��Ws2_32��̬���*/
	WSAStartup(wVersionRequest, &wsaData);

	SOCKET socket_server;
	/**
	 * socket(int af,int type,int protocol);
	 * af:��ַ���� ͨ��AF_INET
	 * type:�׽�������ͨ��ΪSOCK_STREAM
	 * 		SOCK_STREAM����ʾ�������ӵ���ʽ�׽���
	 * 		SOCK_DGRAM:���������ӵ����ݰ��׽���
	 * 		SOCK_RAW:����ԭʼ�׽���
	 * protocol����ʾ�׽��ֽӿ����õ�Э�飬�û���ָ����������Ϊ0
	 */

	// AF_INET:��ַ��
	// SOCK_STREAM����ʽ�׽���TCP���ض��ĵ�ַ�������Э��
	socket_server = socket(AF_INET, SOCK_STREAM, 0);

	// ���׽��ְ���ָ���˿ں͵�ַ��
	// int bind(SOCKET s,const struct sockaddr* name,int namelen)
	// s:�׽��ֱ�ʾ
	// name����װ��ַ�Ͷ˿ڵĽṹ��
	// namelen��ȷ��name�������ĳ���
	// ����ֵ��ִ�гɹ�����0��ʧ�ܷ���SOCKET_ERROR

	// ��������ַ��Ϣ�ṹ
	SOCKADDR_IN Server_add;
	// ��ַ����
	Server_add.sin_family = AF_INET;
	// ������ַ
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(8888);

	// ����socket
	if (bind(socket_server, (SOCKADDR*) &Server_add,
			sizeof(SOCKADDR))==SOCKET_ERROR) {
		// printf("socket open error !  \n");
		return;
	}

	// listen(SOCKET s,int backlog) �������׽������óɼ���ģʽ ������ʽ�׽��ֱ��봦�ڼ���ģʽ���ܽ��տͻ��˵��׽�������
	// s:�׽��ֱ�ʾ
	// backlog���ȴ����ӵ�������ӳ��ȣ����backlog����Ϊ2����ʱ��3���ͻ���ͬʱ��������ǰ�����ͻ��˻���õȴ������У��������ͻ��˺��յ�������Ϣ
	// ��ʱ Ϊ������׼�� ���ȴ���ĿΪ5
	listen(socket_server, 5);

	// accept(SOCKET s,struct sockaddr* addr,int* addrlen);
	// �ú����Ĺ����ǽ��տͻ��˵����ӣ�����ʽ�׽����У�ֻ���׽��ִ��ڼ���ģʽ�����ܽ��տͻ�������
	// s���׽��ֱ�ʾ
	// addr ������һ��ͻ��˵� �˿ں� IP��ַ����Ϣ
	// addrlen ��addr�ĳ���
	// ����ֵ��һ���µ��׽���
	SOCKADDR_IN Client_add;
	Client_add.sin_family = AF_INET;
	// ������ַ
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Server_add.sin_port = htons(8888);
	// ���յĿͻ��˵�����
	SOCKET socket_receive;
	int length = sizeof(SOCKADDR);
	socket_receive = accept(socket_server, (SOCKADDR*) &Client_add, &length);

	//closesocket(SOCKET s) �ر��׽�����
	// ���s������SO_DONTLINGER,����øú�����������
	// ���������ʱ������δ��ɣ����������䣬Ȼ��ر��׽���

	// int connect(SOCKET s,const struct sockaddr* addr,int addrlen);
	// ����һ����������
	// s���׽���
	// addr �� ��Ҫ���ӵ������Ͷ˿�
	// addrlen��addr����
	// ����ֵ��ִ�гɹ�����0������SOCKET_ERROR �û�����ͨ��WSAGETLASTERROR�õ���������

	// htons(u_short h) ��һ��16λ�޷��Ŷ������������������з�ʽתΪ�������з�ʽ������16λ�������з�ʽ
	// htonl(u_long) ��һ���޷��ų������������������з�ʽתΪ�������з�ʽ������32λ�������з�ʽ
	// inet_addr(const char* ip) ���ַ�����ʾ�ĵ�ַת����32λ���޷��ų�����

	// recv(SOCKET s,char* buf,int len,int flags) ���׽����н�������
	// s����ʾ�׽���
	// buf����ʾ�������ݵĻ�����
	// len����ʾbuf�ĳ���
	// flags����ʾ���÷�ʽ�����ΪMG_PEEK,���ʾ�鿴���������ݣ�������ǰ�˵����ݻᱻ����һ�ݵ����ػ������У�����������ݲ��������������
	// ���Ϊ��MSG_OOB�����ʾ��������Out_of_Band���ݣ�Ҳ�����������

	// send(SOCKET s,const char* buf,int len,int flags);

	// recvfrom(SOCKET s,char* buf,int len,int flags,struct sockaddr* from,int* fromlen)
	// ����һ�����ݱ���Ϣ��������Դ��ַ
	// s���׽���
	// buf�� ָ�򻺳�����ָ�룬����������
	// len :�������ĳ���
	// flags �� ͨ���������ֵ����Ӱ�캯���ĵ�����Ϊ
	// from��ָ���ַ�ṹ��ָ�룬�������շ������ݷ��ĵ�ַ��Ϣ
	// fromlen���������ĳ���

	// sendto(SOCKET s,const char* buf,int len,int flag,const struct sockaddr* to ,int tolen)
	// to��ָ��Ŀ���׽��ֵĵ�ַ
	// tolen��to�ĳ���

	// WSACleanup() �ͷ�Ws2_32��̬��
}
