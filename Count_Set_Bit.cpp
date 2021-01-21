#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

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
