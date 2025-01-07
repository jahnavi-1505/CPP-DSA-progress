#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word = "";

        // Extract words from the string
        while (ss >> word)
            words.push_back(word);

        // Reverse the order of the words
        reverse(words.begin(), words.end());

        // Construct the resulting string
        string result = "";
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " "; // Add space between words
            result += words[i];
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input string
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Use getline to handle spaces in the input

    // Reverse the words in the string
    string result = solution.reverseWords(input);

    // Print the result
    cout << "String after reversing words: " << result << endl;

    return 0;
}
