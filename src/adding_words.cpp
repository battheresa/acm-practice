#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <iterator>
using namespace std;

int main() {
    map<string, int> dictW;
    map<int, string> dictV;
    string command;
    
    while (cin >> command) {
        if (command == "def") {
            string word;
            int value;
        
            cin >> word;
            cin >> value;
        
            if (dictW.count(word) != 0) {
                dictV.erase(dictW.at(word));
                dictW.erase(word);
            }
        
            dictW.insert({word, value});
            dictV.insert({value, word});
        }
        else if (command == "calc") {
            int i = 0, j = 0, sum = 0;
            char sign = '*';
            string sent, word;
            bool found = true;
            
            cin.ignore();
            getline(cin, sent, '\n');
            
            while (i < sent.length()) {
                j = (int) sent.find(" ", i);
                word = sent.substr(i, j - i);
                i = j + 1;
                
                if (dictW.count(word) != 0) {
                    if (sign == '*' || sign == '+')
                        sum += dictW.at(word);
                    else if (sign == '-')
                        sum -= dictW.at(word);
                    
                    sign = sent[i];
                    i += 2;
                }
                else {
                    cout << sent << " unknown" << endl;
                    found = false;
                    break;
                }
            }
            
            if (found) {
                if (dictV.count(sum) != 0)
                    cout << sent << " " << dictV.at(sum) << endl;
                else
                    cout << sent << " unknown" << endl;
            }
        }
        else if (command == "clear") {
            dictW.clear();
            dictV.clear();
        }
    }
    
    return 0;
}
