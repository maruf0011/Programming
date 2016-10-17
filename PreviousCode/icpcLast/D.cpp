#include <bits/stdc++.h>

using namespace std;

int arr[2048][2];

int main()
{
    int n,b;

    while(cin>>n>>b)
    {
        for(int i = 0 ; i<n ; i++)
            cin>>arr[i][0];

        for(int i = n-1 ; i>= 0 ; i--)
        {
            if(i==(n-1)) arr[i][1] = arr[i][0];
            else arr[i][1] = max(arr[i][0] , arr[i+1][1]);
        }
        long long  sol = b;
        for(int i = 0 ; i<n  ; i++)
        {
            int buy = (b/arr[i][0]);
            long long tmp = buy*arr[i][1];
            tmp += (b - (buy*arr[i][0]));
            sol = max(sol , tmp);
        }
        cout<<sol<<endl;
    }
    return 0;
}
