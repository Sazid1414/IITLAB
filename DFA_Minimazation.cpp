#include<bits/stdc++.h>
using namespace std;

int minimizationMatrix[10][10];
int dfaMatrix[10][10];
int finalStateIndex, stateCount;

int getIndex(char ch, char *statesArray) {
    for (int k = 0; k < 8; k++) {
        if (statesArray[k] == ch) {
            return k;
        }
    }
    return -1;
}

int minimize(int ch1, int ch2, int i, int j, int k) {
    if (minimizationMatrix[i][j] <= 1) return minimizationMatrix[i][j];
    if (k == stateCount) return 0;
    if ((dfaMatrix[i][0] == finalStateIndex && dfaMatrix[j][0] == finalStateIndex) ||
        (dfaMatrix[i][1] == finalStateIndex && dfaMatrix[j][1] == finalStateIndex)) {
        minimizationMatrix[ch1][ch2] = 1;
        return 1;
    } else if ((dfaMatrix[i][0] != finalStateIndex && dfaMatrix[j][0] != finalStateIndex) ||
               (dfaMatrix[i][1] != finalStateIndex && dfaMatrix[j][1] != finalStateIndex)) {
        k++;
        if ((dfaMatrix[i][1] != finalStateIndex && dfaMatrix[j][1] != finalStateIndex) &&
            (minimizationMatrix[ch1][ch2] != 1 || minimizationMatrix[ch1][ch2] != 0)) {
            minimizationMatrix[ch1][ch2] = minimize(ch1, ch2, dfaMatrix[ch1][1], dfaMatrix[ch2][1], k);
        }
        if ((dfaMatrix[i][0] != finalStateIndex && dfaMatrix[j][0] != finalStateIndex)) {
            minimizationMatrix[ch1][ch2] = minimize(ch1, ch2, dfaMatrix[i][0], dfaMatrix[j][0], k);
        }
    } else {
        minimizationMatrix[ch1][ch2] = 0;
    }
    return minimizationMatrix[ch1][ch2];
}

int main() {
    int alphabetSize, check = 0;
    char initialState, finalState, temp;
    
    cout << "Enter the number of states: ";
    cin >> stateCount;
    char statesArray[stateCount];
    bool reachableStates[stateCount];
    
    cout << "Enter the states:\n";
    for (int i = 0; i < stateCount; i++) {
        cin >> statesArray[i];
        reachableStates[i] = false;
    }
    
    cout << "Enter the number of elements in the alphabet: ";
    cin >> alphabetSize;
    char alphabet[alphabetSize];
    
    cout << "Enter the alphabet elements: ";
    for (int i = 0; i < alphabetSize; i++) {
        cin >> alphabet[i];
    }

    cout << "Enter the transitions:\n";
    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < alphabetSize; j++) {
            cout << "From " << statesArray[i] << " by " << alphabet[j] << " : ";
            cin >> temp;
            dfaMatrix[i][j] = getIndex(temp, statesArray);
        }
    }

    cout << "\nTransitions: " << endl;
    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < alphabetSize; j++) {
            cout << "From " << statesArray[i] << " by " << alphabet[j] << " : ";
            cout << statesArray[dfaMatrix[i][j]] << endl;
        }
    }

    cout << "Enter the initial state: ";
    cin >> initialState;
    cout << "Enter the final state: ";
    cin >> finalState;

    finalStateIndex = getIndex(finalState, statesArray);

    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < stateCount; j++) {
            if (i == j) minimizationMatrix[i][j] = 1;
            else if (i == finalStateIndex || j == finalStateIndex) {
                minimizationMatrix[i][j] = 0;
            } else {
                minimizationMatrix[i][j] = 5;
            }
        }
    }

    for (int i = 0; i < stateCount; i++) {
        cout << statesArray[i] << "  ";
        for (int j = 0; j <= i; j++) {
            cout << minimizationMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << " ";
    for (int i = 0; i < stateCount; i++) {
        cout << "  " << statesArray[i];
    }

    int check1, check2;

    for (int i = 0; i < stateCount; i++) {
        for (int k, j = 0; j < i; j++) {
            if (minimizationMatrix[i][j]) {
                minimizationMatrix[i][j] = minimize(i, j, i, j, 0);
            }
        }
    }

    for (int i = 0; i < stateCount; i++) {
        cout << statesArray[i] << "  ";
        for (int j = 0; j <= i; j++) {
            cout << minimizationMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << " ";
    for (int i = 0; i < stateCount; i++) {
        cout << "  " << statesArray[i];
    }

    return 0;
}
