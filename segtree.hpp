#include<bits/stdc++.h>
using namespace std;
#ifndef SEG_TREE_INCLUDE
#define SEG_TREE_INCLUDE
template <class T>
class segtree
{
public:
	 segtree(T* list,int n,T identity,T (*function)(T a,T b));
	void update(int change);
	T query(int start,int end);
private:
	void build(int l,int r,int x);
	void update(int l,int r,int x,int change);
	T query(int l,int r,int x,int i,int j);
	T* container;
	T* listcopy;
	T identity;
	T (*merge)(T a,T b);
	int n;
};
template <class T>
segtree<T>::segtree(T* list,int n,T identity,T (*function)(T a,T b))
{
	this->n = n;
	listcopy=list;
	this->identity=identity;
	container=new T[4*n];
	merge = function;
	build(0,n-1,0);
}
template<class T>
void segtree<T>::build(int l,int r,int x)
{
	if(l==r)
	{
		container[x] = listcopy[l];
		return;
	}
	int m=(l+r)/2;
	int L=2*x+1;
	int R=L+1;
	build(l,m,L);
	build(m+1,r,R);
	container[x]=(*merge)(container[L],container[R]);
}
template<class T>
void segtree<T>::update(int change)
{
	update(0,n-1,0,change);
}
template<class T>
void segtree<T>::update(int l,int r,int x,int change)
{
	if(l>change||r<change)
		return;
	if(l==r)
	{
		container[x]=listcopy[change];
		return;
	}
	int m=(l+r)/2;
	int L=2*x+1;
	int R=L+1;
	update(l,m,L,change);
	update(m+1,r,R,change);
	container[x]=(*merge)(container[L],container[R]);
}
template<class T>
T segtree<T>::query(int start,int end)
{
	return query(0,n-1,0,start,end);
}
template<class T>
T segtree<T>::query(int l,int r,int x,int i,int j)
{
	if(l>j||r<i)
		return identity;
	if(i<=l&&r<=j)
		return container[x];
	int m=(l+r)/2;
	int L=2*x+1;
	int R=L+1;
	return (*merge)(query(l,m,L,i,j),query(m+1,r,R,i,j));
}
#endif