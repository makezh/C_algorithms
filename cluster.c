#include <stdio.h>
#include <stdlib.h>

struct pair{
        	int start,time,finish;
	};
struct queue {        
        	int cap,count;
		struct pair *heap;
		
	};
struct queue q;

void swap(int i, int j)
{
	struct pair t;
	t=q.heap[j];
	q.heap[j]=q.heap[i];
	q.heap[i]=t;
}

void Init( int n)
{	
	q.heap=(struct pair*)malloc((n+1)*sizeof(struct pair));
	q.count=0;
	q.cap=n;
}

void Heapify(int i, int n)
{	
	int l,r,j;
	for(;;)
	{
		l=2*i+1;
		r=l+1;
		j=i;
		if (l<n && q.heap[i].finish>q.heap[l].finish)
			i=l;
		if (r<n && q.heap[i].finish>q.heap[r].finish)
			i=r;
		if (i==j) break;
		swap(i,j);
	}
}

void Insert(struct pair ptr)
{	
	int i=q.count;
	q.count=i+1;
	q.heap[i]=ptr;
	while (i>0 && q.heap[(i-1)/2].finish > q.heap[i].finish)
	{	
		swap((i-1)/2,i);
		i=(i-1)/2;
	}
}

int ExtractMin()
{
	struct pair ptr;
	ptr=q.heap[0];
	--q.count;
	if(q.count>0)
	{
		q.heap[0]=q.heap[q.count];
		Heapify(0,q.count);
	}
	return ptr.finish;
}

int ExtractMax()
{
	struct pair ptr;
	int max=q.heap[0].finish,i=1;
	while(q.count!=0)
	{
		if (q.heap[i].finish>max)
			max=q.heap[i].finish;
		++i;
		--q.count;
	}
	return max;
}
	
int main()
{
	int n,j,k;
	scanf("%d %d", &n, &k);
	Init(n);
	struct pair *array=(struct pair*)malloc((k+1)*sizeof(struct pair));
	int result;
	for(int i=0;i<k;++i)
	{
		scanf("%d %d", &array[i].start, &array[i].time);
	}
	for (int i = 0; i < n; ++i)
	{
		array[i].finish = array[i].start + array[i].time;
		Insert(array[i]);
	}
	int i=n;
	while(q.count!=0)
	{	
		result=ExtractMin();
		if (i < k && array[i].start>result)
		{
			array[i].finish = array[i].start + array[i].time;
			Insert(array[i]);
		}
		else if (i<k)
		{
			array[i].finish = result + array[i].time;
			Insert(array[i]);
		}
		else
			result=ExtractMax();
		i++;
	}
	printf("%d\n", result);
	free(array);
	free(q.heap);
	return 0;


}
