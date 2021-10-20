/*
tags: BFS
*/
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string upOne(const string& s, int i)
    {
        string tmp = s;
        char c = '0';
        switch(tmp[i])
        {
            case '9':
            c = '0';
            break;
                        case '8':
            c = '9';
            break;
                        case '7':
            c = '8';
            break;
                        case '6':
            c = '7';
            break;
                        case '5':
            c = '6';
            break;
                        case '4':
            c = '5';
            break;
                        case '3':
            c = '4';
            break;
                        case '2':
            c = '3';
            break;
                        case '1':
            c = '2';
            break;
                        case '0':
            c = '1';
            break;
            default:
            c = '0';
        }
        tmp[i] = c;
        return tmp;
    }
    string downOne(const string& s, int i)
    {
        string tmp = s;
        char c = '0';
        switch(tmp[i])
        {
            case '9':
            c = '8';
            break;
                        case '8':
            c = '7';
            break;
                        case '7':
            c = '6';
            break;
                        case '6':
            c = '5';
            break;
                        case '5':
            c = '4';
            break;
                        case '4':
            c = '3';
            break;
                        case '3':
            c = '2';
            break;
                        case '2':
            c = '1';
            break;
                        case '1':
            c = '0';
            break;
                        case '0':
            c = '9';
            break;
            default:
            c = '0';
        }
        tmp[i] = c;
        return tmp;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> deads;
        queue<string> q;
        q.push("00");
        for(int i = 0; i < deadends.size(); i++)
        {
            deads.insert(deadends[i]);
        }
        int step = 0;
        int count = 0;
        while(q.size())
        {
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                // 判断
                string t = q.front();
                cout<<"Count "<<count++<<"Size:"<<s<< " i:"<<i<<" Hsize:"<<visited.size()<<" cur:"<<t<<" - step:"<<step<<endl;
                q.pop();
                if(t == target)
                {
                    return step;
                }
                if(deads.find(t) != deads.end())
                {
                    continue;
                }
                
                // 扩展一轮
                for(int i = 0; i < t.size();i++)
                {
                    string tup = upOne(t, i);
                    string tdown = downOne(t, i);
                    if(visited.find(tup) == visited.end())
                    {
                        q.push(tup);
                        visited.insert(tup); // 避免重复插入队列q内
                    }
                    if(visited.find(tdown) == visited.end())
                    {
                        q.push(tdown);
                        visited.insert(tdown); // 避免重复插入队列q内
                    }                    
                    cout<<"up:"<<tup<<"- down:"<<tdown<<endl;
                }

            }
            step++;
        }
        return -1;
    }
};

class Solution1 {
public:
    string upOne(const string& s, int i)
    {
        string tmp = s;
        char c = '0';
        switch(tmp[i])
        {
            case '9':
            c = '0';
            break;
                        case '8':
            c = '9';
            break;
                        case '7':
            c = '8';
            break;
                        case '6':
            c = '7';
            break;
                        case '5':
            c = '6';
            break;
                        case '4':
            c = '5';
            break;
                        case '3':
            c = '4';
            break;
                        case '2':
            c = '3';
            break;
                        case '1':
            c = '2';
            break;
                        case '0':
            c = '1';
            break;
            default:
            c = '0';
        }
        tmp[i] = c;
        return tmp;
    }
    string downOne(const string& s, int i)
    {
        string tmp = s;
        char c = '0';
        switch(tmp[i])
        {
            case '9':
            c = '8';
            break;
                        case '8':
            c = '7';
            break;
                        case '7':
            c = '6';
            break;
                        case '6':
            c = '5';
            break;
                        case '5':
            c = '4';
            break;
                        case '4':
            c = '3';
            break;
                        case '3':
            c = '2';
            break;
                        case '2':
            c = '1';
            break;
                        case '1':
            c = '0';
            break;
                        case '0':
            c = '9';
            break;
            default:
            c = '0';
        }
        tmp[i] = c;
        return tmp;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> deads;
        queue<string> q;
        q.push("00");
        for(int i = 0; i < deadends.size(); i++)
        {
            deads.insert(deadends[i]);
        }
        int step = 0;
        int count = 0;
        while(q.size())
        {
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                // 判断
                string t = q.front();
                cout<<"Count "<<count++<<"Size:"<<s<< " i:"<<i<<" Hsize:"<<visited.size()<<" cur:"<<t<<" - step:"<<step<<endl;
                q.pop();                
                if(t == target)
                {
                    return step;
                }
                if(visited.find(t) == visited.end())
                {
                    visited.insert(t);
                }
                else
                {
                    continue;
                }
                if(deads.find(t) != deads.end())
                {
                    continue;
                }
                
                // 扩展一轮
                for(int i = 0; i < t.size();i++)
                {
                    string tup = upOne(t, i);
                    string tdown = downOne(t, i);
                    if(visited.find(tup) == visited.end())
                    {
                        q.push(tup);
                    }
                    if(visited.find(tdown) == visited.end())
                    {
                        q.push(tdown);
                    }                    
                    cout<<"up:"<<tup<<"- down:"<<tdown<<endl;
                }

            }
            step++;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    vector<string> deads;
    string target;
    string input;
    getline(cin, input);
    cin>>target;
    string t;
    input.push_back(' ');
    for(int i = 0; i < input.size();i++ )
    {
        if(input[i] == ' ')
        {
            deads.push_back(t);
            t = "";
            continue;

        }
        t.push_back(input[i]);
    }
    for(auto s: deads)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<"input:"<<input<<" target:"<<target<<endl;
    Solution1 sol;
    cout<<sol.openLock(deads, target)<<endl;

}