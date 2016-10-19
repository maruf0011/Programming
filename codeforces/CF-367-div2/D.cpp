#include "bits/stdc++.h"

using namespace std;

struct node
{
	int next[2];
	int cnt;
	node(){
		cnt = 0,next[0] = -1, next[1] = -1;
	}
};

std::vector<node> tree;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n) {
		tree.clear();

		int root = 0;
		tree.push_back(node());

		for(int i= 0 ; i<=n ; i++){
			char ch = '+';
			long long num = 0LL;
			if(i) cin>>ch>>num;
			int curNode = 0;
			long long sol = 0;
			for(int j = 32 ; j>=0 ; j--){
				int idx = (num>>j)&1LL;
				if(ch=='+' || ch=='-') {
					tree[curNode].cnt += (ch=='+' ? 1 : -1);
					int nextNode = tree[curNode].next[idx];
					if(nextNode==-1) {
						tree.push_back(node());
						tree[curNode].next[idx] = tree.size()-1;
						nextNode = tree[curNode].next[idx];
					}
					curNode = nextNode;
				} else {
					int nextNode = tree[curNode].next[!idx];
					if(nextNode==-1 || tree[nextNode].cnt ==0) {
						nextNode = tree[curNode].next[idx];
					}
					else {
						sol += (1LL<<j);
					}
					curNode = nextNode;
				}
			}
			if(ch=='?') cout<<sol<<endl;
			else tree[curNode].cnt += (ch=='+' ? 1 : -1);
		}

	}
	return 0;
}