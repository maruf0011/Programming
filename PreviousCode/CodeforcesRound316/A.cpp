#include <bits/stdc++.h>


using namespace std;

int arr[110][110];

int cnt[110];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int sol = 0;
        int solvalue = 0;
        memset(cnt, 0 , sizeof cnt);
        for(int i = 0 ; i<m  ; i++)
        {
            int mxidx = 0;
            int mxvalue = -1;
            for(int j  =0 ; j<n  ; j++)
            {
                int value;
                cin>>value;
                if(mxvalue<value)
                {
                    mxvalue = value;
                    mxidx = j;
                }
            }
            cnt[mxidx]++;
            if(cnt[mxidx]>solvalue)
            {
                sol = mxidx;
                solvalue = cnt[mxidx];
            }
            else if(cnt[mxidx]==solvalue && mxidx<sol)
                sol = mxidx;
        }
        cout<<sol+1<<endl;
    }
    return 0;
}
