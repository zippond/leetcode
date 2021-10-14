class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, m = 0;
        while(low <= high)
        {
            m = (low + high)/2;
            if(nums[m] == target)
            {
                return m;
            }
            // 至少有一边有序，看target是否在有序范围内，如果在，查找这边；否则查找另外一边
            // 判断左边是否有序
            if(nums[low] <= nums[m])
            {
                // 看target是否在有序的这边（左边）
                if((target >= nums[low])&&(target< nums[m])) // 在
                {
                    high = m -1;
                }
                else
                {
                    low =  m + 1;
                }
            }
            else // 右边有序
            {
                // 看target是否在有序的这边（右边）
                if((target > nums[m])&&(target<= nums[high])) // 在
                {
                    low = m + 1;
                }
                else
                {
                    high = m - 1;
                }
            }
        }
        return -1;
    }
};