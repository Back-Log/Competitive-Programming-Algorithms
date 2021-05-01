#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

float square_root(int n,int p)
{
   int s=0;
   int e=n;
   float ans=-1;
   while(s<=e)
   {
      int mid=(s+e)>>1;
      if(mid*mid==n)
      {
      	return mid;
      	//if the number is perfect square
      } 
      else if(mid*mid<n)
      {
      	ans=mid;
      	s=mid+1;
      }
      else
      {
      	e=mid-1;
      }

   }
   //now we have found the integer part of squre root
   //now let's find decimal part
   float inc=0.1;
   //p->this the precision part you want
   for(int i=0;i<p;i++)
   {
     while(ans*ans<=n)
     {
     	ans+=inc;
     }
     //we have overshoot the value
     ans=ans-inc;

    inc*=0.1;

   }

return ans;

}
int32_t main()
{
   int n;
   cin>>n;
//you can take p as input also
 float ans=square_root(n,5);
 cout<<ans<<endl;
//over all time complexity=o(logn+c)):
return 0;

}