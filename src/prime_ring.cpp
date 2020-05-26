#include <iostream>
#include <algorithm>
using namespace std;

int length, arr[16];
bool prime[32];

void search(int n) {
    int i, j;
    bool pass, in;
    
    if (n == length) {
        if (prime[arr[0] + arr[length - 1]]) {
            for (i = 0; i < length; i++) {
                cout << arr[i];
                if (i != length - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    else {
        for (i = 1; i <= length; i++) {
            pass = true;
            arr[n] = i;
            
            for (j = 0; j < n; j++) {
                in = find(arr, arr + n, i) != arr + n;
                
                if(in || !prime[arr[n - 1] + arr[n]]) {
                    pass = false;
                    break;
                }
            }
            if (pass)
                search(n + 1);
        }
    }
}

int main() {
    int size = 1, i, j;
    
    for (i = 0; i < sizeof(prime); i++)
        prime[i] = true;
    
    for (i = 2; i < sizeof(prime); i++)
        for (j = i * 2; j < sizeof(prime); j += i)
            prime[j] = false;
    
    while (cin >> length) {
        cout << "\nCase " << size << ":" << endl;
        size++;
        
        arr[0] = 1;
        search(1);
        
        cout << endl;
    }
    
    return 0;
}
