#include <iostream>
using namespace std;

int main() {
    string first;
    int move1, move2;
    
    while (cin >> first) {
        string second(first, first.length() / 2, first.length() / 2);
        first.erase(first.length() / 2, first.length() / 2);
        
        move1 = 0;
        move2 = 0;
        
        for (int i = 0; i < first.length(); i++) {
            move1 += first[i] - 65;
            move2 += second[i] - 65;
        }
        
        while (move1 > 25)
            move1 -= 26;
        
        while (move2 > 25)
            move2 -= 26;
        
        for (int i = 0; i < first.length(); i++) {
            if (first[i] + move1 > 90)
                first[i] = first[i] + move1 - 26;
            else
                first[i] = first[i] + move1;
            
            if (second[i] + move2 > 90)
                second[i] = second[i] + move2 - 26;
            else
                second[i] = second[i] + move2;
        }
        
        for (int i = 0; i < first.length(); i++) {
            if (first[i] + second[i] - 65 > 90)
                first[i] = first[i] + second[i] - 91;
            else
                first[i] = first[i] + second[i] - 65;
        }
        
        cout << first << endl;
    }
    
    return 0;
}
