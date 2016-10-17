#include <bits/stdc++.h>

using namespace std;

char _find(char a,char b)
{
    for(char i = 'a' ; i<='z' ; i++)
    {
        if(i!=a && i!=b) return i;
    }
    return a;
}

int main()
{
    string s1,s2;
    int n,t;

    while(cin>>n>>t)
    {
        cin>>s1;
        cin>>s2;
        string s3(n , 'a');
        //cout<<s3<<endl;
        int p = 0;

        for(int i = 0 ; i<n ; i++)
        {
            p += (s1[i]!=s2[i]);
        }

        if(t<=p)
        {
            if(2*t<p) cout<<-1<<endl;
            else
            {
                int need1 = p-t;
                int need2 = p-t;
                for(int i = 0 ; i<n ; i++)
                {
                    if(s1[i]==s2[i]) s3[i] = s1[i];
                    else
                    {
                        if(need1)
                        {
                            s3[i] = s1[i]; need1--;
                        }
                        else if(need2)
                        {
                            s3[i] = s2[i];need2--;
                        }
                        else s3[i] = _find(s1[i] , s2[i]);
                    }
                }
                cout<<s3<<endl;
            }

        }
        else
        {
            int need= t-p;
            for(int i = 0 ; i<n ; i++)
            {
                if(s1[i]!=s2[i])
                    s3[i] = _find(s1[i],s2[i]);
                else if(need)
                {
                    need--;
                    s3[i] = _find(s1[i] , s2[i]);
                }
                else s3[i] = s1[i];
            }
            cout<<s3<<endl;
        }
    }
    return 0;
}
