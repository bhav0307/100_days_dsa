/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/

#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];

    int i,j;
    printf("Enter elements of array\n");
    for (i=0;i<n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }

   int min=arr[0],max=arr[0];
   for(i=1;i<n;i++)
   {
    if(arr[i]>max)
    {
        max=arr[i];
    }
    else if(arr[i]<min)
    {
        min=arr[i];
    }
   }
   printf("Maximum element is%d\n",max);
   printf("Minimum element is%d\n",min);

}
