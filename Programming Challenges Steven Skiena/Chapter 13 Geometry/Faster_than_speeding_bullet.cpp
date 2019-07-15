#include <iostream>

#define eps 1e-5

#include <cmath>
# define M_PI           3.14159265358979323846
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

float distance_point_to_point(point &p1, point &p2);
float distance_point_to_line(point &p, line &l);
float extra_length(circle &c, line &l);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int NMAXS = 100;
    point s,t;
    cin>>s.x >>s.y>>t.x>>t.y;
    
    int n_circles;
    cin>>n_circles;
    line l;
    l.a = t.y - s.y;
    l.b = s.x - t.x;
    l.c = t.x * s.y - t.y*s.x;
    circle c[NMAXS];
    
    float distance = distance_point_to_point(s, t);
    for(int i = 0; i <n_circles; i++)
    {   
        circle c;
        cin >> c.center.x >> c.center.y >> c.radius;
        float extra_distance  = extra_length(c, l);
        distance += extra_distance;
    }
    cout << distance << endl;
    return 0;
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

float extra_length(circle &c, line &l)
{
    float distance_center_to_line = distance_point_to_line(c.center, l);
    if (distance_center_to_line >= c.radius)
    {
        return 0;
    }
    else if (distance_center_to_line > eps && distance_center_to_line < c.radius)
    {
        float theta = acos(distance_center_to_line / c.radius);
        float arc_length = 2 * theta * c.radius;
        float canh_goc_vuong_mu_2 = c.radius * c.radius - distance_center_to_line * distance_center_to_line; 
        float missing_line_length = 2 * sqrt(canh_goc_vuong_mu_2);
        
        float extra_path = arc_length - missing_line_length;
        return extra_path;
    }
    else
    {
        float extra_path = 2 * M_PI * c.radius - 2* c.radius;
        return extra_path;
    }
}