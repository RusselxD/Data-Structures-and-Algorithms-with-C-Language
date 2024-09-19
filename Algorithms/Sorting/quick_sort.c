#include <stdio.h>

void print(int[], int);
void qcksort(int[], int start, int end);
int partition(int[], int start, int end);
void swap(int[], int i, int j);

int main()
{
     // for testing an empty array
     // int *arr = NULL;
     // int len = 0;

     int arr[] = {5, 3, 8, 6, 2, 1, 9, 4, 7};
     int len = sizeof(arr) / sizeof(arr[0]);

     printf("Original array:\n\t");
     print(arr, len);

     qcksort(arr, 0, len - 1);

     printf("Sorted array:\n\t");
     print(arr, len);

     return 0;
}

void qcksort(int arr[], int start, int end)
{
     if (end <= start)
          return;

     int partition_index = partition(arr, start, end);

     // recursive calls
     qcksort(arr, start, partition_index - 1);
     qcksort(arr, partition_index + 1, end);
}

int partition(int arr[], int start, int end)
{
     int pivot = arr[end];

     int i = start - 1;

     for (int j = start; j < end; j++)
     {
          if (arr[j] < pivot)
          {
               i++;
               swap(arr, i, j);
          }
     }

     i++;
     swap(arr, i, end);

     return i;
}

void swap(int arr[], int i, int j)
{
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
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