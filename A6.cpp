//A program to demonstrate operations performed on a stack
#include <iostream>
int top = -1;
int arr[100]{0};
void pop(){
    if(top == -1)
       { std::cout<<"Underflow Condition\n";
        }
    else{
        std::cout<< "Popped element is: "<< arr[top]<<'\n';
        top--;
    }

}

void push(int val, int n){
    if(top>n-1){
        std::cout<< "Overflow Condition\n";
    }
    else{
        top++;
        arr[top]=val;
    }
}

void display(){
    if(top>=0){
        std::cout<< "The elements are ";
        for(int i = top; i>=0;i--){
            std::cout<< arr[i]<<',';
        }
        std::cout<<std::endl;
    }
    else{
        std::cout<< "The stack is empty";
    }
}

int main(){int ch, val;
    int n{100};
    
    std::cout<<"1 for push, 2 for pop, 3 for display, 4 for exit";
    do{std::cin>>ch;
    switch(ch){
        case 1: std::cout<< " Enter value to be pushed ";
                std::cin>>val;
                push(val, n);
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: break;
        default: std::cout<< "invalid choice";
    }}while(ch!=4);
}
