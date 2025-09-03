//A program to delete an element at beginning, middle and end of an array
#include <iostream>
#include <vector>

using namespace std;
void delBeg(vector<int>& arr){
    arr.erase(arr.begin());
}

void delMId(vector<int>& arr){
    int pos = arr.size()/2;
    arr.erase(arr.begin()+pos);
}
void delEnd(vector<int>& arr){
    arr.pop_back();
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
    
    cout<<"1 for delete at beginning, 2 for delete at end, 3 for delete at middle\n";
    cin>>c;
    if(c==1){
        delBeg(arr);
        printArr(arr,n);
    }
    else if(c==2){
        delEnd(arr);
        printArr(arr,n);
    }
    else if(c==3){
        delMId(arr);
        printArr(arr,n);
    }
    else
    cout<<"invalid input";
    
}