/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
int ans = 0;
bool isSafe(char in[][8], int i, int j, int n)
{
  //if current position is not valid
  //remove the condition when all the board is empty
  if (in[i][j] == '*')
  {
    return false;
  }

//check straight
  for (int row = 0; row < i; row++)
  {
    if (in[row][j] == '1')
    { 
      return false;
    }
  }
  int row = i;
  int col = j;
  //cheking left diagonal
  while (row >= 0 and col >= 0)
  {
    if (in[row][col] == '1')
    {
      return false;
    }
    row--;
    col--;
  }
  row = i;
  col = j;
  //cheking right diagonal
  while (row >= 0 and col < n)
  {
    if (in[row][col] == '1')
    {
      return false;
    }
    row--;
    col++;
  }
  // So here current postion was not bad
  return true;

}
bool recurse(char in[][8], int i, int n)
{
  //hitting the basecase ,when all the queen is placed
  if (i == n)
  {
    ans++;
    //If we will return true ->it will print one valid arrangment of queen's
    //But here we will get all the arrangement
    return false;
  }

  //recursive case
  for (int j = 0; j < n; j++)
  {
    //checking if the current position is safe to place the queen's
    if (isSafe(in, i, j, n))
    {
      //marked the placed queen
      in[i][j] = '1';
      //calling for remaining row
      bool next = recurse(in, i + 1, n);
      //if next is possible we will return true
      if (next)
      {
        return true;
      }
      //here we are backtraking the step
      in[i][j] = '.';


    }



  }


  return false;

}

int main()
{

  char in[8][8];
  //inputing the board
  //can be of any size here is a chess board
  /*
  input is like this at position *,we can't place queen's
   ....*...
   *...*...
   .......*
   ........
   ..*.*.*.
   ....*...
   ....*..*
   *...*...

  */
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cin >> in[i][j];
    }
  }

  bool ok = recurse(in, 0, 8);
  cout << ans << endl;


  return 0;
}