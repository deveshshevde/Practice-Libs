#include <stdlib.h>
#include <stdio.h>


/*
    * Intentionally includes errors to analyze compile behavior in C language.
*/
    // safety check
#define WITHERR 1 

float add(float a, float b){
    return a + b;
}

float sub(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float division(float a, float b){
    if(b == 0){
        return -1;
    }
    return a / b;
}


int main(int argc, char const *argv[])
{
    
    (void)argc;
    (void)argv;

    char operation;
    scanf("%c" , &operation);
    printf("You have choosen %c operation\n" , operation);
    float (*FnPtr)(float , float) = NULL;
    switch (operation)
    {
    case 'a':
        FnPtr = add;
        break;
    case 's':
        FnPtr = sub;
        break;
    case 'm':
        FnPtr = multiply;
        break;
    case 'd':
        FnPtr = division;
        break;
    default:
        printf("Invalid operation");
        break;
    }

    printf("Enter two numbers\n");
    float num1, num2;
    scanf("%f %f" , &num1 , &num2);
    
    #ifndef WITHERR
    if (FnPtr != NULL) 
    {
        float result = FnPtr(num1, num2);
        printf("Result = %f\n", result);
    }  
    #else
    printf("Result = %f\n",FnPtr(num1, num2) );
    #endif

    return 0;
}
