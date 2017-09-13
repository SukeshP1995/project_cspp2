
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "lcs.h"
#include "bagofwords.h"
# include <stdlib.h>

void filereader(char f[], char r[]){
    long lSize;
    char *text;

    FILE *fp = fopen(f,"rb");

    if(!fp){
        printf("%d",1233);
        perror(f);
        exit(1);
    }

    fseek(fp,0L,SEEK_END);
    lSize=ftell(fp);
    rewind(fp);

    text =  calloc(1,lSize+1);
    if(!text){
        fclose(fp);
        fputs("memory alloc fails",stderr);
        exit(1);
    }

    if(1!=fread(text,lSize,1,fp)){
        fclose(fp);
        free(text);
        fputs("entire read fails",stderr);
        exit(1);
    }

    strcpy(r,text);
    fclose(fp);

}

int main()
{
    char files[100][100],f[100];
    char text1[100],text2[100];
    int c = 0;
    float per=0.0;
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(subcheck(dir->d_name,".txt")){

                strcpy(files[c],dir->d_name);

                c++;
            }
        }
        closedir(d);
    }

    for(int i=0;i<c;i++){
        filereader(files[i],text1);
        for(int j=0;j<c;j++){
            filereader(files[j],text2);
            per = bow(text1,text2);
            printf("%f\t",per);
        }
        printf("\n");
    }
    FILE *fp = fopen("baglog.txt","w");
    fprintf(fp,"\t\t");
    for(int i=0;i<c;i++)
        fprintf(fp,"%s\t",files[i]);
    fprintf(fp,"\n");
    for(int i=0;i<c;i++){
        fprintf(fp,"%s\t",files[i]);
        filereader(files[i],text1);
        for(int j=0;j<c;j++){
            filereader(files[j],text2);
            per = bow(text1,text2);
            fprintf(fp,"%.2f\t\t",per);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\n");

    for(int i=0;i<c;i++){
        filereader(files[i],text1);
        for(int j=0;j<c;j++){
            filereader(files[j],text2);
            per = stringmatch(text1,text2);
            printf("%f\t",per);
        }
        printf("\n");
    }
    fp = fopen("lcslog.txt","w");
    fprintf(fp,"\t\t");
    for(int i=0;i<c;i++)
        fprintf(fp,"%s\t",files[i]);
    fprintf(fp,"\n");
    for(int i=0;i<c;i++){
        fprintf(fp,"%s\t",files[i]);
        filereader(files[i],text1);
        for(int j=0;j<c;j++){
            filereader(files[j],text2);
            per = stringmatch(text1,text2);
            fprintf(fp,"%.2f\t\t",per);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\n");
    return(0);
}
