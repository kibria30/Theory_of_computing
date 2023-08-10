// NFA end with 01

#include<bits/stdc++.h>
using namespace std;

int numberOfState, numOfAlpha, countOftransition[1000][1000];
char states[1000];
char alphabet[1000];
char transition[1000][1000][1000];
char str[1000], start, final;

int traverse(string str, char start, char final){
    char curr = start;
    if(curr == final){
        return 1;
    }else{

    }
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
                cout<<transition[i][j]<<" ";
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
    cout<<curr<<"->";
    for(int i=0; i<str.size()-1; i++){
        for(int j=0; j<numOfAlpha; j++){
            for(int k=0; k<countOftransition[i][j]; k++){
                if(str[i] == alphabet[j] && str[i+1] == 1){
                    curr = transition[abs(curr-start)][j][k++];  // (curr - start) korle oi state/row er index pawa jay
                    break;
                }
                if(str[i] == alphabet[j] && str[i+1] == 0){
                    curr = transition[abs(curr-start)][j][k];
                    break;
                }
            }
        }
        cout<<curr<<"->";
    }
    cout<<endl;
    if(curr == final) cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl;
}