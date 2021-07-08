#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        sort(input.begin(), input.end());
        cout<<input<<endl;
    }
    return 0;
}