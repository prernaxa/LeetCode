class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxEle = -1;
        int index = -1;
        for(int i=0; i<nums.size(); i++){
        if(nums[i]>maxEle){
            maxEle = nums[i];
            index = i;
        }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i != index && maxEle < 2 * nums[i]) {
                return -1;
            }
        }

        return index;
    }
};