#include <bits/stdc++.h>

using namespace std;


typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<pair<int,int> > VP;
typedef vector<VP> VVP;
typedef vector<pair<int,pair<int,string > > >VPP;

char arr[] = {'.' , 'G' , 'R' , 'S'};

struct defend
{
    int h;

    defend(int h): h(h){}


    char getTower(int mask,int idx)
    {
        return arr[(mask>>(idx*2))&3];
    }

    pair<int,pair<int,string> > __kill(int mask)
    {
        string str = "";
        int cost= 0;
        VI slow(10);
        for(int i = 0 ; i<10 ; i++)
        {
            str.push_back(getTower(mask , i));
            slow[i] = (str[i]=='S')+ (i==0 ? 0 : slow[i-1]);
            if(str[i]=='.') continue;
            cost += (str[i]=='S') ? 5 : (str[i]=='G' ? 3 : 10);
        }
        //if(str!="....GSSRRR") return make_pair(0 , make_pair(0 , "--"));
//        cout<<"string "<<str<<endl;

        int ret = 0;

        VP calc[2];
        int read = 0,write= 1;

        for(int i = 1 ; i<=10 ; i++)
        {
            calc[read].push_back(make_pair(i , h));
        }
//        cout<<"sisasf "<<calc[read].size()<<endl;
        for(int i = 0 ; i<=9 ; i++)
        {
//            cout<<i<<" --> "<<str[i]<<endl;
            calc[write].clear();

            int delay = max( 0 , (i-5) < 0 ? slow[i] : slow[i] - slow[i-5]);

            delay++;

//            cout<<" delay ::::: "<<delay<<endl;


            if(str[i]=='.' || str[i]=='S')
            {
                for(int j = 0; j<calc[read].size() ; j++)
                    calc[read][j].first += delay;
                calc[write] = calc[read];
                swap(read,write);
                continue;
            }

            sort(calc[read].begin() , calc[read].end());

//            for(int x = 0;  x<calc[read].size() ; x++)
//                cout<<" - "<<calc[read][x].first<<" "<<calc[read][x].second<<endl;

            if(str[i]=='G')
            {
                int next = -1;
                for(int j = 0 ; j<calc[read].size() ; j++)
                {
                    if(next==-1) next = calc[read][j].first;
                    int stay = next==-1 ? delay : max(0 , calc[read][j].first+delay - next);
//                    cout<<" --> "<<next<<" - "<<stay<<endl;
//                    cout<<" now "<<i<<" :: "<<j<<" -> "<<stay<<endl;
                    if(calc[read][j].second > stay)
                    {
                        calc[read][j].second -= stay;
                        calc[read][j].first += delay;
                        next = next+stay;

                        calc[write].push_back(calc[read][j]);
                    }
                    else next = next+calc[read][j].second;
                }

//                for(int x = 0;  x<calc[write].size() ; x++)
//                cout<<i<<" G --- "<<calc[write][x].first<<" "<<calc[write][x].second<<endl;
            }
            else
            {
                for(int j = 0  ; j<calc[read].size() ; j++)
                {
                    calc[read][j].second -= 4*((calc[read][j].first+delay-1)/3 - ((calc[read][j].first-1)/3));
                    calc[read][j].first += delay;
                    if(calc[read][j].second>0)
                        calc[write].push_back(calc[read][j]);
                }

                 //for(int x = 0;  x<calc[write].size() ; x++)
                //cout<<i<<" R --- "<<calc[write][x].first<<" "<<calc[write][x].second<<endl;
            }
            swap(read , write);
        }

        //cout<<"cost "<<cost<<" killed "<<10-calc[read].size()<<endl;

        return make_pair(cost , make_pair(10-calc[write].size() , str));
    }

    VPP process()
    {
        VPP ret;
        VI _cost(11 , -1);
        string _sol[12];
        for(int mask = 0 ; mask<(1<<20) ; mask++)
        {
//            if(mask!=703744) continue;
//            cout<<mask<<endl;
            pair<int,pair<int,string> > ret = __kill(mask);
            if(_cost[ret.second.first]==-1 || _cost[ret.second.first]>ret.first)
            {
                _cost[ret.second.first] = ret.first;
                _sol[ret.second.first] = ret.second.second;
            }
        }

        for(int i = 1 ; i<=10 ; i++)
        {
            if(_cost[i]!=-1)
                ret.push_back(make_pair(_cost[i] , make_pair(i , _sol[i])));
        }
        sort(ret.begin() , ret.end());
        return ret;
    }
};

int main()
{
    freopen("defend.in" ,"r" , stdin);
    freopen("defend.out" , "w" , stdout);
    int hp;

    while(cin>>hp)
    {
        defend df(hp);

        VPP sol = df.process();
        int kill = 0;
        for(int i = 0  ;i<sol.size()  ; i++)
        {
            if(sol[i].second.first>kill)
            {
                //reverse(sol[i].second.second.begin() , sol[i].second.second.end());
                printf("$%d -> kill %d with %s\n",sol[i].first , sol[i].second.first , &sol[i].second.second[0]);
                kill = sol[i].second.first;
            }
        }
    }
}
