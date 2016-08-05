#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
    int n = 0, i = 0, len = 0;
    char str[12] = {};
    int ch[26] = {};
    short c_start = 0, c_end = 0, hbyte = 0, lbyte = 0;
    while (scanf("%d ", &n) != EOF)
    {
        i = 0; len = 0;
        c_start = 0; c_end = 0; hbyte = 0; lbyte = 0;
        memset(ch, 0, 26);
        while (i<n)
        {
            cin.get(str, 12).get();
            len = strlen(str);
            ch[str[0] - 'a'] += 256;
            ch[str[len - 2] - 'a']++;
            i++;
        }
        for (i = 0; i<26; i++)
        {
            hbyte = (ch[i] >> 8) & 0xff; lbyte = ch[i] & 0xff;
            ch[i] = (hbyte > lbyte) ? ((hbyte - lbyte) * 256) : (lbyte - hbyte);
            hbyte = (ch[i] >> 8) & 0xff; lbyte = ch[i] & 0xff;
            if (ch[i]>0 && (hbyte > 1 || lbyte > 1))
            {
                cout << "No" << endl;
                break;
            }
            if (ch[i] > 0){
                1 == hbyte ? c_start++ : c_end++;
            }
            if (c_start > 1 || c_end > 1)
            {
                cout << "No" << endl;
                break;
            }
        }
        if (i == 26)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}