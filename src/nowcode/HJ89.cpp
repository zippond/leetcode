/*
描述
计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 除(/)四种运算法则计算得到整数24，本问题中，扑克牌通过如下字符或者字符串表示，其中，小写joker表示小王，大写JOKER表示大王：

3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER

本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。

详细说明：

1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，没有括号，友情提醒，整数除法要当心，是属于整除，比如2/3=0，3/2=1；
2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1；
3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
4.输出的算式格式为4张牌通过+-* /四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确；
5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24，2 A 9 A不能变为(2+1)*(9-1)=24
6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。
7.因为都是扑克牌，不存在单个牌为0的情况，且没有括号运算，除数(即分母)的数字不可能为0

输入描述：
输入4张牌为字符串形式，以一个空格隔开，首尾无空格；

输出描述：
输出怎么运算得到24，如果无法得出24，则输出“NONE”表示无解，如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getCard(int n)
{
    if( n == 11) return "J";
    if( n == 12) return "Q";
    if( n == 13) return "K";
    if( n == 1 ) return "A";
    return to_string(n);
}
void printCards(vector<int>& vc, vector<char>& vo)
{
    cout<<getCard(vc[0])<<vo[0]<<getCard(vc[1])<<vo[1]<<getCard(vc[2])<<vo[2]<<getCard(vc[3])<<endl;
}

bool calc(vector<int> vc, vector<char> vo, int target)
{
    /*
    for(int i = 0; i< 4; i++)
    {
        cout<<vc[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i< 3; i++)
    {
        cout<<vo[i]<<" ";
    }
    cout<<endl;
    */
    for(int i = 0 ; i < 3; i++)
    {
        char op = vo[i];
        //vc[i+1] = vc[i] vo[i] vc[i+1]
        if(vo[i] == '+')
        {
            vc[i+1] = vc[i] + vc[i+1];
        }
        else if(vo[i] == '-')
        {
            vc[i+1] = vc[i] - vc[i+1];
        }
        else if(vo[i] == '*')
        {
            vc[i+1] = vc[i] * vc[i+1];
        }
        else
        {
            if(vc[i] % vc[i+1]) return false;
            vc[i+1] = vc[i] / vc[i+1];
        }    
    }
    //cout<<"V3:"<<vc[3]<<endl;
    return vc[3] == target;
}
bool check(vector<int>& vc, vector<char>& vo, int target)
{
    sort(vc.begin(), vc.end());
    string ops = "+-*/";
    do
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    vo[0] = ops[i];
                    vo[1] = ops[j];
                    vo[2] = ops[k];
                    if(calc(vc, vo, target)) return true;
                }
            }
        }
        /* */

    } while (next_permutation(vc.begin(), vc.end()));
    return false;
}

bool process(vector<string>& vs, vector<int>& vc)
{
    for(int i = 0; i < vs.size(); i++)
    {
        if((vs[i] == "joker")||(vs[i] == "JOKER")) return false;
        if(vs[i] == "10")
        {
            vc[i] = 10;
        }
        else if(vs[i] == "J")
        {
            vc[i] = 11;
        }
        else if(vs[i] == "Q")
        {
            vc[i] = 12;
        }
        else if(vs[i] == "K")
        {
            vc[i] = 13;
        }
        else if(vs[i] == "A")
        {
            vc[i] = 1;
        }
        else
        {
            vc[i] = vs[i][0] - '0';
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    vector<string> v(4);
    while(cin>>v[0]>>v[1]>>v[2]>>v[3])
    {
        vector<int> vc(4);
        if(process(v, vc))
        {
            vector<char> vo(3);
            if(check(vc, vo, 24))
            {
                printCards(vc, vo);
            }
            else
            {
                cout<<"NONE"<<endl;
            }
        }
        else
        {
            cout<<"ERROR"<<endl;
        }
    }
    return 0;
}


/*
 old solution
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

inline char getchar(int n)
{
    if(n == 1) return 'A';
    if(n == 11) return 'J';
    if(n == 12) return 'Q';
    if(n == 13) return 'K';
    return '0' + n;
}
inline int getnum(string& s)
{
    if(s == "A") return 1;
    if(s == "J") return 11;
    if(s == "Q") return 12;
    if(s == "K") return 13;
    return atoi(s.c_str());
}

inline int min_calc(int a, int b, char op)
{
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return -1;
}
int calc(vector<int>& v, char c1, char c2, char c3)
{
    
    int i = 0;
    int ret = v[i];
    ret = min_calc(ret, v[1], c1);
    ret = min_calc(ret, v[2], c2);
    ret = min_calc(ret, v[3], c3);
 //   cout<<"c:"<<v[0]<<v[1]<<v[2]<<v[3]<<endl;
 //   cout<<"Calc "<<ret << c1 << c2 << c3<<endl;
    return ret;
}
string get24(vector<string> & cards)
{
    vector<char> op = {'+', '-', '*', '/'};
    vector<int> cards_num;
    for(int i = 0; i < cards.size();i++ )
    {
        if((cards[i] == "joker")||(cards[i] == "JOKER")) return "ERROR";
        cards_num.push_back(getnum(cards[i]));
    }
    
    vector<char> final_ops;
    bool find = false;
    sort(cards_num.begin(), cards_num.end());
    
    int fi, fj, fk;
    int count = 0;
    do{
        //vector<char> ops;
        for(int i = 0; i < 4;i++)
        {
            if(find) break;
            for(int j = 0; j < 4; j++)
            {
                if(find) break;
                for(int k = 0; k < 4; k++)
                {
                    int result = 0;
                    result = calc(cards_num, op[i], op[j], op[k]);
                    
                    /*
                    string t;
                            t += getchar(cards_num[0]);
        for(int ti = 1, tj = 0; ti < 4;ti++, tj++)
        {
            t += ops[tj];
            t += getchar(cards_num[ti]);
        }
        */
                    //cout<<count++ <<"a ";
                    
                    if(result == 24)
                    {
                        find = true;
                        //final_ops = ops;
                        fi = i;
                        fj = j;
                        fk = k;
                        break;
                    }
                }
            }
        }
    }while(!find&& next_permutation(cards_num.begin(), cards_num.end()));
    string ret;
    if(find)
    {
        //cout<<getchar(cards_num[0])<<endl;
        ret += getchar(cards_num[0]);
        ret += op[fi];
                ret += getchar(cards_num[1]);
        ret += op[fj];
                ret += getchar(cards_num[2]);
        ret += op[fk];
                ret += getchar(cards_num[3]);
        //cout<<"ret is "<<ret<<fi<<fj<<fk<<endl;
        return ret;
    }
    return "NONE";
}
int main2(int argc, char ** argv)
{
    string c1, c2, c3, c4;
    while(cin>>c1>>c2>>c3>>c4)
    {
        vector<string> cards = {c1, c2, c3, c4};
        cout<<get24(cards)<<endl;
    }
}