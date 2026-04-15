#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    char names[1000][100];
    int i;

    for(i = 0; i < n; i++)
        scanf("%s", names[i]);

    qsort(names, n, sizeof(names[0]), compare);

    char winner[100];
    int maxVotes = 1, count = 1;

    strcpy(winner, names[0]);

    for(i = 1; i < n; i++)
    {
        if(strcmp(names[i], names[i-1]) == 0)
            count++;
        else
        {
            if(count > maxVotes)
            {
                maxVotes = count;
                strcpy(winner, names[i-1]);
            }
            count = 1;
        }
    }

    if(count > maxVotes)
    {
        maxVotes = count;
        strcpy(winner, names[n-1]);
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
