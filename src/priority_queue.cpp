/*
 * @Description: ʹ��priotity_queueʵ�ִ�С������
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-04 22:16:41
 * @LastEditors: szq
 * @LastEditTime: 2020-07-04 22:32:38
 * @FilePath: \cpp\src\priority_queue.cpp
 */ 
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int main(){
    //��������ѵ����ַ�ʽ

    //1.������������Ĭ���Ǵ����
    priority_queue<int> pq1;
    //2.��׼��ʽ
    priority_queue<int,vector<int>,less<int>> pq2;//less�ǱȽ�ǰһ��Ԫ�غͺ�һ��Ԫ�صĽ����
                                                    //lessС�ڵ���˼��������������������

    //����������Ԫ��
    pq1.push(1);
    pq1.push(2);
    pq2.push(1);
    pq2.push(2);

    //���Դ���Ѷ���Ԫ�أ�����Ѷ�����Ԫ��Ϊ����������Ԫ��
    cout << "�����pq1����Ԫ��Ϊ��" << pq1.top() << endl;
    cout << "�����pq2����Ԫ��Ϊ��" << pq2.top() << endl;


    //����С���ѵķ�ʽ
    priority_queue<int,vector<int>,greater<int>> pq3;//greater�ǱȽ�ǰһ��Ԫ�غͺ�һ��Ԫ�صĽ����
                                                    //greater���ڵ���˼���������������˳���
    //��С���������Ԫ��
    pq3.push(1);
    pq3.push(2);
    //����С���Ѷ���Ԫ��,С���Ѷ�����Ԫ��Ϊ��������С��Ԫ��
    cout <<"С����pq3����Ԫ��Ϊ��" << pq3.top() << endl;

}