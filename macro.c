#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int line_cnt=0;
int macro_cnt=0;

int check(char*p,char*line,int nlen);
typedef struct define
{
        char name[30];
        char val[20];
}define;
void macro_handling(char*filename)
{
        define macro[100];
        FILE*src=NULL;
        char line_buffer[100];
        int i,j=0,nlen,vlen,k;
        char mname[10],mval[10];
        char(*line)[100]=NULL;
        src=fopen(filename,"r");
        if(src==NULL)
        {
                printf("error in marco\n");
                exit(0);
        }
        while(fgets(line_buffer,100,src)!=NULL)
        {
                line=realloc(line,(line_cnt+1)*sizeof(*line));
                strcpy(line[line_cnt],line_buffer);
                line_cnt++;
        }
        fclose(src);
        for(i=0;i<line_cnt;i++)
        {
                if(strstr(line[i],"#define")!=NULL)
                {
                        printf("found \n");
                j=0;
                k=0;
                while((line[i][j]!=' ')&&(line[i][j]!='\0'))
                {
                        j++;
                }
                j++;
                while((line[i][j]!=' ')&&(line[i][j]!='\0'))
                {
                        mname[k]=line[i][j];
                        j++;
                        k++;
                }
                mname[k]='\0';
                k=0;
                while(line[i][j]==' ')
                {
                j++;
                }
                while((line[i][j]!='\n')&&(line[i][j]!='\0'))
                {
                        mval[k]=line[i][j];
                        k++;
                        j++;
                }
                mval[k]='\0';
                strcpy(macro[macro_cnt].name,mname);
                strcpy(macro[macro_cnt].val,mval);
                macro_cnt++;
                }
                i++;
                for(j=0;j<macro_cnt;j++)
                {
                        char*p=strstr(line[i],macro[j].name);
                        while(p!=NULL)
                        {
                                if(p!=NULL)
                                {
                                        vlen=strlen(macro[j].val);
                                        nlen=strlen(macro[j].name);
                                        if(check(p,line[i],nlen))
                                        {
                                        memmove(p+vlen,p+nlen,strlen(p+nlen)+1);
                                        memcpy(p,macro[j].val,vlen);
                                }
                                }
                                p=strstr(p+nlen,macro[j].name);
                        }
                }
                i--;
        }
        src=fopen(filename,"w");
        if(src==NULL)
        {
                printf("error in marco w\n");
                exit(0);
        }
        for(i=0;i<line_cnt;i++)
        {
                if(strstr(line[i],"#define")!=NULL)
                {
                        continue;
                }
                fputs(line[i],src);
        }
        fclose(src);
}

int check(char*p,char*line,int nlen)
{
        if(p!=line)
        {
                 if ((p[-1] >= 'a' && p[-1] <= 'z') ||
            (p[-1] >= 'A' && p[-1] <= 'Z'))
            return 0;
        }
        if ((p[nlen] >= 'a' && p[nlen] <= 'z') ||
        (p[nlen] >= 'A' && p[nlen] <= 'Z'))
        return 0;
        int quote = 0;

        for (int i = 0; line[i] != '\0'; i++)
        {
        if (line[i]==*p)
        {
        if (quote == 1)
            return 0;
        else
            return 1;
        }

        if (line[i] == '"')
                quote = !quote;
        }

        return 1;
}
