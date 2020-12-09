/*
note:Binary Search is for an ordered sequence
*/
#include <stdio.h> 
#include <stdlib.h>

int BinarySearch(int n); 

int main(){
	int n;
	printf("please enter several numbers:");
	scanf("%d",&n);
	n = BinarySearch(n);
	printf("its position is:%d",n);
	return 0;
	
}

int BinarySearch(int n){
//if you want to see the core,please jump to line51.
	int searchNum;
	int left = 0,right = n-1,middle;
	int i;
	int choice;
	int *num = (int *)malloc(sizeof(int)*n);
	printf("1.auto generated.\n2.enter them yourself.\ndefault is auto generated.");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			for(i=0; i<n; i++){
				num[i] = rand() % 9+10*i;
			}
			break;
		case 2:
			for(i=0; i<n; i++){
				printf("please enter the %dst number:",(i+1));
				scanf("%d",&num[i]);
			}
			break;
		default:
			for(i=0; i<n; i++){
				num[i] = rand() % 9+10*i;
			};
	}
	for(i=0; i<n; i++){
		printf("%dst number is : %d\n",(i+1),num[i]);
	}
	printf("plese enter the number to search:");
	scanf("%d",&searchNum);
	
//this is core of the algorithm
	while (left <= right){
		middle = (left+right)/2;
		if( searchNum == num[middle]){
			break;
		}
		if(searchNum > num[middle]){
			left = middle +1;
		}
		else{
			right = middle-1;
		}
		if(left>right){
			middle = 2147483647;//this is the solution that didnt fine searchNum
		}	
	}
	free(num);
	return (middle);
}
