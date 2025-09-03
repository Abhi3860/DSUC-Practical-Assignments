//A program to convert an entire expression into an equivalent postfix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int pres(char op){
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    if(op=='^')
        return 3;
    return 0;
}
bool isOp(char c){
    bool a = (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
    return a;
}
string postfix(string infix){
    stack<char> st;
    string postfix=" ";
    for(char c : infix){
        if(isalnum(c)){//operand
            postfix+=c;
        }
        else if(c=='('){//left bracket
            st.push(c);
        }
        else if(c==')'){//right bracket
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else if(isOp(c)){//operator
            while(!st.empty() && (pres(st.top())>=pres(c))){
                postfix+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){//remove all remaining operators
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
int main(){
    string infix;
    cout<< "Enter infix expression\n";
    cin>> infix;
    string post = postfix(infix);
    cout<< "Postfix Expression: "<< post<< '\n';
}