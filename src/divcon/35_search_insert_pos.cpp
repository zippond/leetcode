class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size(); // 范围是 0~n
        while(low < high)       // 中止条件是 low == high，即找到插入点
        {
            int mid = low + (high -low)/2;
            if(nums[mid] == target)     // 找到匹配值，退出
            {
                return mid;
            }
            else if(nums[mid] > target) // 值在左边，注意不能缩小范围，因为插入点可能就在当前位置
            {
                high = mid;
            }
            else if(nums[mid] < target) // 值在右侧，缩小范围
            {
                low = mid + 1;
            }
        }
        return high;
    }
};
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while(low < high)
        {
            int mid = low + (high -low)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                high = mid;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
        }
        return high;
    }
};