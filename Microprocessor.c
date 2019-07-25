#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 100 
typedef struct _job { 
int jobid; 
int starttime; 
int joblength;
int rem; 
} job;
typedef struct _heap { 
job list[MAX_SIZE]; 
int numjobs; 
} heap;

   void initheap(heap*h){
        h->numjobs=0;
         }

void insertjob(heap *h, job j){
  int i,l,r,p,num;
  job temp;  
  num=h->numjobs;
  h->list[num+1]=j;
  h->numjobs++;
  i=num+1;  
  while(i>0){
    p=i/2;
    
    if((h->list[i].rem)<(h->list[p].rem)){temp=h->list[i];h->list[i]=h->list[p];h->list[p]=temp;i=p;}

             }


      }


int extractminjob(heap  *h,  job  *j)
{
  int num,l,r,i=1,smallest;
  job temp;
  num=h->numjobs;

  if(num==0) return -1;
  j=&(h->list[1]); 
  h->list[1]=h->list[num];
  (h->numjobs)--;--num;
  while(i<=num){
    smallest=i;
    l=2*i;
    r=2*i+1;

    if((h->list[l]).rem<(h->list[i]).rem)smallest=l;
    if((h->list[r]).rem<(h->list[smallest]).rem)smallest=r;
    if(smallest!=i){temp=h->list[i];h->list[i]=h->list[smallest];h->list[smallest]=temp;i=smallest;}
  }
 
 return 0;
}
void scheduler(job joblist[], int n){
  int i=1,num=n,t=0,ll;
  int j;
  job now,p,bri;
  now.jobid=0;
  heap *h;
   h=malloc(sizeof(heap));
  initheap(h);
  while(num!=0){
    p=joblist[i];
    //j=joblist[i].starttime;
    if(t==p.starttime){
      if(now.jobid==0){now=p;}
      else if(now.rem>p.joblength){insertjob(h,now);now=p;}
      else {insertjob(h,p);}
                        i++;}
    
    




    printf("%d",now.jobid);
    now.rem--;
    if(now.rem==0){num--;ll=extractminjob(h,&bri);if(ll!=-1){now=bri;}}    


   t++;

  }



  }


void merge (job *A, job *B, job *C, int m,int n)
{
int i=1,j=1,k=1;
while (i<m && j<n)
{
if (A[i].starttime < B[j].starttime) C[k++] = A[i++];
else C[k++] = B[j++];
}
while (i<m+1) C[k++] = A[i++];
while (j<n+1) C[k++] = B[j++];
}

void mergesort (job *A, int n) { 
  int i, j;
 job *B;
 if (n <= 1) return; 
 B = (job *)malloc((n)*sizeof(job));
 i = n/2; 
mergesort(A, i);
 mergesort(A+i, n-i); 
merge(A, A+i, B, i, n-i); 
for (j=1; j<n; j++) A[j] = B[j]; 
 
}



int main(){

  int n,a,b,c,i;
  heap *h;
  job *j; 
 printf("enter n");
    scanf("%d",&n);
    /*  h=malloc(sizeof(heap));
  initheap(h);
  for(i=1;i<n+1;i++){
    printf("enter %d ",i);
    scanf("%d%d%d",&a,&b,&c);
    h->list[i].jobid=a;
    h->list[i].starttime=b;
    h->list[i].joblength=c;
    h->list[i].rem=c;
    h->numjobs+=1;
    }*/
    j=malloc(sizeof(job)*(n+1));
    for(i=1;i<n+1;i++){
      printf("enter %d ",i);
      scanf("%d%d%d",&a,&b,&c);
      j[i].jobid=a;
      j[i].starttime=b;
      j[i].joblength=c;
      j[i].rem=c;

       }
  

     mergesort(j,n+1);
    for(i=1;i<n+1;i++)printf("%d",j[i].jobid);

    scheduler(j,n);



return 0;
}
