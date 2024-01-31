void Revised_BubbleSort(int DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    int temp = 0;


    for (i = 0; i < Length - 1; i++)
    {
        int swap_count = 0;

        for (j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
                ++swap_count;
            }
        }
        if (swap_count == 0) {
            return;
        }
    }
}
