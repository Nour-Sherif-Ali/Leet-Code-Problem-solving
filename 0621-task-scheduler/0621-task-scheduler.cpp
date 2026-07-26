class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);

        // Count each task
        for (char task : tasks) {
            frequency[task - 'A']++;
        }

        
        int maxFrequency = *max_element(
            frequency.begin(),
            frequency.end()
        );

        
        int maxFrequencyTasks = 0;

        for (int count : frequency) {
            if (count == maxFrequency) {
                maxFrequencyTasks++;
            }
        }

        int calculatedLength =
            (maxFrequency - 1) * (n + 1)
            + maxFrequencyTasks;

        return max(
            static_cast<int>(tasks.size()),
            calculatedLength
        );
    }
};