#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    while(cin>>n)
    {
        int count = 0;
        while(n)
        {
            n = n&(n<<1);
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}