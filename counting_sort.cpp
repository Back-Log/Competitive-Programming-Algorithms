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
//counting sort -> when the range of number is small ->>>number should be>0
// than for sortin g we can use couting sort
//time compexity -> O(n+range(largest-smallest))
void counting_sort(int arr[],int n)
{
  //first find the largest element
	int mx=-1;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,arr[i]);
	}
	//allocating a dynemic frequncy array
std::vector<int> freq(mx+1);
	//fill the freq array
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	} 
	//now time to calculate the answer
	int j=0;
	//ans pointer
	for(int i=0;i<=mx;i++)
	{
		while(freq[i]>0)
		{
           arr[j++]=i;
           freq[i]--;
		}
	}
	return;

}
int32_t main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}   
counting_sort(arr,n);
//printing the element in sorted order
for(int i=0;i<n;i++)
{
 cout<<arr[i]<<" ";
}
cout<<endl;
return 0;

}


