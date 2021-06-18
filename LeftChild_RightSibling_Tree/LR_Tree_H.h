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

//스택을 위한 구조체
typedef struct {
	LCRSNode* Node;
	int Depth;
	struct Stack* Down;
}LCRSStack;

//노드 생성
LCRSNode* LCRS_CreateNode(DataType Data);
//노드 삭제
void LCRS_DestroyNode(LCRSNode* Node);
//노드 연결
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);
//트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth);
//스택을 이용한 트리 출력
void LCRS_SPrintTree(LCRSNode* Node, int Depth);
//스택 노드 만들기
LCRSStack* Create_S(LCRSNode* Node, int Depth);
//푸쉬
static void LCRS_SPush(LCRSStack** Stack, LCRSStack* Node);
//팝
static LCRSStack* LCRS_SPop(LCRSStack** Stack);
//특정 레벨의 모든 노드 출력
void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level);
//트리 삭제
void LCRS_DestroyTree(LCRSNode* Node);

#endif // LR_Tree_H