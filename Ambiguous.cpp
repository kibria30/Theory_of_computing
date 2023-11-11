#include<bits/stdc++.h>

using namespace std;

vector<string> V{"aS", "aSbS", ""};
bool isExist(string ele){
    return (find(V.begin(), V.end(), ele) != V.end());
}

string leftmost1(string S, string str, int ptr){
    cout<<"S -> "<<S<<" -> ";
    for(int i=0; i<S.size() && ptr<str.size(); i++){
        string temp = "";
        if(S[i] == 'a' || S[i]=='b')
            ptr++;
      
        if(S[i] == 'S'){
            if(isExist(temp + str[ptr]+"S"+ str[ptr+1] + "S")){
                S = S.replace(i, 1, temp + str[ptr]+"S"+ str[ptr+1] + "S");
                cout<<S<<" -> ";
            }
            else if(isExist(temp + str[ptr]+"S")){
                S = S.replace(i, 1, temp + str[ptr]+"S");
                cout<<S<<" -> ";
            }
            else{
                for(int i=0; i<S.size(); i++){
                    if(S[i] == 'S'){
                        S = S.replace(i, 1, "");
                    }
                }
                
                cout<<S<<" -> ";
                break;
            }
            ptr++;
        } 
    }
    cout<<endl;
    return S;
}

string leftmost2(string S, string str){
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
    return S;
}

int main(){
    string str, S;
    str = "aab";
    string a = leftmost1(V[0], str, 0);
    string b = leftmost2(V[1], str);
    if(a == b) cout<<"Ambiguous"<<endl;
    else cout<<"Not ambigous"<<endl;
    return 0;
}
