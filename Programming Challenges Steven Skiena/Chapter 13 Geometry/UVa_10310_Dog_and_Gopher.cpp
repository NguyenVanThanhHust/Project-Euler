#include <iostream>
#include <cmath>
#include <iomanip>

#define M_PI           3.14159265358979323846
#define eps 1e-5
#define NMAXS 1000
using namespace std;

struct point
{
    float x, y;
};

struct line
{
    float a, b, c;
};

struct circle
{
    point center;
    float radius;
};

struct hole
{
    point p;
    float distance_to_gopher;
    float distance_to_dog;
    bool isEscaped;
};

float distance_point_to_point(point &p1, point &p2);
float distance_point_to_line(point &p, line &l);
line get_midperpendicular_line(point &p1, point &p2);
bool is_closer_to_dog_size(hole &h, line &midperpendicular_line);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n_holes;
    cin >> n_holes;

    hole h[NMAXS];
    point dog, gopher;
    cin >> gopher.x >> gopher.y;
    cin >> dog.x >> dog.y;
    line midperpendicular_line = get_midperpendicular_line(dog, gopher);
    int escapedIndex = -1;
    for (int i = 0; i < n_holes; i++)
    {
        cin >> h[i].p.x >> h[i].p.y;
        if (is_closer_to_dog_size(h[i], midperpendicular_line))
        {
            h[i].isEscaped == false;
        }
        else
        {
            h[i].distance_to_gopher = distance_point_to_point(h[i].p, gopher);
            h[i].distance_to_dog = distance_point_to_point(h[i].p, dog);
            if (h[i].distance_to_dog > 2 * h[i].distance_to_gopher)
            {
                escapedIndex = i;
                h[i].isEscaped = true;
                break;
            }
        }
    }
    if (escapedIndex == -1)
    {
        cout << "The hoppper cannot escape." << endl;
    }
    else
    {
        cout << "The hopper can escape through the hole at (" << setprecision(3)<<h[escapedIndex].p.x << "," << h[escapedIndex].p.y << " )" << endl;
    }
    return 0;
}

float distance_point_to_point(point &p1, point &p2)
{
    float d_x = (p1.x - p2.x) * (p1.x - p2.x);
    float d_y = (p1.y - p2.y) * (p1.y - p2.y);
    float res = sqrt(d_x + d_y);
    return res;
}

float distance_point_to_line(point &p, line &l)
{
    float mau = sqrt(l.a * l.a + l.b * l.b);
    float tu = abs(l.a * p.x + l.b * p.y + l.c);
    float res = tu / mau;
    return res;
}

line get_midperpendicular_line(point &p1, point &p2)
{
    // p1 is dog, p2 is gopher
    point middle_point;
    middle_point.x = (p1.x + p2.x) / 2;
    middle_point.y = (p1.y + p2.y) / 2;

    line l;
    l.a = p1.y - p2.y;
    l.b = p2.x - p1.x;
    l.c = -l.a*middle_point.x - l.b*middle_point.y;

    double on_dog_side = l.a * p1.x + l.b*p1.y + l.c;
    if (on_dog_side > 0)
    {
        return l;
    }
    else
    {
        l.a = -l.a;
        l.b = -l.b;
        l.c = -l.a*middle_point.x - l.b*middle_point.y;
        return l;
    }
}

bool is_closer_to_dog_size(hole &h, line &midperpendicular_line)
{
    float value = midperpendicular_line.a * h.p.x + midperpendicular_line.b *h.p.y + midperpendicular_line.c;
    if (value > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}