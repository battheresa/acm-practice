#include <iostream>
#include <set>
#include <iterator>
using namespace std;

bool valid(int x , int y) {
    if (x / 100000 > 0 || (x / 1000 <= 0 && y / 1000 <= 0))
        return false;
    
    set<int> checklist;
    int i;
    
    while (x > 0 || y > 0) {
        checklist.insert(x % 10);
        x /= 10;
        checklist.insert(y % 10);
        y /= 10;
    }
    
    if (checklist.size() != 10)
        return false;
    
    for (i = 0; i < 10; i++)
        if (checklist.count(i) == 0)
            return false;
    
    return true;
}

int main() {
    string bstr;
    int input[1000], temp, size = 0, i = 0, a, b;
    bool noSol;
    
    cin >> temp;
    
    while (temp != 0) {
        input[size] = temp;
        size++;
        cin >> temp;
    }
    
    for (i = 0; i < size; i++) {
        noSol = true;
        b = 1234;
        
        while (b <= 98765 / input[i]) {
            a = input[i] * b;
            
            if (valid(a, b)) {
                noSol = false;
                bstr = to_string(b);
                
                if (bstr.length() == 4)
                    bstr.insert(0, "0");
                
                cout << to_string(a) + " / " + bstr + " = " + to_string(input[i]) << endl;
            }
            b++;
        }
        
        if (noSol)
            cout << "There are no solutions for " + to_string(input[i]) + "." << endl;

        cout << endl;
    }
    
    return 0;
}

