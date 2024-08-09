#include <bits/stdc++.h>
using namespace std;

int romanToInt (string s) {
    unordered_map <char, int> romanInt = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.length();
    
    for (int i = 1; i <= n; i++){
        if ((i < n) && (romanInt[s[i-1]] < romanInt[s[i]])){
            result -= romanInt[s[i-1]];
        } else {
            result += romanInt[s[i-1]];
        }
    };

    return result;
}

int main () {
    string s = "II";
    cout << romanToInt(s) << endl;
}