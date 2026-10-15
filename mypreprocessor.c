#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"operation.h"
char op_file[100];
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
    strcpy(op_file,argv[1]);
    len=strlen(op_file)-1;
    memset(op_file+len,'i',1);
    dest = fopen(op_file, "w");
    comment_remove(src,dest);
    fclose(dest);
    fclose(src);
    macro_handling(op_file);
    insert_header(op_file);

}
