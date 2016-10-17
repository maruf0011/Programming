#include <bits/stdc++.h>

using namespace std;

int dp[2010][2010];
int d;

typedef vector <pair<long long,long long> > VP;
typedef vector <double> VD;
VP p;
VD dist;

int find_dist(int i,int j)
{
    return ((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second));
}

int rec(int cur,int prev)
{
    if(cur==((int)p.size()-1))
    {
        return 1;
    }

    int &ret = dp[cur][prev];
    if(ret!=-1) return ret;

    ret = 222000;

    if(dist[cur+1] - dist[prev] <= d && cur!=0)
    {
        ret  = min(ret , rec(cur+1 , prev));
    }
    ret = min(ret , rec(cur+1 , cur)+1);
    return ret;
}

int main()
{
    int n;
    while(cin>>n>>d)
    {
        p = VP(n);

        for(int i = 0 ; i<p.size(); i++)
        {
            cin>>p[i].first>>p[i].second;
        }

        dist = VD(n , 0.0);

        for(int i = 1 ; i<p.size() ; i++)
            dist[i] = dist[i-1]+sqrt(find_dist(i-1 , i));

        memset(dp , -1 , sizeof dp);

        cout<<rec(0 , 0)<<endl;
    }
    return 0;
}
