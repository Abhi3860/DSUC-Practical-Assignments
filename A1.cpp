//A program to sort an array in ascending and descending order

#include <iostream>

void AscendingSort(int arr[], int n){
    int tem;
    for (int i = 0; i < n-1; i++)   
    {
        for (int j = 0; j < n-i-1; j++)
        {   if(arr[j]>arr[j+1]){
            tem = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tem;}
        }
        
    }
    
}

void DescendingSort(int arr[], int n){
    int tem;
    for (int i = 0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
            tem=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tem;}
        }
    }
}

int main(){
    int arr[100],n;
    std::cout<<"Enter no of elements \n";
    scanf("%d",&n);
    std::cout<<"Enter elements\n";
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int AscArr[100], DscArr[100];
    for(int i =0;i<n;i++){
        AscArr[i]=arr[i];
        DscArr[i]=arr[i];
    }
    AscendingSort(AscArr,n);
    for(int i =0;i<n;i++){
        std::cout<<AscArr[i]<<" ";}
        std::cout<< '\n';
    DescendingSort(DscArr,n);
    for(int i =0;i<n;i++){
        std::cout<<DscArr[i]<<" ";
    }





}