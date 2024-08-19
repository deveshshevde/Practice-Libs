
#include "../Sort&Search/qsort.h"
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    char *array[3] = {"def", "abc", "ghi"};


    /*
        Unsorted 
    */
    for(unsigned long i = 0; i <ARRAY_LENGTH(array) ; i++){
        printf("%s\n", array[i]);
    }
    puts("\n");

    qsort(array, ARRAY_LENGTH(array), sizeof(char*), compare_string);

    /*
        sorted 
    */
    for(unsigned long i = 0; i <ARRAY_LENGTH(array) ; i++){
        printf("%s\n", array[i]);
    }

    return 0;
}
