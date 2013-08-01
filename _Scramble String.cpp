#include"stage2.h"
/* 
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
bool containAll(const string& s1,int st1,int end1,const string& s2,int st2,int end2)  //好好理解吧
{  
    vector<int> visit(256,0);  
    int len=end1-st1+1;  
    for(int i=0;i<len;i++)  
        visit[s1[st1+i]]++;  
  
    bool ans=true;  
    for(int i=0;i<len;i++)  
    {  
        if (visit[s2[st2+i]]<=0)  
        {  
            ans=false;  
            break;  
        }  
        visit[s2[st2+i]]--;  
    }  
    return ans;  
}  
  
bool isOK(string& s1,int st1,int end1,string& s2,int st2,int end2)  
{  
    if (st1>end1 && st2>end2)  
        return true;  
    if (st1==end1&&st2==end2)  
        return s1[st1]==s2[st2];  
  
    bool ans=false;  
    for(int len=1;len<=(end1-st1);len++)  
    {  
        int right=end1-st1+1-len;  
        int loc=st2;  
          
          
        if (containAll(s1,st1,st1+len-1,s2,st2,st2+len-1))  
        {  
            ans= isOK(s1,st1,st1+len-1,s2,st2,st2+len-1)&&isOK(s1,st1+len,end1,s2,st2+len,end2);  
        }  
        if (ans)  
            break;  
        if (containAll(s1,st1,st1+right-1,s2,st2+len,end2))  
        {  
            ans= isOK(s1,st1,st1+right-1,s2,st2+len,end2)&&isOK(s1,st1+right,end1,s2,st2,st2+len-1);              
        }  
        if (ans)  
            break;  
    }  
    return ans;  
}  
  
bool isScramble(string s1,string s2)  
{  
    int sz1=s1.size();  
    int sz2=s2.size();  
    if (sz1!=sz2) return false;  
    return isOK(s1,0,sz1-1,s2,0,sz2-1);  
}