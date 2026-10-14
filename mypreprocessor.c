#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"operation.h"
char str[100];
int len;
int main(int argc, char *argv[])
{
    FILE *src = NULL;
    FILE *dest = NULL;

    if(argc != 2)
    {
        printf("error in input\n");
        exit(0);
    }

    src = fopen(argv[1], "r");
    if(src==NULL)
    {
	    printf("error in src\n");
	    exit(0);
    }
    strcpy(str,argv[1]);
    len=strlen(str)-1;
    memset(str+len,'i',1);
    dest = fopen(str, "w");
    comment_remove(src,dest);
    fclose(dest);
    fclose(src);
    marcohandling(str);
    fileinclusion(str);

}
