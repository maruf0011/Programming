#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define sz(a) ((int)a.size())

using ll = long long;
using VI  = vector<int>;
using VVI = vector<VI>;
using pii = pair<int,int>;
using VP = vector<pii>;
int n;
int calcPos(VI &data,VVI &g,int node)
{
    int ret=-1;

    VI wc(n , 0);
    VI pos(n , -1);

    int curNode = data[n-1];

    for(int i = sz(data)-2 ; i>=0 ; i--)
    {
        if(g[curNode][data[i]])
        {
            wc[curNode]++;
        }
        else
        {
            wc[data[i]]++;
            curNode = data[i];
        }
    }

    for(int i = 0 ; i<n ; i++)
        cout<<i <<" wc "<<wc[i]<<endl;

    pos[curNode] = 1;

    VP slist;
    int idx = 2;
    for(int i = 0 ; i<n ; i++)
    {
        if(i==curNode) continue;
        slist.push_back({ wc[i] , i });
    }

    sort(slist.begin() , slist.end());

    for(int i = sz(slist)-1 ; i>=0 ; i--)
    {
        if(i==(sz(slist)-1) || (slist[i].x!=slist[i+1].x))
            pos[slist[i].y] = idx++;
        else pos[slist[i].y] = pos[slist[i+1].y];
    }
    for(int i = 0 ; i<n ; i++)
    {
        cout<<i<<" pos "<<pos[i]<<endl;
    }
    return pos[node];
}

int posMax(VVI &g,VP &s,int node)
{
    VI data(n);
    VI flag(n , 0);
    int idx = n-1;
    data[idx--] = node;
    flag[node] = 1;

    for(int i = 0 ; i<n ; i++)
    {
        if(i==node || !g[node][i]) continue;
        data[idx--] = i;
        flag[i] = 1;
    }
    idx = 0;
    for(int i = sz(s)-1 ; i>=0 ; i--)
    {
        if(flag[s[i].y]) continue;
        data[idx++]= s[i].y;
    }

    for(int i =0 ; i<n ; i++)
    {
        cout<<" - "<<data[i]<<endl;
    }
    int pos = calcPos(data , g , node);
    return pos;
}

int posMin(VVI &g,VP &s,int node)
{
    VI data(n);
    VI flag(n , 0);
    int idx = 0;
    data[idx++] = node;
    flag[node] = 1;

//    for(int i = 0 ; i<n ; i++)
//    {
//        if(i==node || !g[node][i]) continue;
//        data[idx--] = i;
//        flag[i] = 1;
//    }
//    idx = 0;
    for(int i = sz(s)-1 ; i>=0 ; i--)
    {
        if(flag[s[i].y]) continue;
        data[idx++]= s[i].y;
    }
    int pos = calcPos(data , g , node);
    return pos;
}

int main()
{
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        cin>>n;

        VVI g(n , VI(n , 0));

        for(auto &x: g)
            for(auto &y: x)
                cin>> y;

        VP slist;

        for(int i = 0 ; i<n  ; i++)
        {
            int cnt = 0;
            for(int j =0 ; j<n ; j++)
                cnt+= g[i][j];

            slist.push_back({cnt , i});
        }

        sort(slist.begin() , slist.end());

        VP sol;

        for(int i = 0 ; i<n ; i++)
        {
            int mx = posMax(g , slist , i);
            int mn = posMin(g , slist , i);

            cout<<i<<" "<<mx<<" "<<mn<<endl;
        }
    }
    return 0;
}
