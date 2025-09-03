// Program to accept a postfix expression, ask the values for variables of an expression and then calculate the expression for that value
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int askVal(char C){
    int a;
    cout<< "Enter value of variable "<< C;
    cin>> a;
    return a;
 }
bool isNumDigit(char C){
    if(C>= '0' && C<='9')
        return true;
    return false;
}

bool isOp(char C){
    if(C=='+'|| C== '-'|| C== '*'|| C== '/' || C== '^')
        return true;
    return false;
}

int perOp(char operation, int op1, int op2){
    if(operation== '+')
        return op1+op2;
    else if(operation== '-')
        return op1-op2;
    else if(operation== '*')
        return op1*op2;
    else if(operation== '/')
        return op1/op2;
    else if(operation== '^')
        return pow(op1,op2);
    else{
        cout<< "Unexpected Error\n";
        return -1;
    }
}

int evalPostfix(string exp){
    stack<int> S;
    for(int i = 0; i< exp.length();i++){
        if(exp[i]== ' ' || exp[i]== ',')
            continue;
        else if(isalpha(exp[i])){
            int val = askVal(exp[i]);
            
            S.push(val);

        }
        else if(isOp(exp[i])){
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            int res = perOp(exp[i], op1, op2);
            S.push(res);
        }
        else if(isNumDigit(exp[i])){
            int operand = 0;
            while(i<exp.length() && isNumDigit(exp[i])){
                operand = (operand*10)+ (exp[i]- '0');
                i++;
            }
            i--;
            S.push(operand);
        }
    }
    return S.top();

}

int main(){
    string expression;
    cout<< "Enter postfix expression:\n";
    getline(cin, expression);
    int res = evalPostfix(expression);
    cout<< "Output= "<<res<< '\n';
}