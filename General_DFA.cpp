#include<bits/stdc++.h>
using namespace std;

int traverse(string str, char final){
    char curr = str[0];
    if(curr == final){
        return 1;
    }else{

    }
}

int main()
{
    int numberOfState, numOfAlpha;
    char states[100000];
    char alphabet[100000];
    char end;
    char transition[1000][1000];

    cout<<"Number of states: ";
    cin>>numberOfState;
    cout<<"Enter states: "<<endl;
    for(int i=0; i<numberOfState; i++){
        cin>>states[i];
    }

    cout<<"Number of alphabet: ";
    cin>>numOfAlpha;
    cout<<"Enter alphabets:"<<endl;
    for(int i=0; i<numOfAlpha; i++){
        cin>>alphabet[i];
    }

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numOfAlpha; j++){
            cout<<"From: "<<states[i]<<" Via: "<<alphabet[j]<<" to(which?): ";
            cin>>transition[i][j];
            
        }
    }

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numOfAlpha; j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }

    string str;
    char curr, start, final;
    cout<<"Enter string: ";
    cin>>str;
    cout<<"Enter starting state:";
    cin>>start;
    cout<<"Enter final state: ";
    cin>>final;
    curr = start;
    cout<<"path: ";
    cout<<curr<<"->";
    for(int i=0; i<str.size(); i++){
        for(int j=0; j<numOfAlpha; j++){
            if(str[i] == alphabet[j]){
                curr = transition[curr-start][j];  // (curr - start) korle oi state/row er index pawa jay
                break;
            }
        }
        cout<<curr<<"->";
    }
    cout<<endl;
    if(curr == final) cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl;
} 