#include <iostream>
#include <vector>

using namespace std;

bool check(int n)
{
    if((n % 7 ) == 0) return true;
    while(n)
    {
        int t = n % 10;
        if( t == 7) return true;
        n /= 10;
    }
    return false;
}
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        for(int i = 7; i <= n; i++)
        {
            if(check(i)) count++;
        }
        cout<<count<<endl;
    }
}