#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long>a(3);
    vector<long long>b(3);

    while(cin>>a[0]>>a[1]>>a[2])
    {
        cin>>b[0]>>b[1]>>b[2];

        long long n = 0;
        long long e = 0;

        for(int i = 0 ; i<a.size() ; i++)
        {
            if(a[i]>b[i])
            {
                e += (a[i]-b[i]);

                if((a[i]-b[i])%2)
                    e++ , n++;
            }
            else n += (b[i]-a[i]);
        }

        cout<<(e >= (2*n) ? "Yes" : "No")<<endl;
    }
    return 0;
}
