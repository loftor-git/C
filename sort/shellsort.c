void shellsort(int *a,int n)
{
int k = n/2;
while(k>0)
{
for(int i = k;i< n;i++)
{
int t = a[i];
#if 0
//算法1
int j = i - k;
while(j >= 0 && t < a[j])
{
a[j + k] = a[j];
a[j] = t;
j = j - k;
}
#endif
#if 0
//算法2
int j;
for(j = i - k;j>=0 && t < a[j];j -= k)
a[j + k] = a[j];
a[j + k] = t;
#endif
#if 0
//算法3
int j;
for(j = i;j >= k && t < a[j - k];j -= k)
a[j] = a[j - k];
a[j] = t;
#endif
//算法4
int j = i;
while(j >= k && t < a[j - k])
{
a[j] = a[j-k];
j = j-k;
}
a[j] = t;
}
k /= 2;
}
}
int main()
{
int a[N]= {8,10,3,5,7,4,6,1,9,2};
shellsort(a,sizeof(a)/sizeof(a[0]));
for(int k = 0;k < N;k++)
printf("a[%d] = %d\n",k,a[k]);
return 0;
}