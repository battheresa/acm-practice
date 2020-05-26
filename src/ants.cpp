#include <iostream>
using namespace std;

int nearestEnd(int l, int n) {
    if (l - n < n)
        return l - n;
    
    return n;
}

int farthestEnd(int l, int n) {
    if (l - n < n)
        return n;
    
    return l - n;
}

int main() {
    int ants[1000][1000], time[1000][2], length, number;
    int cases, i, j, min, max;
    
    cin >> cases;
    
    for (i = 0; i < cases; i++) {
        cin >> length;
        cin >> number;
        
        for (j = 0; j < number; j++)
            cin >> ants[i][j];
        
        min = 0;
        max = 0;
        
        for (j = 0; j < number; j++) {
            if (nearestEnd(length, ants[i][j]) > min)
                min = nearestEnd(length, ants[i][j]);
            
            if (farthestEnd(length, ants[i][j]) > max)
                max = farthestEnd(length, ants[i][j]);
        }
        
        time[i][0] = min;
        time[i][1] = max;
    }
    
    for (i = 0; i < cases; i++)
        cout << time[i][0] << " " << time[i][1] << endl;
    
    return 0;
}
