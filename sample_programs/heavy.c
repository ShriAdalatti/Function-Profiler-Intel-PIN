#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

double compute(int n) {
    double s = 0;
    for (int i = 1; i <= n; i++) s += sqrt((double)i);
    return s;
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1]) { int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
}

void run_all() {
    long long f = 0;
    for (int i = 0; i < 100000; i++) f += factorial(20);
    printf("factorial sum: %lld\n", f);

    double s = 0;
    for (int i = 0; i < 200; i++) s += compute(100000);
    printf("compute sum: %.2f\n", s);

    int arr[2000];
    for (int i = 0; i < 2000; i++) arr[i] = 2000 - i;
    bubble_sort(arr, 2000);
    printf("sort done\n");
}

int main() {
    run_all();
    return 0;
}
