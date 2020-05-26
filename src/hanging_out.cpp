#include <iostream>
using namespace std;

int main() {
    int max, events, current = 0, added, denied = 0;
    string action;
    
    cin >> max >> events;
    
    for (int i = 0; i < events; i++) {
        cin >> action >> added;
        
        if (action == "enter") {
            if (current + added <= max)
                current += added;
            else
                denied++;
        }
        else if (action == "leave") {
            current -= added;
            
            if (current < 0)
                current = 0;
        }
    }
    
    cout << denied << endl;
    
    return 0; 
}
