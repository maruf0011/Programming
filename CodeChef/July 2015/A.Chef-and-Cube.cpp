#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef std::vector<VI> VVI;


int main()
{
	VVI list;
	// i/nt a[] = {2,3,4};
	// VI a;
	// a= {1,2,3};
	// cout<<a[0]<<' '<<a[2]<<endl;
	list.push_back({2,4,3,5});
	list.push_back({2,4,3,5});
	list.push_back({0,4,1,5});
	list.push_back({0,4,1,5});
	list.push_back({2,0,3,1});
	list.push_back({2,0,3,1});

	map<string,int>colorIndex =  {{"blue",0}, {"red",1}, {"green",2}, {"yellow",3}, {"orange" , 4},{"black" , 5}};

	int tcaese;
	cin>>tcaese;

	while(tcaese--)
	{
		VI v(6);
		for(int i = 0 ; i<6 ; i++)
		{
			string str;
			cin>>str;
			v[i] = colorIndex[str];
		}
		int sol = 0;
		for(int i = 0  ; i<6 && !sol ; i++)
		{
			for(int j = 0 ; j<list[i].size() && !sol ; j++)
			{
				int idx1 = list[i][j];
				int idx2 = list[i][(j+1)%4];

				if(v[i]==v[idx1] && v[i] == v[idx2]) sol=1;
			}
		}
		if(sol)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
