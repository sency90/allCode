#include <cstdio>
#include <cstdlib>
#include <cstring>
class stars {
public:
    char** arr;
    stars* small;
    int num;
    stars(int n) {
        num = n;
        if (n > 1)
            small = new stars(n / 3);
        arr = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++)
            arr[i] = (char*)calloc(n + 1, 1);
    }
    ~stars() {
        if (small)
            delete small;
        for (int i = 0; i < num; i++)
            free(arr[i]);
        free(arr);
    }
    char* print(int n) {
        if (num == 1) {
            return "*";
        }
        if (*arr[n])
            return arr[n];
        strcpy(arr[n], small->print(n % (num / 3)));
        if (n / (num / 3) == 1) {
            char* str = new char[num / 3 + 1];
            memset(str, 32, num / 3);
            str[num / 3] = 0;
            strcat(arr[n], str);
            delete[] str;
        }
        else
            strcat(arr[n], small->print(n % (num / 3)));
        strcat(arr[n], small->print(n % (num / 3)));
        return arr[n];
    }
};
int main() {
    int n;
    scanf("%d", &n);
    stars s(n);
    for (int i = 0; i < n; i++)
        puts(s.print(i));
}
