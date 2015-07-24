#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* stack;
int stacksize;
int counter;
int continrun;

void init()
{
	stacksize = 100;
	stack = (int*)malloc(stacksize*sizeof(int));
	counter = -1;
	continrun = 1;
}

void end()
{
	free((void*)stack);
	stack = NULL;
	stacksize = 0;
	continrun = 0;
}

void resize()
{
	stacksize*=2;
	stack = realloc(stack, stacksize*sizeof(int));
}

void push(int value)
{
	if(counter==stacksize) resize();
	stack[++counter] = value;
	printf("ok\n");
}

void pop()
{
	if(counter>=0)
	{
		printf("%d\n", stack[counter--]);
	}
	else printf("error\n");
}

void back()
{
	if(counter>=0)
	{
		printf("%d\n", stack[counter]);
	}
	else printf("error\n");
}

void size()
{
	printf("%d\n", (counter+1));
}

void clear()
{
	counter = -1;
	printf("ok\n");
}

void exitprogram()
{
	printf("bye\n");
	continrun = 0;
}

int main(int argc, char** argv)
{
	init();
	char Look = 0;
	char cmd[20];
	while(continrun)
	{
		scanf("%s", cmd);
		if(!strncmp(cmd, "push", 4))
		{
			int number = 0;
			scanf(" %d", &number);
			push(number);
		}
		else if(!strncmp(cmd, "pop", 3))
		{
			pop();
		}
		else if(!strncmp(cmd, "back", 4))
		{
			back();
		}
		else if(!strncmp(cmd, "size", 4))
		{
			size();
		}
		else if(!strncmp(cmd, "clear", 5))
		{
			clear();
		}
		else if(!strncmp(cmd, "exit", 4))
		{
			exitprogram();
		}
	}
	end();
	return 0;
}
