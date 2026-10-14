#include<stdio.h>
#include<string.h>
#include<stdio.h>
#define DEBUG
#ifdef DEBUG 
#define  P(x) printf("%s\n",x);
#else
    #define P(x)
#endif
void *read_file(char*line,FILE*src)
{
	return fgets(line,100,src);
}

void write_file(char ch,FILE*dest)
{
	fputc(ch,dest);
}

void comment_remove(FILE*src,FILE*dest)
{
	P("inside function\n");
	char line[100];
	int i,flag=0,multi=0,newline=0;
	/*while(read_file(line,src))
	{   
		P("inside while\n");
		for(i=0;line[i]!='\0';i++)
		{
			if(flag==1)
			{
				P("flag is 1\n");
			if(line[i]=='"')
			{
				P("flag is 0\n");
				flag=0;
				write_file(line[i],dest);
			}
			}
			else if(flag==0)
			{
				P("flag is 0\n");
				if(line[i]=='"')
				{
					flag=1;
					P("flag is 1\n");
				}
				write_file(line[i],dest);
			}
			else if((line[i]=='/')&&(line[i+1]=='*'))
			{
				multi=1;
				i++;
			}
			else if(multi==1)
			{
			 if((line[i]=='*')&&(line[i+1]=='/'))
			{
				multi=0;
				i++;
			}
			}
			else if((line[i]=='/') && (line[i+1] =='/') &&(flag==0))
			{
				break;
			}
			else
			{
				write_file(line[i],dest);
			}
				
	}
	}*/
	while(read_file(line,src))
{
    P("inside while");

    for(i=0; line[i]!='\0'; i++)
    {
        if(multi == 1)
        {
            P("inside multi comment");

            if(((line[i]=='*') && (line[i+1]=='/')))
            {
                multi=0;
                i++;
            }
	    else if(line[i]=='\n')
	    {
		    write_file('\n',dest);
	    }
	    else if(line[i]==EOF)
	    {
		    printf("multi line error\n");
	    }
        }
        else if(flag == 1)
        {
            P("inside string");

            write_file(line[i],dest);

            if(line[i]=='"')
            {
                flag=0;
            }
        }
        else
        {
            P("normal code");

            if(line[i]=='"')
            {
                flag=1;
                write_file(line[i],dest);
            }
            else if(line[i]=='/' && line[i+1]=='/')
            {
		   while(line[i]!='\n' &&  line[i]!='\0')
		    {
			    i++;
		    }
		    if((line[i]=='\n'))
		    {
			    write_file('\n',dest);
		   }
                break;
            }
            else if(line[i]=='/' && line[i+1]=='*')
            {
                multi=1;
                i++;
            }
	    else {
		    if(line[i]=='\n')
		    {
			   
				    write_file(line[i],dest);
		    }
           	 else
            {
                write_file(line[i],dest);
            }
        }
    }
}
}
}
	

