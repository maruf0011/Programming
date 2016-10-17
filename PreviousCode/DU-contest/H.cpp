#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using tp = tuple<int,int,int>;
using pll = pair<ll,ll>;
vector<vector<int> > vadj(6100);
int parent[6100];
bool vis[6100];

bool dfs(int u,int h,int tr ,vector<tp> &trIndex)
{
    if(u==tr) return true;
    if(vis[u]) return false;
    vis[u] = true;
    bool ret = false;
    int x,y,z;
    for(auto &v: vadj[u])
    {
        tie(x,y,z) = trIndex[u];
        if(z<=h && !vis[v])
        {
            parent[v] = u;
            ret |= dfs(v , h, tr,trIndex);
        }
        if(ret) return ret;
    }
    return ret;
}


ll Cross(pll a,pll b,pll c)
{
    pll x = make_pair(b.first-c.first , b.second-c.second);
    pll y = make_pair(a.first-c.first , a.second-c.second);
    return abs(x.first*y.second - x.second*y.first);
}

int isInside(vector<tp>&tr , tp p)
{
    ll x1,y1,z1,x2,y2,z2 , x3,y3,z3;
    ll px,py,pz;
    tie(px,py,pz) = p;
    ll total = 0;
    tie(x1,y1,z1) = tr[0];
    tie(x2,y2,z2) = tr[1];
    tie(x3,y3,z3) = tr[2];
    total += Cross(make_pair(x1,y1) , make_pair(x2,y2) , make_pair(px,py));
    total += Cross(make_pair(x2,y2) , make_pair(x3,y3) , make_pair(px,py));
    total += Cross(make_pair(x1,y1) , make_pair(x3,y3) , make_pair(px,py));
    ll fulltr = Cross(make_pair(x1,y1) , make_pair(x3,y3) , make_pair(x2,y2));


    return fulltr==total;
}

int find_index(vector<vector<tp>>&trp , tp x)
{
    for(int i = 0 ; i<trp.size() ; i++)
    {
       if(isInside(trp[i] , x)) return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("hiking.in" , "r" , stdin);
    freopen("hiking.out" , "w" , stdout);
    int n;
    while(cin>>n)
    {
        vector<tp>triangleIndex(3*n );
        map<tp,int>mpIndex;

        vector<tp>v(3);
        vector<vector<tp> >trianglePoints(n);

        for(int i = 0 ; i<3*n ; i++)
            vadj[i].clear();

        int cnt = 0;
        for(int i= 0 ; i<n ; i++)
        {
            tp pev;
            for(int j = 0 ; j<3; j++)
            {
                int x,y,z;
                cin>>x>>y>>z;
                tp p = make_tuple(x,y,z);
                if(mpIndex.find(p)==mpIndex.end())
                {
                    mpIndex[p] = cnt++;
                    triangleIndex[cnt-1] = p;
                }
                v[j] = p;
            }

            for(int j = 0 ; j<3 ; j++)
            {
                vadj[mpIndex[v[j]]].push_back(mpIndex[v[(j+1)%3] ]);
                vadj[mpIndex[v[(j+1)%3]]].push_back(mpIndex[v[j] ]);
            }
            trianglePoints[i] = v;
        }

        int x,y,z;
        cin>>x>>y>>z;
        tp a = make_tuple(x,y,z);
        if(mpIndex.find(a)==mpIndex.end())
        {
            mpIndex[a] = cnt++;
            triangleIndex[cnt-1] = a;
//            cout<<" - "<<cnt-1<<endl;
        }
        cin>>x>>y>>z;
        tp b=  make_tuple(x,y,z);
        if(mpIndex.find(b)==mpIndex.end())
        {
            mpIndex[b] = cnt++;
            triangleIndex[cnt-1] = b;
//            cout<<" - "<<cnt-1<<endl;
        }

        int tmp = find_index(trianglePoints , a);
        for(auto pp : trianglePoints[tmp])
        {
            vadj[mpIndex[pp]].push_back(mpIndex[a]);
            vadj[mpIndex[a]].push_back(mpIndex[pp]);
        }
        tmp = find_index(trianglePoints , b);

        for(auto pp : trianglePoints[tmp])
        {
            vadj[mpIndex[pp]].push_back(mpIndex[b]);
            vadj[mpIndex[b]].push_back(mpIndex[pp]);
        }

        int low = 0 , high = 1000100;
        parent[mpIndex[a]] = -1;


        while(low<high)
        {
            memset(vis , 0 , sizeof vis);
            int mid = (low+high)>>1;
            if(dfs(mpIndex[a] , mid , mpIndex[b] , triangleIndex)==false)
                low = mid+1;
            else high = mid;
//            cout<<high<<" "<<low<<endl;
        }

        vector<tp>vsol;
        int u = mpIndex[b];
        while(u!=-1)
        {
            vsol.push_back(triangleIndex[u]);
//            cout<<u<<endl;
            u = parent[u];

        }
        cout<<vsol.size()<<endl;
        for(int i = (int)vsol.size()-1 ; i>=0 ; i--)
        {
            int x,y,z;
            tie(x,y,z) = vsol[i];
            cout<<x<<' '<<y<<' '<<z<<endl;
        }

    }
    return 0;
}
