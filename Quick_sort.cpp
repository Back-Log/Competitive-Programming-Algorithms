#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

int partition(int arr[],int s,int e)
{
    //first decide the pivot element 
    int pivot=arr[e];
    int i=s-1;
    int j=s;
    //j is from start
    for(;j<=e-1;)
    {
        //itreting through whole array
        if(arr[j]<=pivot)
        {
           i+=1;
            swap(arr[i],arr[j]);
        }
        j+=1;
        //increment j every time
    }
 // now time to arrange pivot elent to their position
 swap(arr[i+1],arr[e]);
 return i+1;
 //returning current pivot position

}
void quick_sort(int arr[],int s,int e)
{

//base case
if(s>=e)
{
    return;
}
//call the partition method
int p=partition(arr,s,e);

quick_sort(arr,s,p-1);
quick_sort(arr,p,e);

}
int main()
{
    //time complexity -> O(NlogN);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int arr[n];
    //it's inplace sorting algorithm ,no need of extra array
    for(int i=0;i<n;i++)cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    
return 0;
}
