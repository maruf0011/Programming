//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
//#include "/media/ridowan/0D1ECD4233D83EF2/Ridowan/Prob setter/testlib/testlib.h"
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector< int >

//const double EPS = 1e-9;
//const int INF = 0x7f7f7f7f;

#define MN 100000

struct node {
    int st,fn;
    multiset<int> m;
}tr[MN*4+100];

int n,sm;
int jy[MN+1];
int pr[MN+1];
int tp[MN+1];
int wt[MN+1];
int cnt[MN+1];
int dg[MN+1];
int ss[MN+1];
int du[MN+1];
int vl[MN+1];

void init(int p, int st, int fn) {
    tr[p].st = st;
    tr[p].fn = fn;
    tr[p].m.clear();
    if(st==fn) return;

    int md = (tr[p].st + tr[p].fn)>>1, lf = (p<<1)+1, rt = lf+1;
    init(lf,st,md);
    init(rt,md+1,fn);
}

int query(int p, int v) {
    //cerr<<tr[p].st<<' '<<tr[p].fn<<' '<<v<<'\n';
    if(tr[p].m.empty() || (*(tr[p].m.rbegin()))<=v) return -1;
    if(tr[p].st==tr[p].fn) return du[tr[p].st];
    int lf = (p<<1)+1, rt = lf+1;
    int r = query(rt, v);
    return (r==-1)?query(lf, v):r;
}

void update(int p, int i, int v, bool isInsert) {
    if(isInsert) tr[p].m.insert(v);
    else tr[p].m.erase(tr[p].m.find(v));
    if(tr[p].st==tr[p].fn) return;

    int md = (tr[p].st + tr[p].fn)>>1, lf = (p<<1)+1, rt = lf+1;
    if(i<=md) update(lf, i, v, isInsert);
    else update(rt, i, v, isInsert);
}

vector<pii> g[MN+1];
vector<int> fn[MN+1];
map<int,stack<int>> chk;
map<int,stack<int>> ::iterator it;

int findPr(int u) {
    return pr[u]==u?u:(pr[u]=findPr(pr[u]));
}

int dfs(int u, int ds, int sm) {
    //cerr<<u<<' '<<ds<<' '<<sm<<'\n';
    int i,j = g[u].size(), rm = -1, v;
    du[ds]=u;
    dg[u]=ds;

    vl[u] = sm + jy[u];
    if((it=chk.find(vl[u]))!=chk.end() && !(it->ss.empty())) {
        v = it -> ss.top();
        rm = findPr(v);
    }
    chk[vl[u]].push(u);

    int q = query(0, vl[u]);

    //cerr<<' '<<u<<' '<<rm<<' '<<q<<' '<<vl[u]<<' '<<ds<<' '<<sm<<'\n';

    if(rm==-1 || (q!=-1 && dg[q]>dg[rm])) rm = q;

    if(rm!=-1) {
        fn[rm].PB(u);
    }

    update(0, ds, sm, true);

    j=0;
    for(i=0;i<g[u].size();i++) {
        cnt[u] += dfs(g[u][i].ff, ds + 1, sm + g[u][i].ss);
        pr[g[u][i].ff] = u;
        while(j<fn[u].size()) {
            chk.find(vl[fn[u][j]])->ss.pop();
            cnt[u]--;
            j++;
        }
    }

    update(0, ds, sm, false);

    /*for(i=0,j=fn[u].size();i<j;i++) {
        chk.find(vl[fn[u][i]])->ss.pop();
        cnt[u]--;

        289962 diff
    }*/
	return cnt[u];
}


int main() {
	//READ("test.in");
	READ("village_fair_2.in");
	WRITE("village_fair_2_red.out");
	//registerValidation();
	int T,I,i;
	//T = inf.readInt(1,10,"T");
	//inf.readLine();
	cin>>T;
	//cerr<<T<<'\n';
	for(I=1;I<=T;I++) {
        //cerr<<I<<'\n';
        /*n = inf.readInt(1, MN,"N");inf.readLine();
        cerr<<n<<'\n';
		jy[1] = inf.readInt(0, 1000,"jy[1]");
		for(i=2;i<=n;i++) {
			inf.readSpace();
			jy[i] = inf.readInt(0, 1000,"jy["+to_string(i)+"]");
			scanf("%d",&jy[i]);
		}
		inf.readLine();
		tp[1] = inf.readInt(0, 0,"tp[1]");
		for(i=2;i<=n;i++) {
			inf.readSpace();
			tp[i] = inf.readInt(1, n,"tp["+to_string(i)+"]");
		}
		inf.readLine();
		wt[1] = inf.readInt(0, 0,"wt[1]");
		for(i=2;i<=n;i++) {
			inf.readSpace();
			wt[i] = inf.readInt(-1000, 1000,"wt["+to_string(i)+"]");
		}
		inf.readLine();*/

		cin>>n;
		for(i=1;i<=n;i++) {
            scanf("%d",&jy[i]);
            //assert(jy[i]<=1000);
		}
		for(i=1;i<=n;i++) {
            scanf("%d",&tp[i]);
            //assert(tp[i]>=0);
		}
		for(i=1;i<=n;i++) scanf("%d",&wt[i]);

		for(i=1;i<=n;i++) {
			pr[i]=i;
			g[i].clear();
			fn[i].clear();
			cnt[i]=1;
		}

		for(i=2;i<=n;i++) {
            //cerr<<i<<' '<<tp[i]<<' '<<wt[i]<<'\n';
			g[tp[i]].PB(pii(i,wt[i]));
		}

		chk.clear();

		init(0,0,n-1);

		dfs(1,0,0);
        //cerr<<cnt[1]<<'\n';
		cout<<"Case "<<I<<":\n";
		for(i=1;i<=n;i++) printf("%d\n", cnt[i]);
	}
	//inf.readEof();
	return 0;
}
