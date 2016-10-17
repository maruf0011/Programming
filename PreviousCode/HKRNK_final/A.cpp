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
#define MAXX 101000
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
    for(int i = 0 ; i<n ; i++)
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

        while((i+len)<str.size() && (j+len)<str.size() && str[i+len]==str[j+len]) len++;

        lcp[k] = len;
        if(len) len--;
    }
    return;
}

int nowCount[MAXX];
int segLength[4*MAXX];
int segUpd[4*MAXX];
int segLCP[4*MAXX];

/// update for LCP segment

void buildSegLcp(int cur,int st,int ed)
{
    if(st==ed)
    {
        segLCP[cur] = lcp[st];
        return;
    }

    int mid = (st+ed)>>1;
    buildSegLcp(cur*2 , st,mid);
    buildSegLcp(cur*2+1 , mid+1 , ed);

    segLCP[cur] = min(segLCP[cur*2] , segLCP[cur*2+1]);

    return;
}

int queryLCP(int cur,int st,int ed,int l,int r)
{
    if(st>r || ed<l) return (1<<30);

    if(st>=l && ed<=r) return segLCP[cur];

    int mid = (st+ed)>>1;
    return min(queryLCP(cur*2 , st,mid , l,r) , queryLCP(cur*2+1 , mid+1 , ed,l,r));
}

///update for used length of the lcp

void relax(int cur,int st,int ed)
{
    if(st!=ed)
    {
        //cout<<"prophageted "<<cur<<" "<<st<<" "<<ed<<" "<<segUpd[cur]<<endl;
        segUpd[cur*2] += segUpd[cur];
        segUpd[cur*2+1] += segUpd[cur];
    }

    segLength[cur] += segUpd[cur];
    segUpd[cur] = 0;
    return;
}

void updateLength(int cur,int st,int ed,int l,int r,int val)
{
    //cout<<"cur "<<cur<<" st "<<st<<" ed "<<ed<<endl;
    if(segUpd[cur]) relax(cur , st,ed);

    if(st>r || ed<l ) return;
    if(st>=l && ed<=r)
    {
        //cout<<"updated "<<endl;
        segUpd[cur] += val;
        relax(cur , st,ed);
        return;
    }
    int mid = (st+ed)>>1;
    updateLength(cur*2 , st ,mid , l,r,val);
    updateLength(cur*2+1 , mid+1 , ed,l,r,val);

    return;

}

int queryLength(int cur,int st,int ed,int idx)
{
    if(segUpd[cur]) relax(cur,st,ed);

    if(st==ed)
    {
        //cout<<"return for st "<<st<<" "<<segLength[cur]<<endl;
        return segLength[cur];
    }

    int mid = (st+ed)>>1;

    if(idx<=mid)
        return queryLength(cur*2 , st,mid , idx);
    else return queryLength(cur*2+1 , mid+1 , ed,idx);

    return 0;
}

/// ----------------------- solution process .................

int findLocation(int st,int ed,int n,int value)
{
    int low = st,high = ed;
    while(low<high)
    {
        int mid = (low+high+1)>>1;
        int tmp = queryLCP(1,0,n-1 , st , mid);
        if(tmp<value)
            high = mid-1;
        else low = mid;
    }
    if(lcp[low]<value) low--;
    return low;
}


bool check_for_null()
{
    for(int i = 0 ; i<26 ; i++)
    {
        int okay = 1;
        int cnt = 0;
        for(int j = 0 ; j<str.size() ; j++)
        {
            if(str[j]==(i+'a'))
            {
                cnt++;
                okay &= (j%2);
            }
        }
        if(okay && cnt>=1) return true;
        if(cnt==1) return true;
    }
    return false;
}

string find_solution(int n,int k)
{
    memset(segUpd ,  0 , sizeof segUpd);
    memset(segLength , 0 , sizeof segLength);
    memset(nowCount , 0 , sizeof nowCount);

    for(int i = 0 ; i<n ; i++)
    {
        //cout<<" kha "<<sa[i]<<endl;
        if(i==0)
        {
            nowCount[i]= sa[i]%2;
        }
        else nowCount[i] = nowCount[i-1] + (sa[i]%2);
    }

    int sum = 0;
    //k--;
    int isfirst = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(sa[i]%2)
        {
            //cout<<" -------------------------------------- now staring "<<i<<endl;
            int len = queryLength(1,0 , n-1 , i)- isfirst ;
            //cout<<"qlen "<<len<<endl;
            isfirst = 1;
            for(int j = len ; j<=n-sa[i] ; j++)
            {
                //cout<<"for every len "<<j<<endl;
                int tmp = findLocation(i+1 , n-1 , n , j);
                int tmp2 = findLocation(i+1 , n-1 , n , j+1);

                int tmpcount  = nowCount[tmp] - (i==0 ? 0 : nowCount[i-1]);
                int tmpcount2= nowCount[tmp2] - (i==0 ? 0 : nowCount[i-1]);
                //cout<<" tmp "<<tmp<<" tmpcount "<<tmpcount<<endl;
                updateLength(1,0 , n-1 , i , tmp , 1);
                if(j==0) tmpcount = 1;
                if(tmpcount2 != (tmp2-i+1))
                {
                    continue;
                }
                else if(tmpcount < k)
                {
                    k -= tmpcount;
                }
                else
                {
                    return str.substr(sa[i] , j);
                }
            }
        }
    }

    return "no solution";
}

int main()
{
    int k;
    int tcase,cas=1;

    while(cin>>str)
    {
        cin>>k;

        int n = str.size();
        buildsa(n);
        buildLCP(n);

        buildSegLcp(1, 0 , n-1);



        string sol = find_solution(n , k);
        if(sol=="") sol = "-";

        if(str.size()==1 && k==1) sol = "-";
        cout<<sol<<endl;
    }
    return 0;
}
