#include"stage3.h"
/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
/*��̬�滮(��Ҫ����⣩
����S����ǰm����ĸ���Ӵ��а������ٸ�T����ǰn����ĸ���Ӵ��������������ΪA[m][n]�� 
���Եõ�����ʽ ��
if(S[m-1] == T[n-1]) A[m][n] = A[m-1][n-1] + A[m-1][n];
else A[m][n] = A[m-1][n-1];
�ٴ���߽�������ɡ�
*/

int numDistinct(string S, string T) {//����,��Ȼ������01�����ķ�����������01�������Ż��洢�ռ�
    vector<int> f(T.size()+1);
    f[T.size()] = 1;
    for (int i = S.size()-1; i >= 0; --i) {
        for (int j = 0; j < T.size(); ++j) {
            f[j] += (S[i]==T[j])*f[j+1];
        }
    }
    return f[0];
}

int numDistinct2(string S, string T) {//��ô�о�������������������������,��Ҫ�ٺ�ʵ
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int **a;
    a = new int*[S.length()];
    for(int i = 0;i < S.length();i++)
        a[i] = new int[T.length()];
    for(int i = 0;i < S.length();i++)
        for(int j = 0;j < T.length();j++)
            a[i][j] = -1;
    return DP(S.length()-1,T.length()-1,a,&S,&T);
}
int DP(int m,int n,int **a,string *S, string *T)
{
    if(n == -1)
        return 1;
    else if(m == -1)
        return 0;
    if(m < n)
        return 0;
    if(a[m][n] != -1)
        return a[m][n];
    if(S->at(m) != T->at(n))
    {
        a[m][n] = DP(m-1,n,a,S,T);
        return a[m][n];
    }
    else
    {
        a[m][n] = DP(m-1,n-1,a,S,T) + DP(m-1,n,a,S,T);
        return a[m][n];
    }
}