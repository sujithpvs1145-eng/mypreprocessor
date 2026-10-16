#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void *write_file(char *headername ,char(*line)[100],int*i,char*name,int*cnt);
//#define DEBUG
#ifdef DEBUG
#define P(x) printf("%s\n",x)
#else
#define P(x)
#endif
int cnt=0;
 void insert_header(char*name)
{
        char line_buff[100];
        char s[100];
        int i,k=0,j,z,flag=0,a,b;
        char (*line)[100]=NULL;
        FILE*src=fopen(name,"r");
        if(src==NULL)
        {
                printf("error in file src\n");
                exit(0);
        }
                P("1: entered function\n");
                while(fgets(line_buff,100,src)!=NULL)
                {
                        P("2: reading line %d\n");
                        line=realloc(line,(cnt+1)*sizeof(*line));
                        if(line==NULL)
                        {
                                printf("error in line \n");
                                exit(0);
                        }
                        strcpy(line[cnt],line_buff);
                        cnt++;
                }
                fclose(src);
                P("3: finished reading\n");
                P("4: starting processing\n");
                for(i=0;i<cnt;i++)
                {
                        P("in i loop\n");
                for(j=0;line[i][j]!='\0';j++)
                        {
                                P("in j loop\n");
                                if(line[i][j]=='#')
                                {
                                        if(strstr(line[i],"include"))
                                        {
                                        P("in include strstr liip\n");
                                                while(line[i][j]!='<' && line[i][j]!='"' && line[i][j]!='\0' )
                                                {
                                                P("in while loop \n");
                                                j++;
                                                }
                                                if(line[i][j]=='<')
                                                {
                                                        P("found\n");
                                                                flag =1;
                                                        j++;
                                                }
                                                else if(line[i][j]=='"')
                                                {
                                                        flag =2;
                                                        j++;
                                                }
                                                if(flag==1)
                                                {
                                                        k=0;
                                                        while(line[i][j]!='>')
                                                        {
                                                                s[k]=line[i][j];
                                                                j++;
                                                                k++;
                                                                P("in 2 while \n");
                                                        }
                                                        s[k]='\0';
                                                        line[i][0]='\0';
                                                        printf("%s\n",s);
                                                        line=write_file(s, line, &i, name, &cnt);

                                                }
                                                 if(flag ==2)
                                                {
                                                        k=0;
                                                        while(line[i][j]!='"')
                                                        {
                                                                s[k]=line[i][j];
                                                                j++;
                                                                k++;
                                                                P("in usr \n");
                                                        }
                                                        s[k]='\0';
                                                        line[i][0]='\0';
                                                        line=write_file(s, line, &i, name, &cnt);

                                                }
}
}
}
}
}



void *write_file(char *headername ,char(*line)[100],int*i,char*name,int*cnt)
{
        char(*templine)[100]=NULL;
        char *path[] = {
    "/usr/lib/gcc/x86_64-linux-gnu/15/include",
    "/usr/local/include",
    "/usr/include/x86_64-linux-gnu",
    "/usr/include",
    "/home/vamsi/sujith/project"
        };
        char str[100];
        FILE*inc=NULL;
        int z,size,cnt1=0,a,b;
        size=sizeof(path)/sizeof(*path);
        for(z=0;z<size;z++)
        {
                strcpy(str,path[z]);
                strcat(str,"/");
                strcat(str,headername);
                inc=fopen(str,"r");
                printf("%s",str);
                if(inc!=NULL)
                {
                        printf("found in flag 1 #\n");
                        break;
                }
        }
        if(inc==NULL)
        {
                printf("error in writefile\n");
                exit(0);
        }
        while(fgets(str,100,inc)!=NULL)
        {
                templine=realloc(templine,(cnt1+1)*sizeof(*templine));
                strcpy(templine[cnt1],str);
                cnt1++;
        }
        line=realloc(line,(*cnt+cnt1-1)*sizeof(*line));
        memmove(&line[*i+cnt1],&line[*i],(*cnt-*i-1)*sizeof(*line));
        memcpy(&line[*i+1],templine,cnt1*sizeof(*line));
        *cnt=*cnt+cnt1-1;
        *i=cnt1+*i;
        fclose(inc);
        printf("%s\n",name);
        inc=fopen(name,"w");
        if(inc==NULL)//
        {
                printf("error in w mode inc\n");
                exit(0);
        }
        for(a=0;a<*cnt;a++)
        {


                for(b=0;line[a][b]!='\0';b++)
                {
                        fputc(line[a][b],inc);
                }

        }
        fclose(inc);
        return line;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     42,20-41      All
	
