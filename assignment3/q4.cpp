#include<iostream>
using namespace std;

#define MAX 100

struct stack{
    char arr[MAX];
    int top;
}s;

void initiate(){
    s.top = -1;
}

int isempty(){
    return s.top == -1;
}

void push(char ch){
    if (s.top < MAX-1){
        s.arr[++s.top] = ch;
    }
}

char pop(){
    if (!isempty()){
        return s.arr[s.top--];
    }
    return '\0';
}

char peek(){
    if (!isempty()){
        return s.arr[s.top];
    }
    return '\0';
}

int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

char isoperand(char ch){
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

void infixToPostfix(char infix[],char postfix[]){
    initiate();
    int i=0,k=0;
    
    while(infix[i] != 0){
        char ch = infix[i];
        
        if(isoperand(ch)){
            postfix[k++]=ch;
        }
        
        else if (ch == '('){
            push(ch);
        }
        
        else if (ch == ')'){
            while(!isempty() && peek() != '('){
                postfix[k++] = pop();
            }
            
            pop();
        }
        
        else {
            while(!isempty() && (precedence(peek()) > precedence(ch)) || (precedence(peek()) == precedence(ch)) && peek() != '('){
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }
    
    while(!isempty()){
        postfix[k++] = pop();
    }
}

int main(){
    char infix[MAX] , postfix[MAX];
    cout << "enter infix expression: " << endl;
    cin >> infix;
    
    infixToPostfix(infix,postfix);
    
    cout << "postfix expression: " << postfix << endl;
    
    return 0;
}