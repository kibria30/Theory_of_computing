#include<bits/stdc++.h>

using namespace std;

vector<string> V{"aS", "aSbS", ""};

bool isExits(string ele){
    return (find(V.begin(), V.end(), ele) != V.end());
}

string leftmost1(string S, string str, int ptr){
    cout<<"S -> "<<S<<" -> ";
    for(int i=0; i<S.size() && ptr<str.size(); i++){
        string temp = "";
        if(S[i] == 'a' || S[i]=='b')
            ptr++;

      
        if(S[i] == 'S'){
            
            if(isExits(temp + str[ptr]+"S"+ str[ptr+1] + "S")){
                S = S.replace(i, 1, temp + str[ptr]+"S"+ str[ptr+1] + "S");
                cout<<S<<" -> ";
            }
            else if(isExits(temp + str[ptr]+"S")){
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
        
        // string temp2 = "";
        // for(int i=0; i<S.size(); i++){
        //     if(S[i] != 'S') temp2 = temp2 + S[i];
        // }
        // if(temp2 == str) return;
    }
    cout<<endl;
    return S;
}

string leftmost2(string S, string str, int ptr){
    cout<<"S -> "<<S<<" -> ";
    for(int i=0; i<S.size() && ptr<str.size(); i++){
        string temp = "";
        if(S[i] == 'a' || S[i]=='b')
            ptr++;

      
        if(S[i] == 'S'){
            if(isExits(temp + str[ptr]+"S")){
                S = S.replace(i, 1, temp + str[ptr]+"S");
                cout<<S<<" -> ";
            }
            
            else if(isExits(temp + str[ptr]+"S"+ str[ptr+1] + "S")){
                S = S.replace(i, 1, temp + str[ptr]+"S"+ str[ptr+1] + "S");
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
        
        // string temp2 = "";
        // for(int i=0; i<S.size(); i++){
        //     if(S[i] != 'S') temp2 = temp2 + S[i];
        // }
        // if(temp2 == str) return;
    }
    cout<<endl;
    return S;
}

int main(){
    string str, S;
    str = "aab";
    string a = leftmost1("aS", str, 0);
    string b = leftmost2("aSbS", "aab", 0);
    if(a ==b ) cout<<"Ambiguous"<<endl;
    else cout<<"Not ambigous"<<endl;
    return 0;
}
