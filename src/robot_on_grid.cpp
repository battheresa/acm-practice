// TIME LIMIT EXCEEDS

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n, ways;
char map[1000][1000];
bool visited[1000][1000], found;

void search(int r, int c) {
    if (r > n || c > n || map[r][c] == '#')
        return;
    
    if (r == n - 1 && c == n - 1) {
        if (ways + 1 > pow(2, 31) - 1)
            ways -= pow(2, 31) - 1;
        
        ways++;
    }
    
    search(r + 1, c);
    search(r, c + 1);
}

string path;

void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || map[r][c] == '#' || visited[r][c] || found)
        return;
    
    
    if (r == n - 1 && c == n - 1) {
        found = true;
        return;
    }
    
    visited[r][c] = true;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}


int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    
    search(0, 0);
    
    if (ways == 0) {
        found = false;
        dfs(0, 0);
        
        if (found)
            cout << "THE GAME IS A LIE" << endl;
        else
            cout << "INCONCEIVABLE" << endl;
    }
    else
        cout << ways << endl;
     
    return 0;
}
