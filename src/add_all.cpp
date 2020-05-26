#include <iostream>
#include <queue>
using namespace std;

int main() {
    int length, temp, sum, i;
    priority_queue <int, vector<int>, greater<int>> q;
    queue<int> out, add;
    
    cin >> length;
    
    while (length != 0) {
        for (i = 0; i < length; i++) {
            cin >> temp;
            q.push(temp);
        }

        sum = 0;
        while (!q.empty()) {
            temp = q.top();
            q.pop();
            temp += q.top();
            q.pop();
            
            if (!q.empty())
                q.push(temp);
            
            sum += temp;
        }
        
        out.push(sum);
        cin >> length;
    }
    
    while (!out.empty()) {
        cout << out.front() << endl;
        out.pop();
    }
    
    return 0;
}
