#include <bits/stdc++.h>

using namespace std;

#define maxx 101000

vector<int>vadj[maxx];
bool used[maxx];
int dist[maxx];
int visited[maxx];

typedef pair<int,int> pii;

pii dfs(int u,int cnt)
{
    //memset(visited , 0 , sizeof visited);
//    cout<<"came for sol "<<endl;
    dist[u] = 0;
    queue<int>Q;
    Q.push(u);
    visited[u] = cnt;
    pii ret = make_pair(u , 0);
    used[u] = true;

    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
//        cout<<now<<endl;
        for(int i= 0 ; i<vadj[now].size() ; i++)
        {
            int v = vadj[now][i];

            if(visited[v]!=cnt)
            {
                used[v] = true;
                visited[v] = cnt;
                dist[v] = dist[now]+1;
                Q.push(v);

                if(ret.second<dist[v])
                    ret = make_pair(v, dist[v]);
            }
        }
    }
    return ret;
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        for(int i = 0 ; i<=n ; i++)
        {
            vadj[i].clear();
            visited[i] = 0;
            used[i] = 0;
        }
        int cnt = 1;

        for(int i = 0 ; i<m ; i++)
        {
            int u,v;
            cin>>u>>v;
            vadj[u].push_back(v);
            vadj[v].push_back(u);
        }
        int mx = 0;
        vector<int>vdist;
        for(int i = 0 ; i<n ; i++)
        {
            if(!used[i])
            {
                //cout<<"for "<<i<<endl;
                pii ret = dfs(i , cnt++);
                ret = dfs(ret.first , cnt++);
                vdist.push_back(ret.second);
                //cout<<ret.second<<endl;
//                mx =  max( max(ret.second , mx), (mx+1)/2+(ret.second+1)/2 +1);
            }
        }

        vdist.push_back(0);
        vdist.push_back(0);
        sort(vdist.rbegin() , vdist.rend());


        mx = max({vdist[0] , (vdist[0]+1)/2+(vdist[1]+1)/2+1 , (vdist[2]+1)/2+(vdist[1]+1)/2+2});

        cout<<mx<<endl;

    }
    return 0;
}
