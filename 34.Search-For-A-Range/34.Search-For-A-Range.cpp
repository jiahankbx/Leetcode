class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left,right,mid,start,end,mid1;
        vector<int> v;
        left=0;
        right=nums.size()-1;
        mid=(left+right)/2;
        if(left==right&&nums[left]!=target){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        if(left==right&&nums[left]==target){
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        while(left<right){
            if(nums[mid]<target){
                left=mid+1;
                mid=(left+right)/2;
            }
            else if(nums[mid]>target){
                right=mid;
                mid=(left+right)/2;
            }
            else if(nums[mid]==target) break;
        }
        if(left==right&&nums[left]!=target){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        if(left==right&&nums[left]==target){
            v.push_back(left);
            v.push_back(left);
            return v;
        }
        mid1=mid; //记录下mid值方便计算end
        left=0; //开始计算start
        right=mid1;
        mid=(left+right)/2;
        while(left<right){
            if(nums[mid]==target&&nums[mid-1]<target){
                start=mid;
                break;
            }    
            else if(nums[mid]==target&&nums[mid-1]==target){
                right=mid;
                mid=(left+right)/2;
            }
            else if(nums[mid]<target){
                left=mid+1;
                mid=(left+right)/2;
            }
        }
        if(left==right) start=left;
        left=mid1; //开始计算end
        right=nums.size()-1;
        mid=(left+right)/2;
        while(left<right){
            if(nums[mid]==target&&nums[mid+1]>target){
                end=mid;
                break;
            }
            else if(nums[mid]==target&&nums[mid+1]==target){
                left=mid+1;
                mid=(left+right)/2;
            }
            else if(nums[mid]>target){
                right=mid;
                mid=(left+right)/2;
            }
        }
        if(left==right) end=right;
        v.push_back(start);
        v.push_back(end);
        return v;
};
};

9ms beat 39.59%
