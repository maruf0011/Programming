#include <bits/stdc++.h>

using namespace std;

using VI =  vector<int>;

struct pq
{
    int n,d;
    pq(){}
    pq(int n,int d):n(n),d(d){}
    bool operator<(const pq &b)const
    {
        return d<b.d;
    }
};

int main()
{
    int n;

    while(cin>>n)
    {
        VI d(n+1);
        priority_queue<pq>PQ;

        for(int i =1 ; i<=n ; i++)
        {
            cin>>d[i];
            PQ.push(pq(i , d[i]));
        }

        //cout<<PQ.top().n<<endl;

        queue<int>Q;
        Q.push(PQ.top().n);
        VI par(n+1);
        par[PQ.top().n] = 0;
        PQ.pop();

        while(!Q.empty())
        {
            int now = Q.front();Q.pop();
            while(d[now])
            {
                pq tmp = PQ.top();PQ.pop();
                par[tmp.n] = now;
                d[now]--;
                d[tmp.n]--;
                if(d[tmp.n]) Q.push(tmp.n);
            }
        }

        for(int i = 1; i<=n ; i++)
            cout<<par[i]<<endl;
    }
    return 0;
}
