/******************************************************************************

Given a set of points Pi , 1 ≤ i ≤ N (≥ 2) on the x-axis, find Pi and P
j such that |Pi − P j | is minimum. e.g. P1 | P2 | P3 | P4 | P5 | P6
{P4 , P6} is the closest pair.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100000

struct point {
    double x;
    double y;
};

int cmp_x(const void *a, const void *b)
{
    const struct point *p1 = a;
    const struct point *p2 = b;
    if (p1->x < p2->x) {
        return -1;
    } else if (p1->x > p2->x) {
        return 1;
    } else {
        return 0;
    }
}

int cmp_y(const void *a, const void *b)
{
    const struct point *p1 = a;
    const struct point *p2 = b;
    if (p1->y < p2->y) {
        return -1;
    } else if (p1->y > p2->y) {
        return 1;
    } else {
        return 0;
    }
}

double distance(const struct point *p1, const struct point *p2)
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

double closest_pair(struct point *points, int n)
{
    if (n <= 1) {
        return INFINITY;
    }
    int m = n / 2;
    double xm = points[m].x;
    double d = fmin(closest_pair(points, m), closest_pair(points + m, n - m));
    qsort(points, n, sizeof(struct point), cmp_y);
    struct point strip[MAX_POINTS];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(points[i].x - xm) < d) {
            for (int k = j-1; k >= 0 && points[i].y - strip[k].y < d; k--) {
                d = fmin(d, distance(&points[i], &strip[k]));
            }
            strip[j++] = points[i];
        }
    }
    return d;
}

int main()
{
    int n;
    struct point points[MAX_POINTS];
    printf("Enter the number of points: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter point %d (x y): ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    qsort(points, n, sizeof(struct point), cmp_x);
    double d = closest_pair(points, n);
    printf("The closest pair of points is %f\n", d);
   
}

