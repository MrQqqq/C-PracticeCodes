#include <iostream>
using namespace std;

int getIndex(int *arr,int start,int end){
    int tmp = arr[start];
    while(start < end){
        while(start < end && arr[end-1] > tmp){
            --end;
        }
        arr[start] = arr[end - 1];
        while(start < end && arr[start] < tmp){
            ++start;
        }
        arr[end - 1] = arr[start];
    }
    arr[start] = tmp;
    return start;
}
void quickSort(int *arr,int start,int end){
    if(start < end){
        int index = getIndex(arr,start,end);
        quickSort(arr,start,index);
        quickSort(arr,index+1,end);
    }
    
}
int main(int argc,char *argv[]){
    int arr[7] = {3,7,9,4,2,5,1};
    quickSort(arr,0,7);
    for(auto num : arr){
        cout << num << " ";
    }
    cout << endl;
}