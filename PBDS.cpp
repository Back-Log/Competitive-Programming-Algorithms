#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*
Here in the typedef we can change the value of int to any type -> ex-string,double,pair<int,int>....

To use the duplicate element in the set we need to insert the values in the set by pair->like {value,index}

we can also use <greater> or <less_equal> instead of less in required places
*/
typedef tree<int,null_type,less<int>,rb_tree_tag,
		tree_order_statistics_node_update>
		PBDS;


int main()
{

// Declairing a Policy based data structure

PBDS s;

/*
There are two important mathod in PBDS
1-> find_by_order(k):- returns the itretor to the Kth largest element (index start from 0)
2-> order_of_key(k):- returns the number of element in the set ,which are strictly less than (k).

*/

return 0;

}