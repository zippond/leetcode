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
            else
            {
                pcount++;
                sum += var;
            }
        }
        if(!pcount) pcount = 1;
        cout<<count<<" "<<sum*1.0/pcount<<endl;
    }
    return 0;
}