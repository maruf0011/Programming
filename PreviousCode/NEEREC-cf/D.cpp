
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int dir(vector<int>&a)
{
    if(a[1]<a[2]) return 1;
    return -1;
}

int isIntersect(vector<int>&a,vector<int>&b)
{
    int ret= 0;

    int s = max(min(a[1],a[2]) , min(b[1],b[2]));
    int f = min(max(a[1],a[2]) , max(b[1],b[2]));

    //cout<<s<<" -- "<<f<<endl;
    if(s<=f)
    {
        //if(((f-s+1)%2)==0) return 0;
        int sta = a[0]+abs(s-a[1]);
        int eda = a[0]+abs(f-a[1]);
        int stb = b[0]+abs(s-b[1]);
        int edb = b[0]+abs(f-b[1]);

        //cout<<sta<<" a "<<eda<<endl;
        //cout<<stb<<" b "<<edb<<endl;

        if(dir(a)==dir(b))
            return sta==stb;
        else
        {
            int st = max(min(sta,eda) , min(stb,edb));
            int ed = min(max(sta,eda) , max(stb,edb));
            return st<=ed;
        }

    }
    else return 0;
}

int main()
{
    int tcase,cas=1;

    int n;
    while(cin>>n)
    {
        VVI per(n , VI(3));

        for(int i = 0 ; i<n ; i++)
            for(int j = 0 ; j<3 ; j++)
                cin>>per[i][j];
        VI sol(n , 0);
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(i==j) continue;

                //cout<<" for i "<<i<<" and j "<<j<<endl;
                int ret = isIntersect(per[i] , per[j]);
                sol[i] += ret;
            }
        }

        for(int i= 0 ; i<n ; i++)
            cout<<sol[i]<<' ';
        cout<<endl;
    }
    return 0;
}
