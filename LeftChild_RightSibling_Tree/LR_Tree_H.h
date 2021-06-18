#ifndef LR_Tree_H
#define LR_Tree_H

#include <malloc.h>
#include <stdio.h>

typedef char DataType;

typedef struct tagLCRSNode {
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;
		
	DataType Data;
} LCRSNode;

//������ ���� ����ü
typedef struct {
	LCRSNode* Node;
	int Depth;
	struct Stack* Down;
}LCRSStack;

//��� ����
LCRSNode* LCRS_CreateNode(DataType Data);
//��� ����
void LCRS_DestroyNode(LCRSNode* Node);
//��� ����
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);
//Ʈ�� ���
void LCRS_PrintTree(LCRSNode* Node, int Depth);
//������ �̿��� Ʈ�� ���
void LCRS_SPrintTree(LCRSNode* Node, int Depth);
//���� ��� �����
LCRSStack* Create_S(LCRSNode* Node, int Depth);
//Ǫ��
static void LCRS_SPush(LCRSStack** Stack, LCRSStack* Node);
//��
static LCRSStack* LCRS_SPop(LCRSStack** Stack);
//Ư�� ������ ��� ��� ���
void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level);
//Ʈ�� ����
void LCRS_DestroyTree(LCRSNode* Node);

#endif // LR_Tree_H