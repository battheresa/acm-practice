#include <iostream>
#include <algorithm>
using namespace std;

int set[30005];
int s[30005];

int find_sets(int v) {
    if (v == set[v])
        return v;
    
    return find_sets(set[v]);
}

int main() {
    int output[10000];
    int test, citizen, pair, p, q;
    
    cin >> test;
    
    for (int k = 0; k < test; k++) {
        cin >> citizen >> pair;
        
        for (int i = 0; i <= citizen; i++) {
            set[i] = i;
            s[i] = 1;
        }
        
        for (int i = 0; i < pair; i++) {
            cin >> p >> q;
            
            p = find_sets(p);
            q = find_sets(q);
            
            if (q != p) {
                set[q] = p;
                s[p] += s[q];
            }
        }
        
        output[k] = *max_element(s, s + citizen + 1);
    }
    
    for (int k = 0; k < test; k++)
        cout << output[k] << endl;
    
    return 0;
}
