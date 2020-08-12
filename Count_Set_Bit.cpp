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
#define int long long
#define endl "\n"
#define max(x,y) (x>y)?x:y
#define min(x,y) (x<y)?x:y
#define s(n) scanf("%d",&n)
#define mem memset(a, 0, sizeof(a))
#define minimum(a)	*min_element(a.begin(), a.end())
#define maximum(a)	*max_element(a.begin(), a.end())
typedef vector<int> vi;
typedef vector<string> vs;
/*
* * * * * * * * * * * * * * * * * * * * * *
*       ☆꧁𝓑𝓐𝓒𝓚_𝓛𝓞𝓖꧂☆              **
*                                        ***
* * * * * * * * * * * * * * * * * * * * *****
*/ 
int count_set_bit(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        //adding last bit of n if 1 or 0
        n=n>>1;
        //discarding last bit
    }
return ans;

}
int set_bit_fast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        //removing every set bit from right to left
        ans++;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
   int n;
   cin>>n;
   //O(log(n))->complexity
   cout<<count_set_bit(n)<<endl;
   //O(no of set bit)
   cout<<set_bit_fast(n)<<endl;
   //built in method in c++
   cout<<__builtin_popcount(n)<<endl;
  
return 0;
}
