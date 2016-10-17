#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    int cnt = 0;
    for(int i = 1  ; i<=A  ; i++){
        for(int j = 1 ; j<=B ; j++){
                if((abs(i-j))%3) continue;
            for(int k = 5-(j%5) ; k<=C ; k+= 5){
                for(int l = 1 ; l<=D && ((i*k)%4)==0 ; l++){
                    if(__gcd(i , l)==1){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
