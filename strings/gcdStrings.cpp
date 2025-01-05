#include <iostream>
#include <string>
using namespace std;

int customGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int gcdLength = customGcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution;

    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    string result = solution.gcdOfStrings(str1, str2);

    if (result.empty()) {
        cout << "No common divisor string found." << endl;
    } else {
        cout << "The GCD of the strings is: " << result << endl;
    }

    return 0;
}
