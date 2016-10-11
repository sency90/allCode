#include <stdio.h>
#include <algorithm>
#include <functional>

int arr[1010];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + N, std::greater<int>());
    for (int i = 0; i <= N; i++) {
        int count = 0, count2 = 0;
        int check = 0;
        for (int j = 0; j < N; j++) {

            if (count >= i && i < arr[j]) {
                check = 1;
                break;
            }
            if (count != i && i <= arr[j]) count++;
        }
        if (count == i && !check) {
            printf("%d\n", i);
            break;
        }
    }
}
