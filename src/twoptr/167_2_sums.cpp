/*
    双指针！！！
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 1, h = numbers.size();
        int m;
        vector<int> ret;
        while(l < h) // 不相等
        {
            int s = numbers[l-1] + numbers[h-1];
            m = l + (h - l)/2;
            if( s == target )
            {
                ret.push_back(l);
                ret.push_back(h);
                break;
            }
            else if(s > target)
            {
                h--;
            }
            else
            {
                l++;
            }

        }
        return ret;
    }
};
