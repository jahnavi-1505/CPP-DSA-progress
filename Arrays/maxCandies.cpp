#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        // Find the maximum number of candies
        for (int i = 0; i < candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }

        vector<bool> res;
        // Check if each kid can have the greatest number of candies
        for (int j = 0; j < candies.size(); j++) {
            if (candies[j] + extraCandies >= maxi)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};

int main() {
    // Example input
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    Solution sol;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    // Output the result
    cout << "Result: ";
    for (bool canHaveMaxCandies : result) {
        cout << (canHaveMaxCandies ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
