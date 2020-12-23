/**
* @mainpage
* # Загальне завдання
* 1. Розробити функцію.
*
* # Опис програми
* 2. Функціональне призначення
*  Програма призначена для знаходження НСД двох чисел 
*  Та знаходження середнього арифметичного элементів масиву.
* 3. Опис логічної структури
*    1) Щоб знайти НСД використовуємо метод Евкліда.
*    2) Спочатку заповнюємо масив фіксованого розміру цілими числами. Далі
*    Знаходимо суму усіх елементів масиву та знаходимо середнє значення.
*
* @author .
* @date 23-dec-2020
*/

/**
* @file main.c
* Програма призначена для знаходження НСД двох чисел та знаходження середнього арифметичного элементів масиву. 
* @author 
* @return Змінну з кількістю пар таких чисел.
* @version 0.1 
* date 23.12.2020 
*
*/
/**
* @mainpage
* # Загальне завдання
* 1. Розробити функцію.
*
* # Опис програми
* 2. Функціональне призначення
*  Програма призначена для знаходження НСД двох чисел 
*  Та знаходження середнього арифметичного элементів масиву.
* 3. Опис логічної структури
*    1) Щоб знайти НСД використовуємо метод Евкліда.
*    2) Спочатку заповнюємо масив фіксованого розміру цілими числами. Далі
*    Знаходимо суму усіх елементів масиву та знаходимо середнє значення.
*
* @author .
* @date 23-dec-2020
*/

/**
* @file main.c
* Програма призначена для знаходження НСД двох чисел та знаходження середнього арифметичного элементів масиву. 
* @author 
* @return Змінну з кількістю пар таких чисел.
* @version 0.1 
* date 23.12.2020 
*
*/
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#define length_of_main_array 5
int function_of_filling_array(int, float*);
void sort(float* ptr_One, float* ptr_Two);

int main() {
    srand(time(NULL));
    float* main_array = (float*)malloc(length_of_main_array * sizeof(float));
    *main_array = function_of_filling_array(length_of_main_array, main_array);

    printf("\n");

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
}

void sort(float* ptr_One, float* ptr_Two)
{
    float* ptr_Tmp = ptr_One;
    while (ptr_One != ptr_Two)
    {
        if (*ptr_One < *ptr_Two)
        {
            float tmp = *ptr_One;
            *ptr_One = *ptr_Two;
            *ptr_Two = tmp;
        }
        ++ptr_One;
    }
    if (ptr_Tmp < ptr_Two)
    {
        sort(ptr_Tmp, ptr_Two - 1);
    }
}


int function_of_filling_array(int length, float* mainArray) 
{
    for (int i = 0; i < length; i++) {
            *(mainArray + i) = (rand() % 10 + -3)/1.2 ;
    }
    return 0;
}