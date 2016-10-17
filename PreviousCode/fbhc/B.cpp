#include <bits/stdc++.h>

using namespace std;
char inp[2][1024];
int node[2][1024];
int sz[2048];

int main()
{
    freopen("bin.txt" , "r" ,stdin );
    freopen("bout.txt" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--)
    {
        int n;
        cin>>n;

        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                cin>>inp[i][j];
            }
        }

        int cnt = 0;
        memset(node , -1 , sizeof node);
        memset(sz , 0  ,sizeof sz);

        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(inp[i][j]=='.')
                {
                    if(!j || inp[i][j-1]=='X') node[i][j] = cnt++;
                    else node[i][j]  =node[i][j-1];
                    sz[node[i][j]]++;
                }
            }
        }

        int sol = cnt;

        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(sz[node[i][j]]==1 && sz[node[!i][j]]>=1)
                {
                    sol--;
                    sz[node[i][j]] = -1;
                    sz[node[!i][j]] = -1;
                }
            }
        }

        cout<<"Case #"<<cas++<<": "<<sol<<endl;
    }
    return 0;
}
