#include <iostream>
using namespace std;

int main() {
    string jon;
    string doctor;
    
    cin >> jon >> doctor;
    
    if (jon.length() >= doctor.length())
        cout << "go" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
