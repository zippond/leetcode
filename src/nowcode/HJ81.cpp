#include <iostream>
#include <string>
#include <set>
using namespace std;

bool check(string& s1, string& s2)
{
    set<char> s;
    for(int i = 0; i < s1.size(); i++)
    {
        s.insert(s1[i]);
    }
    
    for(int i = 0; i < s2.size(); i++)
    {
        if(s.find(s2[i]) == s.end()) return false;
    }
    
    return true;
}
int main(int argc, char** argv)
{
    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        cout<<(check(s2, s1)?"true":"false")<<endl;
    }
    return 0;
}