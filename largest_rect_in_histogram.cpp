#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Key Terminologies:
// 1. Histogram: A graphical representation where bars represent data quantities.
// 2. Stack: A linear data structure that follows Last-In-First-Out (LIFO) order.
// 3. Sentinel: An extra value (here, height = 0) added at the end to flush out the remaining bars in the stack.
// 4. Area = Height × Width: Formula used to calculate the rectangular area.

class Solution {
public:
    // Function to compute largest rectangle area in histogram
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);  // Sentinel to flush stack
        stack<int> st;         // Stores indices of bars
        int maxArea = 0;       // Tracks maximum area

        for (int i = 0; i < heights.size(); i++) {
            // While current height is less than the bar at stack top
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width is current index if stack is empty, else difference between current index and new stack top - 1
                int width = st.empty() ? i : i - st.top() - 1;

                // Calculate area and update maxArea if larger
                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            st.push(i); // Push current index
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> histogram = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area: "
         << sol.largestRectangleArea(histogram) << endl; // Expected Output: 10

    return 0;
}
