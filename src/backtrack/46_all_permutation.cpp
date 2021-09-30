class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& tmp, vector<int>& nums)
    {
        if(tmp.size() == nums.size())
        {
            result.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size();i++)
        {
            if(find(tmp.begin(), tmp.end(), nums[i]) == tmp.end())
            {
                tmp.push_back(nums[i]);
                dfs(result, tmp, nums);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result, tmp, nums);
        return result;
    }
};