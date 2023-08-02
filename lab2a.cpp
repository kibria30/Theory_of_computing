#include<bits/stdc++.h>
using namespace std;

string cal_swap(string str, int initial, int target){
    char temp = str[initial];
    str[initial] = str[target];
    str[target] = temp;
    return str;
}

void permutate(string str, int pos){
    if(pos>=str.length()){
        cout<<str<<endl;
    }
    string output;
    for(int i=pos; i<str.length(); i++){
        output = cal_swap(str, pos, i);
        permutate(output, pos+1);
    }
}

int main(){
    int length, pos = 0, i;
    char str[10000];
    cin>>length;

    for(i=0; i<length; i++){
        str[i] =(char)(i+48);
    }
    str[i] = '\0';
    permutate(str, pos);
}