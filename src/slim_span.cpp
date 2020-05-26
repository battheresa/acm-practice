#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int v, e, a, b, w[105], output[105];
    int gap, min = 1000000, count = 0;
    
    do {
        cin >> v >> e;
        memset(w, 0, sizeof(w));
        
        for (int i = 0; i < e; i++)
            cin >> a >> b >> w[i];
        
        sort(w, w + e);
        gap = 0;
        min = 1000000;
        
        for (int i = 0; i < e - (v - 2); i++) {
            gap = w[i + (v - 2)] - w[i];
        
            if (gap < min)
                min = gap;
        }
            
        if  (min == 1000000)
            min = -1;
        
        output[count++] = min;
    } while (v != 0 || e != 0);
    
    for (int i = 0; i < count - 1; i++)
        cout << output[i] << endl;
    
    
    return 0;
}
