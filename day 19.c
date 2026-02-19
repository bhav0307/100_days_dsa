/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int min_sum = abs(a[0] + a[1]);
    int x = a[0], y = a[1];

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if(abs(sum) < min_sum)
            {
                min_sum = abs(sum);
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}
