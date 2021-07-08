#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    while(cin>>n)
    {
        for(int i = 0; i <= 100; i++)
        {
            for(int j = 0; j <= (100 -i); j++)
            {
                int k = 100 -i -j;
                if((15*i + 9*j + k) == 300)
                cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    return 0;
}