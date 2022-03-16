#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct serie{
    int v[3];
    int max;
} serie;

typedef struct buffer{
    serie *vector;
    int size, capacity;
} buffer;

void
realloc_what_it_needs(buffer *crs)
{
    crs->capacity *= 2;
    serie *aux;
    aux = realloc(crs->vector, crs->capacity * sizeof(*(crs->vector)));
    free(crs->vector);
    crs->vector = aux;
}

int
maximum(int a, int b, int c)
{
    int d;
    if (a >= b)
        d = a;
    else
        d = b;
    if (d >= c)
        return d;
    else
        return c;
}

void
adding_the_nums(buffer *crs, int a, int b, int c)
{
    if (crs->size == crs->capacity)
        realloc_what_it_needs(crs);
    (crs->vector[crs->size]).v[0] = a;
    (crs->vector[crs->size]).v[1] = b;
    (crs->vector[crs->size]).v[2] = c;
    (crs->vector[crs->size]).max = maximum(a, b, c);
}

int
main()
{
    char command[30];
    buffer *the_special = malloc(sizeof(*the_special));
    if (!the_special) {
        fprintf(stderr, "Malloc failed\n");
        return 1;
    }
    the_special->size = 0;
    the_special->capacity = 10;
    the_special->vector = malloc(the_special->capacity * sizeof(*(the_special->vector)));
    while(1) {
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adding_the_nums(the_special, a, b, c);
            printf("The maximum is: %d\n", (the_special->vector[the_special->size]).max);
        }
        if (strcmp(command, "free") == 0) {
            free(the_special->vector);
            free(the_special);
            break;
        }
    }
    return 0;
}