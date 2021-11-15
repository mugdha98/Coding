#include<bits/stdc++.h>
using namespace std;

/*Given an array arr[] of size N and an integer K.
 Find the maximum for each and every contiguous subarray of size K.

Example:

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
*/
vector<int> subarray(vector<int> a,int k){
    list<int> l;
    vector<int>ans;
    int i=0,j=0;
    while(j<a.size()){
        //calculation
        while(l.size()>0 && l.back()<a[j]){
            l.pop_back();
        }
        l.push_back(a[j]);

        if(j-i+1<k)j++;
        else if(j-i+1 == k){
            //ans
            ans.push_back(l.front());
            //slide
            if(l.front()==a[i])l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    vector<int> arr;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    cin>>k;
    vector<int> ans;
    ans=subarray(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}