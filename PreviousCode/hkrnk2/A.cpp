#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int A_i = 0;A_i < N;A_i++){
       cin >> A[A_i];
    }
    int sol = -1;
    for(int i = 0 ; i<2001 ; i++){
        int tmp = 0;
//        cout<<i<<" "<<endl;
        for(int j = 0 ; j<N ; j++){
            int idx = A[j]/(i+1);
            if(idx*(i+1) <= A[j])
                idx++;

            if((int)(A[j]/idx)!=i)
            {
                tmp = -1;
                break;
            }
            tmp += idx;
        }
        if(tmp==-1) continue;
//        cout<<" -> "<<tmp<<endl;
        if(sol==-1 || tmp<sol) sol = tmp;
    }
    cout<<sol<<endl;
    return 0;
}

