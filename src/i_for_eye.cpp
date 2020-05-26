#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dict[20][2] = {
    {"at", "@"},
    {"and", "&"},
    {"are", "r"},
    {"one", "1"},
    {"won", "1"},
    {"too", "2"},
    {"to", "2"},
    {"two", "2"},
    {"for", "4"},
    {"four", "4"},
    {"bee", "b"},
    {"bea", "b"},
    {"be", "b"},
    {"see", "c"},
    {"sea", "c"},
    {"eye", "i"},
    {"owe", "o"},
    {"oh", "o"},
    {"you", "u"},
    {"why", "y"}};

int main() {
    int cases;
    string input, output[1000];
    
    cin >> cases;
    cin.ignore();
    
    for (int i = 0; i < cases; i++) {
        getline(cin, input, '\n');
        
        for (int start = 0; start < (int) input.length(); start++) {
            for (auto pair : dict) {
                string word = input.substr(start, (int) pair[0].length());
                bool up = false;
                
                if (word[0] >= 65 && word[0] <= 90) {
                    word[0] = tolower(word[0]);
                    up = true;
                }
                
                if (word == pair[0]) {
                    input.replace(start, (int) pair[0].length(), pair[1]);
                    
                    if (up)
                        input[start] = toupper(pair[1][0]);
                    
                    break;
                }
            }
        }
        
        output[i] = input;
    }
    
    for (int i = 0; i < cases; i++)
        cout << output[i] << endl;
    
    return 0;
}
