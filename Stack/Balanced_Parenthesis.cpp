#include<iostream>
#include <stack>
using namespace std;
bool solve(char a[])
{
	stack<int>s;
  for(int i=0;a[i]!='\0';i++)
  {
    if(a[i]=='(')
    {
    	s.push(i);
    }
    else if(a[i]==')')
    {
    	if(s.empty())
    	{
    		return false;
    	}
    	else
    	{
    		s.pop();
    	}
    }
  }
 return s.empty();

}
int main()
{
  char arr[100]="(()()(()";
  //our work is to check that given expression is valid or not
  if(solve(arr))
  {
  	cout<<"YES"<<endl;
  }
  else
  {
  	cout<<"NO"<<endl;
  }
  

	return 0;
}