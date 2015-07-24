#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* queue;
int queuesize;
int counter;
int continrun;
int frontcounter;

void init()
{
	queuesize = 100;
	queue = (int*)malloc(queuesize*sizeof(int));
	counter = -1;
	continrun = 1;
	frontcounter = 0;
}

void end()
{
	free((void*)queue);
	queue = NULL;
	queuesize = 0;
	continrun = 0;
	counter = 0;
	frontcounter = 0;
}

void resize()
{
	queuesize*=2;
	queue = realloc(queue, queuesize*sizeof(int));
}

void push(int value)
{
	if(counter==queuesize) resize();
	queue[++counter] = value;
	printf("ok\n");
}

void pop()
{
	if(counter>=frontcounter)
	{
		printf("%d\n", queue[frontcounter++]);
	}
	else printf("error\n");
}

void front()
{
	if(counter>=frontcounter)
	{
		printf("%d\n", queue[frontcounter]);
	}
	else printf("error\n");
}

void size()
{
	printf("%d\n", (counter+1-frontcounter));
}

void clear()
{
	counter = -1;
	frontcounter = 0;
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
		else if(!strncmp(cmd, "front", 4))
		{
			front();
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
