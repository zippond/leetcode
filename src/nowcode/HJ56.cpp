#include <iostream>
#include <vector>
using namespace std;

bool check(int n)
{
    int sum = 1;
    int m = n;
    for(int i = 2; i <= m/2; i++)
    {
        if(( n % i ) == 0)
        {
            sum += i;
        }
    }
    return sum == m;
}

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        for(int i = 5; i <= n; i++)
        {
            if(check(i)) count++;
        }
        cout<<count<<endl;
    }
}