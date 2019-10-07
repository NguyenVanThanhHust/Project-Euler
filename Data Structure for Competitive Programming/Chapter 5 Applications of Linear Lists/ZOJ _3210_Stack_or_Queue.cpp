#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        bool isStack = true; 
        bool isQueue = true;
        int in[100], out[100];
        for (size_t i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> out[i];
            if (out[i] != in[i])
            {
                isQueue = false;
            }
            if (in[n-i-1] != out[i])
            {
                isStack = false;
            }
        }

        if (isStack && isQueue)
        {
            cout << "both" << endl;
        }
        else if(isStack)
        {
            cout << "stack" << endl;
        }
        else if (isQueue)
        {
            cout << "queue" << endl;
        }
        else
        {
            cout << "neither" << endl;
        }
    }
    return 0;
}