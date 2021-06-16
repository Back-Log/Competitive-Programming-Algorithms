#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back
void tower_of_hanoi(int n,char source,char helper,char desti)
{
  //base case
  if(n==0)
  {
      return;
  }
  //first transfer (n-1) disk from source to helper
  tower_of_hanoi(n-1,source,desti,helper);
  //1 disk from source to desti.
  cout<<"shift disk "<<n<<" from "<<source<<" to "<<desti<<endl;
  //next (n-1) from helper to desti
  tower_of_hanoi(n-1,helper,source,desti);
  return;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   //takes 2^n - 1 total move 
   char source='A';
   char helper='B';
   char desti='C';
   tower_of_hanoi(n,source,helper,desti); 
return 0;
}
