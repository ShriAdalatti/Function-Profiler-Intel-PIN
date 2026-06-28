#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 200

// Recursive factorial
long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

// Fibonacci recursion
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// Swap helper
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Bubble sort
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Linear search
int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Matrix multiplication
void matrix_multiply(int n)
{
    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = i + j;
            b[i][j] = i - j;
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Matrix Result: %d\n", c[0][0]);
}

// Floating point compute
double compute(int n)
{
    double s = 0;

    for (int i = 1; i <= n; i++)
    {
        s += sqrt((double)i);
    }

    return s;
}

// Main workload
void run_all()
{
    int arr[1000];

    for (int i = 0; i < 1000; i++)
    {
        arr[i] = 1000 - i;
    }

    bubble_sort(arr, 1000);

    int pos = linear_search(arr, 1000, 500);

    long long fact = factorial(15);

    int f = fib(20);

     matrix_multiply(150);

    double c = compute(5000000);

    printf("Position = %d\n", pos);
    printf("Factorial = %lld\n", fact);
    printf("Fib = %d\n", f);
    printf("Compute = %f\n", c);

}

int main()
{
    run_all();
    return 0;
}
