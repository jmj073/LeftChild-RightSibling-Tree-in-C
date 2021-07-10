#define _CRT_NO_SECURE_WARGNINGS

#include "LR_Tree_H.h"

int main() {
	LCRSNode* Root = LCRS_CreateNode('a');
	
	LCRSNode* b = LCRS_CreateNode('b');
	LCRSNode* c = LCRS_CreateNode('c');
	LCRSNode* d = LCRS_CreateNode('d');
	LCRSNode* e = LCRS_CreateNode('e');
	LCRSNode* f = LCRS_CreateNode('f');
	LCRSNode* g = LCRS_CreateNode('g');
	LCRSNode* h = LCRS_CreateNode('h');
	LCRSNode* i = LCRS_CreateNode('i');
	LCRSNode* j = LCRS_CreateNode('j');
	LCRSNode* k = LCRS_CreateNode('k');

	LCRS_AddChildNode(Root, b);
		LCRS_AddChildNode(b, c);
		LCRS_AddChildNode(b, d);
			LCRS_AddChildNode(d, e);
			LCRS_AddChildNode(d, f);
	LCRS_AddChildNode(Root, g);
		LCRS_AddChildNode(g, h);
	LCRS_AddChildNode(Root, i);
		LCRS_AddChildNode(i, j);
			LCRS_AddChildNode(j, k);

	LCRS_PrintTree(Root, 0);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	LCRS_PrintNodesAtLevel(Root, 2);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	LCRS_SPrintTree(Root);

	LCRS_DestroyTree(Root);
}