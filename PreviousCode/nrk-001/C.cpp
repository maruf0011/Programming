#include <bits/stdc++.h>

using namespace std;


long long cnt[30];

int main()
{
    freopen("concatenation.in","r" , stdin);
    freopen("concatenation.out","w" , stdout);
    string a,b;
    while(cin>>a>>b)
    {
        memset(cnt , 0 , sizeof cnt);
        for(int i =((int)b.size())-2; i>=0 ; i--)
        {
            cnt[b[i]-'a']++;
        }

//        for(int i = 0 ; i<25; i++)
//            cout<<i<<' '<<cnt[i]<<endl;
        long long tot = ((long long)a.size() *(long long)b.size());
        int tmpcnt = 0;
        for(int i =1  ;i<a.size() ; i++)
        {
            if(a[i]!=a[i-1])
            {
//                cout<<(a[i-1]-'a')<<" "<<cnt[a[i-1]-'a']<<" - "<<tmpcnt<<endl;
                tot -= cnt[a[i-1]-'a']*tmpcnt;
                tmpcnt = 1;
            }
            else tmpcnt++;
        }
//        cout<<tmpcnt<<endl;
        tot -= cnt[a[(int)a.size()-1]-'a']*tmpcnt;

        cout<<tot<<endl;
    }
}
