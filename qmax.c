#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pair{
        	int *v, *m, *m2;};
struct stack {        
		int cap,top1,top2;
		struct pair data;
	};
struct stack s;
void push1(long x)
{	
	s.data.v[s.top1]=x;
	if ((s.top1 == 0) || (x>s.data.m[s.top1-1]))
		s.data.m[s.top1]=x;
	else
		s.data.m[s.top1]=s.data.m[s.top1-1];
	++s.top1;
}
void push2(long x, int n)
{
	s.data.v[s.top2]=x;
	if ((s.top2 == n-1) || (x>s.data.m2[s.top2+1]))
		s.data.m2[s.top2]=x;
	else
		s.data.m2[s.top2]=s.data.m2[s.top2+1];
	--s.top2;
}
long pop1()
{
	--s.top1;
	return s.data.v[s.top1];
}
long pop2()
{
	++s.top2;
	return s.data.v[s.top2];
}
void enq(long x)
{	
	push1(x);
}
long deq(int n)
{
	if(s.top2==s.cap-1)
	{
		while (s.top1!=0)
			push2(pop1(),n);
	}
		return pop2();
}
long max(long a , long b)
{
	if (a>=b) return a;
	else return b;
}
char *mygets(char *dest, size_t size) {
    /* read a line from standard input and strip the linefeed if any */
    if (fgets(dest, size, stdin)) {
        dest[strcspn(dest, "\n")] = '\0';
        return dest;
    }
    return NULL;
}

int main()
{	
	
	int n,i,j;
	long r,d,dup,sw1,sw2;
	scanf("%d\n", &n);
	s.data.v=(int*)malloc((n+1)*sizeof(int));
	s.data.m=(int*)malloc((n+1)*sizeof(int));
	s.data.m2=(int*)malloc((n+1)*sizeof(int));
	s.cap=n;
	s.top1=0;
	s.top2=n-1;
	char **str;
	str=(char**)malloc((n+1)*sizeof(char*));
	
	for(i=0;i<n;i++)
	{	
		str[i]=malloc(60 * sizeof(char));
		fgets(str[i],60,stdin);
		d=1;
		r=0;
		if ((strcmp(str[i],"EMPTY\n"))==0)
		{
			if((s.top1==0)&&(s.top2==s.cap-1))
				printf("true\n");
			else
				printf("false\n");
		}
		else if (str[i][0]=='E' && str[i][1] == 'N' && str[i][2] == 'Q')
		{

			for(j=strlen(str[i])-2;str[i][j]!= ' '; --j)
			{
				//printf("%c ", str[i][j]);
				if(str[i][j]=='-')
				r=-r;
				else
				{r=r+1*d*(str[i][j]-48);
				d*=10;}
			}
			enq(r);
		}
		else if (strcmp(str[i],"DEQ\n")==0)
			printf("%ld\n", deq(n));
		else if (strcmp(str[i],"MAX\n")==0)
		{	
			if (s.top2==n-1 && s.top1!=0)
				printf("%d\n", s.data.m[s.top1-1]);
			else if (s.top2!=(n-1) && s.top1==0)
				printf("%d\n", s.data.m2[s.top2+1]);
			else
				printf("%ld\n", max(s.data.m[s.top1-1],s.data.m2[s.top2+1]));
		}
		free(str[i]);
	}
	free(s.data.v);
	free(s.data.m);
	free(s.data.m2);
	free(str);
}
