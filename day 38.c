#include <stdio.h>
#include <string.h>

int main() {
    int n, pq[100], size = 0, x;
    char op[10];
    scanf("%d", &n);

    while(n--) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            int i = size - 1;
            while(i >= 0 && pq[i] > x) {
                pq[i + 1] = pq[i];
                i--;
            }
            pq[i + 1] = x;
            size++;
        }

        else if(strcmp(op, "delete") == 0) {
            if(size == 0) printf("-1\n");
            else {
                printf("%d\n", pq[0]);
                for(int i = 0; i < size - 1; i++)
                    pq[i] = pq[i + 1];
                size--;
            }
        }

        else if(strcmp(op, "peek") == 0) {
            if(size == 0) printf("-1\n");
            else printf("%d\n", pq[0]);
        }
    }

    return 0;
}
