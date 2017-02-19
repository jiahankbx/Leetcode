class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        count(candidates,0,target);
        return result;
    }
    void count(vector<int>& candidates,int i,int target){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i&&candidates[j]==candidates[j-1]) continue;
            temp.push_back(candidates[j]);
            count(candidates,j+1,target-candidates[j]);
            temp.pop_back();
        }
    }
};

12ms beat 66.7%
