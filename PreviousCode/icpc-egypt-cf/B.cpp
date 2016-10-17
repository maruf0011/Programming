#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--){
        int q,m;
        cin>>q>>m;

        vector<int>vsol(q , 15);

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<q ; j++)
            {
                char x,y;
                cin>>x>>y;
                if(y=='T')
                    vsol[j] = (1<<(x-'A'));
                else vsol[j] &= (15-(1<<(x-'A')));
            }
        }
        int f = 0;
        for(auto &v: vsol)
        {
            if(f) cout<<' ';
            else f = 1;
            if(__builtin_popcount(v)==1)
            {
                if(v==1) cout<<'A';
                else if(v==2) cout<<'B';
                else if(v==4) cout<<'C';
                else if(v==8) cout<<'D';
            }
            else cout<<'?';
        }
        cout<<endl;
    }
    return 0;
}
