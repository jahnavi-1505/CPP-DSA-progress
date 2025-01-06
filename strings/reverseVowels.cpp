#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            // Move the left pointer to the next vowel
            while (vowels.find(s[left]) == vowels.end() && left < right) {
                left++;
            }
            // Move the right pointer to the previous vowel
            while (vowels.find(s[right]) == vowels.end() && left < right) {
                right--;
            }

            // Swap the vowels
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input string
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Use getline to handle spaces in the input

    // Reverse the vowels in the string
    string result = solution.reverseVowels(input);

    // Print the result
    cout << "String after reversing vowels: " << result << endl;

    return 0;
}
