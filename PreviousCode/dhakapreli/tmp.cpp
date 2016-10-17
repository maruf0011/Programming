#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


typedef vector<int> VI;

int bit[100];

void add(int idx,int add){
//    cout<<idx<<" - "<<add<<endl;

    while(idx>0){
        bit[idx] += add;
        idx -= (idx&(-idx));
//        cout<<idx<<endl;
    }
    return;
}

int sum(int idx){
    int ret = 0;
    while(idx<=20){
        ret += bit[idx];
        idx += (idx&(-idx));
//        cout<<idx<<endl;
    }
    return ret;
}

int main() {
    int tcase,cas=1;
    cin>>tcase;

    while(tcase--) {
        VI inp(20);
        cin>>inp[0];

        for(int i = 0 ; i<20 ; i++)
            cin>>inp[i];

        memset(bit, 0 , sizeof bit);

        VI tmp = inp;

        sort(tmp.begin() , tmp.end());
        int sol = 0;
        for(int i = 0 ; i<tmp.size() ; i++){
            int pos = lower_bound(tmp.begin() , tmp.end() , inp[i]) - tmp.begin();
            sol += sum(pos+1);
            add(pos+1 , 1);
        }

        cout<<sol<<endl;
    }
    return 0;
}

