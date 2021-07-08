/**
    表达式求值
    四则运算
https://blog.nowcoder.net/n/177426021daf45689e9ba735b8824954?f=comment
发表于 2020-02-16 23:53:06
问题：如何判断'+'或'-'是加减还是正负？
解答：用一个变量来判断：数字和运算符是交替出现的（括号的出现不会影响这种交替关系）。

思路
用两个栈分别压数字和运算符；
如果当前运算符优先级('\ * /')高于栈顶运算符('+-')优先级，则将运算符入栈；反之，从数字栈中弹出两个数，从运算符栈中弹出栈顶运算符，进行运算，数字栈压入运算结果，符号栈压入当前运算符。重复该操作直到不满足条件。
出现左括号，则直接压入；出现右括号，则从数字栈中弹出两个数，从运算符栈中弹出栈顶运算符，进行运算，数字栈压入运算结果，重复该操作直到栈顶弹出右括号位置。

***/
#include <iostream>
#include <stack>
using namespace std;
 
string mp = "+-*/)]}";
// 当前运算符与符号栈的栈顶运算符做优先级比较，如果当前优先级高，则不做运算压入栈中，相同进行运算
bool cmp(char c1, char c2)
{
    if (c1 =='(') {
        return false;
    } else if((c1=='+' || c1=='-') && (c2=='*' || c2=='/')){
        return false;
    }
    return true;
}
 
void doCal(stack<double> &st, stack<char> &so)
{
    double b = st.top();
    st.pop();
    double a = st.top();
    st.pop();
    int op = so.top();
    so.pop();
    if(op == '+') a = a+b;
    else if(op == '-') a = a-b;
    else if(op == '*') a = a*b;
    else if(op == '/') a = a/b;
    st.push(a);
    return ;
}
 
int main()
{
    string s;
    while(getline(cin, s))
    {
        stack<double> st;
        stack<char> so;
        so.push('(');
        s += ')';
        bool nextIsOp = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(') {
                so.push('(');
            } else if(s[i]==')' || s[i]==']' || s[i]=='}') {
                while(so.top() != '(') doCal(st, so);
                so.pop();
            } else if (nextIsOp) {
                while(cmp(so.top(), s[i])) doCal(st, so);
                so.push(s[i]);
                nextIsOp = false;
            } else {
                int j = i;
                if(s[j] == '-' || s[j] == '+') i++;
                while(mp.find(s[i]) == mp.npos) i++;
                string t = s.substr(j, i-j);
                st.push((double)stoi(t));
                i--;
                nextIsOp = true;
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}