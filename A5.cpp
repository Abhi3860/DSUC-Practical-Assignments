// program to search for a specific element in an array
#include <iostream>
#include <vector>
using namespace std;
int searchEl(vector<int>& arr, int val){
    for(int i : arr){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
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
    cout<<"enter value to be searched ";
    cin>>c;
    int res = searchEl(arr, c);
    if(res != -1){
        cout<< "Element "<< c << " found at "<< res << " index\n";
    }
    else
    cout << "Element not found";
}