#define BOOST_TEST_MODULE segtree test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "segtree.hpp"
#include<bits/stdc++.h>
namespace utf = boost::unit_test;
#define INF 1000000009
auto merging(auto a,auto b)
{
	return a+b;
}
BOOST_AUTO_TEST_CASE( addition_test )
{
	int a[]={1,2,3,4,5};
    segtree<int> test(a,5,0,&merging);
    BOOST_CHECK_EQUAL(test.query(0,4),15);
    a[2]= 10;
    test.update(2);
    BOOST_CHECK_EQUAL(test.query(0,4),22);
    BOOST_CHECK_EQUAL(test.query(2,2),10);
	BOOST_CHECK_EQUAL(test.query(1,1),2);
    BOOST_CHECK_EQUAL(test.query(3,3),4);
    BOOST_CHECK_EQUAL(test.query(1,3),16);

}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
BOOST_AUTO_TEST_CASE( min_test )
{
	int a[]={1,2,3,4,5};
    segtree<int> test(a,5,INF,&min);
    BOOST_CHECK_EQUAL(test.query(0,4),1);
    a[2]= 10;
    test.update(2);
    BOOST_CHECK_EQUAL(test.query(0,4),1);
    BOOST_CHECK_EQUAL(test.query(2,2),10);
	BOOST_CHECK_EQUAL(test.query(1,1),2);
    BOOST_CHECK_EQUAL(test.query(3,3),4);
    BOOST_CHECK_EQUAL(test.query(1,3),2);
    a[0]=100;
    test.update(0);
    BOOST_CHECK_EQUAL(test.query(0,4),2);
    BOOST_CHECK_EQUAL(test.query(0,3),2);
    BOOST_CHECK_EQUAL(test.query(1,4),2);
}
BOOST_AUTO_TEST_CASE( floating_point_test)
{
	float a[]={1.234,2.5,3.87,5,34};
	segtree<float> test(a,5,0,&merging);
	BOOST_CHECK_CLOSE(test.query(0,4),46.604,0.001);
	BOOST_CHECK_CLOSE(test.query(0,2),7.604,0.001);
	BOOST_CHECK_CLOSE(test.query(3,4),39,0.001);
}