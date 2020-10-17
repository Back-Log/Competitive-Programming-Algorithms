#include<bits/stdc++.h>
using namespace std;
//o(n)->time complexity using stack data structure
int main() {
stack<int>s;
int n;
cin>>n;
int arr[n+1];
for(int i=1;i<=n;i++)
{
	cin>>arr[i];
}
cout<<1<<" ";
s.push(1);
for(int i=2;i<=n;i++)
{
  while(!s.empty() and arr[s.top()]<=arr[i])
  {  
       s.pop();
  }
  if(!s.empty())
  {
      cout<<i-s.top()<<" ";
  }
  else
  {
      cout<<i<<" ";
  }
  s.push(i);

}


	return 0;
}