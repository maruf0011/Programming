#include <bits/stdc++.h>

#define maxx 100100
#define sz(a) (int)a.size()

using namespace std;

using pii = pair<int,int>;
using vp = vector<pii >;
using vi = vector<int>;

int seg[4*maxx];

void ini(int cur,int st,int ed,vp &v){
	if(st==ed){
		seg[cur] = v[st].second;
		return;
	}

	int mid = (st+ed)/2;
	ini(cur*2,st,mid,v);
	ini(cur*2+1,mid+1,ed,v);

	seg[cur] = max(seg[cur*2],seg[cur*2+1]);
	return;
}

int find_max(int cur,int st,int ed,int l,int r){
	if(st>r || ed<l) 
		return -1;
	if(st>=l && ed<=r){
		return seg[cur];
	}
	int mid = (st+ed)/2;
	return max(find_max(cur*2,st,mid,l,r) , find_max(cur*2+1,mid+1,ed,l,r));
}

int lower_bound(int target,vp &v){
	int low = 0 , high = sz(v)-1;

	while(low<high){
		int mid = (low+high)>>1;
		if(v[mid].first<target)
			low = mid+1;
		else high = mid;
	}
	if(v[low].first>=target) return low;
	return -1;
}

int heigher_bound(int target,vp &v){
	int low = 0 , high = sz(v)-1;

	while(low<high){
		int mid = (low+high+1)>>1;
		if(v[mid].first>target)
			high = mid-1;
		else low = mid;
	}
	if(v[low].first<=target) return low;
	return -1;
}

int main(){
	int n,k;
	string s;

	while(cin>>n>>k){
		cin>>s;

		int total = 0;
		
		int root = 0;
		int sol = 0;
		vp v(n,{0,0});

		for(int i =0 ; i<n ; i++ ) {
			if(s[i]=='a'){
				total+= 1;
			}
			else total -= 1;
			v[i] = {total,i};
		}

		vp u = v;

		sort(u.begin(),u.end());

		ini(1,0,n-1,u);

		int prev = 0;
		for(int i = 0 ; i<n ; i++) {
			int left = prev-k,right = k-prev;
			int l = lower_bound(left,u);
			int r = heigher_bound(right,u);
			
			if(l==-1 || r==-1) continue;

			int value = find_max(1,0,n-1,l,r);

			if(value>=i) sol = max(sol , value-i+1);
			prev = v[i].first;
		}

		cout<<sol<<endl;
	}
}