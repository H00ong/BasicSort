void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Ret_Pivot(int Left, int Mid, int Right, int DataSet[]) {
	int a = DataSet[Left];
	int b = DataSet[Mid];
	int c = DataSet[Right];

	if (a > b) {
		if (c > a) {
			return Left;
		}
		else if (c > b) {
			return Right;
		}
		else
			return Mid;
	}
	else {
		// a < b ����
		if (c > b) {
			return Mid;
		}
		else if (c < a) {
			return Left;
		}
		else
			return Right;
	}
}


int MyPartition(int DataSet[], int Left, int Right) {

	int Mid = (Left + Right) / 2;
	// �־��� ���� ���ϴ� ����
	int Pivot_index = Ret_Pivot(Left, Right, Mid, DataSet);
	int Pivot = DataSet[Pivot_index];

	while (Left < Right) {
		while (DataSet[Left] <= Pivot && Left < Right) ++Left;
		while (DataSet[Right] >= Pivot && Left <= Right) --Right;

		if (Left < Right) {
			Swap(&DataSet[Left], &DataSet[Right]);
		}
		else
			break;
	}
	if (Left < Pivot_index) {
		Swap(&DataSet[Pivot_index], &DataSet[Left]);
		return Left;
	}
	else if (Right >= Pivot_index) {
		Swap(&DataSet[Pivot_index], &DataSet[Right]);
		return Right;
	}
}

int Partition(int DataSet[], int Left, int Right) {
	
	int First = Left;
	int Mid = (Left + Right) / 2;
	// �־��� ���� ���ϴ� ����
	int Pivot_index = Ret_Pivot(Left, Right, Mid, DataSet);
	int Pivot = DataSet[Pivot_index];
	
	Swap(&DataSet[Left], &DataSet[Pivot_index]);

	while (Left < Right) {
		while (DataSet[Left] <= Pivot && Left < Right) ++Left;
		while (DataSet[Right] >= Pivot && Left <= Right) --Right;

		if (Left < Right) {
			Swap(&DataSet[Left], &DataSet[Right]);
		}
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right) {
	if (Left < Right) {
		int index = Partition(DataSet, Left, Right);
		// index ������ first Pivot���� ���� �� �������� ū ������ �и���
		QuickSort(DataSet, Left, index - 1);
		QuickSort(DataSet, index + 1, Right);
	}
}
