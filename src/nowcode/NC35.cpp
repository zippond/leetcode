/*
* 最小编辑代价
*/ 
class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int l1 = str1.size(), l2 = str2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1));
        for(int i = 1; i <= l1; i++)
        {
            dp[i][0] = dc * i;
        }
        for(int j = 1; j <= l2; j++)
        {
            dp[0][j] = ic * j;
        }
        for(int i = 1; i<= l1; i++)
        {
            for(int j = 1; j <= l2; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1] + rc, 
                                  min(dp[i-1][j]+ dc, dp[i][j-1] + ic));
                }
            }
        }
        return dp[l1][l2];
    }
};

class Solution {
public:
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        if(str1==""&&str2=="") return 0;
        int len1 = str1.size();
        int len2 = str2.size();
        //想清楚状态矩阵的定义，下标代表长度！！
        int dp[len1+1][len2+1];
        for(int i=0;i<=len1;i++){
            dp[i][0] = i*dc;//str1所有字符全部删除变成str2
        }
        for(int j=0;j<=len2;j++){
            dp[0][j] = j*ic;//空字符串str1全部插入变成str2
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    //等价于str1的前i-1个字符和str2的前j-1个字符编辑距离的子问题。
                    //即对于str1的第i个字符'X'，对于str2的第j个字符'W'，我们在str1的末尾'X'替换为字符'W'，
                    //那么dp[i][j]最小可以为dp[i-1][j-1]+rc；
                    int choice1 = dp[i-1][j-1] + rc;//替换
                     
                    //等价于str1的前i个字符和str2的前j-1个字符编辑距离的子问题。
                    //即对于str2的第j个字符'X'，我们在str1的末尾添加了一个相同的字符'X'，
                    //那么dp[i][j]最小可以为dp[i][j-1]+ic；
                    int choice2 = dp[i][j-1]+ic;//插入
                     
                    //等价于str1的前i-1个字符和str2的前j个字符编辑距离的子问题。
                    //即对于str1的第i个字符'X'，我们在str2的末尾添加了一个相同的字符'X'，等价于在str1的末尾删除了该字符'X'，
                    //那么dp[i][j]最小可以为dp[i][j-1]+dc；
                    int choice3 = dp[i-1][j]+dc;//删除
                    dp[i][j] = min(choice1,min(choice2,choice3));
                }
            }
        }
        return dp[len1][len2];
    }
};
