//implement a circular queue using array
#include <iostream>
using namespace std;

class Queue{
   int *arr;
   int current_size,max_size,frnt,rear;
public:
	//we can give the size of queue                              
	Queue(int size=10)
	{
		arr=new int[size];
		max_size=size;
		frnt=0;
		rear=max_size-1;
		current_size=0;
	}
	//function to check queue is empty or not
	bool empty()
	{
		return current_size==0;
	}
	//to check full or not
	bool full()
	{
		return current_size==max_size;
	}
	void push(int d)
	{
		if(!full())
		{
         rear=(rear+1)%max_size;
         arr[rear]=d;
         current_size++;
     }
	}
    void pop()
    {
    	if(!empty())
    	{
    	frnt=(frnt+1)%max_size;
    	current_size--;
        }
    }
    int front()
    {
    	return arr[frnt];
    }
    //constructor
    ~Queue()
    {
      if(arr!=NULL)
      {
        delete [] arr;
        arr=NULL;
      }
    }
};
int main()
{
   Queue check;
   for(int i=1;i<=9;i++)
   {
   	check.push(i);
   }
   check.push(25);
   check.pop();
   while(!check.empty())
   {
   	cout<<check.front()<<endl;
   	check.pop();
   }


	return 0;
}