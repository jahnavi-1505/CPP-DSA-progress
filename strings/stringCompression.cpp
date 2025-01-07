#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            // Count the occurrences of the current character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Add the character to the compressed array
            chars[idx++] = ch;

            // If count is greater than 1, append the count as characters
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--; // Adjust for the outer loop increment
        }

        // Resize the vector to the new size
        chars.resize(idx);
        return idx;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input vector
    vector<char> chars;
    string input;
    cout << "Enter characters without spaces (e.g., aaabbccc): ";
    cin >> input;

    // Fill the vector with input characters
    for (char ch : input) {
        chars.push_back(ch);
    }

    // Compress the vector
    int newLength = solution.compress(chars);

    // Output the compressed characters
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}
