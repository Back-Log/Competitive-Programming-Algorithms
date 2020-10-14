#include<iostream>
#include<stack>
using namespace std;
void transfer(stack<int>&s1,stack<int>&s2,int n)
{
	int val;
	for(int i=0;i<n;i++)
	{
		val=s1.top();
		s2.push(val);
        s1.pop();
	}


}
void reverse_stack(stack<int>&s,int n)
{
  stack<int>extra;
  int val;
  for(int i=0;i<n;i++)
  {
  	val=s.top();
  	s.pop();
  	transfer(s,extra,n-i-1);
  	s.push(val);
  	transfer(extra,s,n-i-1);

  }



}
int main()
{
   stack<int>s;
   for(int i=1;i<=10;i++)
   {
   	s.push(i);
   }
   reverse_stack(s,s.size());
 
   //extra stack is the reverse of orignal
   while(!s.empty())
   {
   cout<<s.top()<<" ";
   s.pop();

   }
cout<<endl;




	return 0;
}