#include<bits/stdc++.h>

using namespace std;

vector<string> A{"0A", ""};
vector<string> B{"0B", "1B", ""};

bool isExitsInA(string ele){
    return (find(A.begin(), A.end(), ele) != A.end());
}

bool isExitsInB(string ele){
    return (find(B.begin(), B.end(), ele) != B.end());
}

void leftmost(string S, string str, int ptr){
    for(int i=0; i<S.size() && ptr<str.size(); i++){
        string temp = "";
        if(S[i] == 'A' && isExitsInA(temp + str[ptr] + S[i])){
            S = S.replace(i, 1, temp + str[ptr] + S[i]);
            cout<<S<<" -> ";
        }
        else {
            S = S.replace(i, 1, temp);
            cout<<S<<" -> ";
            break;
        }
        ptr++;
    }

    ptr++;
    for (int i = 0; i < S.size(); i++) {
        string temp = "";
        if (S[i] == 'B') {
            if (isExitsInB(temp + str[ptr] + S[i])) {
                S = S.replace(i, 1, temp + str[ptr] + S[i]);
                cout << S << " -> ";
                ptr++;
            }
        }
    }
    cout <<"00101" <<endl;

}

int main(){
    string str, S;
    str = "00101";
    S = "A1B";
    cout<<"lefrmost:"<<endl;
    leftmost(S, str, 0);
    return 0;
}
