#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
    string input;
    while(getline(cin, input))
    {
        map<char, int> m;
        for(int i = 0; i < input.size();i++)
        {
            m[input[i]]++;
        }
        vector<pair<char, int>> v;
        for(auto p : m)
        {
            v.push_back(p);
        }

        sort(v.begin(), v.end(), [](pair<char, int> x, pair<char, int> y){
            if(x.second == y.second) return (x.first < y.first);
            return x.second > y.second;
            
        });

        for(int i = 0; i < v.size();i++)
        {
            cout<<v[i].first;
        }
        cout<<endl;
    }
    return 0;
}