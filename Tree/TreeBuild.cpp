#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  	int data;
  	Node *left;
  	Node *right;
  	Node(int d)
  	{
  		data=d;
  		left=right=NULL;
  	}

};
Node* BuildTreeRecursive()
{
  int d;
  cin>>d;
  if(d==-1)
  {
  	return NULL;
  }
  Node* root=new Node(d);
  root->left=BuildTreeRecursive();
  root->right=BuildTreeRecursive();
  
  return root;

}
//input->>(5 3 -1 4 -1 -1 8 5 -1 -1 -1)
// going to build the tree in preorder(root,left,right)
//input 8 5 6 -1 3 -1 -1 9 2 -1 -1 -1 0 7 -1 -1 3 4 -1 -1 11 -1 -1
void printPreorder(Node* root)
{
 if(root==NULL)
 	return;
 cout<<root->data<<" ";
 printPreorder(root->left);
 printPreorder(root->right);

}
// Inorder -> (left,root,right)
void printInorder(Node* root)
{
 if(root==NULL)
 	return;
 printInorder(root->left);
 cout<<root->data<<" ";
 printInorder(root->right);

}
// Post order -->(left,right,root)
void printPostorder(Node* root)
{
 if(root==NULL)
 	return;
 printPostorder(root->left);
 printPostorder(root->right);
 cout<<root->data<<" ";
}
//calculate the hight of the tree using recursion
int hight(Node *root)
{
 if(root==NULL)
 {
  return 0;
 }
int leftHight=hight(root->left);
int righthight=hight(root->right);
return max(leftHight,righthight)+1;

}
/*
Write a function to print tree in level order treversel
*/
void printLavelorder(Node*root,int level)
{
 if(root==NULL)
 {
  return;
 }
 if(level==1)
 {
  cout<<root->data<<" ";
 }
 printLavelorder(root->left,level-1);
 printLavelorder(root->right,level-1);

return;
}
// Print the tree in level order treversal --->also called -->BFS (Breadth First Search)
//*****************************************************************************************
void BFS(Node*root)
{
  //we need queue to process the data
  queue<Node*>q;
  q.push(root);
  while(!q.empty())
  {
    Node *ans=q.front();
    cout<<ans->data<<" ";
    q.pop();
    if(ans->left!=NULL)
    {
      q.push(ans->left);
    }
    if(ans->right!=NULL)
    {
      q.push(ans->right);
    }


  }
 return;

}
//******************************************************************************************
/*
Now our task is to print the every lavel of the tree in O(n) time
1-Mathod--> We can use queue<pair<Node*,lavel>>q -->than print for every lavel
2-Marhod -> Put Null when every lavel ends 

*/
void LavelBFS(Node*root)
{
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
  {
     Node *ans=q.front();
     //cout<<ans->data<<" ";
     if(q.front()==NULL)
     {
      cout<<endl;
      q.pop();
      if(!q.empty())
      {
        //means we have proccesd current level
        //push null for next lavel
        q.push(NULL);
      }

     }
     else
     {
      cout<<ans->data<<" ";
      q.pop();
   if(ans->left!=NULL)
    {
      q.push(ans->left);
    }
    if(ans->right!=NULL)
    {
      q.push(ans->right);
    }

     }

   }
 
return;
}
/*
Now our task is to calculate the total number of node in the tree
*/
int TotalNode(Node*root)
{
  if(root==NULL)return 0;
  int left=TotalNode(root->left);
  int right=TotalNode(root->right);
  return 1+left+right;
}
/*
Our task is to calculate the sum of data of all node
*/
int SumNode(Node*root)
{
  if(root==NULL)return 0;
  int leftSum=SumNode(root->left);
  int rightSum=SumNode(root->right);
 
 return root->data+leftSum+rightSum;
}
/*
  Calculate dimeter of the tree
  -> Maximum distence between any two nodes of the tree
  this O(n^2) solution
  */
int Diameter(Node*root)
{
  if(root==NULL)
  {
    return 0;
  }
  int h1=hight(root->left);
  int h2=hight(root->right);
  int one=h1+h2;
  int two=Diameter(root->left);
  int three=Diameter(root->right);
  return max(one,max(two,three)); 

}
/*
Let's find the diameter in O(n) time
*/
//going to creat pair(bottom up approach)
class Pair{
 public:
  int hight;
  int diameter;
};
Pair OptimalDiameter(Node*root)
{
  Pair p;
  if(root==NULL)
  {
    p.hight=p.diameter=0;
    return p;
  }
  // if not than we have two options
  Pair left=OptimalDiameter(root->left);
  Pair right=OptimalDiameter(root->right);
  p.hight=max(left.hight,right.hight)+1;
  p.diameter=max(left.hight+right.hight,max(left.diameter,right.diameter));

  return p;
}
int main()
{

  Node* root=BuildTreeRecursive();
  cout<<"Preorder: ";
  printPreorder(root);
  cout<<endl;
  cout<<"Inorder: ";
  printInorder(root);
  cout<<endl;
  cout<<"Postorder: ";
  printPostorder(root);
  cout<<endl;
  cout<<"Hight :"<<hight(root)<<endl;
  int h=hight(root);
  // printLavelorder(root,3);
  //Now print all the lavels
  //takes order of n^2 to print
  for(int i=1;i<=h;i++)
  {
    cout<<"Lavel-"<<i<<":";
    printLavelorder(root,i);
    cout<<endl;

  }
 BFS(root);
 cout<<endl;
 LavelBFS(root);
 cout<<"Total Node :"<<TotalNode(root)<<endl;
 cout<<"Total Sum of Element of node :"<<SumNode(root)<<endl;
 cout<<"Diameter :"<<Diameter(root)<<endl;
 Pair ans=OptimalDiameter(root);
 cout<<"Optiaml Diameter :"<<ans.diameter<<endl;
 cout<<"Hight :"<<ans.hight<<endl;
	return 0;
}