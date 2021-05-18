/*
  Time is the most valuable thing a man can spend. – Theophrastus
*/
#include<bits/stdc++.h>
using namespace std;
/*
Binary Indexed Tree also called Fenwick tree provides a way to represent
an array of numbers in a from of array, allowing prefix sums to be calculated
efficiently.
Key features -> Requires less space than segment tree
Time Compexity :
Update - O(logn)
query - O(logn)

*/
//define size of BIT array in case of large array element use co-ordinate compression in specfic cases
const int N = 1e2 + 10;
//BIT vector to store the values
vector<int>BIT(N);

//BIT update function
void update(int i, int by, int n)
{
  // by is the increment factor ,n- total size ,i- position
  while (i <= n)
  {
    BIT[i] += by;
    // every time i will incerent that much number of time
    i += (i & (-i));
  }


}

int query(int i)
{
  int result = 0;
  //Gives the sum till index i inclusive

  while (i > 0)
  {
    result += BIT[i];
    //Decrement factor
    i -= (i & (-i));

  }

  return result;

}
int main()
{
  /*
    *Alwayes use 1 based indexing*
    Every index in BIT stores the cumulative sum from the index i to i-2^r+1 (can be written as i-(1<<r)+1)(inclusive)
    Here r=the last set bit in the index i
    ex- i=4 ->100 (Here the last set is at postion 2)->r=2

    Key observation-> if cuurent index of BIT is in from of powers of 2 than it wiil store sum from 1 to i
    -> if the index is odd than it will store only the sum of cuurent index
  */

//First build the BIT using update function

  int n;
  cin >> n;

  vector<int>arr(n + 10);

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    //building BIT
    update(i, arr[i], n);
  }
  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    //Gives the sum from l to r
    cout << query(r) - query(l - 1) << endl;


  }
  return 0;

}