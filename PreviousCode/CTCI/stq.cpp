#include <bits/stdc++.h>

using namespace std;

using VS = vector<stack<int> >;


struct SetOfStacks
{
	int size;
	int cur_stack;
	int MAX_SIZE;
	int tot_size;
	VS S;
	SetOfStacks(int size,int cur_stack,int MAX_SIZE):size(size) , S(size) , cur_stack(cur_stack) , MAX_SIZE(MAX_SIZE) , tot_size(0){}
	void push(int value)
	{
		S[cur_stack].push(value);
		if(S[cur_stack].size()==MAX_SIZE) cur_stack++;
		tot_size++;
		return;
	}
	void pop()
	{
		S[cur_stack].pop();
		if(S[cur_stack].empty()) cur_stack-- , tot_size--;
	}

	int top()
	{
		return S[cur_stack].top();
	}

	void popAt(int index)
	{
		if(!S[index].empty()) S[index].pop();
		tot_size--;
	}

	int Size()
	{
		return tot_size;
	}
};


void rec(char f,char m,char t,int n)
{
	if(n==0) return;
	rec(f,t,m,n-1);
	cout<<f<<" to "<<t<<" disk "<<n<<endl;
	rec(m,f,t,n-1);
}

struct gameState
{
	char from,aux,to;
	int iter;
	int disks;

	gameState(char from,char aux,char to,int disks,int iter):from(from),aux(aux),to(to),disks(disks),iter(iter){}
	void print(){cout<<from<<" to "<<to<<" disk "<<disks<<endl;}
};

int main(int argc, char const *argv[])
{

	//rec('A','B','C' , 2);

	gameState gs('A' , 'B' , 'C' , 4 , 0);

	stack<gameState>s;
	s.push(gs);

	while(!s.empty())
	{
		gameState now = s.top();
		if(now.disks==1)
		{
			now.print();
			s.pop();
			if(!s.empty()) s.top().iter++;
		}
		else
		{
			if(now.iter==0)
				s.push(gameState(now.from , now.to , now.aux , now.disks-1 , 0));
			else 
			{
				now.print();
				s.pop();
				if(!s.empty())s.top().iter++;
				s.push(gameState(now.aux , now.from , now.to,now.disks-1 , 0));
			}
		}
	}

	// SetOfStacks st(10 , 0 , 2);

	// st.push(10);
	// st.push(10);
	// st.push(9);
	// st.push(10);
	// st.push(9);
	// cout<<st.top()<<endl;
	// st.pop();
	// cout<<st.top()<<endl;
	return 0;
}