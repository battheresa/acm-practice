#include <iostream>
#include <queue>
using namespace std;

int cow, dist[10000];
bool visited[10000], found = false;

int bfs(int cur) {
    queue<int> q;
    q.push(cur);
    
    visited[cur] = true;
    dist[cur] = 1;
    
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        
        if (cur == cow)
            break;
        else {
            if (visited[cur + 1] == false) {
                visited[cur + 1] = true;
                dist[cur + 1] = dist[cur] + 1;
                q.push(cur + 1);
            }
            if (visited[cur - 1] == false) {
                visited[cur - 1] = true;
                dist[cur - 1] = dist[cur] + 1;
                q.push(cur - 1);
            }
            if (visited[cur * 2] == false) {
                visited[cur * 2] = true;
                dist[cur * 2] = dist[cur] + 1;
                q.push(cur * 2);
            }
        }
    }
    
    return dist[cur];
}

int main() {
    int man, i;
    
    while (cin >> man) {
        cin >> cow;
        
        for (i = 0; i < 10000; i++) {
            visited[i] = false;
            dist[i] = 0;
        }
        
        cout << bfs(man) - 1 << endl;
    }
        
    return 0;
}
