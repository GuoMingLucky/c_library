/*//单链表的增删改查
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char SLDataType;

typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

SLNode* SLNodeBuyNode(SLDataType c)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("mallocinit failed\n");
		exit(1);
	}

	newnode->data = c;
	newnode->next = NULL;
	
	return newnode;
}

void SLNodeInit(SLNode** pphead, SLDataType c)
{
	assert(pphead);
	*pphead = SLNodeBuyNode(c);
}

void SLNodeDestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	SLNode* next = cur->next;
	while (cur != NULL)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
//查
SLNode* SLNodeFind(SLNode **pphead,SLDataType c) 
{
	assert(pphead);
	if ((*pphead)->data == c) 
	{
		return *pphead;
	}
	else 
	{
		SLNode* cur = *pphead;
		while (cur) 
		{
			if (cur->data == c) 
			{
				return cur;
			}
			cur = cur->next;
		}
	}
	return NULL;
}
//增
void SLNodeInsert(SLNode** pphead, SLDataType c,SLDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		*pphead = SLNodeBuyNode(c);
		return;
	}
	else
	{
		SLNode* find = SLNodeFind(pphead, x);
		if (find != NULL)
		{
			SLNode* next = find->next;
			SLNode* newNode = SLNodeBuyNode(c);

			newNode->next = next;
			find->next = newNode;
		}
		else
		{
			printf("插入失败，没有找到改字符\n");
			exit(1);
		}
	}
}
void SLNodePrint(SLNode *phead) 
{
	assert(phead);
	SLNode* cur = phead;
	while (cur) 
	{
		printf("%c-> ",cur->data);
		cur = cur->next;
	}
}
//删
void SLNodeErase(SLNode **pphead,SLDataType x) 
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur  = *pphead;
	SLNode* prev = *pphead;

	if ((*pphead)->data == x)  //头删
	{
		SLNode *newhead = (*pphead)->next;
		free(*pphead);
		*pphead = newhead;
		return ;
	}

	while (cur != NULL) 
	{
		if (cur->data == x) 
		{
			prev->next = cur->next;
			free(cur);
			return;
 		}
		prev = cur;
		cur = cur->next;
	}
	printf("删除失败,没有该字符\n");
	exit(1);
}
//改

void SLChangeData(SLNode **pphead,SLDataType x ,SLDataType c) 
{
	SLNode* Find = SLNodeFind(pphead,x);
	if (Find != NULL)
		Find->data = c;
	else
	{
		printf("改变字符失败，没有找到改字符\n");
		exit(1);
	}
}

void test02()
{
	SLNode SL;
	struct SLNode* pcur = &SL;
	SLNodeInit(&pcur, 'a');
	SLNodeInsert(&pcur, 'b', 'a');
	SLNodeInsert(&pcur, 'c', 'a');
	SLNodeInsert(&pcur, 'd', 'a');
	SLNodeInsert(&pcur,'e','a');
	SLNodePrint(pcur);   //a->e->d->c->b->
/*	printf("\n");                     //字符g找不到了
	SLNodeInsert(&pcur, 'a', 'g');
	SLNodePrint(pcur);   //a->e->d->c->b->
*/

	//printf("\n");
	//SLNodeErase(&pcur, 'a');
	//SLNodePrint(pcur);   //e->d->c->b->
	//printf("\n");
	//SLNodeErase(&pcur, 'd');
	//SLNodePrint(pcur);   //e->c->b->
	//printf("\n");
	//SLNodeErase(&pcur, 'g');
	//SLNodePrint(pcur);     //失败
	//printf("\n");
	//SLChangeData(&pcur,'e','a');
	//SLNodePrint(pcur);  //a->c->b
	//printf("\n");
/*	SLChangeData(&pcur, 'c', 'b');
	SLNodePrint(pcur);  //a->b->b
*/
//	SLChangeData(&pcur, 'b', 'c');
//	SLNodePrint(pcur);  //a->c->c
//	printf("\n");
///*	SLChangeData(&pcur, 'b', 'c');   //找不到b了
//	SLNodePrint(pcur);  //a->c->c
//*/
//	SLNodeDestroy(&pcur);
//}

//int main()
//{
//	test02();
//
//	return 0;
//}
