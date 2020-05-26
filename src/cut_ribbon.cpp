#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[3], cuts[4005];
    
    cin >> n >> a[0] >> a[1] >> a[2];
    memset(cuts, -100, sizeof(cuts));
    cuts[0] = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            if (i >= a[j])
                cuts[i] = max(cuts[i], cuts[i - a[j]] + 1);
    
    cout << cuts[n] << endl;
    
    return 0;
}

// try recursion
