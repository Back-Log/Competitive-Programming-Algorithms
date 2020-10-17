#include<iostream>
#include<stack>
using namespace std;
#define int long long
int solve(int arr[],int n)
{
  stack<int>s;
  int area=-1;
  int temp;
  int i=0;
  for(;i<n;i++)
  {
     while(!s.empty() and arr[s.top()]>arr[i])
     {
     	int val=s.top();
     	s.pop();
     	if(s.empty())
     	{
     		temp=arr[val]*i;
     		area=max(area,temp);
     	}
     	else
     	{
     		temp=arr[val]*(i-s.top()-1);
     		area=max(area,temp);
     	}
     }
     if(s.empty())s.push(i);
     else if(arr[s.top()]<arr[i])
     {
     s.push(i);
     }
  	
  }
  while(!s.empty())
  {
  	int val=s.top();
     	s.pop();
     	if(s.empty())
     	{
     		temp=arr[val]*i;
     		area=max(area,temp);
     	}
     	else
     	{
     		temp=arr[val]*(i-s.top()-1);
     		area=max(area,temp);
     	}
  }

return area;


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
  
 int ans=solve(arr,n);
 cout<<ans<<endl;



}