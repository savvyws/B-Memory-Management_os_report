#include <stdio.h>
#include <stdlib.h>

// Global variables
int global_var1 = 100;
int global_var2 = 200;
int global_var3 = 300;

// Recursive function
int recurr_1(int level)
{
    if (level == 20)
    {
        return level;
    }
    printf("Address of local var in level %d: %p\n", level, &level);
    return recurr_1(level + 1); // return the value to propagate through recursion
}

int main()
{
    printf("Address of global variable: %p ; its value: %d\n", &global_var1, global_var1);
    printf("Address of global variable: %p ; its value: %d\n", &global_var2, global_var2);
    printf("Address of global variable: %p ; its value: %d\n", &global_var3, global_var3);
    printf("\n");

    int *malloc_var_1 = (int *)malloc(sizeof(int));
    int *malloc_var_2 = (int *)malloc(sizeof(int));
    int *malloc_var_3 = (int *)malloc(sizeof(int));

    // Check for successful memory allocation
    if (malloc_var_1 == NULL || malloc_var_2 == NULL || malloc_var_3 == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(malloc_var_1);
        free(malloc_var_2);
        free(malloc_var_3);
        return 1;
    }

    *malloc_var_1 = 500;
    *malloc_var_2 = 600;
    *malloc_var_3 = 700;
    printf("Address of malloc_variable: %p ; its value: %d\n", malloc_var_1, *malloc_var_1);
    printf("Address of malloc_variable: %p ; its value: %d\n", malloc_var_2, *malloc_var_2);
    printf("Address of malloc_variable: %p ; its value: %d\n", malloc_var_3, *malloc_var_3);
    printf("\n");

    recurr_1(1);
    printf("\n");

    printf("Address of global variable: %p ; its value: %d\n", &global_var1, global_var1);
    printf("Address of global variable: %p ; its value: %d\n", &global_var2, global_var2);
    printf("Address of global variable: %p ; its value: %d\n", &global_var3, global_var3);

    // Free allocated memory
    free(malloc_var_1);
    free(malloc_var_2);
    free(malloc_var_3);

    return 0;
}
