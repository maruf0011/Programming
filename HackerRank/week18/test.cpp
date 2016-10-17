#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

const int MAXN = 5010;
int n, MOD;

int dp[MAXN][MAXN], add[MAXN][MAXN];
char s[MAXN];

inline int mod(int x) {
    while (x < 0) {
        x += MOD;
    }
    while (x >= MOD) {
        x -= MOD;
    }
    return x;
}

int brute() {
    vector<int>v;
    for (int i = 0; i < n; i++) {
        v.pb(i);
    }
    int res = 0;
    do {
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'G') {
                if (v[i] < v[i + 1] ) {
                    ok = false;
                }
            }
            else {
                if (v[i] > v[i + 1] ) {
                    ok = false;
                }
            }
        }
        res += ok;
    }
    while (next_permutation(v.begin(), v.end() ) );

    return res % MOD;
}

int main() {
    scanf("%d%d\n", &n, &MOD);
    gets(s);
    //cerr<<s<<endl;
    dp[0][0] = 1;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == 'G' ) {
                add[i + 1][0] += dp[i][j];
                add[i + 1][0] = mod(add[i + 1][0]);

                add[i + 1][j + 1] -= dp[i][j];
                add[i + 1][j + 1] = mod(add[i + 1][j + 1]);
            }
            else {
                add[i + 1][j + 1] += dp[i][j];
                add[i + 1][j + 1] = mod(add[i + 1][j + 1]);
            }
        }
        int sum = 0;
        for (int j = 0; j <= i + 1; j++) {
            sum += add[i + 1][j];
            sum = mod(sum);
            dp[i + 1][j] = sum;
        }
    }


    for(int i = 0 ; i<n  ; i++)
    {
        for(int j = 0 ; j<n ; j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[n - 1][i];
        ans = mod(ans);
    }

    cout<<ans<<"\n";
    //cerr<<brute()<<endl;
    return 0;
}
