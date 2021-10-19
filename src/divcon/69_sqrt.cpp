#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        int m;
        while(l <= h) // 中止条件为 l > h
        {           
            m = l + (h - l)/2;
            long long s = (long long)m*m;
            if(s == x)
            {
                return m;
            }
            else if (s < x)
            {
                l = m+1;
            }
            else if(s > x)
            {
                h = m -1;
            }
        }
        return h;
    }
};


class Solution1 {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        int m, ret;
        while(l <= h) // 中止条件为 l > h
        {           
            m = l + (h - l)/2;
            long long s = (long long)m*m;
            if(s == x)
            {
                return m;
            }
            else if (s < x)
            {
                ret = m;
                l = m+1;
            }
            else if(s > x)
            {
                h = m -1;
            }
        }
        return ret;
    }
};
int main(int argc, char **argv)
{
    int n;
    Solution s;
    while(cin>>n)
    {
        cout<<s.mySqrt(n)<<endl;
    }
    return 0;
}