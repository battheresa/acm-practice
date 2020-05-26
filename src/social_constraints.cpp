#include <iostream>
#include <algorithm>
using namespace std;

int findIndex(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    
    return -1;
}

int main() {
    int input[2], con[1000][3], perm[1000], size = 0, total[1000], i, j, v1, v2;
    bool good = true;
    
    cin >> input[0];
    cin >> input[1];
    
    while (input[0] != 0 || input[1] != 0) {
        for (i = 0; i < input[1]; i++) {
            cin >> con[i][0];
            cin >> con[i][1];
            cin >> con[i][2];
        }
        
        total[size] = 0;
        
        for (j = 0; j < input[0]; j++)
            perm[j] = j;
        
        do {
            good = true;
            
            for (j = 0; j < input[1]; j++) {
                if (good) {
                    v1 = findIndex(perm, input[0], con[j][0]);
                    v2 = findIndex(perm, input[0], con[j][1]);
                    
                    if ((con[j][2] < 0 && abs(v1 - v2) < abs(con[j][2])) ||
                        (con[j][2] > 0 && abs(v1 - v2) > con[j][2]))
                        good = false;
                }
            }
            
            if (good)
                total[size]++;
        } while (next_permutation(perm, perm + input[0]));
        
        size++;
        cin >> input[0];
        cin >> input[1];
    }
    
    for (i = 0; i < size; i++)
        cout << total[i] << endl;
    
    return 0;
}
