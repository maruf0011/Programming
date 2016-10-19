#include "bits/stdc++.h"

using namespace std;

struct node
{
	int value;
	node *right,*down;
	node(){
		right = NULL,down = NULL;
	};
};

using VN = vector<node>;
using VVN = vector<VN>;

struct solve
{
	int r,c;
	VVN grid;

	solve(int r,int c) : r(r), c(c), grid(r+2, VN(c+2)) {}

	solve(){}
	void inputGrid() {
		for(int i = 1 ; i<=r ; i++) {
			for(int j = 1 ; j<=c ; j++) {
				cin>>grid[i][j].value;
			}
		}

		for(int i = 0 ; i<=r ; i++) {
			for(int j = 0 ; j<=c ; j++) {
				grid[i][j].right = &grid[i][j+1];
				grid[i][j].down = &grid[i+1][j];
			}
		}
	}

	node* _goto(node *curNode,int right,int down) {
		for(int i = 0 ; i<right ; i++) {
			curNode = curNode->right;
		}
		for(int i = 0 ; i<down ; i++) {
			curNode = curNode->down;
		}
		return curNode;
	}

	void swapDown(node *a,node *b,int len) {
		for(int i = 0 ; i<len ; i++) {
			swap(a->down, b->down);
			a = a->right, b= b->right;
		}
		return;
	}

	void swapRight(node *a,node *b,int len) {
		for(int i = 0; i<len; i++) {
			swap(a->right, b->right);
			a = a->down, b = b->down;
		}
		return;
	}
	void process(int x,int y,int p,int q,int l,int w) {
		vector<pair<node *,node *> >v;

		node *aNode = &grid[0][0], *bNode = &grid[0][0];

		aNode = _goto(aNode, y-1, x-1);
		bNode = _goto(bNode, q-1, p-1);

		v.push_back({aNode->right, bNode->right});
		v.push_back({_goto(aNode, 1, l), _goto(bNode, 1, l)});
		v.push_back({aNode->down, bNode->down});
		v.push_back({_goto(aNode, w, 1), _goto(bNode, w, 1)});


		for(int i = 0 ; i<v.size() ; i++) {
			if(i<2) swapDown(v[i].first, v[i].second, w);
			else swapRight(v[i].first, v[i].second, l);
		}
	}

	void __print() {
		for(int i =1 ; i<=r ; i++) {
			node *curNode = &grid[i][0];

			for(int j = 0 ; j<c ; j++) {
				curNode = curNode->right;
				cout<<curNode->value<<' ';
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int row,col,q;
	while(cin>>row>>col>>q) {
		solve s(row,col);
		s.inputGrid();
		for(int i =0 ; i<q; i++) {
			int x,y,p,q,l,w;

			cin>>x>>y>>p>>q>>l>>w;
			s.process(x,y,p,q,l,w);
		}
		s.__print();
	} 
	return 0;
}