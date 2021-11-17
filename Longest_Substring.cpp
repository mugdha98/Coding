/*
Given a string you need to print the size of the longest possible substring that has exactly k unique characters.


Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4
*/
#include<bits/stdc++.h>
using namespace std;

int longest_substring(string s,int k){
    int i=0,j=0,ans=INT_MIN;
    unordered_map<char,int> mp;
    while(j<s.length()){
        //cout<<"yes";
        //calculations
        mp[s[j]]++;

        if(mp.size()<k)j++;
        else if(mp.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }
        else{
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s;
        cin>>k;
        cout<<longest_substring(s,k)<<endl;
    }
    return 0;
}