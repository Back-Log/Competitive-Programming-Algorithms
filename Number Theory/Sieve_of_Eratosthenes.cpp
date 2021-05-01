#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

void seive_of_eratosthenes(int *arr,int n)
{
  for(int i=3;i<=10000;i+=2)
  {
    arr[i]=1;
    //marking all the odd numbers as prime
  }
 for(int i=3;i*i<=10000;i+=2)
 {
   if(arr[i]==1)
   {
    for(int j=i*i;j<=10000;j=j+i)
    {
      //this is optimize approach ,you can start with 2*i
        arr[j]=0;
    }
   }

 }
//handling edge cases
 arr[0]=arr[1]=0;
 arr[2]=1;

}
//also known as Prime seive
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   //enter n (til where you want to ganrate prime number)
   int arr[10001]={0};
   seive_of_eratosthenes(arr,n);
   //printing
for(int i=0;i<=n;i++)
 {
    if(arr[i]==1)
    {
        cout<<i<<" ";
    }
 }
cout<<endl;
  
return 0;
}
