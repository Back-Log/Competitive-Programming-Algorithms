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
    int n,k;
    cin>>n;
    cin>>k;
    int arr[100];
    int count=0;
    arr[0]=0;
    //first element of the array is zero so that we can treverse the array from 1
    int cum_sum[100];
    //array containing cumuletive sum
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        cum_sum[i]=arr[i]+cum_sum[i-1];

    }
    //O(n^2) solution
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(cum_sum[j]-cum_sum[i]==k)
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
return 0;
}
