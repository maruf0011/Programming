#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<long long> VL;
typedef vector<VL> VVL;

const long long mod = 1000000007LL;

struct node
{
    int n;
    VVL mat;
    node(int n) : n(n) , mat(n , VL(n , 0)) {}

    node operator *(const node &b)const
    {
        node ret(n);
        for(int i = 0 ; i<n ; i++)
            for(int j = 0 ; j<n ; j++)
            {
                for(int k = 0 ; k<n ; k++)
                {
                    ret.mat[i][j] += ((mat[i][k]*b.mat[k][j])%mod);
                    ret.mat[i][j] %= mod;
                }
            }
        return ret;
    }

};


long long kmp(string a,string b)
{
    string str = a+"#"+b;

    VL par((int)str.size() , 0);

    int k = 0;
    par[k] = 0;

    for(int i = 1 ; i<str.size() ; i++)
    {
        while(k>0 && str[k]!=str[i])
            k = par[k-1];
        if(str[k]==str[i]) k++;
        par[i] = k;
    }
    return par[(int)str.size()-1];
}

long long matPow(node base,int pow)
{
    node ret(base.n);

    for(int i = 0; i<base.n ; i++)
        ret.mat[i][i] = 1;

    while(pow)
    {
        //cout<<pow<<endl;
        if(pow&1)
            ret = ret*base;
        pow /= 2;
        base = base*base;
    }

    long long sol = 0;
    for(int i = 0 ; i<base.n ; i++)
        for(int j = 0 ; j<base.n ; j++)
            sol = (sol+ret.mat[i][j])%mod;
    return sol;
}

int main()
{
    int tcase,cas=1;
    cin>>tcase;
    string str;
    while(tcase--)
    {
        int n,m;
        cin>>n>>m;
        vector<string>v;
        node base(n);
        set<string>s;
        for(int i = 0 ; i<n ; i++)
        {
            cin>>str;
            if(s.count(str)) continue;
            s.insert(str);
            v.push_back(str);
        }



        for(int i = 0  ; i<n ; i++)
            for(int j = 0 ; j<n ; j++)
        {
            //if(i==j) continue;
            long long value = kmp(v[i], v[j]);
            if(value>1)
                base.mat[j][i] = 1;
        }
        long long sol = 0;
        sol = matPow(base, m-1);
        cout<<sol<<endl;
    }
    return 0;
}
