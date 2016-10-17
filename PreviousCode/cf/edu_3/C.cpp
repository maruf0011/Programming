#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<long long>v(n);
        long long tot = 0;
        for(auto &x: v)
        {
            cin>>x;
            tot += x;
        }
        sort(v.begin() , v.end());
        long long need = tot / (long long)n;

        long long cnt = n - (tot- (need*n))  ,sol = 0;

        for(auto &x: v)
        {
            if(x<=need && cnt)
            {
                sol += (need-x);
                cnt--;
            }
            else if(x<=(need+1))
            {
                sol += (need+1-x);
            }
        }

        cout<<sol<<endl;
    }
    return 0;
}
