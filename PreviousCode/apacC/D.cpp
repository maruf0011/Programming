#include <bits/stdc++.h>

using namespace std;


typedef vector<long long> VL;
typedef vector<VL > VVL;
multiset<int>s[3010];

int main()
{

    freopen("dl.in" , "r+" , stdin);
    freopen("dl.out" , "w+" , stdout);

    ios::sync_with_stdio(false);

    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        long long x,c;
        int n,k,m;
        cin>>n>>m>>c>>x;

        for(int i = 0 ; i<=n ; i++)
        {
            s[i].clear();
        }

        VL a(n+1) , b(n+1);
        for(int i = 1 ; i<=n ; i++)
            cin>>a[i];
        for(int i = 1  ;i<=n ; i++)
            cin>>b[i];

        int last = 1;

        VL tmp(n+1);

        long long sol = 0;

        for(int j = 1 ; j<=n  ; j++)
        {
//            cout<<"now "<<j<<endl;
            if(j-last>=m)
            {
                for(int i = 1 ; i<=n ; i++)
                {
                    long long val = (a[i]*i+b[last]*last+c)%x;
                    s[i].erase(s[i].find(val));
                }
                last++;
            }
            int last2 = 1;
            multiset<long long>stmp;
            for(int i = 1 ; i<=n ; i++)
            {
//                cout<<"why "<<i<<endl;
                if(i-last2>=m)
                {
                    stmp.erase(stmp.find(tmp[last2]));
                    last2++;
                }

                long long val = (a[i]*i+b[j]*j+c)%x;
//                cout<<val<<endl;
                s[i].insert((val));
                tmp[i] = *s[i].rbegin();
                stmp.insert(tmp[i]);
//                cout<<tmp[i]<<endl;

                if((i-last2+1)==m && (j-last+1)==m)
                {
//                    cout<<"okay"<<endl;
                    sol += *stmp.rbegin();
                }
            }
//            cout<<"done "<<j<<endl;
        }
        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }
    return 0;
}
