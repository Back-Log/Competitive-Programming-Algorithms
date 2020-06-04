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
#define ll long long
#define MAX 1e9
#define MIN -1e9
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
  
  int n;
  cin>>n;
  //number of element in the array
  int arr[100];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  //array must be sorted if not sort it
  int target;
  cin>>target;
  int leftpointer=0,rightpointer=n-1;
  while(leftpointer<rightpointer)
  {
    if(arr[leftpointer]+arr[rightpointer]==target)
    {
        //if target found we are printing the target
        cout<<arr[leftpointer]<<" "<<arr[rightpointer]<<endl;
        leftpointer++;
        rightpointer--;
    }
    else if(arr[leftpointer]+arr[rightpointer]>target)
    {
        //if the sum is greater we are decresing the right pointer
      rightpointer--;
    }
  else if(arr[leftpointer]+arr[rightpointer]<target)
  {
      //decreasing left pointer in this stage
      leftpointer++;
  }

  }
return 0;
}
