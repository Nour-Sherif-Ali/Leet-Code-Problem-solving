class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> output;
    deque<int> q; // stores indexes

    int l = 0;

    for (int r = 0; r < nums.size(); r++) {

        // Remove smaller values from the back
        while (!q.empty() && nums[q.back()] < nums[r]) {
            q.pop_back();
        }

        // Add current index
        q.push_back(r);

        // Remove index if it is outside the window
        if (!q.empty() && q.front() < l) {
            q.pop_front();
        }

        // Start adding answers when window size reaches k
        if (r + 1 >= k) {
            output.push_back(nums[q.front()]);
            l++;
        }
    }

    return output;
    
}
};