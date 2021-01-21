#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  int n;
  cin>>n;
  //number of element in the array
  int arr[100];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  //array must be sorted if not sort it
  int target;
  cin>>target;
  int leftpointer=0,rightpointer=n-1;
  while(leftpointer<rightpointer)
  {
    if(arr[leftpointer]+arr[rightpointer]==target)
    {
        //if target found we are printing the target
        cout<<arr[leftpointer]<<" "<<arr[rightpointer]<<endl;
        leftpointer++;
        rightpointer--;
    }
    else if(arr[leftpointer]+arr[rightpointer]>target)
    {
        //if the sum is greater we are decresing the right pointer
      rightpointer--;
    }
  else if(arr[leftpointer]+arr[rightpointer]<target)
  {
      //decreasing left pointer in this stage
      leftpointer++;
  }

  }
return 0;
}
