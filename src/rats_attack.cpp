#include <iostream>
using namespace std;

int main() {
    int n, radius, rats, data[20000][3], map[1025][1025], max[1000][3], i, j, r, c;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> radius;
        cin >> rats;
        
        max[i][0] = 0;
        
        for (r = 0; r < 1025; r++)
            for (c = 0; c < 1025; c++)
                map[r][c] = 0;
        
        for (j = 0; j < rats; j++) {
            cin >> data[j][0];
            cin >> data[j][1];
            cin >> data[j][2];
        }
        
        for (j = 0; j < rats; j++) {
            for (r = data[j][0] - radius; r <= data[j][0] + radius; r++) {
                for (c = data[j][1] - radius; c <= data[j][1] + radius; c++) {
                    if (r >= 0 && r <= 1024 && c >= 0 && c <= 1024) {
                        map[r][c] += data[j][2];
                        
                        if (map[r][c] > max[i][0]) {
                            max[i][0] = map[r][c];
                            max[i][1] = r;
                            max[i][2] = c;
                        }
                    }
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        cout << max[i][1] << " " << max[i][2] << " " << max[i][0] << endl;
    }
    
    return 0;
}
