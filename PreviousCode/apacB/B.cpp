#include <bits/stdc++.h>

using namespace std;

#define maxx 100000


set<int>sp,sg,se;
vector<int>vext,vpadel;

int Find(int target)
{
    int n = sqrt(target);
    for(int i = 2 ; i<=n ; i++)
    {
        if((target%i)==0)
        {
            int v1= i;
            int v2 = target/i;

            if((se.count(v1) && sg.count(v2)) || (se.count(v2) && sg.count(v1))) return true;
        }
    }

    return false;
}



int main()
{
    freopen("bl.in" , "r+" , stdin);
    freopen("bl.out" , "w+" , stdout);
    ios_base::sync_with_stdio(false);
    int tcase,cas=1;

    cin>>tcase;


    while(tcase--)
    {
        int pp,ee,tt;

        cin>>pp>>ee>>tt;
        sp.clear();
        sg.clear();
        vext.clear();
        vpadel.clear();
        se.clear();

        for(int i= 0 ; i<pp ; i++)
        {
            int val;
            cin>>val;
            sp.insert(val);
            vpadel.push_back(val);
        }

        for(int i = 0 ; i<ee ; i++)
        {
            int val;
            cin>>val;
            vext.push_back(val);
            se.insert(val);
        }

        for(int i = 0 ; i<tt ; i++)
        {
            int val;
            cin>>val;
            sg.insert(val);
        }

        int m;
        cin>>m;

        cout<<"Case #"<<cas++<<":\n";

        for(int i = 0 ; i<m ; i++)
        {
            int p,q;

            cin>>p>>q;
            int issol = 0;
            for(int j = 0 ; j<vext.size() && !issol ; j++)
            {
                se.erase(vext[j]);
                for(int k =0  ; k<vpadel.size() && !issol ; k++)
                {
                    int now = vext[j]*vpadel[k];
                    if((now%p)==0)
                    {
                        int next = q*(now/p);
                        if(Find(next))
                        {
                            issol = 1;
                            break;
                        }
                    }
                }
                se.insert(vext[j]);
            }

            if(issol)
                cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}
