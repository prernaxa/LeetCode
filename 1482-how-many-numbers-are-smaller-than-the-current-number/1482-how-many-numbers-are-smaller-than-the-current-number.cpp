class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
     vector<int> sorted = nums;             
        sort(sorted.begin(), sorted.end());    

        unordered_map<int, int> smallerCount;  
        for (int i = 0; i < sorted.size(); i++) {
            if (smallerCount.find(sorted[i]) == smallerCount.end()) {
                smallerCount[sorted[i]] = i;   
            }
        }

        vector<int> result;
        for (int n : nums) {
            result.push_back(smallerCount[n]);
        }
        return result;
    }
};