#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int ncount = 0, pcount = 0, sum = 0, n = 0;
    while(cin>>n)
    {
        if(n < 0)
        {
            ncount++;
        }
        else
        {
            pcount++;
            sum += n;
        }
    }
    double avg = 0.0;
    if(pcount) avg = sum*1.0/pcount;
    printf("%d\n%.1f\n", ncount, avg);
    return 0;
}