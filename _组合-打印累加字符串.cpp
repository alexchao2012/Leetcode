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
    // ��ʼ���ַ���������1��
    char digs[27] = "abcdefghijklmnopqrstuvwxyz";
    digs[len] = 0;

    bool flag = true;
    while (flag)
    {
        printf("%s,", digs);

        flag = false;
        for (int i = len-1; i >= 0; i --)
        {
            // �ַ����ӵ�λ����λ���������ֵ�������3��
            digs[i] ++;
            // ����������ģ�����ʹ�ַ����ε���
            if (digs[i] <= 'z'-(len-1-i))
            {
                // �ַ������ε����ģ�����2��
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