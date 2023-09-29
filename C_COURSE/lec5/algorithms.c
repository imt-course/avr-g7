
int LinearSearch (int arr[], int length, int number)
{
    int i;
    int index = length;
    for (i=0; i<length; i++)
    {
        if (number == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

int BinarySearch (int arr[], int length, int number)
{
    int start = 0;
    int end = length - 1;
    int middle;
    int index = length;
    while (start <= end)
    {
        middle = (start + end) / 2;
        if (number > arr[middle])
        {
            start = middle + 1;
        }
        else if (number < arr[middle])
        {
            end = middle - 1;
        }
        else
        {
            index = middle;
            break;
        }
    }
    return index;
}

void BubbleSort (int arr[], int length)
{
    int i, j;
    int swapFlag = 0;
    for (i=length-1; i>0; i--)
    {
        swapFlag = 0;
        for (j=0; j<i; j++)
        {
            if (arr[j+1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapFlag = 1;
            }
        }
        if (swapFlag == 0)
        {
            break;
        }
    }
}