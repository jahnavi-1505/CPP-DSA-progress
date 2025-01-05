#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        for (int i = 0; i < max(m, n); i++) {
            if (i < m)
                result.push_back(word1[i]);
            if (i < n)
                result.push_back(word2[i]);
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test cases
    string word1, word2;

    // Example 1
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    string result = solution.mergeAlternately(word1, word2);

    // Print the result
    cout << "Merged string: " << result << endl;

    return 0;
}
