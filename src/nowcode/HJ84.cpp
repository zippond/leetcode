#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        int count = 0;
        for(int i = 0; i < input.size();i++)
        {
            if((input[i] >= 'A')&&(input[i] <= 'Z'))
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}