#include <bits/stdc++.h>

using namespace std;


struct data
{
    long long a,b,c;
    data(){}
    data(long long a,long long b,long long c):a(a) , b(b) , c(c){}
    bool operator<(const data &x)const
    {
        if(a!=x.a) return a<x.a;
        if(b!=x.b) return b<x.b;
        return c<x.c;
    }
};

long long D(pair<long long,long long> a,pair<long long,long long> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main()
{
    freopen("astronomy.in" , "r" , stdin);
    freopen("astronomy.out" , "w" , stdout);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        vector<pair<long long,long long> >v(n);

        for(auto &x : v)
            cin>>x.first>>x.second;

        int m;
        cin>>m;

        map<data , long long >mpCount;

        auto tmp = make_pair(0LL , 0LL);
        vector<long long>x(m),y(m),z(m);

        for(int i = 0 ; i<n ; i++)
            for(int j = i+1 ; j<n ; j++)
            {
                long long p =D(tmp , v[i]) ,q =D(tmp , v[j]) ,r =D(v[i],v[j]);
                    mpCount[data(r, min(p,q) , max(p,q))]++;
            }

        for(int i = 0 ; i<m ; i++){
            cin>>x[i]>>y[i]>>z[i];
            cout<<mpCount[data(z[i],min(x[i],y[i]) , max(x[i],y[i]))]<<endl;
        }

    }
    return 0;
}

/**
6
0 2
1 1
2 0
5 0
-3 4
-4 3
4
25 25 2
4 2 2
4 25 9
25 25 100
*/
