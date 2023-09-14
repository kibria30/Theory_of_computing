#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int numberOfState, numOfAlpha;
char states[MAX];
char alphabet[MAX];
char transition[MAX][MAX];
string store[100][100][100];

void getDFA(){
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
}

void initStore(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<3; k++){
                store[i][j][k] = "\0";
            }
        }
    }
}

string RE(int i, int j, int k){
    if( k==0 ){
        if(i==1 && j==1) return " e + 1 ";
        else if((i == 2 && j == 2) || (i==1 && j==3)) return " e ";
        else if(i==3 && j==3) return " e + 0 ";
        else if((i==1 && j==2) || (i==2 && j==3)) return " 0 ";
        else if((i==2 && j==1) || (i==3 && j ==1)) return " 1 ";
        else return " e ";
    }

    if(store[i][j][k] != "\0") return store[i][j][k];
    
    store[i][j][k] = (RE(i, j, k-1) + " + (" + RE(i, k, k-1) + ") (" + RE(k, k, k-1) + ")*(" + RE(k, j, k-1) + ")");
    return store[i][j][k];
   
}

int main()
{
    freopen("regular_input.txt", "r", stdin);

    getDFA();

    initStore();

    for(int k=0; k<3; k++){
        for(int i=1; i<4; i++){
            for(int j=1; j<4; j++){
                cout<<"RE("<<i<<", "<<j<<", "<<k<<") = "<<RE(i, j, k)<<endl;
            }
        }
    }

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numOfAlpha; j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }

} 