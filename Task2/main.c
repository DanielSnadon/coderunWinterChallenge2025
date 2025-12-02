#include <stdio.h>
#include <stdlib.h>

int snadonize(int howDeep, int *constData, int size, int target) {
    if (howDeep == 0) {
        int best = target;
        int otv = 0;
        for (int k = 0; k < size; k++) {
            int t = target - constData[k];
            if (abs(t) < abs(best)) {
                best = t;
                otv = constData[k];
            }
        }
        return otv;
    }

    int *data = malloc(sizeof(int) * size);
    for (int j = 0; j < size; j++) {
        data[j] = constData[j];
    }

    int closest = 0;
    for (int i = 0; i < size; i++) {
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        int result = data[0] + snadonize(howDeep - 1, data + 1, size - 1, target - data[0]);
        if (result == target) {
            free(data);
            return result;
        }
        if ((abs(target - result) < abs(target - closest)) ||
            ((abs(target - result) == abs(target - closest)) && (result > closest))) {
            closest = result;
        }
    }
    free(data);
    return closest;
}

int main() 
{
    int numbers[10] = {0};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    int nearest = 1000;
    int otv = 0;
    for (int i = 0; i < 10; i++) {
        int curr = snadonize(i, numbers, 10, 100);
        if ((abs(100 - curr) < nearest) || (((abs(100 - curr) == nearest) && (curr > otv)))) {
            otv = curr;
            nearest = abs(100 - curr);
        }
    }

    printf("%d", otv);
    return 0;
}