#include <bits/stdc++.h>
#include "segtree.h"

using namespace std;
int gcd(int a,int b)
{
  if(a==0)
    return b;
  return gcd(b%a,a);
}
int merging(int a,int b)
{
  return gcd(a,b);
}
int main()
{
  int a[8]={1,2,8,4,144,56,32,1};
  segtree<int> *t=new segtree<int>(a,8,0,&merging);
  cout<<t->query(0,7)<<endl;
  cout<<t->query(2,5)<<endl;
  cout<<t->query(6,6)<<endl;
  a[6]=1;
  t->update(6);
  cout<<t->query(0,7)<<endl;
  cout<<t->query(2,5)<<endl;
  cout<<t->query(6,6)<<endl;
  return 0;
}