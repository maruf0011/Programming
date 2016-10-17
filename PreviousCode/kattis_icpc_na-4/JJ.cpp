#include <bits/stdc++.h>

using namespace std;


int rx[] = {0,1,0,-1};
int ry[] = {1,0,-1,0};

struct solve
{
    string str;
    solve(string str): str(str){}


    void process()
    {
        int x=0,y = 0;
        set<pair<int,int>>s;

        int dir= 0;
        int min_x = 0 , min_y = 0, max_x = 0,max_y = 0;
        s.insert(make_pair(x,y));
        for(int i = 0 ; i<str.size() ; i++)
        {
            if(str[i]=='F')
            {
            }
            else if(str[i]=='B')
            {
                dir += 2;
                dir %= 4;
            }
            else if(str[i]=='R') dir = (dir+1)%4;
            else dir = (dir-1+4)%4;
            x = x+rx[dir] , y = y+ry[dir];
            s.insert(make_pair(x,y));
//            cout<<x<<" -- "<<dir<<" "<<y<<endl;
            min_x = min(min_x , x);
            min_y = min(min_y , y);
            max_x = max(max_x , x);
            max_y = max(max_y , y);
        }

        min_x -= 1;
        max_x += 1;
        max_y += 1;
        cout<<max_x - min_x+1 <<" "<<max_y-min_y+1<<endl;
        for(int x = min_x ; x<=max_x ; x++)
        {
            for(int y = min_y ; y<=max_y  ; y++)
                if(s.count(make_pair(x,y))) cout<<'.';
                else cout<<'#';
            cout<<endl;
        }
    }
};


int main()
{
    int tcase,cas=1;
    cin>>tcase;
    cout<<tcase<<endl;
    while(tcase--)
    {
        string str;
        cin>>str;
        solve solver(str);
        solver.process();
    }
}
