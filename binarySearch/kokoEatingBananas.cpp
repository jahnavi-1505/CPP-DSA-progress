#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // For INT_MIN

using namespace std;

class Solution {
public:
    long long calc(vector<int>& piles, int h) {
        long long totalH = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)piles[i] / (double)h);
        }
        return totalH;
    }

    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calc(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    // Input example
    vector<int> piles = {3, 6, 7, 11}; // Example piles
    int h = 8;                         // Example number of hours

    Solution solution;
    int result = solution.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
