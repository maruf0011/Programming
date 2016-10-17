#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>


using namespace std;

#include <cstring>
#include <vector>
#include <queue>

using namespace std;

double dp[513][513];

vector<pair<int,int> >vp;

double dist(pair<int,int> p1,pair<int,int>p2)
{
    //cout<<sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second))<<endl;
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

double rec(int cur,int last)
{
    if(cur==(int)vp.size())
    {
        return dist(vp[last] , vp[(int)vp.size()-1]);
    }

    double &ret=  dp[cur][last];
    if(ret > (-.5)) return ret;

    ret = (1LL<<55);
    //cout<<cur-1<<" "<<cur<<endl;
    ret = min(ret , rec(cur+1 , last)+dist(vp[cur-1] , vp[cur]));
    //cout<<" -< "<<last<<" "<<cur<<endl;
    ret = min(ret , rec(cur+1 , cur-1)+dist(vp[last] , vp[cur]));

    return ret;
}

int main()
{
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int n;
        cin>>n;

        vp.clear();

        for(int i = 0 ; i<n ; i++)
        {
            int x,y;
            cin>>x>>y;

            vp.push_back(make_pair(x,y));
        }

        memset(dp , -1 , sizeof dp);

        double sol = rec(1 , 0);

        printf("%.10lf\n",sol);
    }
    return 0;
}
