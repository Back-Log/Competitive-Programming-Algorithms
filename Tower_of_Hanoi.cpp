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
void tower_of_hanoi(int n,char source,char helper,char desti)
{
  //base case
  if(n==0)
  {
      return;
  }
  //first transfer (n-1) disk from source to helper
  tower_of_hanoi(n-1,source,desti,helper);
  //1 disk from source to desti.
  cout<<"shift disk "<<n<<" from "<<source<<" to "<<desti<<endl;
  //next (n-1) from helper to desti
  tower_of_hanoi(n-1,helper,source,desti);
  return;


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
   //takes 2^n - 1 total move 
   char source='A';
   char helper='B';
   char desti='C';
   tower_of_hanoi(n,source,helper,desti); 
return 0;
}
