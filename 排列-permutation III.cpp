#include"stage2.h"

/*
Here is the idea. For each k, divide the number of previous permutations into some factorials, 
for each factorial, count how many and save this info into an index array. 
Based on this array, we can choose which digit at each position. e.g, for n=4, k=20, 
it has 19 permutations before, 19 = 33! + 02! + 1*1! + 0, so the index[] would be 0,1,0,3 
(reversing order), which can be interpreted as the order of digit in an ordered array, e.g, 
3 means arr[3] in [1,2,3,4] which is 4.
*/
int fact(int n);
string getPermutation2(int n, int k){
 assert(1<=k && k<=fact(n));

    string s;
    int i;        
    vector<int> index(n,0);

    int kk = k - 1;
    for (i=n-1; i>=0; i--) {
        while (kk >= fact(i)) { //index[i] * i! 
            index[i]++;
            kk -= fact(i);
        }
    }

    vector<int> arr;
    for (i=0; i<n; i++) arr.push_back(i+1);
    for (i=n-1; i>=0; i--) {
        s = s + (char)(arr[index[i]] + '0');
        arr.erase(arr.begin() + index[i]);
    }
    return s;
}

int fact(int n)
{
    int f = 1;
    for (int i=n; i>0; i--)
        f = f * i;
    return f;
}


/*
����
�������ʵ�к�ǿ�Ĺ��ɿ�ѭ�����ȣ�n��Ԫ�ص�����������n!��������ķ����У���k�ķ�Χ��0 <= k < n!������Ŀ����ʵ������1<=k<=n!)
���Կ���һ�����ɣ�������n���������У���һλ��Ԫ������(n-1)!һ����ֵģ�Ҳ��˵���p = k / (n-1)!����ô���е��ʼһ��Ԫ��һ����arr[p]��
������ɿ���������ȥ����ʣ���n-1��Ԫ��������ѡ���ڶ�������������...������n��Ԫ�ء�����ͽ�����



��Ŀ������Permutation Sequence
The set [1,2,3,��,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
��123��
��132��
��213��
��231��
��312��
��321��
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/

string getPermutation(int n, int k) {
    char *arr = new char[n];
    int pro = 1;
    for(int i = 0 ; i < n; ++i) {
        arr[i] = '1' + i;
        pro *= (i + 1);
    }
    k = k - 1;
    k %= pro;
    pro /= n;//pro = 1 * 2 * ... * (n-1)
    for(int i = 0 ; i < n-1; ++i) {
        //for index i
        int selectI = k / pro;
        k = k % pro;
        pro /= (n - i - 1);
        int temp = arr[selectI + i];
        for(int j = selectI; j > 0; --j)
            arr[i + j] = arr[i + j - 1];
        arr[i] = temp;
    }
    return string(arr, arr + n);
}