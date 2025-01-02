#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array to perform binary search
        sort(potions.begin(), potions.end());
        
        vector<int> res;
        for (int k : spells) {
            int low = 0, high = potions.size() - 1;
            int mid;

            // Perform binary search to find the smallest potion
            while (low <= high) {
                mid = low + (high - low) / 2;
                if ((long long)potions[mid] * k >= success)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // All potions from `low` to the end of the array are successful
            res.push_back(potions.size() - low);
        }

        return res;
    }
};

int main() {
    // Example input
    vector<int> spells = {10, 20, 30};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 50;

    Solution solution;
    vector<int> result = solution.successfulPairs(spells, potions, success);

    // Output the result
    cout << "Successful pairs: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
