// https://github.com/shadowmydx/poj/blob/master/Printer%20Queue%203125.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int queue[200];
int front;
int rear;
int top;
int stack[200];

int main(void)
{
    int test;
    int n, m;
    int time;
    int start;
    int flag;
    int tmp;
    int size;
    cin >> test;
    while (test)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> queue[i];
            stack[i] = queue[i];
        }
        sort(stack, stack + n);
        front = 0;
        rear = n - 1;
        top = rear;
        time = 0;
        start = m;
        flag = 1;
        size = n;
        while (flag)
        {
            if (queue[front] != stack[top])
            {
                tmp = queue[front];
                front = (front + 1) % size;
                rear = (rear + 1) % size;
                queue[rear] = tmp;
                if (!start)start = n - 1;
                else start--;
            }
            else if (queue[front] == stack[top])
            {
                time++;
                if (!start)break;
                else
                {
                    //cout << stack[top] << " " << queue[front] << " " << start << endl;
                    //system("pause");
                    top--;
                    n--;
                    front = (front + 1) % size;
                    if (!start)start = n - 1;
                    else start--;
                }
            }
        }
        cout << time << endl;
        test--;
    }
    return 0;
}