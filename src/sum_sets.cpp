#include <iostream>
#include <algorithm>
using namespace std;

int findD (int arr[], int n) {
    int a, b, c, d;
    
    if (n == 1)
        return arr[0];
    
    for (d = n - 1; d >= 0; d--) {
        for (a = 0; a < n; a++) {
            if (n == 2) {
                if (a != d && arr[a] == arr[d])
                    return arr[d];
            }
            else {
                for (b = a + 1; b < n; b++) {
                    if (n == 3) {
                        if (a != b && b != d && a != d)
                            if (arr[a] + arr[b] == arr[d])
                                return arr[d];
                    }
                    else {
                        for (c = b + 1; c < n; c++)
                            if (a != b && a != c && a != d && b != c && b != d && c != d)
                                if ( arr[a] + arr[b] + arr[c] == arr[d])
                                    return arr[d];
                    }
                }
            }
        }
    }
    
    return 536870912;
}



int main() {
    string output[1000];
    int input[1000], size = 0, temp, i, x;
    
    cin >> temp;
    
    while (temp != 0) {
        for (i = 0; i < temp; i++)
            cin >> input[i];
        
        sort(input, input + temp);
        
        x = findD(input, temp);
        if (x == 536870912)
            output[size] = "no solution";
        else
            output[size] = to_string(x);
        
        size++;
        cin >> temp;
    }
    
    for (i = 0; i < size; i++)
        cout << output[i] << endl;
    
    return 0;
}
