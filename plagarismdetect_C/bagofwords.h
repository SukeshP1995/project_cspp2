#include<string.h>
#include<math.h>
struct dictionary{
    char word[100];
    int count;
}dict[1000], dict1[1000], dict2[1000];

int dicreator(char text[], struct dictionary dict[] ){
    char word[1000][100];
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
    int c1=0;

    for(k=0;k<c;k++){
        flag = 1;
        for (i = 0; i<strlen(word[k]);i++){

            if(word[k][i]>122 || word[k][i]<97){

                flag = 0;
                break;
            }
        }
        if(flag){
            strcpy(word[c1],word[k]);
            c1 +=1;
        }
    }
    c = c1;
    for(k=0;k<c;k++){
        flag = 1;
        for(i = 0;i < len;i++){
            if(strcmp(dict[i].word,word[k])==0){

                dict[i].count += 1;
                flag = 0;
                break;
            }
        }
        if(flag){
            strcpy(dict[i].word,word[k]);

            dict[i].count = 1;
            len += 1;
        }
    }

    return len;
}

double bow(char text1[],char text2[]){

    int len1,len2;
    len1 = dicreator(text1,dict1);
    len2 = dicreator(text2,dict2);


    double dps = 0,ss1 = 0,ss2 = 0,cost;
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            if(strcmp(dict1[i].word,dict2[j].word)==0){
                dps += (dict1[i].count)*(dict2[j].count);
            }
        }
    }

    for(int i=0; i<len1; i++)
        ss1 += (dict1[i].count)*(dict1[i].count);

    for(int i=0; i<len2; i++)
        ss2 += (dict2[i].count)*(dict2[i].count);
    ss1 = sqrt(ss1);
    ss2 = sqrt(ss2);
    cost = dps*100/(ss1*ss2);

    return cost;
}
