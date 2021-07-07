#include <iostream>
#include <vector>
using namespace std;

bool check(int n)
{
    int sum = 0;
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