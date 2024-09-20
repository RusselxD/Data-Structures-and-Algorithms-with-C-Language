#include <stdio.h>
#include <stdlib.h>

typedef struct
{
     int *data;
     int top;
     int capacity;
} Stack;

Stack *create_stack();
void push(Stack *, int);
int pop(Stack *);
void free_memory(Stack *);
void print_error(char[]);

int main()
{
     Stack *stack = create_stack();

     return 0;
}

Stack *create_stack()
{
     Stack *new_stack = (Stack *)malloc(sizeof(Stack));
     if (new_stack == NULL)
     {
          print_error("Error: Memory allocation failed.\n");
          return NULL;
     }

     new_stack->data = (int *)malloc(10 * sizeof(int));
     if (new_stack->data == NULL)
     {
          print_error("Error: Memory allocation failed.\n");
          free(new_stack);
          return NULL;
     }

     // initial capacity
     new_stack->capacity = 10;

     new_stack->top = -1;

     return new_stack;
}

void push(Stack *stack, int data)
{
     stack->top++;

     if (stack->top >= stack->capacity)
     {
          // grow
     }

     stack->data[stack->top] = data;
}

int pop(Stack *stack)
{
     if (stack->top < 0)
     {
          print_error("Error: Stack is empty.\n");
          free_memory(stack);
          exit(0);
     }

     int top_data = stack->data[stack->top];
     stack->top--;

     // shrink if top is smaller than capacity / 3

     return top_data;
}

int peek(Stack *stack)
{
     if (stack->top < 0)
     {
          print_error("Error: Stack is empty.\n");
          free_memory(stack);
          exit(0);
     }
     return stack->data[stack->top];
}

void free_memory(Stack *stack)
{
     free(stack->data);
     free(stack);
}

void print_error(char message[])
{
     fprintf(stderr, message);
}