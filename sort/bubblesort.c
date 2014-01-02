#include "stdio.h"

int main(int argc, char const *argv[])
{
    int arr[10] = {6,4,3,8,9,1,2,5,7,0};
    for (int i = 10; i > 0; --i)
    {
        for (int j = 0 ; j < i; ++j)
        {
            if (arr[j+1]>arr[j])
            {
                int temp;
                temp=arr[j+1];
                arr[j+1]=arr[j];
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