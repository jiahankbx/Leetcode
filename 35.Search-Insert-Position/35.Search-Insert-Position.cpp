class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]<target) continue;
            else return i;
        }
        return i;
    }
};

6ms beat 26.39%
