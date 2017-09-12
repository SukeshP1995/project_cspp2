#include<string.h>
#include <stdio.h>
#include "lcs.h"

void main(){
    char text1[100],text2[100];
    scanf("%[^\n]\n",text1);
    scanf("%[^\n]",text2);
    float r = stringmatch(text1,text2);
    printf("%f",r);
}
