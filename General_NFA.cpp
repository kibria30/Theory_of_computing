#include<bits/stdc++.h>
using namespace std;

const int MAX_STATES = 1000;
const int MAX_ALPHABET = 1000;

int numberOfStates, numOfAlpha, countOfTransition[MAX_STATES][MAX_ALPHABET];
char states[MAX_STATES];
char alphabet[MAX_ALPHABET];
char transition[MAX_STATES][MAX_ALPHABET][MAX_STATES];
char str[1000], start, final;

vector<char> path;

bool traverse(int ptr, char curr) {
    bool result = false;

    if (ptr == strlen(str)){
        return curr == final;
    }

    for (int j = 0; j < numOfAlpha; j++) {
        if (str[ptr] == alphabet[j]) {
            for (int k = 0; k < countOfTransition[abs(curr - states[0])][j]; k++) {
                char nextState = transition[abs(curr - states[0])][j][k];
                result = result || traverse(ptr + 1, nextState);
                if(result == true){
                    path.push_back(nextState);
                }
            }
        }
    }
    return result;
}

int main() {
    freopen("NFA_01_input.txt", "r", stdin);

    cout << "Number of states: ";
    cin >> numberOfStates;
    cout << "Enter states:" << endl;
    for (int i = 0; i < numberOfStates; i++) {
        cin >> states[i];
    }

    cout << "Number of alphabet: ";
    cin >> numOfAlpha;
    cout << "Enter alphabets:" << endl;
    for (int i = 0; i < numOfAlpha; i++) {
        cin >> alphabet[i];
    }

    for (int i = 0; i < numberOfStates; i++) {
        for (int j = 0; j < numOfAlpha; j++) {
            cout << "From: " << states[i] << " Via: " << alphabet[j] << " to(which?): " << endl;
            cout << "How many transitions: ";
            cin >> countOfTransition[i][j];
            for (int k = 0; k < countOfTransition[i][j]; k++) {
                cin >> transition[i][j][k];
            }
        }
    }

    char curr;
    cout << "Enter string: ";
    cin >> str;
    cout << "Enter starting state:";
    cin >> start;
    cout << "Enter final state: ";
    cin >> final;
    curr = start;
    cout << "path: ";
    if (traverse(0, start)) {
        
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }
    path.push_back(start);
    int n = path.size();
    cout<<"path: ";        //path printing e jamela ase
    for(int i=0; i<n; i++){
        cout << path.back()<<" -> ";
        path.pop_back();
    }
    cout<<endl<<endl;
    return 0;
}