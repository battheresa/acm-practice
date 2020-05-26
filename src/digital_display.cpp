#include <iostream>
using namespace std;

int width = 5, midW = 2, height = 7, midH = 3, length = 4, num[4];

void repeat(string *str, int n, char c) {
    for (int i = 0; i < n; i++)
        *str += c;
}

void horizontal(string *str, string s, string check) {
    for (int k = 0; k < length; k++) {
        s[num[k]] == ' ' && check[num[k]] == ' ' ? *str += " " : *str += "+";
        repeat(str, width - 2, s[num[k]]);
        k == length - 1 ? *str += "+" : *str += "+  ";
        k == 1 ? *str += "   ": *str += "";
    }
}

void vertical(string *str, string s1, string s2, bool dot) {
    for (int k = 0; k < length; k++) {
        *str += s1[num[k]];
        repeat(str, width - 2, ' ');
        *str += s2[num[k]];
        k == length - 1 ? *str += "" : *str += "  ";
        k == 1 ? (dot ? *str += "o  " : *str += "   ") : *str += "";
    }
}

int main() {
    string input, output[5000], temp;
    string n1 = "- -- -----";
    string n2 = "|   ||| ||";
    string n3 = "|||||  |||";
    string n4 = "  ----- --";
    string n5 = "| |   | | ";
    string n6 = "|| |||||||";
    string n7 = "- -- -- --";
    int size = 0;
    
    while (cin >> input) {
        if (input == "end") {
            output[size++] = input;
            break;
        }
        
        num[0] = input[0] - '0';
        num[1] = input[1] - '0';
        num[2] = input[3] - '0';
        num[3] = input[4] - '0';
        
        temp = "";
        for (int i = 0; i < height; i++) {
            if (i == 0)
                horizontal(&temp, n1, n2);
            else if (i == 1)
                vertical(&temp, n2, n3, false);
            else if (i == 2)
                vertical(&temp, n2, n3, true);
            else if (i == 3)
                horizontal(&temp, n4, n5);
            else if (i == 4)
                vertical(&temp, n5, n6, true);
            else if (i == 5)
                vertical(&temp, n5, n6, false);
            else if (i == 6)
                horizontal(&temp, n7, n5);
            
            temp += "\n";
        }
        
        output[size++] = temp + "\n";
    }
    
    for (int i = 0; i < size; i++)
        cout << output[i] << endl;
    
    return 0;
}
