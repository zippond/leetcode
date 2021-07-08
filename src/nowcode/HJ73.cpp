/*
    计算天数
*/

#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int y)
{
    return ((y % 400) == 0)||(((y % 4) == 0)&&((y%100) != 0));
}
int getDays(int y, int m, int d)
{
    vector<int> monthdays({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    for(int i = 1; i < monthdays.size();i++)
    {
        monthdays[i] = monthdays[i-1] + monthdays[i];
    }
    int days = monthdays[m-1] + d;
    if(isLeapYear(y)&&(m > 2))
    {
        days += 1;
    }
    return days;
}
int main(int argc, char **argv)
{
    int y, m, d;
    while(cin>>y>>m>>d)
    {
        cout<<getDays(y, m, d)<<endl;
    }
    return 0;
}