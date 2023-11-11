#include<bits/stdc++.h>

using namespace std;

vector<string> store{"0A", "0B", "1B", ""};

bool isExist(string ele){
    return (find(store.begin(), store.end(), ele) != store.end());
}

void leftmost(string S, string str){
    cout<<"S -> "<<S <<" -> ";
    for(int i=0; i<str.size(); i++){
        string temp = "";
        if(S[i] != str[i]){
            temp = temp + str[i] + S[i];
            if(isExist(temp)){
                S = S.replace(i, 1, temp);
                cout<<S<<" -> ";
            }
            else{
                S = S.replace(i, 1, "");
                cout<<S<<" -> ";
            }
        }
    }
    for(int i=0; i<S.size(); i++){
        if(S[i] > 64 && S[i] < 91){
            S = S.replace(i, 1, "");
            cout<<S<<endl;
        }
    }
}

int main(){
    string S, str;
    S = "A1B";
    str = "00101";
    cout<<"leftmost:"<<endl;
    leftmost(S, str);
    return 0;
}