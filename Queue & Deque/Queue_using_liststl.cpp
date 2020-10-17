#include<iostream>
#include<list>
//this is a doubly linked list
using namespace std;

class Queue{
  list<int>l;
  int current_size=0;
public:
	Queue()
	{ 
     current_size=0;
	}
	void push(int d)
	{
		l.push_back(d);
		current_size++;
	}
	bool empty()
	{
		return current_size==0;
	}
	void pop()
	{
		if(!empty())
		{
			l.pop_front();
			current_size--;
		}
	}
	int front()
	{
		return l.front();

	}




};
int main()
{
	Queue q;
	for(int i=0;i<10;i++)
	{
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(10);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

	return 0;
}