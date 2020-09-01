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
void merge(int arr[],int s,int e)
{
  int mid=(s+e)/2;
  int i=s;
  int j=mid+1;
  int k=s;//this the pointer pointing to the start ,will use to copy the element in origanal array
  int temp[10000];//tmp array to store sorted value;
  while(i<=mid and j<=e)
  {
    if(arr[i]<arr[j])
    {
        temp[k]=arr[i];
        i++;
    }
    else
    {
        temp[k]=arr[j];
        j++;
    }
    k++;
  }
  //in case j or i reches to end but remaning not
  while(i<=mid)
  {
      temp[k]=arr[i];
      i++;k++;
  }
  while(j<=e)
  {
      temp[k]=arr[j];
      j++;k++;
  }
  //copying the temp array to the origanal array
for(int i=s;i<=e;i++)
{
    arr[i]=temp[i];
}

}
void merge_sort(int arr[],int s,int e)
{
    //the first step is devide the array into smaller part
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)>>1;
    //calculeting mid point
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    //now the array is devided 
    //its time to merge the array
    merge(arr,s,e);


}
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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}
