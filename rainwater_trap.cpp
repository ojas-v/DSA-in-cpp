/*
Terminologies:
- Histogram: A series of vertical bars representing elevation.
- Trapped Water: Water that accumulates between bars where lower bars are bounded by taller bars on both sides.
- Two-pointer Technique: An optimization strategy that uses two indices moving inward from both ends.
- maxL, maxR: Running maximums from left and right sides.
*/

#include <iostream>
#include <vector>
using namespace std;

// RainwaterTrapper class that contains the logic for trapping rainwater
class RainwaterTrapper {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;         // Two pointers from left and right
        int maxL = 0, maxR = 0;       // Max height to the left and right of the current bars
        int ans = 0;                  // Accumulator to store total trapped water

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= maxL) 
                    maxL = height[l];  // Update maxL if current is higher
                else 
                    ans += maxL - height[l]; // Water trapped at l = maxL - height[l]
                ++l;
            } else {
                if (height[r] >= maxR) 
                    maxR = height[r];  // Update maxR if current is higher
                else 
                    ans += maxR - height[r]; // Water trapped at r = maxR - height[r]
                --r;
            }
        }
        return ans;
    }
};

// Main function to test the program
int main() {
    RainwaterTrapper sol;
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1}; // Sample histogram

    int waterTrapped = sol.trap(heights);

    cout << "Total Trapped Rain Water: " << waterTrapped << endl; // Expected: 6

    return 0;
}

