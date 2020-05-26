#include <iostream>
#include <algorithm>
using namespace std;

int goal, length, arr[15], size = 0;
bool mask[15];
string output[10000];

int check() {
    int temp = 0, i;
    
    for(i = 0; i < length; i++)
        if(mask[i]) {
            temp += arr[i];
            if (temp > goal)
                break;
        }
    
    return temp;
}

void search(int cur, int remain) {
    int i, count = 0;
    
    if (cur == length || remain == 0) {
        if (remain == 0) {
            for (i = 0; i < cur; i++)
                if (mask[i])
                    output[size] += to_string(arr[i]) + "+";
            
            output[size].erase(output[size].length() - 1);
            size++;
        }
        return;
    }
    
    // !(cur > 0 && mask[cur] == mask[cur - 1] && arr[cur] == arr[cur - 1])
    if (cur < 0 || mask[cur] != mask[cur - 1] || arr[cur] != arr[cur - 1]) {
        mask[cur] = true;
        count = check();
        if (count <= goal)
            search(cur + 1, goal - count);
    }
    
    mask[cur] = false;
    count = check();
    if (count <= goal)
        search(cur + 1, goal - count);
}

int main() {
    int i;
    
    cin >> goal;
    cin >> length;
    
    while (length != 0) {
        for (i = 0; i < length; i++)
            cin >> arr[i];
        
        output[size++] = "Sums of " + to_string(goal) + ":";
        
        search(0, goal);
        
        if (output[size - 1][0] == 'S')
            output[size++] = "NONE";
        
        cin >> goal;
        cin >> length;
    }
    
    for (i = 0; i < size; i++)
        cout << output[i] << endl;
    
    return 0;
}
