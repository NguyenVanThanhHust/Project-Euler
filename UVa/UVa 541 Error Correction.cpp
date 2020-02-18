#include <iostream>

#define cond(x1, y1, x2, y2) x1 > 0 && y1 > 00 && x2 < 0 && y2 < 0
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int k;
    int a[100][100], c[100], d[100];
    cin >> k;
    while (k)
    {
        for (int i = 0; i < k; i++)
        {
            c[i] = 0;
            for (int j = 0; j < k; j++)
            {
                cin >> a[i][j];
                c[i] += a[i][j];
            }
        }
        for (int j = 0; j < k; j++)
        {
            d[j] = 0;
            for (int i = 0; i < k; i++)
            {
                d[j] += a[i][j];
            }
        }
        int wrong_col = -1, wrong_row = -1 ;
        int n_wrong_col = 0, n_wrong_row = 0;
        for (int i = 0; i < k; i++)
        {
            if (c[i] % 2 != 0)
            {
                n_wrong_row++;
                wrong_row = i + 1;
            }
            if (d[i] % 2 != 0)
            {
                n_wrong_col++;
                wrong_col = i + 1;
            }
        }
        if (n_wrong_row == 0 && n_wrong_col == 0)
        {
            cout << "Ok" << endl;
        }
        else if (n_wrong_row == 1 && n_wrong_col == 1)
        {
            cout << "Change bit (" << wrong_row << "," << wrong_col << ")" << endl;
        }
        else
        {
            cout << "Corrupt" << endl;
        }
        cin >> k;
    }
    return 0;
}