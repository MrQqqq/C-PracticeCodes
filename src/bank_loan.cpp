/*
 * @Description: ���д���ȶϢ�͵ȶ��Ļ��ʽ
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-07-01 09:32:19
 * @LastEditors: szq
 * @LastEditTime: 2020-07-01 12:01:45
 * @FilePath: \cpp\src\bank_loan.cpp
 */ 
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

/**
 * @destription: �ȶϢÿ���»����ͻ����ܶ���������Ϣ��
 * @param {type} ��principal������   months������������  rate:������
 * @return: û�з���ֵ
 */
void average_capital_plus_interest(double principal,int months,double rate){
    double total_per_month;//�ȶϢÿ���»����ܶ�
    double total_principal_interest;//�������Ϣ�ܶ�
    double rate_month = rate / 12;//������
    total_per_month = principal * rate_month * pow(rate_month + 1,months) 
                        / (pow(rate_month + 1,months) - 1);
    total_principal_interest = total_per_month * months;
    cout << "�ȶϢ��������Ϊ��"  << endl;
    cout << "ÿ���»����Ϊ:" << setiosflags(ios::fixed) << setprecision(2) << total_per_month << endl;
    cout << "�����ܶ�Ϊ��" << setiosflags(ios::fixed) << setprecision(2) << total_principal_interest << endl;
}

/**
 * @destription: �ȶ��ÿ���»����ͻ����ܶ���������Ϣ��
 * @param {type} ��principal������   months������������  rate:������
 * @return: û�з���ֵ
 */

void average_interest(double principal,int months,double rate){
    double principal_per_month = principal / months;//�ȶ��ÿ���»����
    double total_principal_interest = 0;//�������Ϣ�ܶ�
    double rate_month = rate / 12;//������
    cout << "�ȶ�𻹿�����Ϊ��" << endl;
    for(int i = 1;i <= months;i++){
        double total_per_month = principal * rate_month + principal_per_month;//ÿ�ڻ����ܶ�
        principal = principal - principal_per_month;//ʣ�౾��
        cout << "��" << i << "���»�����Ϊ��" << setiosflags(ios::fixed) << setprecision(2) << total_per_month << endl;
        total_principal_interest += total_principal_interest;
    }
    cout << "�����ܶ�Ϊ��" << setiosflags(ios::fixed) << setprecision(2) <<total_principal_interest << endl;
}


int main(){
    double principal;//����
    double rate;//������
    double months;//��������
    cout << "�����������:";
    cin >> principal;
    cout << endl;

    cout << "������������ޣ���λ���£�:";
    cin >> months;
    cout << endl;

    cout << "���������������:";
    cin >> rate;
    cout << endl;


    int choice = 1;//���ʽ,1Ϊ�ȶϢ��2Ϊ�ȶ��
    cout << "1.�ȶϢ" << endl;
    cout << "2.�ȶ��" << endl;
    cout << "��ѡ�񻹿ʽ��" ;
    cin >> choice;
	cout << endl;
    
    switch (choice)
    {
    case 1:
        average_capital_plus_interest(principal,months,rate);
        break;
    case 2:
        average_interest(principal,months,rate);
        break;
    default:
        break;
    }
}

