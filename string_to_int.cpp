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
//always carefull with overflow
int rec_string_to_int(string s,int n)
{
  if(n==0)
  {
      return 0;
  }
  int digit=s[n-1]-'0';
  int ans=rec_string_to_int(s,n-1);

   return ans*10+digit;
} 
int itstring_to_int(string s)
{
    int power=1;
    for(int i=0;i<s.size()-1;i++)
    {
        power*=10;
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    { 
        int cal=((s[i]-'0')*power);
        ans+=cal;
        power/=10;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    int ans;
    //this one is itretive mathod
    ans=itstring_to_int(s);
    cout<<ans<<endl;
    //inbult function
    ans=stoi(s);
    cout<<ans<<endl;
    //let's solve using recursion
    ans=rec_string_to_int(s,s.size());
    cout<<ans<<endl;

    
return 0;
}
