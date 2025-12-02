#include <stdio.h>
#include <math.h>

int main() 
{
    long long r, b, w, h;
    scanf("%lld %lld", &r, &b);
    w = (r - 4 + sqrt(r * r - 8 * r + 16 - 16 * b)) / 4 + 2;
    h = b / (w - 2) + 2;
    
    if (w > h) {
        printf("%lld %lld", w, h);
        return 0;
    }
    printf("%lld %lld", h, w);
    return 0;
}