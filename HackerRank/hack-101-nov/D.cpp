#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VU = vector<unsigned long long>;
using VVU = vector<VU>;

VVU bpow;
VU base;

struct Hash
{
    //VU base;
    VU HashValues;
    VU power;
    int sz;
    Hash(){}
    Hash(int sz):HashValues(sz , 0) , power(sz , 0) {}

    bool operator==(const Hash &h)const
    {
        for(int i = 0 ; i<power.size() ; i++)
            if(HashValues[i]!=h.HashValues[i]) return false;
        return true;
    }
    void addChar(char ch)
    {
        for(int i = 0 ; i<power.size() ; i++)
        {
            power[i]++;
            HashValues[i] *= base[i];
            HashValues[i] += (ch-'a');
        }
    }

    Hash operator-(const Hash &h)
    {
        Hash ret(h.sz);
        for(int i = 0 ; i<power.size(); i++)
        {
            ret.HashValues[i] = HashValues[i] - h.HashValues[i]*bpow[i][ power[i] - h.power[i] ];
        }
        return ret;
    }
    void printHash()
    {
        for(auto x: HashValues)
        {
            cout<<" H "<<x;
        }
        cout<<endl;
        for(auto y: power)
        {
            cout<<" p "<<y;
        }
        cout<<endl;
    }
};

int main()
{
    int n,q;
    ios_base::sync_with_stdio(false);

    while(cin>>n>>q)
    {
        string str;
        cin>>str;

        int mxlen = sqrt(n);
//        cout<<mxlen<<endl;

        VVI dp(n+2 , VI(mxlen+1 , 0));
        base = {3,5};

        bpow = VVU(2 , vector<ull>(n+10 , 0));
        bpow[0][0] = 1;
        bpow[1][0] = 1;
        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                bpow[i][j] = bpow[i][j-1]*base[i];
            }
        }
//        cout<<"OK"<<endl;
        vector<Hash>h(n+10);
        h[0] = Hash(base.size());
        for(int i = 0 ; i<n ; i++)
        {
            h[i+1] = h[i];
            h[i+1].addChar(str[i]);
        }

//        cout<<"OK"<<endl;
        for(int cur = n ; cur>0 ; cur--)
        {
            for(int len= 1 ; len<=mxlen ; len++)
            {
                if((cur+len-1)<=n)
                {
                    if((cur+len*2-1)<=n && (h[cur+len-1]-h[cur-1])==(h[cur+2*len-1]-h[cur+len-1]))
                        dp[cur][len] = dp[cur+len][len]+1;
                    else dp[cur][len] = 1;
                }
                else dp[cur][len] = 0;
            }
        }
//        cout<<"OK"<<endl;

        for(int i = 0 ; i<q ; i++)
        {
            int x,y;
            cin>>x>>y;

            if((y-x+1)<=mxlen)
            {
                cout<<dp[x][y-x+1]<<endl;
            }
            else
            {
                int length = y-x+1;
                Hash tmp = h[y] - h[x-1];
                int _pointer = x+length;

                int sol = 1;

                while(_pointer<=n)
                {
                    if((h[_pointer+length-1]-h[_pointer-1])==tmp) sol++ , _pointer+=length;
                    else break;
                }
                cout<<sol<<endl;
            }
        }
    }
    return 0;
}
