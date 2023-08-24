#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MAX = 1000;
int numOfStates, numOfAlpha, countOfTransition[MAX][MAX];
char NFA_states[MAX], alphabet[MAX];
char NFA_table[MAX][MAX][MAX];
map<string, string> DFA_states; // NFA state set -> DFA state
map<string, string> DFA_table[MAX]; // DFA state -> transitions

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

void convert(const set<char>& currentStateSet) {
    string currentState = setToString(currentStateSet);
    if (DFA_states.find(currentState) != DFA_states.end()) {
        return; // State set is already processed
    }
    
    DFA_states[currentState] = currentState;
    
    for (int i = 0; i < numOfAlpha; i++) {
        set<char> nextStateSet;
        
        for (char state : currentStateSet) {
            int stateIndex = state - 'A';
            
            for (int j = 0; j < countOfTransition[stateIndex][i]; j++) {
                nextStateSet.insert(NFA_table[stateIndex][i][j]);
            }
        }
        
        string nextState = setToString(nextStateSet);
        if (!nextState.empty()) {
            convert(nextStateSet); // Recursive call to process next state set
            DFA_table[currentState][alphabet[i]] = setToString(nextStateSet);
        }
    }
}

int main() {
    // Your input reading and NFA to DFA conversion setup here
    getNFA_table();
    print_NFA_table();
    // Call convert() with the initial state set (e.g., starting with {NFA_states[0]})
    set<char> initialStateSet = {NFA_states[0]};
    convert(initialStateSet);
    
    // Your output printing and other processing here
    
    return 0;
}
