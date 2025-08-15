class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        /*
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] && i<j){
                    count++;
                 }
            }
        }
        return count;
        */

    unordered_map<int, int> freq;
    int count = 0;
    for (int num : nums) {
        count += freq[num];    // Add no. of times num has appeared so far
        freq[num]++;           // Inc freq of num
    }
    return count;
    }
};