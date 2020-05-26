#include <iostream>
using namespace std;

int main() {
    int size = 0, correct = 0, wrong = 0, n = 0, temp, i, j;
    string secret[1000], test[1000];
    int word[26], guessed[26];
    
    cin >> temp;
    
    while (temp != -1) {
        cin >> secret[size];
        cin >> test[size];
        cin >> temp;
        size++;
    }
    
    for (i = 0; i < size; i++) {
        correct = 0;
        wrong = 0;
        n = 0;
        
        for (j = 0; j < 26; j++) {
            word[j] = 0;
            guessed[j] = 0;
        }
        
        for (j = 0; j < secret[i].length(); j++) {
            if (word[secret[i][j] - 'a'] == 0) {
                word[secret[i][j] - 'a'] = 1;
                n++;
            }
        }
        
        for (j = 0; j < test[i].length(); j++) {
            if (wrong < 7 && guessed[test[i][j] - 'a'] == 0) {
                if (word[test[i][j] - 'a'] == 1)
                    correct++;
                else
                    wrong++;
                
                guessed[test[i][j] - 'a'] = 1;
            }
        }
        
        cout << "Round " << i + 1 << endl;

        if (correct == n)
            cout << "You win." << endl;
        else if (wrong >= 7)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
    }
    
    return 0;
}


/*
 #include <set>
 #include <iterator>

 
 set<char> word, guessed;
 
 
 word.clear();
 guessed.clear();
 correct = 0;
 wrong = 0;
 
 for (j = 0; j < secret[i].length(); j++)
 word.insert(secret[i][j]);
 
 for (j = 0; j < test[i].length(); j++) {
 if (guessed.count(test[i][j]) == 0) {
 if (word.count(test[i][j]) == 1)
 correct++;
 else
 wrong++;
 
 guessed.insert(test[i][j]);
 }
 
 if (correct == word.size() || wrong == 7)
 break;
 }
 */
