#include <iostream>
using namespace std;

int getSum(int n)
{
    return (2 + (2+ 3*(n-1)))*n/2;
}
int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        cout<<getSum(n)<<endl;
    }
    return 0;
}