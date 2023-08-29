#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int numberOfState, numOfAlpha;
char states[MAX];
char alphabet[MAX];
char transition[MAX][MAX];

string RE(int first, int second, int numOfInterMidiateStates){
    if(numOfInterMidiateStates == 0){
        if(transition[first-1][0] == states[second-1]){
            return "0";
        }
        else if(transition[first-1][1] == states[second-1]){
            return "1";
        }
        else{
            return "";
        }
    }
    else{
        string result = "";
        RE(first, second, numOfInterMidiateStates-1) + 
        RE(first, numOfInterMidiateStates, numOfInterMidiateStates-1) + "(" + 
        RE(numOfInterMidiateStates, numOfInterMidiateStates, numOfInterMidiateStates-1) + ")*" 
        + s Rikk-1(Rkkk-1)* Rkjk-1 )

        return result;

}

int main()
{
    freopen("regular_input.txt", "r", stdin);

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

    cout<<RE(1, 2, 1)<<endl;
} 