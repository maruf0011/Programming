//Programming Contest Template
//Shafaet Ashraf 
#include <bits/stdc++.h>

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<int,int>
#define pmp make_pair
#define uu first
#define vv second
using namespace std;
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1LL<<(pos)))
#define off(n,pos)  n & ~(1LL<<pos)
#define ison(n,pos) (bool)(n & (1LL<<(pos)))
string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define mx 100002

int joy[mx];
int edg[mx];
int in[mx];
int cost[mx];
int ans[mx];
vector<int>kid[mx];
set<int>ms[mx];
int main()
{
	READ("village_fair_2.in");
	WRITE("village_fair_2_sf.out");
    int t,ks=0;
    cin>>t;
    while(t--)
    {

        mem(in, 0);
        int n;
        cin>>n;
        repl(i, n){
            ms[i].clear();
            kid[i].clear();
            cin>>joy[i];
            ms[i].insert(joy[i]);
            kid[i].pb(i);
        }
        repl(i,n){
            cin>>edg[i];
            in[edg[i]]++;
        }
        repl(i,n)
        {
            cin>>cost[i];
        }
        
        queue<int>q;
        repl(i,n){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            
            q.pop();
            int v=edg[u];
            if(v==0)continue;
            in[v]--;
            
            if(in[v]==0)
            {
                q.push(v);
            }
            rep(i, sz(kid[u]))
            {
                    int id=kid[u][i];
                    kid[v].pb(id);
            }
            
            foreach(it, ms[u])
            {
                int j=*it;
                j=j+cost[u];
                if(j>=0)
                ms[v].insert(j);
            }
            ans[u]=sz(ms[u]);
            ms[u].clear();
            kid[u].clear();
            
        }
        ans[1]=sz(ms[1]);
        printf("Case %d:\n",++ks);
        repl(i,n)
        {
            printf("%d\n",ans[i]);
        }
        //cout<<1<<" -> "<<sz(ms[1])<<endl;
        
    }
    return 0;
}
