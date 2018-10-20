#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

PNode pHand;
//////////////////不带头结点的单链表////////////////////////////////////// 
// .h 
// 链表初始化 
void SListInit(PNode* pHead);

// 尾插 
void SListPushBack(PNode* pHead, DataType data);


// 尾删 
void SListPopBack(PNode* pHead);

// 头插 
void SListPushFront(PNode* pHead, DataType data);

// 头删 
void SListPopFront(PNode* pHead);

// 查找值为data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode* pHead, DataType data);

// 在链表pos位置后插入结点data 
void SListInsert(PNode* pHead, PNode pos, DataType data);

// 删除链表pos位置上的结点 
void SListErase( PNode pos);

// 销毁单链表 
void SListDestroy(PNode* pHead);

// 求链表中结点的个数 
int SListSize(PNode pHead);

// 将链表中的结点清空 
void SListClear(PNode* pHead);

// 获取结点 
PNode BuySListNode(DataType data);

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// 以下链表的面试题，放在下次作业中交，在底下先实现 

//从头到尾打印单链表
void PrintListFromTail2Head(PNode pHead);

// 删除链表的非尾结点，要求不能遍历链表 
void DeleteNotTailNode(PNode pos);

// 在链表pos位置前插入值为data的结点 
void InsertPosFront(PNode pos, DataType data);

// 约瑟夫环 
void JosephCircle(PNode* pHead, const int M);

// 使用冒泡方式对单链表进行排序 
void BubbleSort(PNode pHead);

// 单链表的逆序---三个指针 
void ReverseSList(PNode* pHead);

// 单链表的逆序---使用头插法 
PNode ReverseSListOP(PNode pHead);

// 合并两个有序链表，合并起来依然要有序 
PNode MergeSList(PNode pHead1, PNode pHead2);

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead);

// 查找链表的倒数第K个结点 
PNode FindLastKNode(PNode pHead, int K);

//删除链表的倒数第K个节点
PNode DeleteLastKNode(PNode pHead,int K);

// 判断两个单链表是否相交---链表不带环 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// 如果相交 获取交点 
PNode GetCrossNode(PNode pHead1, PNode pHead2);

// 判断链表是否带环 
PNode IsCircle(PNode pHead); 

// 求环的长度 
int GetCircleLen(PNode pHead); 

// 求环的入口点--注意推断过程 
PNode GetEnterNode(PNode pHead, PNode pMeetNode); 

// 判断链表是否带环，链表可能带环 
int IsListCrossWithCircle(PNode pHead1, PNode pHead2); 

// 复杂链表的复制 
//PCListNode CopyComplexList(PCListNode pHead); 