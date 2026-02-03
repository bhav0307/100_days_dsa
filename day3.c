/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/

#include <stdio.h>

int main() {
    int n, k;
    int c=0,d=0;
    int pos = 0;


    printf("Enter size of the array");
    scanf("%d", &n);

    printf("Enter elements of array");
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
   
    printf("Enter key to be found");
    scanf("%d", &k);


    for(int i=0;i<n;i++)
    {
        ++c;
        if(arr[i]==k)
        {
            pos=i;
            d=1;
            break;
        }
    }
   if(d==1)
   {
    printf("position of the key is %d \n",pos);
    printf("number of comparision : %d \n",c);}

    else{
        printf("Key not found");
    }
    

    return 0;
}
