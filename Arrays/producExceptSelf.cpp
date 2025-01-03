#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int left = 1;
        // Calculate the product of elements to the left of each index
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        // Calculate the product of elements to the right of each index
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    // Output the result
    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
