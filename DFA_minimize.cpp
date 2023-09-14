#include<iostream>
#define MAX 1000

using namespace std;

int numberOfState, numOfAlpha;
char states[MAX];
char alphabet[MAX];
char transition[MAX][MAX];
int table[MAX][MAX];
char finalState;

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
    cout<<endl;

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numOfAlpha; j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }
}

int similarity(char state1, char state2){
    if(state1 == finalState && state2 == finalState && state1 == state2) return 1;
    if(state1 == finalState && state2 != finalState) return 0;
    else if(state1 != finalState && state2 == finalState) return 0;
    else{
        for(int i=0; i<numOfAlpha; i++){
            
            return similarity(transition[state1-'a'][i], transition[state2-'a'][i]);
            
        }
        return 0;
    }
   
}

void minimize(){
    for(int i=1; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            cout<<"hello";
            table[i][j] = similarity(states[i], states[j]);
        }
    }
}


int main(){

    freopen("dfamini_input.txt", "r", stdin);
    getDFA();

    finalState = 'D';
    minimize();

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numberOfState; j++){
            cout<< table[i][j] <<" ";
        }
        cout<<endl;
    }
}