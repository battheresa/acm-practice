#include <iostream>
#include <cmath>
using namespace std;

double squared(double n) {
    return n * n;
}

int main() {
    int cases, candles;
    double bookX, bookY, lightX, lightY;
    bool lit;
    
    cin >> cases;
    
    for (int i = 0; i < cases; i++) {
        cin >> bookX >> bookY;
        cin >> candles;
        
        lit = false;
        
        for (int j = 0; j < candles; j++) {
            cin >> lightX >> lightY;
            
            double dist = sqrt(squared(bookX - lightX) + squared(bookY - lightY));
            if (dist <= 8.000000)
                lit = true;
        }
        
        if (lit)
            cout << "light a candle" << endl;
        else
            cout << "curse the darkness" << endl;
    }
    
    return 0;
}
