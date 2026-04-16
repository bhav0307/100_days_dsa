#include <stdio.h>

int main()
{
    int n, i, sum = 0, maxLen = 0;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum[n];
    int index[n];
    int size = 0;

    for(i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
            maxLen = i + 1;

        int found = 0, j;

        for(j = 0; j < size; j++)
        {
            if(prefixSum[j] == sum)
            {
                int len = i - index[j];
                if(len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            prefixSum[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
