#include <stdio.h>
#include <stdlib.h>
#include "Mab.h"

int main()
{
    Mab mab;
    init_mab(&mab);
    push(&mab , "ahmniab" , "ahmed nabil") ;
    push(&mab , "kkk" , "ahmed nabil") ;
    push(&mab , "llll" , "ahmed nabil") ;
    push(&mab , "fff" , "ahmed nabil") ;
    push(&mab , "kdmvkdsn" , "ahmed nabil") ;
    printMab(&mab);
    printf("%s\n", search(&mab, "ahmniab"));


    return 0;
}
