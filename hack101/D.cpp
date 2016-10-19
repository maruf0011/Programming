#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pb push_back
#define clean(a,b) memset(a,b,sizeof(a))
#define oo 1<<20
#define dd double
#define ll long long
#define ull unsigned long long
#define ff float
#define EPS 10E-10
#define fr first
#define sc second
#define MAXX 10100
#define PRIME_N 1000000
#define INFI 1<<30
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define MODD 1000000007
#define paii pair<int,int>

//int rx[] = {0,-1,0,1,1,-1,-1,0,1}; //four direction x
//int ry[] = {0,1,1,1,0,0,-1,-1,-1};   //four direction y
//int rep[] = {1,1,4,4,2,1,1,4,4,2}; //repet cycle for mod
//void ullpr(){printf("range unsigned long long : %llu\n",-1U);} //for ull
//void ulpr(){printf("range unsigned long : %lu\n",-1U);} //for ull
//void upr(){printf("range unsigned : %u\n",-1U);} //for ull


string str;
int rnk[MAXX],sa[MAXX];
int cnt[MAXX] , nxt[MAXX];
bool bh[MAXX],b2h[MAXX];
int lcp[MAXX];


bool cmp(int i,int j)
{
    return str[i]<str[j];
}

void sortFirstChar(int n)
{
    /// sort for the first char  ...
    for(int i =0 ; i<n ; i++)
        sa[i] = i;
    sort(sa,sa+n ,cmp);

    ///indentify the bucket ........
    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0  || str[sa[i]]!=str[sa[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            rnk[sa[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = sa[j] - step;
        if(pre>=0)
        {
            int head = rnk[pre];
            rnk[pre] = head+cnt[head]++;
            b2h[rnk[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = sa[j] - step;
        if(pre>=0 && b2h[rnk[pre]])
        {
            for(int k = rnk[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
    return;
}

void buildsa(int n)
{
    ///start sorting in logn step ...
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
        /// cause n-h suffix must be sorted
        b2h[rnk[n-h]] = true;
        cnt[rnk[n-h]]++;

        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        ///set the new sorted suffix array ...
        for(int i =0 ; i<n ; i++)
        {
            sa[rnk[i]] = i;
            bh[i] |= b2h[i]; ///new bucket ....
        }
    }
    return;
}

void buildLCP(int n)
{
    int len = 0;
    for(int i = 0 ;i<n ; i++)
        rnk[sa[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = rnk[i];
        if(k==0)
        {
            lcp[k] = 0;
            continue;
        }
        int j = sa[k-1];
        while(str[i+len]==str[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

int findSol(int p,int q,int n)
{
    int total = 0;
    for(int i = 0 ; i<n ; i++)
    {
        int len = n-sa[i];
        int l = max(lcp[i]+1 , p);
        int r = min(len , q);
        if(l<=r)
        total += (r-l+1);
    }
    return total;
}

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;

int main()
{
    int tcase,cas=1;
    cin>>tcase;
    while(tcase--)
    {
        cin>>str;
        buildsa(SZ(str));
        buildLCP(SZ(str));
        int n = str.size();
        VVI cnt(n,VI(26,0));

        for(int i= 0; i<n ; i++) {
            if(i) {
                for(int j = 0 ; j<26 ; j++)
                    cnt[i][j] = cnt[i-1][j];
            }
            cnt[i][str[i]-'a'] += 1;
        }

        ll sol = 0;

        for(int i = 0 ; i<n; i++) {
            if()
        }

    }
    return 0;
}
