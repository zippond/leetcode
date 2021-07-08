/*
    自守数
*/ 
#include <iostream>
#include <vector>
using namespace std;

bool check(int n)
{
    int power = n*n;
    while(n)
    {
        if((n%10) != (power % 10)) return false;
        n /= 10;
        power /= 10;
    }
    return true;
}
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        for(int i = 0; i <= n; i++)
        {
            if(check(i)) count++;
        }
        cout<<count<<endl;
    }
}