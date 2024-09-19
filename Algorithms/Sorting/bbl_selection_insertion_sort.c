#include <stdio.h>

void print(int[], int);
void bblsort(int[], int);
void slctsort(int[], int);
void insrtsort(int[], int);

int main()
{
     // for testing an empty array
     // int *arr = NULL;
     // int len = 0;

     int arr[] = {5, 3, 8, 6, 2, 1, 9, 4, 7};
     int len = sizeof(arr) / sizeof(arr[0]);

     printf("Original array:\n\t");
     print(arr, len);

     bblsort(arr, len);
     // slctsort(arr, len);
     // insrtsort(arr, len);

     printf("Sorted array:\n\t");
     print(arr, len);

     return 0;
}

void bblsort(int arr[], int len)
{
     if (arr == NULL || len <= 0)
          return;

     int lastIndex = len - 1;
     int swapped = 0;

     // entire array looping
     do
     {
          swapped = 0;

          // individual looping
          for (int i = 0; i < lastIndex; i++)
          {
               if (arr[i] > arr[i + 1])
               {
                    swapped = 1;

                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
               }
          }

          lastIndex--;

     } while (swapped);
}

void slctsort(int arr[], int len)
{
     if (arr == NULL || len <= 0)
          return;

     for (int i = 0; i < len; i++)
     {
          int min = i;
          for (int j = i + 1; j < len; j++)
          { // traversing the array from the current position to find the smallest element
               if (arr[j] < arr[min])
                    min = j;
          }

          if (min != i)
          { // swap the smallest and current element
               int temp = arr[i];
               arr[i] = arr[min];
               arr[min] = temp;
          }
     }
}

void insrtsort(int arr[], int len)
{
     if (arr == NULL || len <= 1)
          return;

     for (int i = 1; i < len; i++)
     {
          int temp = arr[i];
          int j = i - 1;
          while (j >= 0 && arr[j] > temp)
          { // moving elements greater than 'temp' one place to their right
               arr[j + 1] = arr[j];
               j--;
          }

          // inserting 'temp' into its proper position
          arr[j + 1] = temp;
     }
}

void print(int arr[], int len)
{
     if (arr == NULL || len <= 0)
     {
          printf("[]\n");
          return;
     }

     printf("[");
     for (int i = 0; i < len - 1; i++)
     {
          printf("%d, ", arr[i]);
     }
     printf("%d]\n", arr[len - 1]);

     // Output: [5, 3, 8, 6, 2, 1, 9, 4, 7]
}