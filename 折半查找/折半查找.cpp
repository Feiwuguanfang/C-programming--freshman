#include<stdio.h>
#include<string.h>
int main()
{
    int n, key, num[100], low, high, mid;
    scanf_s("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d,", &num[i]);
    }
    getchar();
    scanf_s("%d", &key);
    high = n - 1;
    low = 0;
    mid = (high + low) / 2;
    while (low < high)
    {
        if (key == num[mid])
        {
            printf("%d", mid + 1);
            break;
        }
        if (key < num[mid])
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        if (key > num[mid])
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        if (low == high)
        {
            printf("%d", high + 1);
        }
    }
    return 0;


}