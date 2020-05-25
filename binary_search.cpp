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
    int arr[100];
    //array must be sorted
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int search;
    cin>>search;
    int left =0;
    int right=n-1;
    int mid;
    bool flag=false;
    while(left<=right)
    {  
        mid=left+(right-left)/2;
        /*
     
     we can use mid=(right+left)/2;
     it can be wrong for some cornor case ,so to avoide this we are using these;

        */
      if(arr[mid]==search)
      {
          cout<<"Element is found at "<<mid<<endl;
          flag=true;
          break;
      }
     else if(arr[mid]<search)
     {
         left=mid+1;
     }
     else
     {
         right=mid-1;
     }
    }
    if(!flag)
    {
        cout<<" Not Found !!"<<endl;
    }
return 0;
}
