#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        VI a(n);
        VI diff(n);
        VI sum(n , 0);
        for(int i = 0 ; i<n ; i++)
        {
            cin>>a[i];
        }

        sort(a.begin() , a.end());


        for(int i = 1 ; i<n ; i++)
        {
            diff[i] = abs(a[i]-a[i-1]);
            sum[i] = sum[i-1]+diff[i];
        }

        VI idx;
        VI flag(n , 0);
        for(int i = 0 ; i<n ; i++)
        {
            if(flag[i]) continue;
            int cnt= 0;
            for(int j = i ; j<n ; j+=k)
            {
                flag[j] = 1;
                cnt++;
            }
            idx.push_back(cnt);
        }
        sort(idx.begin() , idx.end());
        int mn = idx[0] , mx = idx[idx.size()-1];
        int sol = 0;
        cout<<mn<<" "<<mx<<endl;
        for(int i = 0 ; i<n ; i++)
        {
            cout<<i<<" -- "<<sol<<endl;
            if(i==0)
            {
                sol += sum[i+mx-1] - sum[i];
                i = i+mx-1;
            }
            else
            {
                sol += (sum[i+mn-1] - sum[i-1]);
                i=  i+mn-1;
            }
            cout<<i<<" -- "<<sol<<endl;
        }

        int tmp = sol;
        sol = 0;
        for(int i = n-1 ; i>= 0 ;i--)
        {
            if(i==n-1)
            {
                sol += sum[i] - sum[i-mx+1];
                i = i-mx+1;
            }
            else
            {
                sol += sum[i] - sum[i-mn+1];
                i = i-mn+1;
            }
        }
        sol = min(sol , tmp);
        cout<<sol<<endl;
    }
    return 0;
}
