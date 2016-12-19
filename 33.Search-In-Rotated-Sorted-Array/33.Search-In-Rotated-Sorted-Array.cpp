class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
            else if(nums[i]<target&&nums[i+1]>target) return -1;
            else if(nums[i]<target&&nums[i]>nums[i+1]) return -1;
            else if(nums[i]>target) continue;
        }
    return -1;
    }
};

3ms beat 65.27%
