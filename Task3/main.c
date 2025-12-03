#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparator(const void* a, const void* b)
{
    long s = *((long*)a);
    long d = *((long*)b);
    if (s > d) return -1;
    if (s < d) return 1;
    return 0;
}

int main() 
{
    int m, n, plank = 0;
    scanf("%d %d", &m, &n);

    long* groups;
    groups = malloc(sizeof(long) * n);
    for (int i = 0; i < n; i++) {
        scanf("%llu", &groups[i]);
        if (groups[i] > plank) {
            plank = groups[i];
        }
    }

    qsort(groups, n, sizeof(long), comparator);

    while (m > 0 && plank != 0) {
        for (int i = 0; i < n; i++) {
            if (m == 0) {
                break;
            }
            if (groups[i] == plank) {
                groups[i]--;
                m--;
            } else {
                break;
            }
        }

        plank--;
    }

    unsigned long long otv = 0;
    for (int i = 0; i < n; i++) {
        unsigned long long temp = groups[i] * groups[i];
        temp = temp % 1000000007ULL;
        otv += temp;
        otv = otv % 1000000007ULL;
    }

    printf("%llu", otv % 1000000007ULL);
    
    free(groups);
    return 0;
}