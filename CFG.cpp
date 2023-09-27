#include<bits/stdc++.h>

using namespace std;

string p[] = {"e", "0", "1", "0P0", "1P1"};

int main(){
    string str, temp, x, y, path = "P";;
    cin>>str;
    cout<<"P"<<" -> ";
    for(int i=0, j = str.size()-1; i<j; i++, j--){
        if(str[i] != str[j]){
            cout<<"Not in this grammer.";
            return 0;
        }
        //cout<<str[i]<<endl;
        //cout<<str[j]<<endl;
        x = str[i];
        y = str[j];
        temp = x + "P" + y;
        //cout<<temp<<endl;
        
        bool exists = (find(p, p + 5, temp) != p + 5);        
        
        //cout<<"yes-"<<exists<<endl;
        
        int pos = 0, k;
        for(k=0; k<path.size(); k++){
            //cout<<"hello";
            if('P' == path[k]){
                pos = k;
            }

        }
        //cout<<"pos-"<<pos<<endl;
        if(exists){
            path = path.replace(pos, 1, temp) ; // str.replace(startpos, length, who_replace)
        }
        if(path == "p"){
            cout<<"Somethig missing!!"<<endl;
            return 0;
        }
        cout<<path<<" -> ";
    }
    cout<<str<<endl;
}
