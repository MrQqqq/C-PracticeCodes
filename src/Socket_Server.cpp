/*
 * @Description: 
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-05-13 15:49:25
 * @LastEditors: szq
 * @LastEditTime: 2020-05-13 16:02:47
 * @FilePath: \cpp\Socket_Server.cpp
 */

#include <iostream>
#include<string>
#include<Windows.h>
#include<WinSock2.h>
#include<fstream>

#pragma comment(lib,"Ws2_32.lib")

using namespace std;
#define PORT 8080//端口号
#define IP_ADDRESS "192.168.2.7"//ip地址

CRITICAL_SECTION cs;

/**
 * @destription: 接收每个客户端连接的处理函数
 * @param {type} 
 * @return: 
 */
DWORD WINAPI ClientThread(LPVOID lpParameter);

/**
 * @destription: 连接和服务器有连接的客户端
 * @param {type} 
 * @return: 
 */
DWORD WINAPI ConnectClientsThread(LPVOID lpParameter);

int main(int arg,char *argv){
    InitializeCriticalSection(&cs);
    //WSADATA结构体主要包含了系统所支持的winsock版本信息
    WSADATA Ws;
    //创建服务器套接字和客户端套接字
    SOCKET ServerSocket,ClientSocket;
    //tcp/ip套接字指定套接字地址
    struct sockaddr_in LocalAddr,ClientAddr;
    //保存执行结果
    int Ret = 0;

}