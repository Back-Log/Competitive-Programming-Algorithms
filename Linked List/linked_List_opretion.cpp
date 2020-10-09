#include <iostream>
using namespace std;
// For deep detail visit : https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
class node{
public:
	int data;
	node*next;
	//defining constructor
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
void print(node*);
int leanth(node*);
void DeleteAthead(node*&);
void DeleteAtTail(node*&);
//write the function to delete the not at pos=p
void DeleteAtMiddle(node*&head,int pos)
{
   if(head==NULL)
   {
   	return;
   }
   else if(pos<=1)
   {
   	DeleteAthead(head);
   }
   else if(pos>=leanth(head))
   {
   	DeleteAtTail(head);
   }
   else
   {
     //first need to find which node we have to delete
   	 node*temp=head;
   	 node*prev=head;
   	 int count=pos;
   	 while(count--)
   	 {
   	 	temp=temp->next;
   	 }
   	 pos--;
   	 while(pos)
   	 {
   	 	prev=prev->next;
   	 	pos--;
   	 }
   prev->next=temp->next;
   delete temp;


   }


} 
void DeleteAtTail(node*&head)
{
  if(head==NULL)
  {
  	return;
  }
  node*tail=head;
  node*prev=head;
  while(tail->next!=NULL)
  {
  	prev=tail;
  	tail=tail->next;
  }
   prev->next=NULL;
  delete tail;


}
void DeleteAthead(node*&head)
{
  if(head==NULL)
  {
  	return;
  }
  node*temp=head->next;
  delete head;
  head=temp;

  return;
}
void InsetAtHead(node*&head,int d)
{
  if(head==NULL)
  {
  	head=new node(d);
  	return;
  }
  node*temp=new node(d);
  //now the head will change
  temp->next=head;
  head=temp;


}
//need to pass by refrence
void InsertAtEnd(node*&head,int d)
{
   if(head==NULL)
  {
  	head=new node(d);
  	return;
  }
  //now we need to find tail pointer
  node*tail=head;
  //if we just do tail!=null it will stop at NUll ,but we want one step ahead
  while(tail->next!=NULL)
  {
  	tail=tail->next;
  } 
 // now we are at the end of linked list
  tail->next=new node(d);

}
int leanth(node*head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
void InsertAtMiddle(node*&head,int pos,int d)
{
  //in case of linked list is null
	if(head==NULL or pos==0)
	{
		InsetAtHead(head,d);
	}
	else if(pos>leanth(head))
	{
		InsertAtEnd(head,d);
	}
	else
	{
		int final=pos-1;
		node*temp=head;
		while(final)
		{
			temp=temp->next;
			final--;
		}

      node*n=new node(d);
      n->next=temp->next;
      temp->next=n;

	}
 

return;

}

void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
	return;
}
void take_input(node*&head)
{
  int d;
  cin>>d;
  //we all end taking input when we get -1
  //here we can also take input till EOF
  //just -> while(cin>>d)
  while(d!=-1)
  {
  	InsertAtEnd(head,d);
  	cin>>d;
  }

}
bool search_key(node*head,int key)
{
	while(head!=NULL)
	{
		if(head->data==key)
		{
			return true;
		}
		head=head->next;
	}
	return false;
}
ostream &operator<<(ostream &os,node*head)
{
	print(head);
	return os;
}
istream& operator>>(istream &is,node*&head)
{
	take_input(head);
	return is;
}
void reverse(node*&head)
{
    node*prev=NULL;
    node*n;
    node*current=head;
    while(current!=NULL)
    {
        n=current->next;
    	current->next=prev;
    	prev=current;
    	current=n;
    }
    head=prev;
 return;
}
int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	//    freopen("output.txt","w",stdout);
 //    #endif
	//creating head pointer that is intially null
    node*head=NULL;
    //first we inserting at begining
    // InsetAtHead(head,4);
    // InsetAtHead(head,3);
    // InsetAtHead(head,2);
    // InsetAtHead(head,1);
    // InsertAtEnd(head,1);
    // InsertAtEnd(head,2);
    // InsertAtEnd(head,3);
    // InsertAtEnd(head,4);
    // InsertAtMiddle(head,2,0);
    // InsertAtMiddle(head,5,5);
    // InsetAtHead(head,-1);
    // // DeleteAthead(head);
    // // DeleteAtTail(head);
    // DeleteAtMiddle(head,8);
  // Now let's creat a function to take input
        //lets do opretor over loading
    // node*head1=NULL;
    cin>>head;

     //take_input(head);
    // print(head);
    // print(head1);
    //now going to creat search function
    //here we can implement only linear search

    int key=3;
    if(search_key(head,key))
    {
    	cout<<"Key Found"<<endl;
    }
    else
    {
    	cout<<"Key Not Found"<<endl;
    }
    //over loading ostream (<<) operator
    cout<<head;
  //now let's write the function to reerse the linked list
    reverse(head);
    cout<<head;

	return 0;
}
