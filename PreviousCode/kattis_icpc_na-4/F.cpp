#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct fInfo
{
    int n,m,k;
    VI vdeg;
    VVI vadj;
    vector<pair<int,int> > tail;

    fInfo(int n,int m,int k): n(n) , m(m) , k(k) , vdeg(n+1 , 0) , vadj(n+1) {}

    void addEdge(int u,int v)
    {
        vadj[u].push_back(v);
        vadj[v].push_back(u);
        vdeg[u]++;
        vdeg[v]++;
    }

    int dfs(int u,int par)
    {
        for(auto &v : vadj[u])
        {
            if(v==par || vdeg[v]>2) continue;
            return dfs(v ,u)+1;
        }
        return 1;
    }

    int bfs()
    {
        VI visited(n+1 , 0);
        queue<int>Q;

        for(int i = 1 ; i<=n ; i++)
        {
            if(vdeg[i]>1) continue;
            visited[i] = 1;
            Q.push(i);
        }
        int total = 0;
        while(!Q.empty())
        {
            int u = Q.front();
//            cout<<u<<endl;
            Q.pop();
            total++;
            for(auto &v: vadj[u])
            {
                if(visited[v]==0)
                {
                    vdeg[v]--;
                    if(vdeg[v]<=1)
                    {
                        visited[v]=1;
                        Q.push(v);
                    }
                }
            }
        }

        return total;
    }

    int process()
    {
        for(int  i=  1 ; i<=n ; i++)
        {
            if(vdeg[i]==1)
            {
                tail.push_back(make_pair(dfs(i , i) , i));
            }
        }


        sort(tail.begin() , tail.end());
        int len = (int)tail.size();



        vector<pair<int,int> >vtmp;
        for(int i = len-1 ; i>=0 ; i--)
        {
            //cout<<" okay "<<i<<endl;
            if(k>0)
            {
                vdeg[tail[i].second]++;
                k--;
            }
            else
            {
                vtmp.push_back(tail[i]);
            }
        }
        tail = vtmp;

//        for(auto &v: tail)
//        {
//            cout<<v.first<<" -> "<<v.second<<endl;
//        }

        return bfs();
    }
};

int main()
{
    int n,m,k;

    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        cin>>n>>m>>k;

        fInfo solver(n , m ,k);

        for(int i = 0 ; i<m ; i++)
        {
            int u,v;
            cin>>u>>v;
            solver.addEdge(u,v);
        }

        cout<<solver.process()<<endl;
    }
    return 0;
}
