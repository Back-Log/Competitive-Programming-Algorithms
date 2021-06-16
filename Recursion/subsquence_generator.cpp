#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

void gen_subsequence(char in[],char out[],int i,int j)
{
   if(in[i]=='\0')
   {
   	out[j]='\0';
   	cout<<out<<" ";
   	return;
   }
   out[j]=in[i];
   //include charcter
   gen_subsequence(in,out,i+1,j+1);
   //exclude charcter
   gen_subsequence(in,out,i+1,j);

	return;
}
int32_t main()
{
	char input[1000];
	cin>>input;
	char output[1000];
	//this for null subsequence
	cout<<" ";
	//total 2^n possible sequence
	gen_subsequence(input,output,0,0);
	return 0;
}