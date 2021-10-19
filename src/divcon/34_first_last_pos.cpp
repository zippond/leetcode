class Solution {
public:
    int firstOf(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, pos = -1, m = 0;
        while(l <= h)
        {
            m = l + (h - l)/2;
            if(nums[m] == target)
            {
                pos = m;
                h = m - 1;
            }
            else if (nums[m] > target)
            {
                h = m - 1;
            }
            else if(nums[m] < target)
            {
                l = m + 1;
            }
        }
        return pos;
    }
    int lastOf(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, pos = -1, m = 0;
        while(l <= h)
        {
            m = l + (h - l)/2;
            if(nums[m] == target)
            {
                pos = m;
                l = m + 1;
            }
            else if (nums[m] > target)
            {
                h = m - 1;
            }
            else if(nums[m] < target)
            {
                l = m + 1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
            if(!nums.size()) return vector<int> ({-1, -1});
            int first = firstOf(nums, target);
            if(first == -1) return vector<int>({-1, -1});
            int last = lastOf(nums, target);
            return vector<int>({first, last});
    }
};