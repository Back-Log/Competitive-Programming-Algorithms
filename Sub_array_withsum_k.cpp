#include<bits/stdc++.h>using namespace std; int findsum(int nums[], int n,int k) {        unordered_map<int, int> seen;        int sum = 0, answer = 0;        for (int j = 0; j < n; ++j) {            seen[sum]++;             sum += nums[j];            answer += seen[sum - k];        }        return answer;    }int main(){	int n;        	cin>>n;	int sum;	cin>>sum;	  int *arr=new int[n];	for(int i=0;i<n;i++)	{		 cin>>arr[i];	}	int result=findsum(arr,n,sum);	cout<<result<<endl;		}