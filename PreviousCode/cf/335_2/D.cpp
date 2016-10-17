#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VP  = vector<pair<int,int>>;

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        int idx = 0;
        VP in(n-1);
        VP out(m-n+1);

        int x,y;
        for(int i = 0 ;i<m ; i++)
        {
            cin>>x>>y;
            if(y)
                in[idx++] = {x,i};
            else out[i-idx] = {x,i};
        }

        sort(in.begin() , in.end());
        sort(out.begin() , out.end());

        idx = 0;
        VP sol(m);
        for(int i = 0 ; i<in.size() ; i++)
            sol[in[i].second] = make_pair(i+1 , i+2);

        for(int i = 1 ; i<in.size() ; i++)
        {
            int u = 1;
            int v = i+2;
            while(idx<out.size() && out[idx].first>=in[i].first && u<v-1)
            {
                sol[out[idx].second] = {u , v};
                u++;
                idx++;
            }
        }
        if(idx!=out.size())
        {
            cout<<"-1"<<endl;
        }
        else
        {
            for(auto &x: sol)
            {
                cout<<x.first<<" "<<x.second<<endl;
            }
        }
    }
    return 0;
}
