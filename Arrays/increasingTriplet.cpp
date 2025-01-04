#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_small = INT_MAX;
        int second_small = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first_small)
                first_small = nums[i];
            else if (nums[i] <= second_small)
                second_small = nums[i];
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5}; // Example input
    bool result = solution.increasingTriplet(nums);
    
    cout << "Result: " << (result ? "True" : "False") << endl;
    return 0;
}
