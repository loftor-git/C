#include "stdio.h"

int main(int argc, char const *argv[])
{
    int arr[10] = {6,4,3,8,9,1,2,5,7,0};

    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i]<arr[j])
            {
                int temp=arr[i];
                for (int k = i; k > j; --k)
                {
                    arr[k]=arr[k-1];
                }
                arr[j]=temp;
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n",arr[i] );
    }
    return 0;
}
