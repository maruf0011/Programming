#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
  set<int>s[2];
  s[0].insert(1);
  s[1].insert(2);

  for (auto &i:  s[1])
  {
    cout<<i<<endl;
    /* code */
  }
  return 0;
}