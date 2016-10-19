#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

struct graph
{
	int n;
	VVI adj;
	VI dist;

	graph(int n): n(n), adj(n),dist(n,-1) {}

	void addEdge(int u,int v,bool directed=false){
		// cout<<u<<" --- "<<v<<endl;
		adj[u].push_back(v);
		if(!directed) adj[v].push_back(u);
		return;
	}

	int bfs(int x,set<int>target){
		queue<int>Q;
		Q.push(x);
		dist[x] = 0;
		while(!Q.empty()){
			int u = Q.front();
			if(target.count(u)>0) {
				return dist[u];
			}
			Q.pop();
			for(auto &v: adj[u]){
				if(dist[v]==-1){
					dist[v] = dist[u]+1;
					Q.push(v);
				}
			}
		}

		return -1;
	}
};

char inp[1024][1024];

int main(){
	int n,m;

	string str1 = "+-|^><vLRUD";
	string str2 = "+|->v^<UDRL";
	vector<string>vDir{"1111",
						"0101",
						"1010",
						"0010",
						"0100",
						"0001",
						"1000",
						"1110",
						"1011",
						"1101",
						"0111"};

	map<char,char>dir;
	map<char,string>door;

	for(int i = 0 ; i<str1.size() ; i++){
		dir[str1[i]] = str2[i];
		door[str1[i]] = vDir[i];
	}

	while(cin>>n>>m) {
	    
	    for(int i = 0 ; i<n ; i++){
	    	for(int j = 0 ; j<m ; j++){
	    		cin>>inp[i][j];
	    	}
	    }

	    graph G(m*n*4);


	    for(int i = 0 ; i<n ; i++){
	    	for(int j = 0 ; j<m ; j++){
	    		if(j!=m-1){
	    			char ch1 = inp[i][j];
		    		char ch2 = inp[i][j+1];
		    		for(int k = 0 ; k<4 && ch1!='*' && ch2!='*'; k++){
		    			if(door[ch1][1]==door[ch2][3] && door[ch1][1]=='1'){
		    				G.addEdge(m*n*k+(i*m+j), m*n*k+(i*m+j+1));
		    			}
		    			ch1 = dir[ch1],ch2 = dir[ch2];
		    		}
	    		}
	    		
	    		if(i!=n-1){
	    			char ch1 = inp[i][j],ch2 = inp[i+1][j];

		    		for(int k = 0 ; k<4 && ch1!='*' && ch2!='*' ; k++){
		    			if(door[ch1][0]==door[ch2][2] && door[ch1][0]=='1'){
		    				G.addEdge(m*n*k+(i*m+j), m*n*k+((i+1)*m+j));
		    			}
		    			ch1 = dir[ch1],ch2 = dir[ch2];
		    		}
	    		}
	    		for(int k = 0 ; k<4 ; k++)
	    			G.addEdge(n*m*k+(i*m+j) , n*m*((k+1)%4)+(i*m+j),true);

	    	}
	    }

	    int x,y;
	    cin>>x>>y;
	    x--;y--;
	    int start = x*m+y;

	    set<int>target;
	    cin>>x>>y;
	    x--;y--;
	    // cout<<"start "<<start<<endl;
	    for(int k = 0 ; k<4 ; k++){
	    	target.insert(n*m*k+(x*m+y));
	    	// cout<<" -- "<<n*m*k+(x*m+y)<<endl;
	    }

	    int sol = G.bfs(start,target);

	    cout<<sol<<endl;
	}
	return 0;
}