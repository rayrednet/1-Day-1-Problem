#include <bits/stdc++.h>
using namespace std;

int romanToInt (string s){
    unordered_map <char, int> romanNumeric = 
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int string_length = s.length();
    for (int i = 1; i<= string_length; i++){
        //check if current number (i-1) less than next number (i)
        if ((i < string_length) && (romanNumeric[s[i-1]] < romanNumeric[s[i]])) {
            result -= romanNumeric[s[i-1]];
        } else {
            result += romanNumeric[s[i-1]];
        }
    }
    return result;
}

int main () {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
}