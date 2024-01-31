#include "DoublyLInkedLIst.h"

void DLL_InsertionSort(Node** List) {
	Node* move = (*List);

	if (move == NULL) {
		return;
	}
	move = move->NextNode;

	while (move != NULL) {
		if (move->PrevNode->Data < move->Data) {
			move = move->NextNode;
			continue;
		}

		int value = move->Data;

		Node* swap = (*List);
		Node* Remove = move;
		Node* temp = NULL;

		move = move->NextNode;

		while (swap != Remove) {
			if (swap->Data > value) {
				temp = DLL_CreateNode(value);
				DLL_RemoveNode(List, Remove);
				DLL_DestroyNode(Remove);

				if (swap->PrevNode == NULL) {
					swap->PrevNode = temp;
					temp->NextNode = swap;
					(*List) = temp;
					break;
				}
				DLL_InsertAfter(swap->PrevNode, temp);
				break;
			}
			swap = swap->NextNode;
		}
	}
}