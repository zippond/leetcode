#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int count = 0, pcount = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            int var;
            cin>>var;
            if(var < 0)
            {
                count++;
            }
            if(var > 0)
            {
                pcount++;
                sum += var;
            }
        }
        if(!pcount) pcount = 1;
        printf("%d %.1f\n", count, sum*1.0/pcount);
    }
    return 0;
}