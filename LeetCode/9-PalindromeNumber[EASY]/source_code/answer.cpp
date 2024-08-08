#include <iostream>

using namespace std;

bool isPalindrome (int x){
    //handle base cases 
    if (x < 0)
        return false;
    if (x < 10)
        return true;

    //initialize variables
    int original = x;
    int reversed = 0;

    //reverse the number
    while (x > 0){
        int digit = x % 10;
        //handling if overflow
        if (reversed > (INT_MAX - digit) / 10) {
                return false; 
            }
        reversed = (reversed * 10) + digit;
        x /= 10;
    }
    return (original == reversed);
}

int main (){
    int x = 1234567899;
    cout << isPalindrome(x) << endl;
}