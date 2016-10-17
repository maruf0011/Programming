#include <bits/stdc++.h>


using namespace std;


typedef vector<int> VI;
int main()
{
    freopen("lca.in", "r" , stdin);
    freopen("lca.out" , "w" , stdout);
    int n;


    while(cin>>n && n)
    {
        VI a(2*n);

        for(int i = 0 ; i<n; i++)
        {
            cin>>a[i*2]>>a[(i*2) +1];
        }
        int cnt =0;
        int isokay = 0;
        int m;
        cin>>m;
        for(int i = 0 ; i<m ; i++)
        {
            int u,v;
            cin>>u>>v;

            if(isokay==0 && i<n && a[i*2]==u && a[i*2+1]==v)
            {
                cnt+=2;
//                cout<<"milse "<<endl;
            }
            else isokay = 1;
        }

        cout<<cnt+1<<endl;
        int idx = 0;
        int totnode = cnt+1;
        for(int i = 0 ; i<totnode ; i++)
        {
            if(cnt==0)
            {
                cout<<"0 0"<<endl;
                continue;
            }
            cout<<a[idx*2]<<' '<<a[idx*2+1]<<endl;
            if(a[idx*2]!=0)
                cnt -= 2;
            idx++;
        }


    }

    return 0;
}
