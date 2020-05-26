#include <iostream>
#include <cmath>
using namespace std;

int map[8][8], pos[8], most[20], n = 0;

void search(int col) {
    int i, j, weight;
    bool pass;
    
    if (col == 8) {
        weight = 0;
        for (i = 0; i < 8; i++)
            weight += map[pos[i]][i];
        
        if (weight > most[n])
            most[n] = weight;
    }
    else {
        for (i = 0; i < 8; i++) {
            pass = true;
            pos[col] = i;
            
            for (j = 0; j < col; j++) {
                if(pos[col] == pos[j] || col - pos[col] == j - pos[j] || col + pos[col] == j + pos[j]) {
                    pass = false;
                    break;
                }
            }
            
            if (pass)
                search(col + 1);
        }
    }
}

int main() {
    int size, i, j, k;
    
    cin >> size;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < 8; j++)
            for (k = 0; k < 8; k++)
                cin >> map[j][k];
    
        most[i] = 0;
        search(0);
        n++;
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < 4 - (int) log10(most[i]); j++)
            cout << " ";
        
        cout << most[i] << endl;
    }
    
    return 0;
}

/*
1
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
 */
