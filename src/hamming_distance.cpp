#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size, input[1000][2], i, j;
    string str;
    
    cin >> size;
    
    for (i = 0; i < size; i++) {
        cin >> input[i][0];
        cin >> input[i][1];
    }
    
    for (i = 0; i < size; i++) {
        str = "";
        
        for (j = 0; j < input[i][0] - input[i][1]; j++)
            str += '0';
        
        for (j = 0; j < input[i][1]; j++)
            str += '1';
        
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
        
        if (i < size - 1)
            cout << endl;
    }
    
    return 0;
}
