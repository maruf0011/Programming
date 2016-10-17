#include <bits/stdc++.h>


#define SZ(a) (int)a.size()

using namespace std;

typedef vector<int> VI;


int dx[] = {0 ,1, 0 , -1};
int dy[] = {1 , 0 ,-1 , 0};

struct dSolver
{
    int R,C,S;

    VI x,y;
    set<pair<int,int> >now,visited;
    vector<pair<int,int > >ins;
    dSolver(int R,int C,int S,int mx): R(R) , C(C) , S(S) ,x(mx) , y(mx){}

    void addIns(int tme ,char dir)
    {
        ins.push_back(make_pair(tme , dir=='L' ? -1 : 1));
    }

    int retx(int now)
    {
        if(now==(R+1)) return 1;
        if(now==0) return R;
        return now;
    }

    int rety(int now)
    {
        if(now==(C+1)) return 1;
        if(now==0) return C;
        return now;
    }

    int move_process(int &b,int &f,int curDir)
    {
        int tmpx = retx(x[f-1]+dx[curDir]);
        int tmpy = rety(y[f-1]+dy[curDir]);

        if(visited.count(make_pair(tmpx ,tmpy))>0)
        {
            now.erase(make_pair(x[b] , y[b]));
            b++;
            if(now.count(make_pair(tmpx , tmpy))>0)
            {
                now.insert(make_pair(0 , 0));
                return -1;
            }
            else
            {
                now.insert(make_pair(tmpx , tmpy));
                x[f] = tmpx, y[f] = tmpy;
                f++;
            }
        }
        else
        {
            now.insert(make_pair(tmpx , tmpy));
            visited.insert(make_pair(tmpx,tmpy));
            x[f] = tmpx, y[f] = tmpy;
            f++;
            if(!((tmpx+tmpy)&1))
            {
                now.erase(make_pair(x[b],y[b]));
                b++;
            }
        }
        return 1;
    }

    int process()
    {
        int f = 1,b = 0;


        now.insert(make_pair(1,1));
        x[0] = 1;
        y[0] = 1;
        visited.insert(make_pair(1,1));
        int isokay = 0;
        int curtime = 0;
        int curDir = 0;
        int sol = -1;
        for(int i = 0 ; i<ins.size() && sol==-1 ; i++)
        {
            while(curtime<ins[i].first)
            {
                curtime++;
                int ret = move_process(b,f,curDir);
                if(ret==-1) return now.size();
            }
            if(curtime == ins[i].first)
            {
                curtime++;
                curDir += ins[i].second;
                if(curDir==-1) curDir = 3;
                if(curDir==4) curDir = 0;
                int ret = move_process(b,f,curDir);
                if(ret==-1) return now.size();
            }
        }

        for(int i = 0 ; i<1000000; i++)
        {
            int ret = move_process(b,f,curDir);
            if(ret==-1) return now.size();
        }
        return now.size();
    }
};


int main()
{
    freopen("dl.in" , "r+" , stdin);
    freopen("dl.out" , "w+" , stdout);
    int tcase,cas=1;

    cin>>tcase;

    while(tcase--)
    {
        int r,c,s;
        cin>>s>>r>>c;
        dSolver ds(r,c,s,10000000);

        for(int i = 0 ; i<s ; i++)
        {
            int tme;
            char ch;
            cin>>tme>>ch;
            ds.addIns(tme , ch);
        }

        int sol = ds.process();

        printf("Case #%d: %d\n",cas++,sol);
    }
    return 0;
}
