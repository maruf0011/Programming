#include <bits/stdc++.h>

#define maxx 100100

using namespace std;

using VI = vector<int>;
using PII = pair<int,int>;

int seg_v[maxx*4];
int seg_p[maxx*4];

void ini(int cur,int st,int ed,VI &L)
{
    if(st==ed){
        seg_p[cur] = st;
        seg_v[cur] = L[st];
        return;
    }
    int mid = (st+ed)>>1;

    ini(cur*2 , st ,mid,L);
    ini(cur*2+1 , mid+1 , ed, L);

    if(seg_v[cur*2]>seg_v[cur*2+1])
    {
        seg_v[cur] = seg_v[cur*2];
        seg_p[cur] = seg_p[cur*2];
    }
    else seg_v[cur] = seg_v[cur*2+1] , seg_p[cur] = seg_p[cur*2+1];
    return;
}

PII query(int cur,int st,int ed,int l,int r)
{
    if(st>r || ed<l) return {-1 , -1};
    if(st>=l && ed<=r) return {seg_v[cur], seg_p[cur]};
    int mid = (st+ed)>>1;
    PII r1 = query(cur*2 , st,mid, l,r);
    PII r2 = query(cur*2+1 , mid+1,ed,l,r);

    if(r1.first>r2.first) return r1;
    return r2;
}


long long find_sol(int l,int r,VI &L)
{
//    cout<<l<<" - "<<r<<endl;
//    getchar();
    if(l>r) return 0LL;

    if(l==r)
    {
        return L[l];
    }
    PII mx = query(1,0,((int)L.size())-1, l,r);
//    cout<<mx.first<<" "<<mx.second<<endl;

    long long ret = (long long)mx.first*(mx.second-l+1LL)*(r-mx.second+1LL);
    return ret+find_sol(l,mx.second-1,L)+find_sol(mx.second+1,r,L);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;

    while(cin>>n>>q){
        VI data(n);
        for(auto &v:data)
            cin>>v;

        VI L(n-1);
        int idx = 0;
        for(int i = 1 ; i<n ; i++)
        {
            L[idx++] = (abs(data[i]-data[i-1]));
        }

        ini(1,0,((int)L.size())-1 , L);

        for(int i = 0 ; i<q ; i++)
        {
            int l,r;
            cin>>l>>r;

            cout<<find_sol(l-1,r-2,L)<<endl;
        }
    }
    return 0;
}
