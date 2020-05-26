#include <iostream>
using namespace std;

int main() {
    int bottles;

    while (cin >> bottles)
        cout << bottles + (bottles / 2) << endl;
    
    return 0;
}


