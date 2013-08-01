#include"stage2.h"

void reverse3(vector<int> &num, int si, int ei) {
        if(si > ei) return;
        if(ei >= num.size()) return;
        int count = ei - si + 1;
        int times = count / 2;
        for(int i = 0; i < times; ++i) {
            int is = si + i;
            int ie = ei - i;
            int temp = num[is];
            num[is] = num[ie];
            num[ie] = temp;
        }
    }
    void nextPermutation3(vector<int> &num) {
        for(int i = num.size() - 2; i >= 0; --i) {
            if(num[i] < num[i+1]) {
                //find the last one who greater than num[i]
                for(int j = num.size() - 1; j > i; --j) {
                    if(num[j] > num[i]) {
                        int temp = num[i];
                        num[i] = num[j];
                        num[j] = temp;
                        break;
                    }
                }
                //reverse the items from i + 1 to num.size() - 1
                reverse3(num, i + 1, num.size() - 1);
                return;
            }
        }
        //no acending order found, reverse all the numbers
        reverse3(num,0,num.size() - 1);
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        result.push_back(num);
        int total = 1;
        for(int i = 0 ; i < num.size() ; ++ i) total *= (i+1);
        total -= 1;
        for(int i = 0 ; i < total; ++i) {
            nextPermutation3(num);
            vector<int> &last = result.back();
            if(last != num) {
                bool noacend = true;
                for(int j = 0; noacend && j < last.size() - 1; ++j ) {
                    if (last[j] < last[j +1] ) noacend = false;
                }
                if (noacend) break;
                result.push_back(num);
            }
        }
        return result;
    }
