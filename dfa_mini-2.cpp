#include<iostream>
#define MAX 1000

using namespace std;

//jur kore milaylam so its working

int numberOfState, numOfAlpha;
char states[MAX];
char alphabet[MAX];
char transition[MAX][MAX];
char table[MAX][MAX];
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

void printTable(){
    cout<<endl<<"Printed table:"<<endl;
    for(int i=0; i<numberOfState; i++){
        for(int j=0; j<numberOfState; j++){
            cout<< table[i][j] <<"\t";
        }
        cout<<endl;
    }
}

void initTable(){
    for(int i=0; i< numberOfState; i++){
        for(int j=0; j<numberOfState; j++){
            if(states[i] == finalState || states[j] == finalState)
                table[i][j] = 'X';

            if( i == j) table[i][j] = '\0';   //jor kore milailam
        }
    }
}

void similarity(char state1, char state2){
    cout<<state1<<state2<<endl;
    for(int i=0; i<numOfAlpha; i++){
        if(table[state1 - 'A'][state2 - 'A'] == '\0'){
            cout<<table[transition[state1-'A'][i]-'A'][transition[state2-'A'][i]-'A']<<" hello "<<endl;  
            table[state1 - 'A'][state2 - 'A'] = table[transition[state1-'A'][i]-'A'][transition[state2-'A'][i]-'A'];         

        }
    }
}

void minimize(){

    initTable();
    
    printTable();

    //similarity('H', 'F');

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
    

    for(int i=1; i<numberOfState; i++){
        for(int j=0; j<i; j++){
            if(table[i][j] == '\0')
                table[i][j] = '=';  
        }
    }

}


int main(){

    freopen("dfamini_input.txt", "r", stdin);
    getDFA();

    finalState = 'D';

    minimize(); 
    printTable();
    cout<<"Final Table:";
    printTable();

}