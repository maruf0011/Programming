#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> PLL;
typedef vector<PLL> VP;

bool isokay(VP &v,long long tot)
{
//    cout<<"caome "<<tot<<endl;
    for(auto &x: v)
    {
        long long value= (long long)(100LL*x.second);
//        cout<<value<<endl;
        if(value>=(x.first*tot)) continue;
        else return false;
    }
//    cout<<"retr true "<<endl;
    return true;
}

bool chk(VP &v,long long low)
{
    if(low==0)
    {
        for(auto &x: v)
        {
            if(x.second==low) continue;
            else return false;
        }
    }
    else
    {
        for(auto &x: v)
        {
            long long value= (long long)((100LL*x.second)/low);
            //cout<<" -> "<<value<<" "<<x.second<<" "<<low  <<endl;
            if(value==0) value = 1;
            if(value == (x.first)) continue;
            else return false;
        }
    }
    return true;
}


long long find_sol(VP &v,long long max_file)
{
    long long low = 0 , high = max_file;

    while(low<high)
    {
        long long mid =(low+high+1)>>1;

        if(!isokay(v,mid))
            high = mid-1;
        else low = mid;
    }
//    cout<<" hehe "<<low<<endl;
    if(!chk(v , low))
    {
        return -1;
    }
    if( chk(v,low+1) ) return -1;
    if(low>0 && chk(v, low-1)) return -1;
    return low;
}


int bruteforce(VP &v)
{
    int cnt = 0;
    int sol = -1;
    for(int i = 0 ; i<=2001 ; i++)
    {
//        cout<<" i "<<i<<endl;
        if(chk(v , i))
        {
//            cout<<i<<endl;
            cnt++;
            sol = i;
        }
    }
    if(cnt==1) return sol;
    return -1;
}

int main()
{
    freopen("bsp.in" , "r+" , stdin);
    freopen("bsp.out" , "w+" , stdout);
    ios::sync_with_stdio(false);
    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        int n;
        cin>>n;
        VP inp(n);
        long long max_file = 0;
        for(int i = 0; i<n ; i++)
        {
            cin>>inp[i].first>>inp[i].second;
        }

        long long sol = -1;
        //sol = find_sol(inp , 1000000000000000000LL);
        sol = bruteforce(inp);
        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }
    return 0;
}
