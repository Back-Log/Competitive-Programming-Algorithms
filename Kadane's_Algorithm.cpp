#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

//Kadane's Algorithm
//find maximum subarray sum in O(n) time
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max_sum=0,current_sum=0;
    for(int i=0;i<n;i++)
    {
      current_sum+=arr[i];
      //if we are hiting current sum as negetive, we will do that 0(it will reduse positve quantity)
      //it will not going to work when all the array element are negetive!!
      if(current_sum<0)
      {
          current_sum=0;
      }
      //storing the max sum
   max_sum=max(max_sum,current_sum);
 
    }
    cout<<max_sum<<endl;
return 0;
}
