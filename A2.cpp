//A program to insert an element at beginning, middle and end of an array
#include <iostream>
#include <vector>

using namespace std;
void insBeg(vector<int>& arr,int val){
    arr.insert(arr.begin(),val);
}

void insMid(vector<int>& arr, int val){
    int pos = arr.size()/2;
    arr.insert(arr.begin()+pos,val);
}
void insEnd(vector<int>& arr, int val){
    arr.push_back(val);
}
void printArr(vector<int>& arr, int n){
    for(int n : arr){
        cout<< n<<" ";
    }
}

int main(){int n,val;
    int a{0};
    
    int c{0};
    vector<int> arr;
    cout<<"Enter number of elements\n";
    cin>>n;
    
    cout<<"Enter elements\n";
    for(int i = 0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Enter value to be inserted\n";
    cin>>val;
    cout<<"1 for insert at beginning, 2 for insert at end, 3 for insert at middle\n";
    cin>>c;
    if(c==1){
        insBeg(arr,val);
        printArr(arr,n);
    }
    else if(c==2){
        insEnd(arr,val);
        printArr(arr,n);
    }
    else if(c==3){
        insMid(arr,val);
        printArr(arr,n);
    }
    else
    cout<<"invalid input";
    
}