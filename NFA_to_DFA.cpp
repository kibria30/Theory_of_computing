#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int numOfStates, numOfAlpha, countOfTransition[MAX][MAX];
char NFA_states[MAX], alphabet[MAX];
char NFA_table[MAX][MAX][MAX];
string DFA_states[MAX], DFA_table[MAX][MAX];

void getNFA_table(){
    cout << "Number of states: ";
    cin >> numOfStates;
    cout << "Enter states:" << endl;
    for (int i = 0; i < numOfStates; i++) {
        cin >> NFA_states[i];
    }

    cout << "Number of alphabet: ";
    cin >> numOfAlpha;
    cout << "Enter alphabets:" << endl;
    for (int i = 0; i < numOfAlpha; i++) {
        cin >> alphabet[i];
    }

    for (int i = 0; i < numOfStates; i++) {
        for (int j = 0; j < numOfAlpha; j++) {
            cout << "From: " << NFA_states[i] << " Via: " << alphabet[j] << " to(which?): " << endl;
            cout << "How many transitions: ";
            cin >> countOfTransition[i][j];
            for (int k = 0; k < countOfTransition[i][j]; k++) {
                cin >> NFA_table[i][j][k];
            }
        }
    }
}

void print_NFA_table(){
    for (int i = 0; i < numOfStates; i++) {
        cout<<NFA_states[i]<< "-> "; 
        for (int j = 0; j < numOfAlpha; j++) {
            for (int k = 0; k < countOfTransition[i][j]; k++) {
                cout<< NFA_table[i][j][k]<<",";
            }
            cout<<"\t";
        }
        cout<<endl;
    }
}

void convert(string state){
    int stateIndex = abs(state - NFA_states[0]);
    DFA_states[stateIndex] = state;
    string nextState;
    for(int i=0; i<numOfAlpha; i++){
        for(int j=0; j<countOfTransition[stateIndex][i]; j++){
            nextState += NFA_table[stateIndex][i][j]; 
        }
        DFA_table[stateIndex][i] = nextState;
    }
}

int main(){
    freopen("NFA_to_DFA_input.txt", "r", stdin);
    getNFA_table();
    print_NFA_table();
    char start;
    cin>>start;
    //convert(start);

}