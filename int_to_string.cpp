#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

string fun_int_to_string(int n)
{
    string ans="";
    while(n>0)
    {
        char c=(n%10)+'0';
        ans+=c;
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    //using inbuilt function
    string ans=to_string(n);
    cout<<ans<<endl;
    ans=fun_int_to_string(n);
    cout<<ans<<endl;
    
return 0;
}
