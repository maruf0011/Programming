#include <bits/stdc++.h>

using namespace std;

int main(){
    int sol =0;
    int x = 30;
    for(int i = 1 ; i<x  ; i++)
    {
        sol ^= i;
        cout<<i<<" "<<sol<<endl;
    }
    return 0;
}
