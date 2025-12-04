#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

// I GAVE UP. But that was close one.

int main() 
{
    
    int q;
    scanf("%d", &q);

    long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
                   41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int foundAmount[2048] = {0};
    long long foundNumbers[2048];
    int overall = 0;
    int otv[10000] = {0};
    int exp[25];
    for (int p = 0; p < 25; p++) {
        exp[p] = 0;
    }
    exp[0] = 0;
    unsigned long long lastFound = 1;
    while (lastFound < 1e18) {
        long long amount = 1;
        lastFound = 1;
        for (int i = 0; i < 24; i++) {
            if (exp[i] == 20) {
                exp[i + 1] += 1;
                exp[i] = exp[i + 1];
            }

            amount *= (1 + exp[i]);

            for (int f = 0; f < exp[i]; f++) {
                lastFound = lastFound * primes[i];
            }
        }

        for (int j = 0; j < 2048; j++) {
            if (foundAmount[j] == amount) {
                if (lastFound < foundNumbers[j]) {
                    foundNumbers[j] = lastFound;
                }
                break;
            } else if (foundAmount[j] == 0) {
                foundAmount[j] = amount;
                foundNumbers[j] = lastFound;
                overall++;
                break;
            }
        }
        exp[0] += 1;
    }
    
    

    long long l, r;
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &l, &r);
        
        for (int g = 0; g < overall; g++) {
            if ((l <= foundNumbers[g]) && (foundNumbers[g] <= r)) {
                otv[i] += 1;
            }
        }
    }

    for (int k = 0; k < q; k++) {
        printf("%d\n", otv[k]);
    }
    
    return 0;
}

// 6 - 4
// 2 3

// 12 - 6
// 2 2 3
// 2 двойки и 1 тройка
// (2 + 1) * (1 + 1) = 6

// 18 - 6
// 2 3 3
// 1 двойка и 2 тройки
// (1 + 1) * (2 + 1) = 6

// 24 - 8
// 2 2 2 3
// 3 двойки и 1 тройка
// (3 + 1) * (1 + 1) = 8

// 30 - 8
// 2 3 5
// 1 двойка, 1 тройка, 1 пятёрка
// (1 + 1) * (1 + 1) * (1 + 1)

// okay, maybe it works.