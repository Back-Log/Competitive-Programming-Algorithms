//first learn about creating object and class
//basic c++ oop revision
#include<iostream>
using namespace std;
//defining class will not accupy any memory
class complex{
public:
	int real;
	int img;
// constructor 
	complex()
	{
      real=0;
      img=0;
    
	}
 complex(int r,int i)
 {
 real=r;
 img=i;
 }
void set_real(const int r)
{
real=r;
}
void set_img(const int i)
{
img=i;
}
void print() const
{
	cout<<real<<"+"<<img<<"i"<<endl;
}
void add(const complex &c) 
{
	real+=c.real;
	img+=c.img;
}
//- (negative) opretor overloading--
void operator-(complex &c)
{
	real-=c.real;
	img-=c.img;
}
//*(product opretor overloading)
void operator*(const complex &c)
{
	int temp=real*c.real-img*c.img;
	int temp1=img*c.real+real*c.img;
	real=temp;
	img=temp1;
}
void operator[](string s)
{
	if(s=="real")
	{
		cout<<real<<endl;
	}
	else
	{
		cout<<img<<endl;
	}
}
//for taking user's input
// void operator>>(istream& is,complex &c)
// {
// 	int r1,i1;
// 	is>>r1>>i1;
// 	//now we can use our pre-define functions to set the value
//    c.set_real(r1);
//    c.set_img(i1);
// }


};

class Book{
private:
	//defining private so that ,no can access directly
	int price;
public:
  string name;
  string auther;
  void print()
  {
  	cout<<name<<" "<<auther<<" "<<price<<endl;
  }
  int discount(int val)
  {
  	return price-(price*val)/100;
  }
  int update_price(int dis)
  {
  	price=price-(price*dis)/100;
  	return price;
  }
  //define setter for private member
  void set_price(int p)
  {
  	price=p;
  }
  //getter to get the price;
  int get_price()
  {
  	return price;
  }

};
//this a simple Book class having three attribute
//1-string type
//2-int type
//3-string
class student{
 private:
 	string name;
 public:
 	int roll_no;
 	//use define constructor
 	// student(string n,int r)
 	// {
 	// 	name=n;
 	// 	roll_no=r;
 	// }
 	//print function
 	void print()
 	{
 	cout<<"Name :"<<name<<endl;
 	cout<<"Roll :"<<roll_no<<endl;
   }
   ~student()
   {
   	cout<<"Destructor called"<<endl;
   }
   void set_name(string n)
   {
   	name=n;
   }
   string get_name()
   {
   	return name;
   }


};
int main()
{
	 #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
     #endif
   //now we can creat object of type book
	Book b;
	//how to accses Book object??
	//so by default all the class atribute are privat
	b.name="Math";
	b.auther="Sharma";
	//price is private we can not use directly
	//b.price=300;
	b.set_price(100);
	//printin value;
	cout<<b.name<<" "<<b.auther<<" "<<b.get_price()<<endl;
	//also you can creat function inside class to print these value;
	//calling print function
	//b.set_price(100);
	b.print();
	//like if you want to give discount then
	int dis;
	cin>>dis;
	cout<<"after discount :";
	cout<<b.discount(dis)<<endl;
	b.update_price(dis);
	b.print();


	//if you print the size it will print all attribut memory allocated sum
	cout<<sizeof(b)<<endl;
	//both print same value-->16
	cout<<sizeof(Book)<<endl;
    complex cc;
cc.print();
complex dd(5,3);
dd.print();
complex ee=dd;
ee.print();
int aa,bb;
cin>>aa>>bb;
complex k;
k.set_real(aa);
k.set_img(bb);
k.print();
ee.add(k);
ee.print();
//let's do some opretor overloading
//how to substrect
ee-dd;
ee.print();
//product opretor overloading
ee*dd;
ee.print();
//let's overload the [] baractes
//this should print real part of d
dd["real"];
dd["img"];
// default cin>> and cout<< function will not going to work here
//because object is type complex
//so lets write the overloading for (>>) and (<<)
complex temp;
//cin>>temp;
//temp.print();
 student s;
 s.set_name("Rajan");
 s.roll_no=29;
 s.print();

	return 0;
}
