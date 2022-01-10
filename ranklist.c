#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem **next;
		char *v;
    int *len;
    int k,m;
};


void Skip(struct Elem *l, int m, int k, struct Elem **p){
    struct Elem *x = l;
    int i = m - 1;
    while(i>=0){
        while((*x).next[i] != NULL && (*x).next[i]->k < k){
            x = (*x).next[i];
        }
        p[i] = x;
        i--;
    }
}

char *Lookup(struct Elem *l, int m, int k){
    struct Elem **p = (struct Elem **) malloc(m * sizeof(struct Elem *));
    Skip(l, m, k, p);
    struct Elem *x = (*p[0]).next[0];
    free(p);
    return (*x).v;
}

void GetSpan(struct Elem *l, int n){
    int m = (*l).m;
    for(int i = 0; i<n; i++){
        (*l).len[i] = 0;
    }
    int NotFilledLevel = 0;
    struct Elem *step = l;
    while(NotFilledLevel != m){
        for(int i = NotFilledLevel; i < m; i++){
            (*l).len[i]++;
        }
        step = (*step).next[0];
        while(NotFilledLevel < m && (*l).next[NotFilledLevel] == step){
            NotFilledLevel++;
        }
    }
}

void Insert(struct Elem *l, int n, int k, char *v){
    struct Elem **p = (struct Elem **) malloc(n * sizeof(struct Elem *));
    Skip(l, n, k, p);
    struct Elem *x;
    x = (struct Elem *) malloc(sizeof(struct Elem));
    (*x).next = (struct Elem **) malloc(n * sizeof(struct Elem *));
    (*x).len = (int *) malloc(n * sizeof(int));
    (*x).k = k;
    (*x).v = v;
    int i = 0;
    while (i<n) {
        (*x).next[i] = (*p[i]).next[i];
        (*p[i]).next[i] = x;
        i++;
    }
    (*x).m = i;
    GetSpan(x, n);
    for(int j = 0; j<i;j++)
		{
        (*p[j]).len[j] = (*p[j]).len[j] - (*x).len[j] + 1;
    }
    while(i < n){
        (*p[i]).len[i]++;
        (*x).next[i] = NULL;
        i++;
    }
    free(p);
}

void Delete(struct Elem *l, int m, int k){
    struct Elem **p = (struct Elem **) malloc(m * sizeof(struct Elem *));
    Skip(l, m, k, p);
    struct Elem *x = (*p[0]).next[0];
    
    int i = 0;
    while (i < m) {
        p[i]->len[i]--;
        if((*p[i]).next[i] == x){
            (*p[i]).len[i] += (*x).len[i];
            (*p[i]).next[i] = (*x).next[i];
        }
        i++;
    }
    free((*x).v);
    free((*x).next);
    free((*x).len);
    free(x);
    free(p);
}

int Rank(struct Elem *l, int m, int k){
    struct Elem *x = l;
    int ans = -1;
		for(int i = m - 1; i >=0; i--)
		{
        while((*x).next[i] != NULL && (*x).next[i]->k <= k)
				{
            ans += (*x).len[i];
            x = (*x).next[i];
        }
    }
    return ans;
}


int main(){
    int n, m = 0, k = 1;
    scanf("%d", &n);

    if(n == 1) m = n;
		
    while(k < n)
		{
        m++;
        k *= 2;
    }

    struct Elem *l;
    l = (struct Elem *) malloc(sizeof(struct Elem));
    (*l).next = (struct Elem **) malloc(m * sizeof(struct Elem *));
    for (int i = 0;  i < m; i++)
        (*l).next[i] = NULL;
    (*l).k = 0;
    (*l).len = (int *) malloc(m * sizeof(int));
    (*l).v = (char *) malloc(256 * sizeof(char));
    for (int i = 0; i<m; i++) {
        (*l).len[i] = 1;
    }
    (*l).m = m;

    for (size_t i = 0; i < n; i++) {
        char cmd[6];
        int k;
        scanf("%s ", cmd);
        scanf("%d", &k);
        if(strcmp(cmd, "INSERT") == 0)
				{
            char *v = malloc(256 * sizeof(char));
            scanf("%s ", v);
            Insert(l, m, k, v);
        }
				else if (!strcmp(cmd, "LOOKUP")) 
				{
            printf("%s\n", Lookup(l, m, k));
        }
				else if (!strcmp(cmd, "DELETE")) 
				{
            Delete(l, m, k);
        }
				else if (!strcmp(cmd, "RANK")) 
				{
            printf("%d\n", Rank(l, m, k));
        }
    }
    
    struct Elem *step = l;
    while((*step).next[0] != NULL)
		{
      step = (*step).next[0];
      free((*l).v);
      free((*l).next);
      free((*l).len);
      free(l);
      l = step;
    }
    free((*l).v);
    free((*l).next);
    free((*l).len);
    free(l);
    return 0;
}