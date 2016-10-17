#include <bits/stdc++.h>

using namespace std;

int cnt[1000000];
int arr[1000000];
int main()
{
    int n;
    while(cin>>n)
    {
        int mnidx = 1;
        for(int i = 1; i<=n ; i++)
        {
            int val ;
            cin>>val;
            if(val<=n)
            {
                cnt[val]++;
                mnidx = min(mnidx , val);
                arr[i] = val;
            }
            else arr[i] = -1;
        }
        int sol = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            if(arr[i]==-1)
            {
                while(cnt[mnidx]!=0)
                {
                    mnidx++;
                }
                arr[i] = mnidx;
                cnt[mnidx] = 1;
                mnidx++;
                sol++;
            }
            else if(cnt[arr[i]] >1)
            {
                cnt[arr[i]]--;
                while(cnt[mnidx]!=0)
                {
                    mnidx++;
                }
                cnt[mnidx] = 1;
                arr[i] = mnidx;
                mnidx++;
                sol++;
            }
        }

        //cout<<sol<<endl;
        for(int i = 1 ; i<=n ;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
    }
    return 0;
}
