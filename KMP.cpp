#include <iostream>
using namespace std;

#define MaxSize 255
void getNext(int *next,string s){
    int j = 0;
    int k = -1;
    next[0] = -1;
    while(j < s.length() - 1){
        if(k == -1 || s[j] == s[k]){
            j++;
            k++;
            if(s[j] == s[k]){
                next[j] = next[k];
            }
            else{
                next[j] = k;
            }
        }
        else{
            k = next[k];
        }
    }
}

int KMP(string s,string t){
    int len = t.size();
    int *next = new int[len],i = 0,j=0;
    getNext(next,t);
    
    while(i < s.length()&&j < t.length()){
        if(j == -1||s[i] == t[j]){
            i++;
            j++;

        }
        else{
            j = next[j];
        }
    }
    if(j >= t.length()){
        return i - j;
    }
    else{
        return -1;
    }
}


int main(){
    int res;
    string s = "ahvdffjdfsjdfg";
    string t = "ffj";
    res = KMP(s,t);
    cout << res << endl;
}