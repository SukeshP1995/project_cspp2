#include<string.h>
#include <stdio.h>

void linewc(char text[]){
    char word[100][100];
    int k,p;

    int len = 0;
    int i = 0,j = 0,c = 0,flag;

    p = strlen(text);

    for(k=0;k<p;k++){
        if(text[k]!=' '){

            if(text[k]>=65 && text[k]<=90){
                text[k] = text[k]+32;
            }

            word[i][j]=text[k];
            j++;

        }
        else{
            word[i][j]='\0';
            i++;
            j=0;

            c += 1;
        }
    }
    word[i][j]='\0';
    c+=1;
    strcpy(text,"");
    for(k=0;k<c;k++){
        flag = 1;
        for (i = 0; i<strlen(word[k]);i++){

            if(word[k][i]>122 || word[k][i]<97){

                flag = 0;
                break;
            }
        }
        if(flag){
            strcat(text,word[k]);
            strcat(text," ");
        }
    }
}



void main(){
    char text[100];
    scanf("%[^\n]",text);
    linewc(text);
    printf("%s",text);

}
