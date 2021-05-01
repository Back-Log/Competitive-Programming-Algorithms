//Implimentation of bucket sort
#include<bits/stdc++.h>
using namespace std;
//this sorting technique is used to sort the student according to their marks
class Student
{
public:
	string name;
	int marks;
};
//class of student having markes and their name;
void bucket_sort(Student In[],int n)
{
	//creating array of vectors
	//assuming that marks are between 0-100
 vector<Student>data[101];
 for(int i=0;i<n;i++)
 {
 	int m=In[i].marks;
 	data[m].push_back(In[i]);
 }
 // just print the values in sorted order
 for(int i=100;i>=0;i--)
 {
     for(auto it=data[i].begin();it!=data[i].end();it++)
 	{
 		cout<<(*it).name<<" "<<(*it).marks<<endl;
 	}
 }


return;
}
int main()
{
 
 //creat a object of array of Student class
	Student Input[1000];
	//1000 size
	int n;
	cin>>n;
	//number of students
	for(int i=0;i<n;i++)
	{
		cin>>Input[i].name>>Input[i].marks;
	}
	bucket_sort(Input,n);
return 0;
}