#include"head.h"

string longestPalindromeDP(string s)
{
	int n=s.size();
	bool table[1000][1000]={false};
	int maxLen=1;
	int longestBegin=0;

	for(int i=0;i<n;i++)
		table[i][i]=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			table[i][i+1]=true;
			longestBegin=i;
			maxLen=2;
		}
	}

	for(int l=3;l<=n;l++)
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j] && table[i+1][j-1])
			{
				table[i][j]=true;
				longestBegin=i;
				maxLen=l;
			}
		}
	return s.substr(longestBegin,maxLen);
}

string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}