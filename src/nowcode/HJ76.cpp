#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int cube = n*n*n;
        int mid = n*n;
        //int start = mid - n + 1;
        int start = n*(n-1) + 1;
        for(int i = 0; i < n; i++)
        {
            if( i == (n-1))
                cout<<start<<endl;
            else
                cout<<start<<"+";
            start += 2;
        }
        
    }
    return 0;
}