#include "LR_Tree_H.h"

//노드 생성
LCRSNode* LCRS_CreateNode(DataType Data) {
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = Data;
}

//노드 삭제
void LCRS_DestroyNode(LCRSNode* Node) {
	free(Node);
}

//노드 연결
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else {
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = Child;
	}
}

//트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth) {
	int i = 0;

	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

//스택을 이용한 트리 출력
void LCRS_SPrintTree(LCRSNode* Node) {
	int Depth = 0;
	LCRSStack* Stack = NULL, * Current;
	LCRS_SPush(&Stack, Create_S(Node, Depth));

	while (Stack != NULL) {
		Current = LCRS_SPop(&Stack);
		Depth = Current->Depth;
		while (Depth--)
			printf(" ");
		printf("%c\n", Current->Node->Data);
		if(Current->Node->RightSibling != NULL)
			LCRS_SPush(&Stack, Create_S(Current->Node->RightSibling, Current->Depth));
		if (Current->Node->LeftChild != NULL)
			LCRS_SPush(&Stack, Create_S(Current->Node->LeftChild, Current->Depth + 1));
		free(Current);
	}
}
//스택 노드 만들기
LCRSStack* Create_S(LCRSNode* Node, int Depth) {
	LCRSStack* NewNode = (LCRSStack*)malloc(sizeof(LCRSStack));
	NewNode->Down = NULL;
	NewNode->Depth = Depth;
	NewNode->Node = Node;
}
//푸쉬
static void LCRS_SPush(LCRSStack** Stack, LCRSStack* Node) {
	Node->Down = *Stack;
	*Stack = Node;
}
//팝
static LCRSStack* LCRS_SPop(LCRSStack** Stack) {
	LCRSStack* Popped = *Stack;
	*Stack = (*Stack)->Down;
	return Popped;
}

//특정 레벨의 모든 노드 출력
void LCRS_PrintNodesAtLevel(LCRSNode* Node, int Level) {
	if (!Level)
		printf("%c\n", Node->Data);
	else if (Node->LeftChild != NULL)
		LCRS_PrintNodesAtLevel(Node->LeftChild, Level - 1);
	if (Node->RightSibling != NULL)
		LCRS_PrintNodesAtLevel(Node->RightSibling, Level);
}

//트리 삭제
void LCRS_DestroyTree(LCRSNode* Node) {

	if (Node->RightSibling != NULL)
		LCRS_DestroyTree(Node->RightSibling);
	if (Node->LeftChild != NULL)
		LCRS_DestroyTree(Node->LeftChild);

	LCRS_DestroyNode(Node);
}