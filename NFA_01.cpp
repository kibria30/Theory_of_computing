// NFA end with 01

#include<bits/stdc++.h>
using namespace std;

int numberOfState, numOfAlpha, countOftransition[1000][1000];
char states[1000];
char alphabet[1000];
char transition[1000][1000][1000];
char str[1000], start, final;

bool traverse(int ptr, char curr){
    cout<<curr<<" -> ";
    bool result = 0;
    for(int i=ptr; i<strlen(str)-1; i++){
        for(int j = 0; j<numOfAlpha; j++){
            if(str[i] == alphabet[j]){
                for(int k=0; k<countOftransition[abs(curr-states[0])][j]; k++){
                    curr = transition[abs(curr-states[0])][j][k];
                    
                    result = result || traverse(i+1, curr);
                }               
            }
        }
    }

    return curr == final;
}

int main(){

    freopen("NFA_01_input.txt", "r", stdin);
    
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
            cout<<"From: "<<states[i]<<" Via: "<<alphabet[j]<<" to(which?): "<<endl;
            cout<<"How many transition: ";
            cin>>countOftransition[i][j];
            for(int k=0; k<countOftransition[i][j]; k++){
                cin>>transition[i][j][k];
            }

        }
    }

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numOfAlpha; j++){
            for(int k=0; k<countOftransition[i][j]; k++){
                cout<<transition[i][j][k]<<" ";
            }
           
        }
        cout<<endl;
    }

    char curr;
    cout<<"Enter string: ";
    cin>>str;
    cout<<"Enter starting state:";
    cin>>start;
    cout<<"Enter final state: ";
    cin>>final;
    curr = start;
    cout<<"path: ";
    if(traverse(0, start)) cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl<<endl<<endl;
}