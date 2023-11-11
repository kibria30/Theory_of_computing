#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int top = -1;
char _stack[MAX];

void push(char ch){
    top++;
    _stack[top] = ch;
}

char pop(){
    if(top == -1){
        cout<<"Stack is under flow!";
        return '\0';
    }
    char temp = _stack[top];
    top--;
    return temp;
}

char topEle(){
    return _stack[top];
}

bool PDA(string str){
    int len = ceil((float)str.size()/2); 
    cout<<len<<endl;
    for(int i=0; i<len; i++){
        push(str[i]);
    }
    int iter = len;
    while(topEle()){
        //cout<<topEle()<<endl;
        if(topEle() == str[iter]){
            pop();
            iter++;
        }
        else break;
    }

    if(topEle() == '\0'){
        return true; 
    }
    else{
        return false;
    }
}

int main(){
    string str;
    cin>>str;
    if(PDA(str)){
        cout<<"Accepted"<<endl;
    }
    else{
        cout<<"Not accepted"<<endl;
    }
}