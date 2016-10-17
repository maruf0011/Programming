#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;

struct node
{
    int d,p;
    node(){}
    node(int d,int p):d(d),p(p){}
};

void add(int x,VI &bit)
{
    while(x>0)
    {
        bit[x] += 1;
        x -= (x&(-x));
    }
    return;
}

int get_value(int x)
{
    int ret= 0;
    while(x>0)
    {
        ret += bit[x];
        x -= (x&(-x));
    }
    return ret;
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int>v(n) , vs;
        int cnt= 0;
        for(auto &x: v)
        {
            cin>>x;
            vs.push_back(x);
        }

        sort(vs.begin() , vs.end());
        vs.resize(unique(vs.begin() , vs.end()) -vs.begin());

        vector<int>bit(n+10 , 0);

        for(auto &x: v)
        {

        }
    }
    return 0;
}
