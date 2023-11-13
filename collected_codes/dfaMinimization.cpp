#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
#define max 20

char start, finish[max], state[max], alphabet[max], tran[max][max];
int numState, numAlphabet, numfinal;
vector<pair<char, char>> equiState;
vector<string> newState;
map<string,vector<string>> minDfa;


char equivalent[max][max];

void printMinDfa() {
    for (const auto& entry : minDfa) {
        cout << "State: " << entry.first <<"   ";
        for (const string& transition : entry.second) {
            cout << transition << " ";
        }
        cout << endl;
    }
}

void dfaReading()
{
    ifstream myfile("minDFA_Input.txt");
    if (!myfile.is_open())
    {
        cout << "Can't open the file" << endl;
    }
    else
    {
        cout << "File opened" << endl;
    }
    myfile >> numState;
    cout << numState << endl;

    for (int i = 0; i < numState; i++)
    {
        myfile >> state[i];
        cout << "State :" << state[i] << endl;
    }

    myfile >> numAlphabet;
    cout << numAlphabet << endl;

    for (int i = 0; i < numAlphabet; i++)
    {
        myfile >> alphabet[i];
        cout << "Alphabet :" << alphabet[i] << endl;
    }
    cout << "Hlw";
    myfile >> start;
    cout << "Start: " << start << endl;
    myfile >> numfinal;
    cout << numfinal << endl;
    for (int i = 0; i < numfinal; i++)
    {
        myfile >> finish[i];
        cout << "Final " << finish[i] << endl;
    }
    cout << endl
         << endl
         << "Transition Table: " << endl;
    for (int i = 0; i < numState; i++)
    {
        bool flag = false;
        if (state[i] == start)
        {
            cout << "->" << state[i];
            flag = true;
        }
        else if (!flag)
        {
            for (int j = 0; j < numfinal; j++)
            {
                if (state[i] == finish[j])
                {
                    cout << " *" << state[i];
                    flag = true;
                }
            }
        }
        if (!flag)
        {
            cout << "  " << state[i];
        }

        for (int j = 0; j < numAlphabet; j++)
        {
            myfile >> tran[i][j];
            cout << ": " << tran[i][j];
        }
        cout << endl;
    }
}

void dfaMinimization()
{
    for (int i = 0; i < numState; i++)
    {
        for (int j = 0; j < numState; j++)
        {
            for (int k = 0; k < numfinal; k++)
            {
                if ((state[i] == finish[k] || state[j] == finish[k]) && i > j)
                {
                    equivalent[i][j] = 'x';
                }
            }
            if (equivalent[i][j] != 'x')
            {
                equivalent[i][j] = '-';
            }
        }
    }

    for (int round = 0; round < numState; round++)
    {
        for (int i = 0; i < numState; i++)
        {
            for (int j = 0; j < numState; j++)
            {
                for (int k = 0; k < numAlphabet; k++)
                {
                    char stateIgettingK = tran[i][k];
                    char stateJgettingK = tran[j][k];
                    int stateIgettingKindex;
                    int stateJgettingKindex;
                    for (int m = 0; m < numState; m++)
                    {
                        if (state[m] == stateIgettingK)
                        {
                            stateIgettingKindex = m;
                        }
                        if (state[m] == stateJgettingK)
                        {
                            stateJgettingKindex = m;
                        }
                    }
                    if (equivalent[stateIgettingKindex][stateJgettingKindex] == 'x')
                    {
                        equivalent[i][j] = 'x';
                    }
                }
            }
        }
    }

    cout << endl
         << endl
         << "Dfa minimization table: " << endl;
    for (int f = 0; f < numState; f++)
    {
        cout << state[f] << " ";
        for (int i = 0; i < numState; i++)
        {
            if (f > i)
                cout << " " << equivalent[f][i];
        }
        cout << endl;
    }
    cout << "  ";
    for (int i = 0; i < numState; i++)
    {
        cout << " " << state[i];
    }

    

    cout << endl
         << endl
         << "Equivalent states are: " << endl;
    for (int i = 0; i < numState; i++)
    {
        for (int j = 0; j < numState; j++)
        {
            if (i > j)
            {
                if (equivalent[i][j] == '-')
                {
                    equiState.push_back(make_pair(state[i], state[j]));
                    //cout << state[i] << " " << state[j] << endl;
                }
            }
        }
    }

    for(pair<char,char>state:equiState){
        cout<<state.first<< "-"<<state.second<<endl;
    }

    for (int i = 0; i < numState; i++)
    {
        bool added = false;
        for (pair<char, char> fpair : equiState)
        {
            if(state[i]==fpair.second){
                added= true;
            }
            if (state[i] == fpair.first)
            {
                newState.push_back(string(1, fpair.first) + fpair.second);
                added = true;
            }
        }
        if(!added){
            newState.push_back(string(1,state[i]));
        }
    }
    cout<<endl<<endl<<"New States: "<<endl;
    for(string s:newState){
        cout<<s<<endl;
    }


    //mindfa creation
    for(string s:newState){
        int indexOfstate;
        for(int i=0;i<numState;i++){
            if(s[0]==state[i]){
                indexOfstate=i;
            }
        }
        vector<string> tranGettingAlpha;
        for(int k=0;k<numAlphabet;k++){
            char tranState = tran[indexOfstate][k];
            for(string s:newState){
                for(int i=0;s[i];i++){
                    if(s[i]==tranState){
                        tranGettingAlpha.push_back(s);
                    }
                }
            }

        }
        minDfa[s]=tranGettingAlpha;
    }

  


}

int main()
{
    dfaReading();
    dfaMinimization();
    printMinDfa();
}