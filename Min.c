#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n=0;
void insert(int arr[],int n);
void delete(int arr[]);
void heapify(int arr[],int i);
void display(int arr[]);


int main(){
	int a[MAX];
	int choice,value;
	while(1){
		printf("Enter \n1.Insert\n2.Delete\n3.Display\n4.Exit");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter a value to insert : ");
				scanf("%d",&value);
				insert(a,value);
				break;
			case 2:
				delete(a);
				break;
			case 3:
				display(a);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid\n");
		}
	}
	return 0;
}


void insert(int arr[],int value){
	int i = n;
	int temp,parent;
	if(n==MAX){
		printf("Heap is full");return;
		
	}
	arr[i] = value;
	parent = (i-1)/2;
	while(i!=0 && arr[i]<arr[parent]){
		temp = arr[i];
		arr[i] = arr[parent];
		arr[parent] = temp;
		i = parent;
		parent = (i-1)/2;
	}
	n++;
}


void heapify(int a[],int index){
	int temp;
	int parent = index;
	int leftchild = 2*index+1;
	int rightchild = 2*index+2;
	if(leftchild<n && a[leftchild]<a[parent]){
		parent = leftchild;
	}
	if(rightchild<n && a[rightchild]<a[parent]){
		parent = rightchild;
	}
	if(parent!=index){
		temp = a[index];
		a[index]=a[parent];
		a[parent] =temp;
		heapify(a,parent);
	}
}


void delete(int a[]){
	if(n==0){
		printf("Heap is empty");
		return;
	}
	printf("Deleted Element : %d\n",a[0]);
	a[0] = a[n-1];
	n--;
	heapify(a,0);
}


void display(int ar[]){
	if(n==0){
		printf("Heap is empty");
		return;
	}
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",ar[i]);
	}
	printf("\n");
}
