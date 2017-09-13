#include<string.h>
#define MAX 100000
void append(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void linewc(char text[]){
    char word[MAX][100];
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

int subcheck(char str[MAX],char substr[MAX]){
    int len1 = 0, len2 = 0, i, j, flag;


    len1 = strlen(str);
    len2 = strlen(substr);
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = i; j < i + len2; j++)
        {
            flag = 1;
            if (str[j] != substr[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        return 1;
    return 0;
}

float stringmatch(char text1[],char text2 []){

    char maxss[100]="";
    int i=0,j=0;
    char substr[100];
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    strcpy(substr,"");
    append(substr,text1[0]);
    while(i<len1 && j<len2){
        if (subcheck(text2,substr)){
            j++;
            if(strlen(maxss)<strlen(substr))
                strcpy(maxss,substr);
            append(substr,text1[i+j]);
        }
        else{
            i += 1;
            j = 0;
            strcpy(substr,"");
            append(substr,text1[i]);
        }
    }
    float per;
    per = strlen(maxss)*200/(len1+len2);
    return per;
}

