#include<bits/stdc++.h>
using namespace std;
int TotalSubarray(int *arr,int n,int k)
{
  int ans=0;
  int freq[k]={0};
  int sum=0;
  for(int i=0;i<n;i++)
  {
  	//we are going to mentain the running sum
  	//in case of reminder is negative ,we are adding k to it
  	sum+=((arr[i]%k+k))%k;
  	freq[sum%k]++;

  }
//handle the freq[0] case seprately for their indivisual contribution
  ans=freq[0];
 for(int i=0;i<k;i++)
 {
 	//adding nC2 to ans for every element
 	ans+=freq[i]*(freq[i]-1)/2;
 }

return ans;
}
int main()
{
 //number of element in the array
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  	//value of K
  	int k;
  cin>>k;
 
  cout<<TotalSubarray(arr,n,k)<<endl;

	return 0;
}