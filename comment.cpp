#include <bits/stdc++.h>

using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;
    bool inMultiLineComment = false;

    while (getline(inputFile, line)) {
        lineNumber++;

        int singleLinePos = line.find("//");
        int multiLineStartPos = line.find("/*");
        int multiLineEndPos = line.find("*/");

        if (inMultiLineComment) {
            cout << "Line " << lineNumber << ": " << line << endl;
            if (multiLineEndPos != string::npos) {
                cout << "Multi-line comment end" << endl;
                inMultiLineComment = false;
            }
            else{
                cout<<"Mistake! Multi-line comment not end."<<endl;
        }
            
        } else {
            if (singleLinePos != string::npos) {
                cout << "Line " << lineNumber << "(single-line): " << line.substr(singleLinePos) << endl;
            }
            if (multiLineStartPos != string::npos) {
                if (multiLineEndPos != string::npos) {
                    cout << "Line " << lineNumber << "(Multi-line): " << line.substr(multiLineStartPos, multiLineEndPos - multiLineStartPos + 2) << endl;
                } else {
                    cout << "Line " << lineNumber << "(Multi-line): " << line.substr(multiLineStartPos) << endl;
                    inMultiLineComment = true;
                }
            }
        }
        
    }

    inputFile.close();
    return 0;
}