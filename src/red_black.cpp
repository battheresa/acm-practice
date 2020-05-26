#include <iostream>
#include <string>
using namespace std;

int width, height, visit[20][20];
char map[20][20];

int dfs(int r, int c, int count) {
    if (r < 0 || r >= height || c < 0 || c >= width || visit[r][c] == 1 || map[r][c] == '#')
        return count;
    
    visit[r][c] = 1;
    count += 1;
    
    count = dfs(r, c - 1, count);
    count = dfs(r, c + 1, count);
    count = dfs(r - 1, c, count);
    count = dfs(r + 1, c, count);
    
    return count;
}

int main() {
    int output[1000], pos[2], size = 0, i, j;
    
    cin >> width;
    cin >> height;
    
    while (width != 0 && height != 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                cin >> map[i][j];
                visit[i][j] = 0;
                
                if (map[i][j] == '@') {
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
        
        output[size] = dfs(pos[0], pos[1], 0);
        size++;
        
        cin >> width;
        cin >> height;
    }
    
    for (i = 0; i < size; i++)
        cout << output[i] << endl;
    
    return 0;
}
