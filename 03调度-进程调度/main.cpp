#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
typedef multimap<int, int> IntIntMMap;
 
int main()
{
    int n = 0, i = 0, si = 0, j = 0, ei = 0, dst = 0;
    int p = 0, q = 0;
    int lastp = 0, sum = 0;
    IntIntMMap coll;
    while (cin >> n)
    {
        int *data = new int[n]();
        i = 0; lastp = 0;
        si = 0; ei = 0; dst = 0;
        coll.clear();
        while (i < n)
        {
            cin >> p >> q;
            coll.insert(make_pair(p, q));
            i++;
        }
        i = 0;
        IntIntMMap::iterator pos;
        bool bfirst = true;
        for (pos = coll.begin(); pos != coll.end(); ++pos)
        {
            p = pos->first;
            q = pos->second;
            data[i] = q;
            if (0 == i)
            {
                lastp = p;
            }
            else
            {
                if (lastp != p)
                {
                    if (bfirst)
                    {
                        sort(data + si, data + i);
                        ei = i;
                        dst = p - lastp;
                        lastp = p;
                        bfirst = false;
                    }
                    else
                    {
                        sort(data + ei, data + i);
                        for (j = si + 1; j < ei; j++)
                        {
                            data[j] += data[j - 1];
                        }
                        data[ei - 1] -= dst;
                        data[ei] += data[ei - 1];
                        si = ei;
                        ei = i;
                        dst = p - lastp;
                        lastp = p;
                    }                  
                }
            }
            i++;
        }
        sort(data + ei, data + i);
        for (j = si + 1; j < ei; j++)
        {
            data[j] += data[j - 1];
        }
        data[ei - 1] -= dst;
        data[ei] += data[ei - 1];
        for (j = ei + 1; j < i; j++)
        {
            data[j] += data[j - 1];
        }      
        sum = 0;
        for (i = 0;i < n - 1; i++)
        {
            sum += data[i];
        }
        printf("%.4f\n", sum / (n*1.0));
        delete [] data;
    }
    return 0;
}
