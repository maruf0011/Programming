#include "bits/stdc++.h"

using namespace std;

bool IsUnique(string s)
{
	int mask = 0;
	for(int i = 0 ; i<s.size() ; i++)
	{
		if(mask&(1<<(s[i]-'a'))) return false;
		mask |= (1<<(s[i]-'a'));
	}
	return true;
}

void _reverse(char s[])
{
	int length = strlen(s);

	for(int i = 0 ; i<length/2 ; i++)
		swap(s[i] , s[length-i-1]);
	return ;
}

bool isPermutation(string a,string b)
{
	vector<int>_count(257 , 0);
	for(auto &ch: a)
		_count[ch]++;
	for(auto &ch: b)
		_count[ch]--;
	for(auto &x: _count)
		if(x!=0) return false;
	return true;
}

void ReplaceSpace(string &str)
{
	string ret = "";
	for(auto &ch: str)
		if(ch!=' ') ret += ch;
		else ret += "%20";
	str = ret;
	return;
}

char* NumToString(int num)
{
	char *str = new char[20];
	int cur_index = 0;
	while(num)
	{
		str[cur_index++] = (num%10)+'0';
		num /= 10;
	}
	str[cur_index] = '\0';
	//cout<<num<<" - "<<str<<endl;
	_reverse(str);
	//cout<<str<<endl;
	return str;
}

char* compress(char *original)
{
	int length = strlen(original);
	char *com = new char[length*2+10];
	int max_count = 0  , cur_index = 0 , cur_count = 0;

	for(int i = 0 ; i<=length ; i++)
	{

		if(i>0 && original[i]!=original[i-1])
		{
			//cout<<original[i-1]<<" "<<cur_count<<endl;
			max_count = max(max_count , cur_count);
			char* string_num= NumToString(cur_count);
			//cout<<string_num<<endl;
			int numLen = strlen(string_num);

			com[cur_index++] = original[i-1];
			for(int j = 0 ; j<numLen ; j++)
				com[cur_index++] = string_num[j];
			cur_count = 1;
		}
		else cur_count++;
	}
	com[cur_index] = '\0';
	if(max_count<=2) return original;
	return com;
}


string compress2(string org)
{
	stringstream ss;
	int count = 0;
	int mx = 0;
	for(int i = 0 ; i<org.size() ; i++)
	{
		if(i && org[i]!=org[i-1])
		{
			ss<<org[i-1]<<count;
			count = 1;
			mx = max(mx , count);
		}
		else count++;
	}
	mx = max(mx , count);
	if(org.size()) ss<<org[org.size()-1]<<count;
	if(mx<=2) return org;
	return ss.str();
}

using VI = vector<int>;
using VVI = vector<VI>;
using PI = pair<int,int>;
#define x first
#define y second


PI get90(PI cur , int N)
{
	return {cur.y , N-cur.x};
}
void roteate90(VVI &matrix)
{
	int N = matrix.size();

	for(int i = 0 ; i<N/2 ; i++)
	{
		for(int j  = i ; j<N-i-1 ; j++)
		{
			PI now = {i ,j};

			for(int k = 0 ; k<3 ; k++)
			{
				PI next = get90(now , N-1);
				swap(matrix[i][j] , matrix[next.x][next.y]);
				now = next;
			}
		}
	}
}

void PrintMat(VVI &m)
{
	for(auto &x: m)
	{
		for(auto &y: x)
			cout<<y<<' ';
		cout<<endl;
	}
}
int main()
{
	cout<<IsUnique("abcdaf")<<endl;

	char str[] = "cdefgh";
	cout<<str<<endl;
	_reverse(str);

	cout<<str<<endl;

	string a = "ab cd";
	string b = "abcd";

	cout<<isPermutation(a,b)<<endl;

	ReplaceSpace(a);
	cout<<a<<endl;
	char original[] = "aaaaaabbccdddd";
	cout<<compress(original)<<endl;
	string tmp = "aaaabbbbcccddd";
	cout<<compress2(tmp)<<endl;

	// pass2Darray(arr);

	VVI mat(5 , VI(5 ,0));
	int cnt = 0;
	for(int i = 0 ; i<mat.size() ; i++)
		for(int j = 0 ; j<mat[i].size() ; j++)
			mat[i][j] = ++cnt;

	PrintMat(mat);
	roteate90(mat);
	PrintMat(mat);


	return 0;
}