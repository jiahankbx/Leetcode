class Solution {
 public:
     vector<int> twoSum(vector<int> &nums, int target) {
     vector<int> result;
         for (int i = 0; i < nums.size()-1; i++) {
             for (int j = i+1; j < nums.size(); j++) {
                 if (nums[i] + nums[j]==target) {
                     result.push_back(i);
                     result.push_back(j);
                     return result;
                 }
             }
         }
         return result;
     }
 };
 
 689ms
 
 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int dummy;
        for(int i=0;i<nums.size()-1;i++){
            dummy=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==dummy){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }    
        }
        return result;
    }
};

492ms
