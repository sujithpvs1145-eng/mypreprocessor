#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define DEBUG
#ifdef DEBUG 
#define P(X) printf("%s\n",X)
#else
#define P(X)
#endif
int line_cnt=0;
int macro_cnt=0;
typedef struct define
{
        char name[30];
        char val[20];
        char par[10][10];
        int is_fun;
        int p1;
}define;
int check(char*p,char*line,int nlen);
void macro_with_parameter(char*p,define m);
void macro_handling(char*filename)
{
        define macro[100];
        FILE*src=NULL;
        char line_buffer[100];
        int i,j=0,nlen,vlen,k,p1;
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
                        P("inside while to skip space");
                }
                j++;
                while((line[i][j]!=' ')&&(line[i][j]!='\0')&& (line[i][j]!='('))
                {
                        mname[k]=line[i][j];
                        j++;
                        k++;
                        P("taking name\n");
                }
                mname[k]='\0';
                macro[macro_cnt].is_fun = 0;
                if(line[i][j]=='(')
                {
                         macro[macro_cnt].is_fun = 1;
                        j++;
                        p1=0;
                        k=0;
                        P("inside if of '('");
                        while((line[i][j]!=')')&&(line[i][j]!='\0'))
                        {
                        if(line[i][j]==',')
                        {
                                macro[macro_cnt].par[p1][k]='\0';
                                p1++;
                                k=0;
                        }
                        else
                        {
                        macro[macro_cnt].par[p1][k]=line[i][j];
                        k++;
                        }
                        j++;
                        }
                        macro[macro_cnt].par[p1][k] = '\0';
    macro[macro_cnt].p1 = p1 + 1;
    j++;
}
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
                        P("got val");
                }
                mval[k]='\0';
                strcpy(macro[macro_cnt].name,mname);
                strcpy(macro[macro_cnt].val,mval);
                macro_cnt++;
                }
                i++;
                for(j=0;j<macro_cnt;j++)
                {
                        P("inside for loop");
                        char*p=strstr(line[i],macro[j].name);
                        while(p!=NULL)
                        {
                                if(p!=NULL)
                                {
                                        vlen=strlen(macro[j].val);
                                        nlen=strlen(macro[j].name);
                                        if(check(p,line[i],nlen))
                                        {
                                                P("into check ");
                                                if(macro[j].is_fun==1)
                                                {
                                                        P("into marco if ");
                                                        macro_with_parameter(p,macro[j]);
                                                        P("into macro fun");
                                                }
                                                else
                                                {
                                        memmove(p+vlen,p+nlen,strlen(p+nlen)+1);
                                        P("memmove");
                                        memcpy(p,macro[j].val,vlen);
                                        P("memcpy");
                                                }
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
                P("Final");
                fputs(line[i],src);
        }
        fclose(src);
}

int check(char*p,char*line,int nlen)
{
        if(p!=line)
        {
                P("P!=line");
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
        if (&line[i]==p)
        {
                                        P("checking line ==p");
        if (quote == 1)
        {

                                        P("quote");
            return 0;
        }
        else
            return 1;
        }

        if (line[i] == '"')
        {
                                        P("line in comment");
                quote = !quote;
        }
        }

}

void macro_with_parameter(char*p,define m)
{
        int len=strlen(m.name);
        char arg[20];
        char expanded[100];
        int k = 0;
        int xlen = strlen(m.par[0]);
        if(p[len]!='(')
        {
                return ;
        }

                                        P("in marco with par");

        char*s=p+len+1;
        while(*s!=')' && *s!='\0')
        {

                                        P("inside while of macro with par");
                arg[k++]=*s;
                s++;
        }
        arg[k]='\0';
        k=0;
        int call_len = (s - p) + 1;
        for(int i = 0; m.val[i] != '\0'; i++)
{

                                        P("inside for of macro fun ");
    if(strncmp(&m.val[i], m.par[0], xlen) == 0)
    {
        strcpy(&expanded[k], arg);
        k += strlen(arg);
        i += xlen - 1;
    }
    else
    {
        expanded[k++] = m.val[i];
    }
}

expanded[k] = '\0';
int expanded_len = strlen(expanded);
                                        P("writing ");
memmove(p + expanded_len, p + call_len,
        strlen(p + call_len) + 1);
                                        P("writing ");
memcpy(p, expanded, expanded_len);
return ;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            99,2          All 
