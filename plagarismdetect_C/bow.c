#include <stdio.h>
#include <string.h>
#include <math.h>
#include "bagofwords.h"

struct dictionary dict1[100],dict2[100];


void main(){
    char text1[100];
    char text2[100];

    scanf("%[^\n]\n",text1);
    scanf("%[^\n]",text2);

    printf("%g",bow(text1,text2));
}
