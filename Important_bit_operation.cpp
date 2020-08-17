#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define MAX 1e9+7
#define MIN -1e9-7
//#define int long long
#define endl "\n"
#define max(x,y) (x>y)?x:y
#define min(x,y) (x<y)?x:y
#define s(n) scanf("%d",&n)
#define mem memset(a, 0, sizeof(a))
#define minimum(a)	*min_element(a.begin(), a.end())
#define maximum(a)	*max_element(a.begin(), a.end())
typedef vector<int> vi;
typedef vector<string> vs;
//int clear_bit(int,int);
/*
* * * * * * * * * * * * * * * * * * * * * *
*       ☆꧁𝓑𝓐𝓒𝓚_𝓛𝓞𝓖꧂☆              **
*                                        ***
* * * * * * * * * * * * * * * * * * * * *****
*/ 
int clear_last_n_bit(int n,int i)
{
    int mask=(-1)<<i;
    //we have to creat mask like ->1100
    //-1 in memory like 111111
    int ans=n&mask;
    return ans;
}
int update_bit(int n,int i,int v)
{
   //for updating any perticuler bit first you should clear that bit
    int clr_bit=(~(1<<i))&n;
    //creat a mask ,value of v either 0 or 1
    //or just call clear bit function
    int mask=(v<<i);
    return clr_bit|mask;
}
int clear_bit(int n,int i)
{
   int mask=~(1<<i);
   //taking the negation of mask ,will change the ith bit to 0 
   int ans=n&mask;
   return ans;

}
int set_bit(int n,int i)
{
    //if the bit 0 than it will change to 1
   int mask=(1<<i);
   int ans=(n|mask);
   return ans;

}
int even_odd(int n)
{
    //performing and with odd number will give 1 otherwise zero
    return (n&1)?1:0;
}
int get_ith_bit(int n,int i)
{
    //mask->performing left shift ith time on 1 than take n & mask
    int mask=(1<<i);
    int ans=n&mask;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
//************************************************************************
int n;
cin>>n;

if(even_odd(n))
{
    cout<<"Number is Odd "<<endl;
}
else
{
    cout<<"Number is Even "<<endl;
}
//************************************************************************
int i;
//enter the i (the bit position you want to extract)
cin>>i;
int ans=get_ith_bit(n,i);
if(ans>0)
{
    cout<<"ith bit is 1 "<<endl;
}   
else
{
    cout<<"ith bit is 0"<<endl;
}
//************************************************************************
//->how to set ith bit
//->pass i to change ith bit
ans=set_bit(n,i);
cout<<ans<<endl;
//***********************************************************************
//->clear ith bit
ans=clear_bit(n,i);
cout<<ans<<endl;
//************************************************************************
//->how to update ith bit with 0 or 1
int v;
cin>>v;
//v=you want to update bit by 0 or 1
cout<<update_bit(n,i,v)<<endl;
//**********************************************************************
//->how to clear last n bit
//like if you want to clear last two bit in n than
ans=clear_last_n_bit(n,2);
cout<<ans<<endl;

return 0;

}
