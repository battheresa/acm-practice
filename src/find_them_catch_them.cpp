#include <iostream>
using namespace std;

int set[200002], level[200002];

int find_sets(int x) {
    if (set[x] == x)
        return x;
    
    return set[x] = find_sets(set[x]);
}


void union_sets(int x, int y) {
    x = find_sets(x);
    y = find_sets(y);
    
    if (x != y) {
        if (level[x] < level[y])
            swap(x, y);
        
        set[y] = x;
        
        if (level[x] == level[y])
            level[x]++;
    }
}
 
int main() {
    int test, n, m, a, b;
    char input;
    
    cin >> test;
    
    for (int k = 0; k < test; k++) {
        cin >> n >> m;
        
        for (int i = 0; i <= 2 * n; i++) {
            set[i] = i;
            level[i] = 0;
        }
         
        for (int i = 0; i < m; i++) {
            cin >> input >> a >> b;
            
            switch (input) {
                case 'A':
                    if (set[a] == set[b])
                        cout << "In the same gang." << endl;
                    else if (set[a] == set[b + n])
                        cout << "In different gang." << endl;
                    else
                        cout << "Not sure yet." << endl;
                    break;
                    
                case 'D' :
                    union_sets(a, b + n);
                    union_sets(b, a + n);
                    break;
            }
            
            for (int j = 1; j <= 2 * n; j++)
                cout << set[j] << ", ";
            cout << endl;
        }
    }
    
    return 0;
}
