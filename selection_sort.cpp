#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

//Selection sort algorithm
//O(n^2)=time complexity
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
     {
         //we are checking the first min element in the array 
         int check=MAX,index;
         for(int j=i;j<n;j++)
         {
          if(arr[j]<check)
          {
              check=arr[j];
              index=j;
          }
         }
         swap(arr[i],arr[index]);
         //hear we are sweping first min element to the first index and same proccess 
         //for remaing element
     }
     for(int i=0;i<n;i++)
     {
         cout<<arr[i]<<" ";
     }
return 0;
}
