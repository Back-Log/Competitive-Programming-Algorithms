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
vector<int>get_factors(vector<int>&primes,int n)
{
    vector<int>ans;
    ans.clear();
    for(int i=0;i*i<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ans.push_back(primes[i]);
            while(n%primes[i]==0)
            {
                n=n/primes[i];
            }

        }
    }
    if(n!=1)
    {
        ans.push_back(n);
    }
    return ans;
} 
vector<int>get_prime(vector<int>&prime,int n)
{
  for(int i=3;i<=1000;i+=2)
  {
    prime[i]=1;
  }
  //mark all the even number as non prime
  for(int i=3;i*i<=1000;i+=2)
  {
    if(prime[i]==1)
    {
        for(int j=i*i;j<=1000;j+=i)
        {
            prime[j]=0;
        }
    }
  }
  prime[0]=prime[1]=0;
  prime[2]=1;
  vector<int>fectors;
  for(int i=2;i<=1000;i++)
  {
   if(prime[i]==1)
   {
    fectors.push_back(i);
   }
  }
return fectors;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  #ifndef ONLINE_JUDGE
		  // freopen("input.txt","r",stdin);
	   //  freopen("output.txt","w",stdout);
    // #endif
    //first task to ganrate prime fectors and store it
      vector<int>p(1000,0);
    //vector<int>primes=get_prime(p,10000);
  //now we have all prime number till n
    int n;
    cin>>n;
    //enter n (the number you want to get prime fector)
    vector<int>primes=get_prime(p,n);
    vector<int>ans=get_factors(primes,n);
    cout<<"Prime Factors are :";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}
