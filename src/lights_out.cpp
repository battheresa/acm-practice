#include <iostream>
using namespace std;

void print(int n, int arr[][6]) {
    cout << "PUZZLE #" << n + 1 << endl;
        
    for (int j = n * 5; j < (n * 5) + 5; j++) {
        cout << arr[j][0] << " ";
        cout << arr[j][1] << " ";
        cout << arr[j][2] << " ";
        cout << arr[j][3] << " ";
        cout << arr[j][4] << " ";
        cout << arr[j][5] << endl;
    }
}


void change(int arr[5][6], int r, int c) {
    arr[r][c] = !arr[r][c];
    
    if (c - 1 >= 0)
        arr[r][c - 1] = !arr[r][c - 1];
    
    if (c + 1 <= 5)
        arr[r][c + 1] = !arr[r][c + 1];
    
    if (r - 1 >= 0)
        arr[r - 1][c] = !arr[r - 1][c];
    
    if (r + 1 <= 4)
        arr[r + 1][c] = !arr[r + 1][c];
}

int main() {
    int input[1000][6], press[1000][6], temp[5][6]; // 0: lights off + not press, 1: lights on + to press
    int size, i, j, k, l;
    bool done = true;
    
    int start[][6] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 1, 1},
                      {0, 0, 0, 1, 1, 1},
                      {0, 0, 1, 1, 1, 1},
                      {0, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1}};
    
    cin >> size;
    
    for (i = 0; i < size * 5; i++) {
        cin >> input[i][0];
        cin >> input[i][1];
        cin >> input[i][2];
        cin >> input[i][3];
        cin >> input[i][4];
        cin >> input[i][5];
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < 7; j++) {
            // RESET PRESSED
            for (k = 0; k < 6; k++)
                press[0][k] = start[j][k];
            
            // RESET TEMP
            for (k = 0; k < 5; k++)
                for (l = 0; l < 6; l++)
                    temp[k][l] = input[k][l];
            
            // LOOP THOUGHT EACH PERMUTATION
            do {
                done = true;
                
                // FOR EACH ROW
                for (k = 0; k < 5; k++) {
                    // FOR EACH COLUME IN PRESS, IF IS SHOULD BE PRESS --> CHANGE TEMP MAP
                    for (l = 0; l < 6; l++)
                        if (press[k][l] == 1)
                            change(temp, k, l);
                    
                    // UPDATE NEXT LINE OF PRESSED TO CURRENT LIGHTS ON
                    if (k + 1 < 5)
                        for (l = 0; l < 6; l++)
                            press[k + 1][l] = temp[k][l];
                }
                
                // CHECK IF LAST ROW ARE ALL TURNED OFF
                for (k = 0; k < 6; k++)
                    if (temp[4][k] == 1)
                        done = false;
                
                if (done)
                    break;
            } while (next_permutation(&press[0][0], &press[0][0] + 6));
            
            if (done)
                break;
        }
    }
    
    cout << "\nFINAL OUTPUT" << endl;
    print(0, temp);
    print(0, press);
    
    return 0;
}
