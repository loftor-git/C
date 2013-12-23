#include "stdio.h"

int main(int argc, char const *argv[])
{
    int arr[10] = {6,4,3,8,9,1,2,5,7,0};
    for (int i = 0; i < 10; ++i)
    {
        for (int j = i ; j < 10; ++j)
        {
            if (arr[i]<arr[j])
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
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