#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
     int *data;
     int top;
     int capacity;
} Stack;

Stack *create_stack();
void push(Stack *, int);
int pop(Stack *);
int peek(Stack *);
bool is_empty(Stack *);
bool grow(Stack *);
void shrink(Stack *);
void print_stack(Stack *);
void free_stack(Stack *);
void print_error(char[]);

int main()
{
     Stack *stack = create_stack();

     printf("Pushed 10 elements: 10, 20, ..., 100\n");
     for (int i = 10; i <= 100; i += 10)
     {
          push(stack, i);
     }

     printf("Current stack content: \n\t");
     print_stack(stack);

     printf("Top element (peeked): %d\n\n", peek(stack));

     printf("Popped: %d\n", pop(stack));
     printf("Popped: %d\n", pop(stack));
     printf("Popped: %d\n", pop(stack));
     printf("Popped: %d\n", pop(stack));
     printf("Popped: %d\n\n", pop(stack));

     printf("Current stack content: \n\t");
     print_stack(stack);

     printf("Top element (peeked): %d\n", peek(stack));

     free_stack(stack);

     printf("\nPress ENTER to continue... ");
     getchar();
     return 0;
}

Stack *create_stack()
{
     Stack *new_stack = (Stack *)malloc(sizeof(Stack));
     new_stack->data = (int *)malloc(10 * sizeof(int));
     new_stack->capacity = 10;
     new_stack->top = -1;
     return new_stack;
}

void push(Stack *stack, int data)
{
     bool can_push_element = true;

     // grow the stack capacity to accomodate additional elements
     if (stack->top == stack->capacity - 1)
     {
          can_push_element = grow(stack);
     }

     if (can_push_element)
     {
          stack->top++;
          stack->data[stack->top] = data;
     }
}

int pop(Stack *stack)
{
     if (is_empty(stack))
     {
          print_error("Error: Stack is empty.\n");
          return -1; // sentinel value
     }

     int top_data = stack->data[stack->top];
     stack->top--;

     // shrink the stack if there are less than or equal thirds-of-the-capacity elements left
     bool few_elements_left = stack->top <= (stack->capacity / 3);

     if (stack->capacity > 10 && few_elements_left)
          shrink(stack);

     return top_data;
}

int peek(Stack *stack)
{
     if (is_empty(stack))
     {
          print_error("Error: Stack is empty.\n");
          return -1; // sentinel value
     }
     return stack->data[stack->top];
}

bool is_empty(Stack *stack)
{
     return stack->top < 0;
}

bool grow(Stack *stack)
{
     int new_capacity = stack->capacity * 2;

     int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int));
     if (new_data == NULL)
     {
          print_error("Error: Memory allocation failed during stack growth.\n");
          return false;
     }
     else
     {
          stack->capacity = new_capacity;
          stack->data = new_data;
          return true;
     }
}

void shrink(Stack *stack)
{
     int new_capacity = stack->capacity / 2;

     int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int));
     if (new_data == NULL)
     {
          print_error("Error: Failed to reallocate memory to decrease capacity.\n");
          return;
     }

     stack->capacity = new_capacity;
     stack->data = new_data;
}

void print_stack(Stack *stack)
{
     if (stack->top < 0)
     {
          printf("[]\n");
          return;
     }

     printf("[");
     for (int i = 0; i < stack->top; i++)
     {
          printf("%d, ", stack->data[i]);
     }
     printf("%d]\n", stack->data[stack->top]);
}

void free_stack(Stack *stack)
{
     free(stack->data);
     free(stack);
}

void print_error(char message[])
{
     fprintf(stderr, message);
}