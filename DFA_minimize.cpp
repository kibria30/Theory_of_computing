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

void initTable(){
    for(int i=0; i< numberOfState; i++){
        for(int j=0; j<numberOfState; j++){
            table[i][j] = -1;
        }
    }
    for(int i=0; i< numberOfState; i++){
        for(int j=0; j<numberOfState; j++){
            if(states[i] == finalState || states[j] == finalState)
                table[i][j] = 0;
        }
    }
}

int similarity(char state1, char state2){
    //cout<<state1<<state2<<endl;
    int result = -1;
    for(int i=0; i<numOfAlpha; i++){
        if(table[state1- 'A'][state2 - 'A'] != 1)
            result = table[transition[state1-'A'][i]-'A'][transition[state2-'A'][i]-'A'];         
    }
    return result;
}

void minimize(){
    initTable();
    
    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            cout<< table[i][j] <<" ";
        }
        cout<<endl;
    }

    for(int i=numberOfState-1; i>0; i--){
        for(int j=0; j<numberOfState; j++){
            table[i][j] = similarity(states[i], states[j]);
        }
    }

    for(int i=numberOfState-1; i>0; i--){
        for(int j=0; j<numberOfState; j++){
            if(table[i][j] == -1)
                table[i][j] == 1;  
        }
    }
}


int main(){

    freopen("dfamini_input.txt", "r", stdin);
    getDFA();

    finalState = 'D';
    minimize();   

    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            cout<< table[i][j] <<" ";
        }
        cout<<endl;
    }
}