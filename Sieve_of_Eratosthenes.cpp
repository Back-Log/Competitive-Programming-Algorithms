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
#define minimum(a)  *min_element(a.begin(), a.end())
#define maximum(a)  *max_element(a.begin(), a.end())
typedef vector<int> vi;
typedef vector<string> vs;
/*
* * * * * * * * * * * * * * * * * * * * * *
*       ☆꧁𝓑𝓐𝓒𝓚_𝓛𝓞𝓖꧂☆              **
*                                        ***
* * * * * * * * * * * * * * * * * * * * *****
*/ 
void seive_of_eratosthenes(int *arr,int n)
{
  for(int i=3;i<=10000;i+=2)
  {
    arr[i]=1;
    //marking all the odd numbers as prime
  }
 for(int i=3;i*i<=10000;i+=2)
 {
   if(arr[i]==1)
   {
    for(int j=i*i;j<=10000;j=j+i)
    {
      //this is optimize approach ,you can start with 2*i
        arr[j]=0;
    }
   }

 }
//handling edge cases
 arr[0]=arr[1]=0;
 arr[2]=1;

}
//also known as Prime seive
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
   //enter n (til where you want to ganrate prime number)
   int arr[10001]={0};
   seive_of_eratosthenes(arr,n);
   //printing
for(int i=0;i<=n;i++)
 {
    if(arr[i]==1)
    {
        cout<<i<<" ";
    }
 }
cout<<endl;
  
return 0;
}
