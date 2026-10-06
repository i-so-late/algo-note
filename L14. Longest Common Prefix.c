#include<stdlib.h>
#include<string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize<1) return "";
    char *prefix=(char*)malloc(sizeof(char)*(strlen(strs[0])+1));
    int preSize=0;
    int i,j;
    char temp;
    strcpy(prefix,strs[0]);
        for(i=0;strs[0][i]!='\0';i++){
            temp=strs[0][i];
            for(j=1;j<strsSize;j++){
                if(strs[j][i]==temp) continue;
                else break;
            }
            if(j==strsSize){
                continue;           
                //preSize++;
            }
            else break;
        }
    prefix[i]='\0';
     return prefix;
}