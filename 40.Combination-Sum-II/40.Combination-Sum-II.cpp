class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        count(candidates,0,target);
        return result;
    }
    void count(vector<int>& candidates,int index,int target){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            count(candidates,i+1,target-candidates[i]);//和39题就差这里，一个是i，一个是i+1
            temp.pop_back();
        }
    }
};

12ms beat 66.7%
