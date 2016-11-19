/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																			括号匹配
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#define Max 10
using namespace std;

typedef struct 
{
	char *base;
	char *top;
}Stack;

int InitStack(Stack *s)
{
	s->base=(char *)malloc(Max*sizeof(char));
	if (!s->base)
		return 0;
	s->top=s->base;
	return 1;
}

int DestroyStack(Stack *s)
{
	free(s->base);
	s->base=s->top=NULL;
	return 1;
}

char Pop(Stack *s)
{
	char ch;
	ch=*s->top;
	s->top--;
	return ch;
}

void Push(Stack *s,char ch)
{
	s->top++;
	*(s->top)=ch;
}

int is_match(char ch1,char ch2)
{
	switch(ch1)
	{
		case '(':
		{
			if (ch2==')')
				return 1;
		}break;

		case '[':
		{
			if (ch2==']')
				return 1;
		}break;

		case '{':
		{
			if (ch2=='}')
				return 1;
		}break;
	}
	return 0;
}

int empty(Stack *s)
{
	if (s->base==s->top)
		return 1;
	else
		return 0;
}

char Gettop(Stack *s)
{
	char ch;
	ch=*(s->top);
	return ch;
}

int main(void)
{
	Stack s;
	char ch;
	cout<<"Please input the '()','[]','{}','#' to quit:";
	InitStack(&s);
	while ((ch=getchar())!='#')
	{
		if (empty(&s))
			Push(&s, ch);
		else
		{
			if (is_match(Gettop(&s),ch))
				Pop(&s);
			else
				Push(&s,ch);
		}
		
	}

	if (empty(&s))
		cout<<"Success!";
	else
		cout<<"Failed!";
}
