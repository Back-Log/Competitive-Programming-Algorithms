#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

//Bubble sort
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
    for(int i=0;i<n-1;i++)
    //we are just doing n-1 iteration to sort the element
    {
        for(int j=0;j<n-i-1;j++)
        {
            //here we are pusing the first bigger element of the array towards the 
            //end of the array
            if(arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
            }
        }
    }
    //bubble sort ==bigger element toward the end of the array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}
