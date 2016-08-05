#include <iostream>
#include <cstring>
 
#define MAX(a,b,c) \
    (((a)>(b))?(((a)>(c))?(a):(c)):(((b)>(c))?(b):(c)))
 
using namespace std;
int a[1001][1001];
char str[1000];
int main()
{  
    int len = 0;
    int i = 0, j = 0;
    while (cin.get(str,1000).get())
    {
        len = strlen(str);
        if (0 == len){
            break;
        }
        for (i = 1; i <= len; i++)
        {
            for (j = 1;j <= len; j++)
            {
                if (str[i - 1] == str[len - j])
                {
                    a[i][j] = a[i - 1][j - 1] + 1;
                }
                else
                {
                    a[i][j] = MAX(a[i - 1][j - 1],
                                  a[i - 1][j], a[i][j - 1]);
                }
            }
        }
        cout << len - a[len][len] - 1 << endl;
        //֪��ΪʲôҪ��1��
        //��Ϊ��ô�Ĳ��������ַ�����߶���һ���ո񣬶�����û���ڳ����
    }
    return 0;
}