#include <iostream>
using namespace std;

// Forward declaration of guess API
int guess(int num);

// Global variable to hold the picked number
int pickedNumber;

// Implementation of the guess API
int guess(int num) {
    if (num > pickedNumber) return -1; // num is too high
    if (num < pickedNumber) return 1;  // num is too low
    return 0;                          // num is correct
}

class Solution {
public:
    int guessNumber(int n) {
        int start = 1; 
        int high = n;

        while (start <= high) {
            int mid = start + (high - start) / 2; 
            int res = guess(mid);
            if (res == 0) return mid; // Correct guess
            else if (res == -1) high = mid - 1; // Adjust the upper bound
            else start = mid + 1; // Adjust the lower bound
        }

        return -1;
    }
};

int main() {
    // Set the picked number
    pickedNumber = 6; // Change this value to test with different picked numbers

    Solution solution;
    int n = 10; // Maximum number to guess
    int result = solution.guessNumber(n);

    cout << "The picked number is: " << result << endl;

    return 0;
}
