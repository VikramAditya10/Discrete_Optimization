#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){return (a>b)?a:b;}
int knapSack(int n, int W, int wt[],int val[]){
if(W==0||n==0)
	return 0;
if(wt[n-1]>W)
	knapSack(n-1,W,wt,val);
else
	return max(val[n-1]+knapSack(n-1,W-wt[n-1],wt,val),
			knapSack(n-1,W,wt,val));

}
int main(){

	int W , n;
	//int val[] = {8,10,15,4};
	//int weight[] = {4,5,8,3};
	printf("Enter the number  of items (n)\n");
	scanf("%d",&n);
	
	printf("Enter the max weight( W)\n");
	scanf("%d",&W);

	printf("Enter the values of item\n");
	int* val = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);

	int* weight = (int*)malloc(sizeof(int)*n);
	printf("Enter the weight of items\n");
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);

	printf("The value is %d ",knapSack(n,W,weight,val));


	printf("\n");
}

