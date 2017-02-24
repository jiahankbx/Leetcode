class Solution {
public:
    int temp;
    int i;
    void nextPermutation(vector<int>& nums){
        int length=nums.size();
        int j=length-1;
        while(j>0){
            //从后往前判定是否为最大序列
            if(nums[j]<=nums[j-1]) j--;
            else{
                //找到两个交换点
                for(i=length-1;i>0;i--){
                    if(nums[i]>nums[j-1]){
                        temp=nums[j-1];
                        nums[j-1]=nums[i];
                        nums[i]=temp;
                        break;
                    };
                };
            break;
            };
        };
        if(j==0) reverse(nums,0,length-1);
        //交换后，尾序列依然降序，需要进行逆序操作
        else reverse(nums,j,length-1);
        for(i=0;i<length;i++) cout<<nums[i];
    };
    void reverse(vector<int>& nums,int left,int right){
        while(left<=right){
            temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
    }
};

9ms beat 35%
    
    
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int Min=INT_MAX;
        int flag=0;
        int save;
        vector<int>::iterator p=nums.begin();
        vector<int>::iterator q=nums.end();
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i]&&nums[j]<Min){
                    Min=nums[j];
                    save=j;
                };
            };
            if(save){
                swap(nums[save],nums[i]);
                sort(p+i+1,q);
                flag=1;
                break;
            };
        };
        if(flag==0) sort(p,q);
    }
};

12ms beat 57%
