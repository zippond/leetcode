class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size(), s2 = nums2.size();
        if(s1 > s2) return findMedianSortedArrays(nums2, nums1); // Assume nums1 has smaller size
        // short cut for empty nums1
        if(s1 == 0)
        {
            if(s2 == 0) return 0.0;

            int c = s2/2;
            if(s2 % 2)
            {
                return nums2[c]*1.0;
            }
            else
            {
                return (nums2[c-1] + nums2[c])/2.0;
            }
        }
        //c1 c2表示分割时分到左边的元素个数。当c1 == 0时表示nums1没有元素被分割到左边；c1 == s1时表示nums1没有元素被分割到右边。也就是开区间右侧。
        // 目标是 c1 + c2 = 偶数时：(s1+s2)/2；奇数时：(s1+s2)/2+1;
        //  即 c1 + c2 = (s1 + s2 + 1)/2; 
        // c1的取值范围是 0~s1
        int low = 0, high = s1, c1 = 0, c2 = 0; 
        while(low <= high)
        {
            cout<<"low:"<<low<<"high:"<<high<<endl;
            // 分割
            c1 = (low + high)/2;
            c2 = (s1 + s2 + 1)/2 - c1;

            // 看是否分割合适
            // nums1[c1] 为区间右侧数字，min_max1;
            // nums1[c1-1] 为区间左侧数字，max_min1;
            // nums2[c2] 为区间右侧数字，min_max2;
            // nums2[c2-1] 为区间左侧数字，max_min2;
            // 注意下标溢出
            int min_max1 = (c1 == s1)?INT_MAX:nums1[c1];
            int min_max2 = (c2 == s2)?INT_MAX:nums2[c2];
            int max_min1 = (c1 == 0)?INT_MIN:nums1[c1-1];
            int max_min2 = (c2 == 0)?INT_MIN:nums2[c2-1];
            int min_max = min(min_max1, min_max2);
            int max_min = max(max_min1, max_min2);
            cout<<"c1:"<<c1<<"c2:"<<c2<<":"<<min_max1<<":"<<min_max2<<":"<<max_min1<<":"<<max_min2<<endl;
            if(min_max1 < max_min2) // c1 太小，右移
            {
                low = c1+1;
                continue;
            }
            if(max_min1 > min_max2) // c1 太大，左移
            {
                high = c1 - 1;
                continue;
            }
            if(max_min <= min_max) // 左边小于右边，停止
            {
                if((s1+s2)%2)
                {
                    return max_min;                    
                }
                else
                {
                    return (max_min + min_max)/2.0;
                }
            }

        }
        return 0.0; // should not be here

    }
};


class Solution2
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int c1 = 0; // cut1 count we play with
        int c2 = 0; // cut2 caculated by c1

        int low = 0;
        int high = m;
        int lmax1 = 0;
        int lmax2 = 0;
        int rmin1 = 0;
        int rmin2 = 0;
        int lmax = 0;
        int rmin = 0;
        if (low == high) // nums1 is empty;
        {
            lmax = nums2[(n + 1) / 2 - 1];
            rmin = nums2[(n + 1) / 2];
        }
        while (low <= high)
        {
            c1 = (low + high) / 2;     // binary cut
            c2 = (m + n + 1) / 2 - c1; // TODO: need confirmation
            // 0 <= c1 <= m;
            lmax1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];
            lmax2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];
            rmin1 = (c1 == m) ? INT_MAX : nums1[c1];
            rmin2 = (c2 == n) ? INT_MAX : nums2[c2];

            lmax = max(lmax1, lmax2);
            rmin = min(rmin1, rmin2);

            //printf("C1 is [%d], C2 is [%d] lmax1 is [%d], lmax2 is [%d], rmin1 is [%d], rmin2 is [%d], lmax is [%d], rmin is [%d]\n", c1, c2, lmax1, lmax2, rmin1, rmin2, lmax, rmin);

            if (lmax <= rmin) // Good
            {
                if ((m + n) % 2)
                {
                    return lmax;
                }
                else
                {
                    return (lmax + rmin) / 2.0;
                }
            }
            else if (lmax1 > rmin2) // move c1 left
            {
                high = c1 - 1;
            }
            else // move c1 right
            {
                low = c1 + 1;
            }
        }
        return 0.0;
    }
};