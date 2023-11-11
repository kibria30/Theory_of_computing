#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<char> _stack;

bool PDA(string str){
    int i;
    for(i=0; i<str.size(); i++){
        if(str[i] == '0'){
            _stack.push_back(str[i]);
        }
        else if(str[i] == '1'){
            if(i<str.size()-1 && str[i+1] == '0'){
                return false;
            }
            if(!_stack.empty()){
                _stack.pop_back();
            }
            else break;
        }
    }

    if(_stack.empty() && i == str.size()){
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