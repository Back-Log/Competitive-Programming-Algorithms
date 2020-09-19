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
void gen_subsequence(char in[],char out[],int i,int j)
{
   if(in[i]=='\0')
   {
   	out[j]='\0';
   	cout<<out<<" ";
   	return;
   }
   out[j]=in[i];
   //include charcter
   gen_subsequence(in,out,i+1,j+1);
   //exclude charcter
   gen_subsequence(in,out,i+1,j);

	return;
}
int32_t main()
{
	char input[1000];
	cin>>input;
	char output[1000];
	//this for null subsequence
	cout<<" ";
	//total 2^n possible sequence
	gen_subsequence(input,output,0,0);
	return 0;
}