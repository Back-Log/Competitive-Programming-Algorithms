#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
int main()
{
  int freq[26]{0};
  char a[1000]="aabccdb";
  //cin>>a;
  int len=strlen(a);
  queue<char>q;
  for(int i=0;i<len;i++)
  {
  	 q.push(a[i]);
  	 int val=a[i]-'a';
  	 freq[val]++;
     while(!q.empty())
     {
       int indx=q.front()-'a';
       if(freq[indx]==1)
       {
       	cout<<q.front();
       	break;
       }
       else if(freq[indx]>1)
       {
         q.pop();
       }
      
     }
     if(q.empty())
     {
     	cout<<-1;
     }
  }
cout<<endl;
	return 0;
}