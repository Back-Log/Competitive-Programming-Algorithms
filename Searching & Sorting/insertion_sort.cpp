#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

//Insertion sort==O(n^2)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        //we are chossing the currennt element in the array and we are
        //puting this element to their right position
        int e=arr[i];
        int k=i-1;
        while(k>=0 && arr[k]>e)
        {
            arr[k+1]=arr[k];
            //copying the cuurent element to the kth index of the array
            k--;
        }
  arr[k+1]=e;

    }
        
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
return 0;
}
