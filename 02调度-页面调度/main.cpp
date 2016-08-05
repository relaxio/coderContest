#include <iostream>
#include <cstring>
using namespace std;
 
typedef unsigned char u1byte;
 
int main()
{
    u1byte page[200], cache[21];
    int n = 0, m = 0, i = 0, ci = 1;
    int t = 0, pageCount = 0, start = 1, unhit = 0;
    while (cin >> n >> m)
    {
        i = 0; t = 0; start = 1; ci = 1;
        unhit = 0;
        memset(page, 0, 200);
        memset(cache, 0, 21);
        while (i < m)
        {
            cin >> t;
            if (0 == page[t])       //未命中
            {
                unhit++;
                if (ci <= n)     //cache未满
                {
                    page[t] = ci;
                    cache[ci] = t;
                    ci++;
                }
                else                //cache满了
                {
                    page[cache[start]] = 0;         //出
                    page[t] = start;                //进
                    cache[start] = t;
                    start = ((start + 1) % n) ? ((start + 1) % n) : n;
                }
            }
            i++;
        }
        cout << unhit << endl;
    }
    return 0;
}
