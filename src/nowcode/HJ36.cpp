#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char dict[26] = {0};
void buildDict(const string& s)
{
    
    vector<char> uniq_chars;
    for(int i = 0; i < s.size(); i++)
    {
        
        char lc = tolower(s[i]);
        if(find(uniq_chars.begin(), uniq_chars.end(), lc) ==  uniq_chars.end())
        {
            uniq_chars.push_back(lc);
        }
    }


    int idx = 0;
    for( idx = 0; idx < uniq_chars.size(); idx++)
    {
        dict[idx] = uniq_chars[idx];
    }
    string all_chars = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < 26; i++)
    {
        if(find(uniq_chars.begin(), uniq_chars.end(), all_chars[i]) == uniq_chars.end())
        {
            dict[idx++] = all_chars[i];
        }
    }
}

string encrypt(const string& plain)
{
    string ret;
    for(int i = 0; i < plain.size();i++)
    {
        char c = plain[i];
        if((c>= 'a')&&(c<='z'))
        {
            ret += dict[c - 'a'];
        }
        else if ((c >= 'A')&&(c <= 'Z'))
        {
            /* code */
            ret += 'A' + dict[c - 'A'] - 'a';
        }
        else
        {
            ret += c;
        }
        
    }
    return ret;
}
int main(int argc, char **argv)
{
    string cypher;
    while(cin>>cypher)
    {
        string plain;
        cin>>plain;
        buildDict(cypher);
        cout<<encrypt(plain)<<endl;
    }
    return 0;
}