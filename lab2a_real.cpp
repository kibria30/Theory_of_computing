#include<bits/stdc++.h>
using namespace std;

int length;

void permutate(string str, int pos){
    cout<<str<<endl;
    string temp;
    for(int i = length-1; i>=pos; i--){
        temp = str;
        temp[i] = '1';
        permutate(temp, i+1);
    }
}

int main(){
    int i;
    char str[10000];
    cin>>length;
    for(i=0; i<length; i++){
        str[i] = '0';
    }
    str[i] = '\0';
    permutate(str, 0);
}