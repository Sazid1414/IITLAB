#include <bits/stdc++.h>
using namespace std;

string startSymbol;
vector<string> productionA;
vector<string> productionB;
vector<string> terminalSymbols;
vector<string> nonTerminalSymbols;
vector<string> result;

bool contains(vector<string> v, string s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) {
            return true;
        }
    }
    return false;
}

string findTerminalSymbol() { // Removed input parameter
    string input;
    cout << "Enter a string: ";
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '0') {
            return "0";
        } else if (input[i] == '1') {
            return "1";
        }
    }
    return "";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    startSymbol = "A1B";
    productionA.push_back("0");
    productionB.push_back("0");
    productionB.push_back("1");
    terminalSymbols.push_back("0");
    terminalSymbols.push_back("1");
    nonTerminalSymbols.push_back("A");
    nonTerminalSymbols.push_back("B");
    string input;
    // cout << "Enter a string: ";
    cin >> input;

    // Leftmost Derivation
    string temp = input;
    string innerTerminalSymbol = findTerminalSymbol();
    int posInner = startSymbol.find_last_of(innerTerminalSymbol);
    string resultTemp = startSymbol;
    cout << "Left Most Derivation: " << resultTemp << "  ";

    for (int i = 0; i < temp.size(); i++) {
        int j = 0;
        for (; j < resultTemp.size(); j++) {
            if (contains(nonTerminalSymbols, string(1, resultTemp[j]))) {
                i = j;
                break;
            }
        }

        if (resultTemp[j] == 'A') {
            if (contains(productionA, string(1, temp[i]))) {
                string resultStr = (string(1, temp[i]) + "A");
                resultTemp.replace(j, 1, resultStr);
            } else {
                resultTemp.replace(j, 1, "");
            }
        } else if (resultTemp[j] == 'B') {
            if (contains(productionB, string(1, temp[i]))) {
                string resultStr = (string(1, temp[i]) + "B");
                resultTemp.replace(j, 1, resultStr);
            } else {
                resultTemp.replace(j, 1, "");
            }
        } else continue;

        if (i == (temp.size() - 1)) {
            cout << resultTemp << "  ";
            resultTemp.replace(i + 1, 1, "");
        }

        cout << resultTemp << "  ";
    }

    // Rightmost Derivation
    string temp2 = input;
    string innerTerminalSymbol2 = findTerminalSymbol();
    int posInStartSymbol = startSymbol.find_first_of(innerTerminalSymbol2);
    int posInTemp2 = temp2.find_first_of(innerTerminalSymbol2);
    string resultTemp2 = startSymbol;
    cout << "\nRight Most Derivation : " << resultTemp2 << "  ";

    // After the breakpoint [first value of innerTerminalSymbol2 of startSymbol in temp2]
    for (int i = posInTemp2 + 1; i < temp2.size(); i++) {
        int j = resultTemp2.size() - 1;
        for (; j >= 0; j--) {
            if (contains(nonTerminalSymbols, string(1, resultTemp2[j]))) {
                break;
            }
        }

        if (resultTemp2[j] == 'A') {
            if (contains(productionA, string(1, temp2[i]))) {
                string resultStr = (string(1, temp2[i]) + "A");
                resultTemp2.replace(j, 1, resultStr);
            } else {
                resultTemp2.replace(j, 1, "");
                cout << resultTemp2 << "  ";
                break;
            }
        } else if (resultTemp2[j] == 'B') {
            if (contains(productionB, string(1, temp2[i]))) {
                string resultStr = (string(1, temp2[i]) + "B");
                resultTemp2.replace(j, 1, resultStr);
            } else {
                resultTemp2.replace(j, 1, "");
                cout << resultTemp2 << "  ";
                break;
            }
        }

        if (i == (temp2.size() - 1)) {
            if (i > j) {
                cout << resultTemp2 << "  ";
                resultTemp2.replace(i, 1, "");
            } else {
                cout << resultTemp2 << "  ";
                resultTemp2.replace(j + 1, 1, "");
            }
        }

        cout << resultTemp2 << "  ";
    }

    // After the breakpoint [first value of innerTerminalSymbol2 of startSymbol in temp2]
    for (int i = 0; i <= posInTemp2; i++) {
        int j = resultTemp2.size() - 1;
        for (; j >= 0; j--) {
            if (contains(nonTerminalSymbols, string(1, resultTemp2[j]))) {
                break;
            }
        }

        if (resultTemp2[j] == 'A') {
            if (contains(productionA, string(1, temp2[i]))) {
                string resultStr = (string(1, temp2[i]) + "A");
                resultTemp2.replace(j, 1, resultStr);
            } else {
                resultTemp2.replace(j, 1, "");
                cout << resultTemp2 << "  ";
                break;
            }
        } else if (resultTemp2[j] == 'B') {
            if (contains(productionB, string(1, temp2[i]))) {
                string resultStr = (string(1, temp2[i]) + "B");
                resultTemp2.replace(j, 1, resultStr);
            } else {
                resultTemp2.replace(j, 1, "");
                cout << resultTemp2 << "  ";
                break;
            }
        }

        if (i == (posInTemp2)) {
            if (i >= j) {
                cout << resultTemp2 << "  ";
                resultTemp2.replace(i + 1, 1, "");
            } else {
                cout << resultTemp2 << "  ";
                resultTemp2.replace(j, 2, "");
            }
        }

        cout << resultTemp2 << "  ";
    }

    return 0;
}
