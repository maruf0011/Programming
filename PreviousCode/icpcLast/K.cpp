#include <bits/stdc++.h>


#define sz(a) ((int)a.size())
using namespace std;

int main()
{
//    string str= "abcdefgh";
//    cout<<str.size()<<endl;
//    str.erase(sz(str)-1);
//    cout<<str<<endl;
//    cout<<str.size()<<endl;
    int n;

    while(cin>>n)
    {
        vector<string>v1(n),v2(n);
        int l = 0;

        vector<set<string> >vs(11);
        for(int i = 0 ; i<n ; i++)
        {
            cin>>v2[i];
            l += sz(v2[i]);
            vs[sz(v2[i])].insert(v2[i]);
            v1[i] = v2[i];
//            v2.push_back(129);
        }

        l /= (n/2);
        char ch;
        cin>>ch;
        for(int i = 0; i<n ; i++)
            v1[i].push_back(ch);

        sort(v1.begin() , v1.end());
////        sort(v2.begin() , v2.end() , [&](const string &a,const string &b){
//
//            for(int i = 0 ; i<min(sz(a) , sz(b)) ; i++)
//                if(a[i]<b[i]) return true;
//                else if(a[i]>b[i]) return false;
//
//            return ch>'z' ? (sz(a)>sz(b)) : (sz(a)<sz(b));
//        });

//        for(auto v: v1)
//            cout<<v<<endl;

        set<string>s;
        int id1 = 0  ,id2 = 0;
        for(int i = 0 ; i<n/2 ; i++)
        {
            int k = l;
            while(id1<n)
            {
                string tmp = v1[id1];
                tmp.erase(sz(tmp)-1);
                if(s.count(tmp)==0)
                {
                    s.insert(tmp);
                    cout<<v1[id1];
                    k -= sz(tmp);
                    id1++;
                    break;
                }
                else id1++;
            }

            while(!vs[k].empty())
            {
                auto it = vs[k].begin();
                if(s.count(*it)==0)
                {
                    cout<<*it<<endl;
                    s.insert(*it);
                    break;
                }
                vs[k].erase(it);
            }
        }
    }
    return 0;
}
