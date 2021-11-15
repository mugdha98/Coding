/*
Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4
*/
#include<bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> arr,int k){
    int i=0,j=0;
    long long sum=0;
    int ans=0;
    while(j< arr.size()){
        sum+=arr[j];
        if(sum<k)j++;
        else if(sum==k){
            if(ans<j-i+1)ans=j-i+1;
            j++;
        }
        else{
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main(){
    //input
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){int t; cin>>t;arr.push_back(t);}

    //output
    cout<<longest_subarray(arr,k);

    return 0;
}