#include <bits/stdc++.h>

using namespace std;

typedef pair<long,long> PLL;

typedef vector<PLL> VP;
#define X first
#define Y second


long long CP(PLL a,PLL b)
{
    return a.X*b.Y - b.X*a.Y;
}


PLL MV(PLL a,PLL b)
{
    return make_pair(b.first - a.first , b.second - a.second);
}


long long find_pos(int _start,int _end,PLL a,PLL x,PLL y,VP &p)
{
    int low = _start , high = _end;

    if(low==high)
    {
        long long tmp = CP(MV(a,x) ,MV(a , y)) * CP(MV(a , x) , MV(a , p[low]));
        if(tmp<=0) return -1;
    }

    long long idx = CP(MV(a,x) , MV(a,y));

    //cout<<" idx "<<idx<<endl;

    while(low<high)
    {
        int mid = (low+high+(idx<0))>>1;

        long long value = CP(MV(a,x) ,MV(a , y)) * CP(MV(a , x) , MV(a , p[mid]));
        //cout<<" mid "<<mid<<" -> "<<value<<endl;
        if(idx>=0)
        {
            if(value<=0)
                low = mid+1;
            else high = mid;
        }
        else
        {
            if(value<=0)
                high = mid-1;
            else low = mid;
        }
    }

    return low;
}


long long bsearch(int start,int n,PLL x,PLL y ,VP &p)
{
    if(CP(MV(p[start] , x)  ,MV(p[start] , y))==0) return 0;

    int low = start+2 , high = start+n-2;

    //cout<<" low "<<low<<" high :" <<high<<endl;


    long long _left = find_pos(low , high , p[start] , x,y ,p);
    long long _right = find_pos(low , high , p[start] , y,x,p);

    if(_left==-1 || _right==-1) return 0;

    long long ret = (_right-_left+1);

    //cout<<start<<" "<<x.first<<" - "<<x.second<<" ::: "<<y.first<<" "<<y.second<<"\n";
    //cout<<"---> "<<_left<<" "<<_right<<" "<<ret<<endl;
    return ret;
}

int main()
{
    freopen("kingdom.in" , "r" , stdin);
    freopen("kingdom.out" , "w" , stdout);
    int n;

    while(cin>>n)
    {
        if(n==0) break;
        VP p(2*n);

        for(int i = 0 ; i<n; i++)
        {
            cin>>p[i].first>>p[i].second;
        }

        for(int i = 0 ; i<n ; i++)
        {
            p[n+i] = p[i];
        }

        PLL x,y;
        cin>>x.first>>x.second;
        cin>>y.first>>y.second;

        //cout<<" okay  ------------ "<<endl;

        long long sol = 0;
        for(int i = 0 ; i<n ; i++)
        {
            sol += bsearch(i , n ,x,y,p);
        }

        cout<<sol/2LL<<endl;
    }
    return 0;
}



/**
5
0 0
6 0
6 4
3 6
0 4
4 1
1 4
4
0 0
4 0
4 4
0 4
1 1
3 1
*/
