#include <stdio.h>

int binary(int[], int len, int trgt);

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int len = sizeof(arr) / sizeof(arr[0]);
     int trgt = 8;

     int index = binary(arr, len, trgt);

     if (index == -1)
     {
          printf("Element not found.\n");
     }
     else
     {
          printf("Element (%d) found at index: %d\n", trgt, index);
     }

     return 0;
}

int binary(int arr[], int len, int trgt)
{
     int left = 0, right = len - 1;
     int mid;

     while (left <= right)
     {
          // binary search formula
          mid = left + (right - left) / 2;

          if (trgt < arr[mid])
          {
               // disregard right half
               right = mid - 1;
          }
          else if (trgt > arr[mid])
          {
               // disregard left half
               left = mid + 1;
          }
          else
          { // element found

               return mid;
          }
     }

     return -1;
}