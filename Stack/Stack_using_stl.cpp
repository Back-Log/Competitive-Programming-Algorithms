#include <bits/stdc++.h>
using namespace std;
int main()
{
  stack<int>s;
  stack<string>str;
  for(int i=10;i>=0;i--)
  {
  	s.push(i);
  }
  char sa='a';
  string oho="lol";
  for(int i=0;i<5;i++)
  {
    oho=sa+oho;
    str.push(oho);
    oho.erase(oho.begin());
    sa++;
  }
while(!s.empty())
{
	cout<<s.top()<<" ";
	s.pop();
}
cout<<endl;
while(!str.empty())
{
	cout<<str.top()<<" ";
	str.pop();
}
cout<<endl;

	return 0;
}