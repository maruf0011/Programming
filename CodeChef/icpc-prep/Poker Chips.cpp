#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase,cas=1;
    cin>>tcase;
    vector<int>isPossible(55);

    int sum = 0;
    int idx = 0;
    while(idx<55)
    {
        isPossible[idx] = sum;
        sum = sum+idx;
        idx++;
    }

    while(tcase--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        sum = 0;
        for(int i = 0 ; i<n ; i++)
        {
            cin>>v[i];
            sum += v[i];
        }
        int sol = -1;
        for(int i = 0 ; i<=50 ; i++)
        {
            int totsum = n*i + isPossible[n];
            if(totsum==sum)
            {
                int tmpsol = 0;
                for(int j = 0 ; j<v.size() ; j++)
                {
                    tmpsol += abs(i+j - v[j]);
                }
                tmpsol/=2;
                if(sol==-1 || sol>tmpsol) sol = tmpsol;
            }
        }
        cout<<sol<<endl;
    }
    return 0;
}
