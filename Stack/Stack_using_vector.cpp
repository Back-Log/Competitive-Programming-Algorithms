#include<iostream>
#include<vector>
using namespace std;


class Stack{
   private:
   	std::vector<int> v;
   public:
   	//function to add the data into stack
   	void add(int data)
   	{
   		v.push_back(data);
   	}
   	//getting the top element of the stack
   	int top()
   	{
   		return v[v.size()-1];
   	}
   	bool empty()
   	{
   		return v.size()==0;
   	}
   	void pop()
   	{
   		if(!v.empty())
   			v.pop_back();
   	}

};
int main()
{
   Stack s;
   for(int i=5;i>0;i--)
   {
   	s.add(i);
   }
   while(!s.empty())
   {
   	cout<<s.top()<<" ";
   	s.pop();
   }



	return 0;
}