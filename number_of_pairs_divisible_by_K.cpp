#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

int total_pair(int arr[],int n,int k)
{
	int freq[k]={0};
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int rem=arr[i]%k;
		if(rem!=0)
		{
			//here for every rem, we are forming the pair with (k-rim)
			ans+=freq[k-rem];
		}
		else
		{
			//0 can form pair with mode zero element
			ans+=freq[0];
		}
		//updating the frequency table
		freq[rem]++;
	}
	
	return ans;
} 
int No_of_pairs(int arr[],int n,int k)
{
	int freq[k]={0};
	//taking the hash map of size k
	for(int i=0;i<n;i++)
	{
		++freq[arr[i]%k];
		//calculeting the hash table freq[arr%k]
	}
	int sum=0;
	//if arr[i]%k ==0 than we can from pairs
	sum+=(freq[0]/2);
	//if the k is even than freq[k/2] also from the valid pair
	if(k%2==0)sum+=(freq[k/2]/2);
	//and after that freq[i] from pair with freq[k-i]
	for(int i=1;i<=k/2;i++)
	{
		//if i==(k-i) is special case to avoid include two time in case k is even
		//we can run loop til i<(k+1)/2 to git rid of this case
		if(i!=(k-i))
		{
			sum+=min(freq[i],freq[k-i]);
		}
	}
	
	return sum;
	
}
//this algorithm is for number of diffrent pair where every element used only once to from a pair
//we can do som changes like total pair in freq[0]=freq[0](freq[0]-1)/2 to get allthe pair 
//where the element can used to from more than one pair
int32_t main()
{
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  int ans=No_of_pairs(arr,n,k);
  cout<<ans<<endl;
  //here one another method to find total number of pairs in array which is divisible by k
  //element can be used to from more than one pair
  ans=total_pair(arr,n,k);
  cout<<ans<<endl;
return 0;

}


