#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int MAXP = 36001;
//bool PTABLE[MAXP] = {false};
int prime_pair[MAXN][MAXN];

bool isPrime(int n)
{
    if(n<2) return false;
    if(n == 2) return true;
    for(int i = 2; i < n/2 +1;i++)
    {
        if((n%i) == 0) return false;
    }
    return true;
}

bool find(int even, vector<int>& veven, vector<int>& vodd, vector<bool>& odd_used, vector<int>& odd_matched)
{
    //cout<<"into find()"<<even << endl;
    for(int j = 0; j < vodd.size();j++)
    {
        //cout<<"into find()2 "<<j<<endl;
        if(!odd_used[j]&&isPrime(even + vodd[j]))
        {
            //cout<<"into find()3 "<<even_idx<<" j "<<j<<endl;
            odd_used[j] = true;
            if(!odd_matched[j]||find(odd_matched[j], veven, vodd, odd_used, odd_matched))
            {
                //cout<<"size is "<< veven.size()<<"IDX is " << even_idx<<"J is "<<j<<endl;
                odd_matched[j] = even;
                //cout<<"end"<<endl;
                //cout<<"for "<<veven[even_idx]<<" matched "<<vodd[j]<<endl;
                return true;
            }
        }
    }
    return false;
}
int main(int argc, char ** argv)
{
    //setPtable();
    int total = 0, nodd = 0, neven = 0, n;
    
    while(cin>>total)
    {
        vector<int> vodd, veven;
 //       veven.push_back(0);
        //vodd.push_back(0);
        for(int i = 0; i < total;i++)
        {
            cin>>n;
            if(n%2) vodd.push_back(n);
            else veven.push_back(n);
        }
        memset(prime_pair, 0, sizeof(prime_pair));
        for(int i = 0; i < veven.size();i++)
        {
            for(int j = 0; j < vodd.size();j++)
            {
                if(isPrime(veven[i] + vodd[j]))
                {
                    prime_pair[i][j] = true;
         //           cout<<"E:"<<veven[i]<<" O:"<<vodd[j]<<endl;
                }
            }
        }
        vector<int> odd_matched(vodd.size());
        int count = 0;
        for(int i = 0; i < veven.size();i++)
        {
            vector<bool> odd_used(vodd.size());
            if(find(veven[i], veven, vodd, odd_used, odd_matched))
            {
                //cout<<"For "<<veven[i]<<" ";
                count++;
            }
                
        }
        cout<<count<<endl;
    }

    return 0;
}