#include <iostream>
#include <cstring>
using namespace std;

int matrix[1000][1000];

int dfs(int n, int v, int count, bool vis[]) {
    vis[v] = true;
    
    for (int u = 0; u < n; u++) {
        if (matrix[v][u] == 1 && !vis[u]) {
            count++;
            count = dfs(n, u, count, vis);
        }
    }
    
    return count;
}

int main() {
    int output[1000], nodes, link, temp, most, vert, size = 0, i, j;
    bool visited[1000];
    
    cin >> nodes;
    
    while (nodes != 0) {
        for (i = 0; i < 1000; i++)
            for (j = 0; j < 1000; j++)
                matrix[i][j] = 0;
        
        for (i = 0; i < nodes; i++) {
            cin >> link;
            
            for (j = 0; j < link; j++) {
                cin >> temp;
                matrix[i][temp - 1] = 1;
            }
        }
        
        most = -1;
        vert = -1;
        
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++)
                visited[j] = false;
            
            temp = dfs(nodes, i, 0, visited);
            
            if (temp > most) {
                most = temp;
                vert = i + 1;
            }
        }
        
        output[size] = vert;
        size++;
        
        cin >> nodes;
    }
    
    for (i = 0; i < size; i++)
        cout << output[i] << endl;
    
    return 0;
}
