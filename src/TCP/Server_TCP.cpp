/*
 * @Description:SOCKET网络通信TCP服务端
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-26 00:04:39
 * @LastEditors: szq
 * @LastEditTime: 2020-06-26 00:39:34
 * @FilePath: \cpp\src\TCP\Server_TCP.cpp
 */
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization() {
	//初始化套接字库
	WORD w_req = MAKEWORD(2, 2);//版本号
	WSADATA wsadata;
	int err;
	err = WSAStartup(w_req, &wsadata);
	if (err != 0) {
		cout << "初始化套接字库失败！" << endl;
	}
	else {
		cout << "初始化套接字库成功！" << endl;
	}
	//检测版本号
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
		cout << "套接字库版本号不符！" << endl;
		WSACleanup();
	}
	else {
		cout << "套接字库版本正确！" << endl;
	}
	//填充服务端地址信息

}

int main() {
	//定义长度变量
	int send_len = 0;
	int recv_len = 0;
	int len = 0;

	//定义发送缓冲区和接收缓冲区
	char send_buf[1024];
	char recv_buf[1024];
	//定义服务器套接字,接受请求套接字
	SOCKET s_server;
	SOCKET s_accept;

	//服务器地址和客户端地址
	SOCKADDR_IN server_addr;
	SOCKADDR_IN accept_addr;
	initialization();

	//填充服务端信息
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(5010);

	//创建套接字
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "套接字绑定失败！" << endl;
	}
	else {
		cout << "套接字绑定成功！" << endl;
	}
	if (listen(s_server, SOMAXCONN) < 0) {
		cout << "设置监听状态失败！" << endl;
	}
	else {
		cout << "设置监听状态成功！" << endl;
	}
	cout << "服务器正在监听连接，请稍候..." << endl;

	len = sizeof(SOCKADDR);
	s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
	if (s_accept == SOCKET_ERROR) {
		cout << "连接失败！" << endl;
		return 0;
	}
	cout << "连接建立，准备接受数据" << endl;

	while (1) {
		recv_len = recv(s_accept, recv_buf, 1024, 0);
		if (recv_len < 0) {
			cout << "接受失败！" << endl;
			break;
		}
		else {
			cout << "客户端信息：" << recv_buf << endl;
		}
		cout << "输入回复信息：";
		cin >> send_buf;
		send_len = send(s_accept, send_buf, 1024, 0);
		if (send_len < 0) {
			cout << "发送失败！" << endl;
			break;
		}
	}

	//关闭套接字
	closesocket(s_server);
	closesocket(s_accept);
	return 0;
}
