//program to sort an array using bubble sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bubbleSort(vector<int>& arr){
    for(int i = 0; i<arr.size();i++){
        int s = 0;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                s=1;
            }
                
        }
        if(!s){
            break;
        }
    }

}

int main(){
    vector<int> arr;
    int a,b,c;
    cout<<"Number of elements\n";
    cin>>a;
    cout<<"Enter elements\n";
    for(int i =0;i<a;i++){
        cin>>b;
        arr.push_back(b);
    }
    bubbleSort(arr);
    for(int i : arr){
        cout<< i<<" ";
    }
}