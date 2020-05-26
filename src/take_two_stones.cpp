#include <iostream>
using namespace std;

int main() {
    long stones;
    
    while (cin >> stones) {
        if (stones % 2 == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    
    return 0;
}
