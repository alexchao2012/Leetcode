#include<iostream>

using namespace std;
const int Charsize=1;
void func(void){
    char *table = new char[Charsize];
    
    for (int num =1; num <=Charsize; ++num){
        int cur =0;
        table[0] ='a'-1;

        while (cur >=0){
            table[cur] +=1;
            
            if (table[cur] <='z')
                if (num -1== cur) {
                    int i;
                    for (i =0; i < num; ++i)
                        cout<<table[i];
                    cout<<", ";
                }
                else{
                    ++cur;
                    table[cur] = table[cur -1];
                }
            else
                cur -=1;
        }
        cout<<endl;
    }
    
    delete[]table;
}

void calc(int len)
{
    // 初始化字符串（性质1）
    char digs[27] = "abcdefghijklmnopqrstuvwxyz";
    digs[len] = 0;

    bool flag = true;
    while (flag)
    {
        printf("%s,", digs);

        flag = false;
        for (int i = len-1; i >= 0; i --)
        {
            // 字符串从低位往高位增，满足字典序（性质3）
            digs[i] ++;
            // 满足该条件的，才能使字符依次递增
            if (digs[i] <= 'z'-(len-1-i))
            {
                // 字符是依次递增的（性质2）
                for (int j = i+1; j < len; j ++)
                    digs[j] = digs[j-1] + 1;
                flag = true;
                break;
            }
        }
    }
    printf("\n");
}

//int main()
//{
//	calc(1);
//    return 0;
//}