#include <stdio.h>
#include <stdlib.h>

struct pair{
        	int k,v;
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
		if (l<n && q.heap[i].k>q.heap[l].k)
			i=l;
		if (r<n && q.heap[i].k>q.heap[r].k)
			i=r;
		if (i==j) break;
		swap(i,j);
	}
}

void Insert(struct pair ptr)
{	
	int i=q.count;
	q.count=i+1;
	q.heap[i].k=ptr.k;
	q.heap[i].v=ptr.v;
	while (i>0 && q.heap[(i-1)/2].k > q.heap[i].k)
	{	
		swap((i-1)/2,i);
		i=(i-1)/2;
	}
}

struct pair ExtractMin()
{
	struct pair ptr;
	ptr=q.heap[0];
	--q.count;
	if(q.count>0)
	{
		q.heap[0]=q.heap[q.count];
		Heapify(0,q.count);
	}
	return ptr;
}
void Merge(int *result,  int n, struct pair **array, int *size)
{	
	int i,j=0;
	int h[n];
	struct pair ptr;
	for(i=0;i<n;++i)
	{	
		Insert(array[i][0]);
		h[i]=1;
	}
		
	while(q.count!=0)
	{	
		ptr=ExtractMin();
		result[j]=ptr.k;
		if(h[ptr.v]<size[ptr.v])
		{	
			Insert(array[ptr.v][h[ptr.v]]);
			++h[ptr.v];
		}
		++j;
	}
	
}	
int main()
{
	int n,i,j;
	scanf("%d", &n);
	struct pair *array[n];
	int size[n],full_size=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &size[i]);
		if(size[i]==0)
		{
			--i;
			--n;
		}
	}
	for(int i=0;i<n;i++)
	{	
		full_size+=size[i];
		array[i]=(struct pair*)malloc((size[i]+1)*sizeof(struct pair));
		for(j=0;j<size[i];++j)
		{
			scanf("%d", &array[i][j].k);
			array[i][j].v=i;
		}
	}
	int *result=(int*)malloc((full_size+1)*sizeof(int));
	Init(n);
	Merge(result,n,array,size);
	for(int i=0;i<full_size;i++)
		printf("%d ", result[i]);
	printf("\n");
	for(i=0;i<n;++i)
		free(array[i]);
	free(q.heap);
        free(result);
	return 0;
}
