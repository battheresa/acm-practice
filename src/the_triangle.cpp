#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int input[105][105], sum[105], row;
    
    cin >> row;
    
    for (int i = 0; i < row; i++)
        sum[i] = 0;
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j <= i; j++)
            cin >> input[i][j];
    
    for (int i = row - 1; i >= 0; i--)
        for (int j = 0; j <= i; j++) 
            sum[j] = input[i][j] + max(sum[j], sum[j + 1]);
            
    cout << sum[0] << endl;
    return 0;
}
