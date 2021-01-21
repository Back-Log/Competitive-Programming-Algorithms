#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back
//always carefull with overflow
int rec_string_to_int(string s,int n)
{
  if(n==0)
  {
      return 0;
  }
  int digit=s[n-1]-'0';
  int ans=rec_string_to_int(s,n-1);

   return ans*10+digit;
} 
int itstring_to_int(string s)
{
    int power=1;
    for(int i=0;i<s.size()-1;i++)
    {
        power*=10;
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    { 
        int cal=((s[i]-'0')*power);
        ans+=cal;
        power/=10;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    string s;
    cin>>s;
    int ans;
    //this one is itretive mathod
    ans=itstring_to_int(s);
    cout<<ans<<endl;
    //inbult function
    ans=stoi(s);
    cout<<ans<<endl;
    //let's solve using recursion
    ans=rec_string_to_int(s,s.size());
    cout<<ans<<endl;

    
return 0;
}
