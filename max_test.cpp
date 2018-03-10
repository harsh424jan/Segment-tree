#include <bits/stdc++.h>
#include "segtree.h"

int merging(int a,int b)
{
  if(a>b)
  return a;
  return b;
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
}