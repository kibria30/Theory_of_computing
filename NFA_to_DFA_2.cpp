#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int numOfStates, numOfAlpha, countOfTransition[MAX][MAX];
char NFA_states[MAX], alphabet[MAX];
char NFA_table[MAX][MAX][MAX];
map <int , string>  DFA_states;
map <string, set<char>> DFA_table;
int ptr =-1;

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

string setToString(const set<char>& stateSet) {
    string result;
    for (char state : stateSet) {
        result += state;
    }
    return result;
}

void convert(string curr){
    ptr++;
    DFA_states[ptr] = curr;
    set<char> state;
    for(int i=0; i<strlen(curr); i++){
        for(int j=0; j<numOfAlpha; j++){
            state.clear():
            for(int k=0; k<countOfTransition[curr[i]-'a'][j]){
                state.insert(NFA_table[curr[i]-'a'][j][k]);
            }
            DFA_table[curr] = state;
        }
    }
}

int main(){
    freopen("NFA_to_DFA_input.txt", "r", stdin);
    getNFA_table();
    print_NFA_table();
    string start;
    cin >> start;
    //convert(start);

}