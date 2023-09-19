#include<iostream>
#define MAX 1000

using namespace std;

int numberOfState, numOfAlpha;
char states[MAX];
char alphabet[MAX];
char transition[MAX][MAX];
char table[MAX][MAX];
char finalState;
//string similarStates;

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

void printTable(){
    cout<<endl<<"Printed table:"<<endl;
    for(int i=1; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            cout<< table[i][j] <<"\t";
        }
        cout<<endl;
    }
}

void initTable(){
    for(int i=1; i< numberOfState; i++){
        for(int j=0; j<i; j++){
            if(states[i] == finalState || states[j] == finalState)
                table[i][j] = 'X';
            else 
                table[i][j] = '\0';
        }
    }
}

void similarity(char state1, char state2){
    cout<<state1<<state2<<endl;
    for(int i=0; i<numOfAlpha; i++){
        if(table[state1 - 'A'][state2 - 'A'] == '\0'){
            table[state1 - 'A'][state2 - 'A'] = table[transition[state1-'A'][i]-'A'][transition[state2-'A'][i]-'A'];
            if(table[state1 - 'A'][state2 - 'A'] == '\0')
                table[state1 - 'A'][state2 - 'A'] = table[transition[state2-'A'][i]-'A'][transition[state1-'A'][i]-'A'];
        }
                     
    }
}

void minimize(){

    initTable();
    
    printTable();

    for(int iter = 0; iter<2; iter++){
        cout<<"iter-"<<iter+1<<endl;
        for(int i=1; i<numberOfState; i++){
            for(int j=0; j<i; j++){
                if(table[i][j] == '\0')
                    similarity(states[i], states[j]);
            }
        }
        printTable();
    }
    
    cout<<endl<<"These states are equivalent: "<<endl;
    for(int i=1; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            if(table[i][j] == '\0'){
                table[i][j] = '=';  
                cout<<states[i]<< " = " << states[j]<<endl;
            }
                
        }
    }

}


int main(){

    freopen("dfamini_input.txt", "r", stdin);
    getDFA();

    finalState = 'D';

    minimize(); 
    printTable();

}