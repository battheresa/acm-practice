#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, rela[1000], street[500], output[1000], vito1, vito2, temp[2], i, j, k;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> rela[i];
        
        for (j = 0; j < rela[i]; j++)
            cin >> street[j];
        
        sort(&street[0], &street[j]);
        
        if (rela[i] % 2 == 1) {
            vito1 = street[(rela[i] - 1) / 2];
            output[i] = 0;
        
            for (k = 0; k < rela[i]; k++)
                output[i] += abs(street[k] - vito1);
        }
        else {
            vito1 = street[rela[i] / 2];
            vito2 = street[rela[i] - 2 / 2];
            temp[0] = 0;
            temp[1] = 0;
            
            for (k = 0; k < rela[i]; k++) {
                temp[0] += abs(street[k] - vito1);
                temp[1] += abs(street[k] - vito2);
            }
            
            if (temp[0] > temp[1])
                output[i] = temp[1];
            else
                output[i] = temp[0];
        }
    }
    
    for (i = 0; i < n; i++)
        cout << output[i] << endl;
    
    return 0;
}
