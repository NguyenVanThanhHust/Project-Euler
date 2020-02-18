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
        int wrong_col_1 = -1, wrong_col_2 = -1, wrong_row_1 = -1, wrong_row_2 = -1;

        for (int i = 0; i < k; i++)
        {
            if (c[i] % 2 != 0)
            {
                if (wrong_row_1 == -1)
                {
                    wrong_row_1 = i + 1;
                }
                else
                {
                    wrong_row_2 = i + 1;
                }
            }
            if (d[i] % 2 != 0)
            {
                if (wrong_col_1 == -1)
                {
                    wrong_col_1 = i + 1;
                }
                else
                {
                    wrong_col_2 = i + 1;
                }
            }
        }
        if (wrong_col_1 < 0 && wrong_row_1 < 0)
        {
            cout << "Ok" << endl;
        }
        else if (cond(wrong_col_1, wrong_row_1, wrong_col_2, wrong_col_2))
        {
            cout << "Change bit (" << wrong_row_1 << "," << wrong_col_1 << ")" << endl;
        }
        else if (cond(wrong_col_2, wrong_row_2, wrong_col_1, wrong_col_1))
        {
            cout << "Change bit (" << wrong_row_2 << "," << wrong_col_2 << ")" << endl;
        }
        else
        {
            cout << "Corrupt" << endl;
        }
        cin >> k;
    }
    return 0;
}