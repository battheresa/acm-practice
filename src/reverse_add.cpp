#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

long reverse(long n, int length) {
    long rev = 0;
    
    for (int i = length; i >= 0; i--) {
        rev += (n % 10) * pow(10, i);
        n /= 10;
    }
    
    return rev;
}

bool isPalindrome(string n) {
    bool pal = true;
    
    for (int i = 0; i < n.length() / 2; i++)
        if (n[i] != n[n.length() - 1 - i])
            pal = false;
    
    return pal;
}

int main() {
    long num[100], reve;
    int size, count, i;
    
    cin >> size;
    
    for (i = 0; i < size; i++)
        cin >> num[i];
    
    for (i = 0; i < size; i++) {
        count = 0;
        
        do {
            reve = reverse(num[i], ((int) log10(num[i])));
            num[i] = num[i] + reve;
            count++;
        } while (!isPalindrome(to_string(num[i])));
        
        cout << count << " " << num[i] << endl;
    }
    
    return 0;
}
