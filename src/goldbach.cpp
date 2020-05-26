#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    bool prime[1000000], exist;
    int num[1000], size = 0, i, j;
    
    do {
        cin >> num[size];
        size++;
    } while(num[size - 1] != 0);
    
    // SIEVE OF ERATOSTHENES
    for (i = 0; i < sizeof(prime); i++)
        prime[i] = true;
    
    for (i = 2; i < sizeof(prime); i++)
        for (j = i * 2; j < sizeof(prime); j += i)
            prime[j] = false;
    
    // CALCULATION
    for (i = 0; i < size - 1; i++) {
        exist = false;
        
        for (j = 2; j <= num[i]; j++)
            if (prime[j] && prime[num[i] - j]) {
                cout << num[i] << " = " << j << " + " << num[i] - j << endl;
                break;
            }
        
        if (!exist)
            cout << "Goldbach's conjecture is wrong." << endl;
    }
    
    return 0;
}
