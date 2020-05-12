#include<iostream>
using namespace std;
#define bigger(a,b) a > b ? a: b
int main(){
    int bigger_num = bigger(10,5);
    cout << bigger_num <<endl;
    return 0;
}