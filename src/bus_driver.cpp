#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int input[3], morn[1000], even[1000], pay[1000], n = 0, first, last, i;
    
    cin >> input[0]; // n
    cin >> input[1]; // d
    cin >> input[2]; // r
    
    while (input[0] != 0 || input[1] != 0 || input[2] != 0) {
        for (i = 0; i < input[0]; i++)
            cin >> morn[i];
        
        for (i = 0; i < input[0]; i++)
            cin >> even[i];
        
        sort(morn, morn + input[0]);
        sort(even, even + input[0]);
        
        last = input[0] - 1;
        pay[n] = 0;
        
        for (first = 0; first < input[0]; first++) {
            if (morn[first] + even[last] > input[1])
                pay[n] += (morn[first] + even[last] - input[1]) * input[2];
            
            last--;
        }
        
        n++;
        cin >> input[0]; // n
        cin >> input[1]; // d
        cin >> input[2]; // r
    }
    
    for (i = 0; i < n; i++)
        cout << pay[i] << endl;
    
    return 0;
}
