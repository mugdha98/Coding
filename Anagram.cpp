/*Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times in txt.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int> m;
    string s1,s2;
    cin>>s1>>s2;

    int k=s2.length();
    //creation of map pf pattern s2
    for(int i=0;i<k;i++){
        if(m.find(s2[i])!=m.end()){
            m[s2[i]]++;
        }
        else m[s2[i]]=1;
    }
    int cnt=m.size();
    int ans=0;
    //logic
    int i=0,j=0;
    while(j<s1.length()){
        //calculation
        if(m.find(s1[j])!=m.end()){
            m[s1[j]]--;
            if(m[s1[j]]==0)cnt--;
        }

        if(j-i+1<k)j++;
        else if(j-i+1 == k){ 
            //ans
            if(cnt==0){ans++;}
            //slide the window
            if(m.find(s1[i])!=m.end()){
                m[s1[i]]++;
                if(m[s1[i]]==1)cnt++;
            }
            i++;
            j++;
        }
    }
    cout<<ans<<endl;

    return 0;
}