#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
//栈底层用的是静态顺序表
typedef struct Stack
{
	STDataType *_arr;
	int top;           //有效个数
	int capacity;	      //空间大下
}Stack;

void StackInit(Stack *ps)
{
	ps->_arr = (Stack *)malloc(sizeof(Stack));
	ps->top = 0;
	ps->capacity = 4; 	
}

void StackDestroy(Stack *ps)
{
	assert(ps);
	free(ps->_arr);
	ps->_arr = NULL;	
}
//入栈
void StackPush(Stack *ps,STDataType x)
{
	assert(ps);	
	Stack *ptmp = realloc(ps->_arr,sizeof(Stack)*(ps->capacity));
	if(ptmp == NULL)
	{
		perror("realloc failed ");
		exit(1);
	}
	ps->_arr = ptmp;
	ps->_arr[ps->top] = x;
	ps->top++;
}

void StackPop(Stack *ps)
{
	assert(ps);
	assert(ps->top >0);
	ps->top--;
}

STDataType StackTop(Stack *ps)
{
	assert(ps);
	assert(ps->top >0);
	return ps->_arr[ps->top];
}

int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;	
}

int StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->top>0?0:1;	
}

int main()
{
	Stack st;
	StackInit(&st);
	
	StackPush(&st,11);
	StackPush(&st,11);
	StackPush(&st,11);
	StackPush(&st,11);
	
	StackDestroy(&st);
	
	return 0;	
}