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
//////////////////����ͷ���ĵ�����////////////////////////////////////// 
// .h 
// �����ʼ�� 
void SListInit(PNode* pHead);

// β�� 
void SListPushBack(PNode* pHead, DataType data);


// βɾ 
void SListPopBack(PNode* pHead);

// ͷ�� 
void SListPushFront(PNode* pHead, DataType data);

// ͷɾ 
void SListPopFront(PNode* pHead);

// ����ֵΪdata�Ľ�㣬���ظý���������е�λ�� 
PNode SListFind(PNode* pHead, DataType data);

// ������posλ�ú������data 
void SListInsert(PNode* pHead, PNode pos, DataType data);

// ɾ������posλ���ϵĽ�� 
void SListErase( PNode pos);

// ���ٵ����� 
void SListDestroy(PNode* pHead);

// �������н��ĸ��� 
int SListSize(PNode pHead);

// �������еĽ����� 
void SListClear(PNode* pHead);

// ��ȡ��� 
PNode BuySListNode(DataType data);

// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
PNode SListBack(PNode pHead);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// ��������������⣬�����´���ҵ�н����ڵ�����ʵ�� 

//��ͷ��β��ӡ������
void PrintListFromTail2Head(PNode pHead);

// ɾ������ķ�β��㣬Ҫ���ܱ������� 
void DeleteNotTailNode(PNode pos);

// ������posλ��ǰ����ֵΪdata�Ľ�� 
void InsertPosFront(PNode pos, DataType data);

// Լɪ�� 
void JosephCircle(PNode* pHead, const int M);

// ʹ��ð�ݷ�ʽ�Ե������������ 
void BubbleSort(PNode pHead);

// �����������---����ָ�� 
void ReverseSList(PNode* pHead);

// �����������---ʹ��ͷ�巨 
PNode ReverseSListOP(PNode pHead);

// �ϲ��������������ϲ�������ȻҪ���� 
PNode MergeSList(PNode pHead1, PNode pHead2);

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead);

// ��������ĵ�����K����� 
PNode FindLastKNode(PNode pHead, int K);

//ɾ������ĵ�����K���ڵ�
PNode DeleteLastKNode(PNode pHead,int K);

// �ж������������Ƿ��ཻ---�������� 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// ����ཻ ��ȡ���� 
PNode GetCrossNode(PNode pHead1, PNode pHead2);

// �ж������Ƿ���� 
PNode IsCircle(PNode pHead); 

// �󻷵ĳ��� 
int GetCircleLen(PNode pHead); 

// �󻷵���ڵ�--ע���ƶϹ��� 
PNode GetEnterNode(PNode pHead, PNode pMeetNode); 

// �ж������Ƿ������������ܴ��� 
int IsListCrossWithCircle(PNode pHead1, PNode pHead2); 

// ��������ĸ��� 
//PCListNode CopyComplexList(PCListNode pHead); 