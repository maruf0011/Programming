/**
	mod values
	 -> 999917
	 -> 999931
	 -> 999953
	 -> 999959
	 -> 999961
	 -> 999979
	 -> 999983
*/


#include "bits/stdc++.h"

using namespace std;

#define ll long long

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<bool> VVB;


typedef vector<ll>VL;
typedef vector<VL>VVL;


ll base[] = {2,3,5,7,11}

struct Hash
{
	int baseLen;
	vector<ll>value;
	Hash(baseLen) : baseLen(baseLen) , value(baseLen, 0LL);

	bool operator<(const Hash &b)const
	{
		for(int i = 0 ; i<baseLen ; i++)
		{
			if(value[i]==b.value[i]) continue;
			else if(value[i]<b.baseLen[i])
				return true;
			else return false;
		}
		return false;
	}

	bool operator==(const Hash &b)const
	{
		for(int i = 0 ; i<baseLen ; i++)
		{
			if(value[i]==b.value[i]) continue;
			else return false;
		}
		return true;
	}
};

struct I
{
	int baseLen;

	VVB grid;
	ll mod;
	int row,col;

	I(int row,int col , int baseLen,ll mod):mod(mod) , row(row) ,col(col) , baseLen(baseLen),grid(r, VB(c , false)) {}

	ll bigmod(ll b,ll p,ll m)
	{
		if(p==0) return 1;
		ll ret = bigmod(p/2);
		ret = (ret*ret)%m;
		if(p&1LL) ret= (ret*b)%m;
		return ret;
	}

	Hash build_first(int start_row,int start_col , int rsize,int csize , VVL &v)
	{
		v = VVL(rsize , VL(baseLen , 0));
		
		Hash ini(baseLen);

		for(int b_idx= 0 ; b_idx<baseLen ; b_idx++)
		{
			for(int i = 0 ; i<rsize ; i++)
			{
				ll tmp = 0LL;
				for(int j = csize-1 ; j>-0 ; j--)
				{
					tmp =  (grid[start_row+i][start_col+j]*bigmod(base[b_idx] , csize - j-1 , mod))%mod;
				}
				v[i][b_idx] = tmp;
				ini.value[b_idx] += (tmp*bigmod(base[b_idx] , i*csize , mod))%mod;
				ini.value[b_idx] %= mod;
			}
		}
		return ini;
	}

	Hash calc(int start_row,int start_col , int rsize,int csize , VVL &v)
	{
		Hash ini(baseLen);

		for(int b_idx= 0 ; b_idx<baseLen ; b_idx++)
		{
			for(int i = 0 ; i<rsize ; i++)
			{
				if(grid[start_row+i][start_col-1]==true)
				{
					v[i][b_idx] -= bigmod(base[b_idx] , csize-1 , mod);
					v[i][b_idx] %= mod;
					v[i][b_idx] += mod;
					v[i][b_idx] %= mod;
				}

				v[i][b_idx] = (v[i][b_idx]*base[b_idx])%mod;
				v[i][b_idx] = (v[i][b_idx] + grid[i+start_row][start_col+csize-1])%mod;

				ini.value[b_idx] += (v[i][b_idx]*bigmod(base[b_idx] , csize*i , mod))%mod;
				ini.value[b_idx] %= mod;
			}
		}
		return ini;
	}

	pair<int,int> getPattern(VVB &pat)
	{
		Hash _pathash(baseLen);
		/// calc hash for pat
		for(int i = 0 ; i<baseLen ; i++)
		{
			_pathash.value[i] = 0LL;
			for(int j = 0 ; j<pat.size();  j++)
			{
				ll tmp = 0;
				for(int k = pat[j].size() ; k>=0 ; k--)
				{
					tmp  = (tmp + pat[j][k]*bigmod(base[i] , pat[j].size() - k-1 , mod))%mod;
				}
			}
			tmp = (tmp*bigmod(base[i] , pat[j].size()* j , mod))%mod;
			_pathash.value[i] = (_pathash.value[i]+tmp)%mod;
		}

		///-----------------check---

		VVL rowHash(pat.size() , VL(baseLen , 0));
		for(int sr_idx = 0 ; sr_idx < grid.size()-pat.size() ; sr_idx++)
		{

			for(sc_idx = 0 ; sc_idx < (grid[sr_idx].size() - pat[0].size()) ; sc_idx++)
			{
				if(sc_idx==0)
				{
					Hash found = build_first(sr_idx , sc_idx , pat.size() , pat[0].size() , rowHash);
				}
				else
				{
					Hash found = calc(sr_idx , sc_idx , pat.size() , pat[0].size() , rowHash);
				}
				if(found==_pathash) return make_pair(sr_idx , sc_idx);
			}
		}

		return make_pair(-1,-1);
	}
};


int main(int argc, char const *argv[])
{
	int baseLen = 1;
	ll mod = 999917LL;
	
	int row,col;

	cin>>row>>col;

	I isolver(row , col , baseLen , mod);

	for(int i = 0 ; i<row ; i++)
	{
		for(int j = 0 ; j<col; j++)
		{
			char ch;
			cin>>ch;
			isolver.grid[i][j] ==
		}
	}

	return 0;
}