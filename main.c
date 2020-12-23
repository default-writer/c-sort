#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define length_of_main_array 50
int function_of_filling_array(int, float*);

void sort(float* ptr_One, float* ptr_Two);
void fast_sort(float* ptr_One, float* ptr_Two);
void swap(float* ptr_One, float* ptr_Two);

int main() {
    srand(time(NULL));
    float* main_array = (float*)malloc(length_of_main_array * sizeof(float));
    float* main_array2 = (float*)malloc(length_of_main_array * sizeof(float));
    *main_array = function_of_filling_array(length_of_main_array, main_array);
    
    for (int i = 0; i < length_of_main_array; i++) {
        main_array2[i] = main_array[i];
    }

    for (int i = 0; i < length_of_main_array; i++) {
        printf("\n%4f", main_array[i]);
    }

    printf("\n");
    printf("\n");

    float* ptr_One = main_array;
    float* ptr_Two = (main_array + length_of_main_array - 1);
    float* result_array = (float*)malloc(length_of_main_array * sizeof(float));

    /*
     |++|++|++|++|++|++|++|
      |   |             |
     ptr_One           ptr_Two
          |
         ptr_One + 1
    */

    /* Задача: положительные числа влево, отрицательные вправо и по середины нули */
    float element = 0;
    
    int n = length_of_main_array - 1;
    int i = 0;

    sort(ptr_One, ptr_Two); 

    for (int i = 0; i < length_of_main_array; i++) {
        printf("\n%4f", main_array[i]);
    }

    printf("\n");
    printf("\n");

    fast_sort(&main_array2[0], &main_array2[length_of_main_array - 1]); 

    for (int i = 0; i < length_of_main_array; i++) {
        printf("\n%4f", main_array2[i]);
    }

    printf("\n");
}

void sort(float* ptr_One, float* ptr_Two)
{
    while (1)
    {
        float* ptr_Tmp = ptr_One;
        while (ptr_One < ptr_Two)
        {
            if (*ptr_One < *ptr_Two)
                swap(ptr_One, ptr_Two);
            ++ptr_One;
        }
        if (ptr_Tmp < ptr_Two) {
            --ptr_Two;
            ptr_One = ptr_Tmp;
            continue;
        }
        break;
    }
}

void fast_sort(float* ptr_One, float* ptr_Two)
{
    while (1)
    {
        float* ptr_Tmp = ptr_One;
        while (ptr_One < ptr_Two)
        {
            // code for speed run (task actually is loosed constraints of strict sort order)
            if (*ptr_One > 0)
            {
                ++ptr_One;
                continue;
            }
            if (*ptr_Two < 0)
            {
                --ptr_Two;
                continue;
            }
            if (*ptr_One < *ptr_Two)
                swap(ptr_One, ptr_Two);
            ++ptr_One;
        }
        if (ptr_Tmp < ptr_Two) {
            --ptr_Two;
            ptr_One = ptr_Tmp;
            continue;
        }
        break;
    }
}

void swap(float* ptr_One, float* ptr_Two) {
    float tmp = *ptr_One;
    *ptr_One = *ptr_Two;
    *ptr_Two = tmp;
    printf("[debug] %4f <--> %4f\n", *ptr_One, *ptr_Two);
}

int function_of_filling_array(int length, float* mainArray) 
{
    for (int i = 0; i < length; i++) {
            *(mainArray + i) = (rand() % 10 + -3)/1.2 ;
    }
    return 0;
}