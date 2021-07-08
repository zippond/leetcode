#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int m, n;
    while(cin>>m>>n)
    {
        int b = max(m, n);
        int s = min(m, n);
        for(int i = 1; i <= s; i++)
        {
            if((b*i)%s == 0)
            {
                cout<<b*i<<endl;
                break;
            }
        }
    }
    return 0;
}