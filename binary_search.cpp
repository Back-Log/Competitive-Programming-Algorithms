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
    int arr[100];
    //array must be sorted
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int search;
    cin>>search;
    int left =0;
    int right=n-1;
    int mid;
    bool flag=false;
    while(left<=right)
    {  
        mid=left+(right-left)/2;
        /*
     
     we can use mid=(right+left)/2;
     it can be wrong for some cornor case ,so to avoide this we are using these;

        */
      if(arr[mid]==search)
      {
          cout<<"Element is found at "<<mid<<endl;
          flag=true;
          break;
      }
     else if(arr[mid]<search)
     {
         left=mid+1;
     }
     else
     {
         right=mid-1;
     }
    }
    if(!flag)
    {
        cout<<" Not Found !!"<<endl;
    }
return 0;
}
