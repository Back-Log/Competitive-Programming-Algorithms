#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

//taking a vector to store all the prime till sqrt(n)
vector<int>prime;
void seive()
{
  int mx=1e5+7;
  bitset<100007>b;
  b.set();
  //set all the value equel to 1 (as a prime)
  //first mark all the even as non prime
  for(int i=0;i<mx;i+=2)
  {
    b[i]=0;
  }
  //2 is only even prime
  b[2]=1;
  b[1]=0;
  for(int i=3;i*1<=mx;i+=2)
  {
  	if(b[i])
  	{
  		for(int j=i*i;j<=mx;j+=i)
  		{
  			b[j]=0;
  		}
  	}
  }
  for(int i=0;i<=mx;i++)
  {
  	if(b[i])
  	{
  		prime.push_back(i);
  	}
  }

}
void segmented_seive(int l,int r)
{
  vector<int>arr(r-l+1,1);
  int i=0;
  //if (l==1)l++;
  while(prime[i]<=sqrt(r))
  {
  	//here we are finding first multiple of current prime number
      int start=(l/prime[i])*prime[i];
      //in case start<l;
      if(start<l)
      {
      	start+=prime[i];
      }
      //we mark all the multiple of start as non prime
      for(;start<=r;start+=prime[i])
      {
      	//we can't mark 3,5,7 as non prime so...this
      	if(start!=prime[i])
         arr[start-l]=0;
      }
   
  i++;

  }
  
for(int i=0;i<(r-l+1);i++)
{
	if(arr[i]==1)
	{
		cout<<i+l<<" ";
	}
}

cout<<endl;

}
int32_t main()
{
  //if you have given to genrate all the prime number till aprox 10^10 or more
	//simple seive will not work
	// hear, we will use segmented seive
	//first step is genrate all the prime numbers till sqrt(n)
	//-->range of n is 10^10
	seive();
 int t;
 cin>>t;
 while(t--)
 {
 	int l,r;
 	cin>>l>>r;
 	//you have to print all the numbers in a given range
 	segmented_seive(l,r);
 }


   
return 0;

}


