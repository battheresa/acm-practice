#include <iostream>
#include <map>
using namespace std;

// TIME LIMIT EXCEEDS

const int MAXN = 50004;
const int MAXK = 1000004;

int main() {
    int n, m, k, start, end, couple, men[MAXN], women[MAXN], output[MAXN];
    int *freqM = new int[MAXK], *freqW = new int[MAXK];
    
    cin >> n;
    cin >> m;
    cin >> k;
    
    for (int i = 0; i < n; i++)
        cin >> men[i];
    
    for (int i = 0; i < n; i++)
        cin >> women[i];
    
    for (int i = 0; i < m; i++) {
        cin >> start;
        cin >> end;
        
        memset(freqM, 0, MAXK);
        memset(freqW, 0, MAXK);
        
        while (start <= end) {
            freqM[men[start]]++;
            freqW[women[start]]++;
            start++;
        }
        
        couple = 0;
        for (int j = 0; j < MAXK; j++) {
            if (freqM[j] >= freqW[j])
                couple += freqW[j];
            else
                couple += freqM[j];
        }
        
        output[i] = couple;
        
        for (int i = 0; i < MAXK; i++) {
            freqM[i] = 0;
            freqW[i] = 0;
        }
    }
    
    for (int i = 0; i < m; i++)
        cout << output[i] << endl;
    
    return 0;
}
