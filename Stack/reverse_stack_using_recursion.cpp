#include<iostream>
#include<stack>
using namespace std;
void bottom_insert(stack<int>&s,int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int d=s.top();
	s.pop();
	bottom_insert(s,x);
	s.push(d);
}

void reverse_stack(stack<int>&s)
{
   if(s.empty()){
   	return;
   }
  int x=s.top();
  s.pop();
  reverse_stack(s);
  bottom_insert(s,x);

}

int main()
{
 
 int n;
 cin>>n;
 stack<int>s;
 for(int i=0;i<n;i++)
 {
 	int x;
 	cin>>x;
 	s.push(x);
 }
 
 reverse_stack(s);
while(!s.empty())
{
	cout<<s.top()<<endl;
	s.pop();
}
return 0;
}
