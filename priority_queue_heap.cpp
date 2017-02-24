#include <iostream>
#include <cmath>
using namespace std;

int arr[20];
int n;

int right(int i){
	return 2*i+1;
}

int left(int i){
	return 2*i;
}

int parent(int i){
	return i/2;
}

void max_heapify(int i){
	int l=left(i);
	int r=right(i);
	int largest;
	if(l<n&&arr[l]>arr[i]){
		largest=l;
	}
	else
		largest=i;
	if(r<n&&arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=i){
		int t=arr[i];
		arr[i]=arr[largest];
		arr[largest]=t;
		max_heapify(largest);
	}
}

void build_max_heap(){
	for(int i=n/2;i>=0;i--){
		max_heapify(i);
	}
}

int maximum(){
	return arr[1];
}

void increase_key(int key,int i){
	if(arr[i]>key){
		std::cout<<"error!!";
		return;
	}
	arr[i]=key;
	int p=parent(i);
	while(i>0&&arr[p]<arr[i]){
		int t=arr[p];
		arr[p]=arr[i];
		arr[i]=t;
		i=p;
		p=parent(i);
	}
}

void insert_key(int k){
	arr[n]=-INFINITY;
	n++;
	increase_key(k,n-1);
}

int extract_max(){
	if(n<1){
		std::cout<<"heap underflow!!";
	}
	else{
		int max=arr[0];
		arr[0]=arr[n-1];
		n--;
		max_heapify(0);
		return max;
	}
}

void display(){
	int show=1;
	for(int i=1;i<=n;i++){
		if(i==show){
			show*=2;
			std::cout<<std::endl;
		}
		std::cout<<arr[i-1]<<"  ";
	}
}

int main(){
	n=10;
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}
	build_max_heap();
	std::cout<<extract_max()<<"\n";
	display();
	insert_key(10);
	display();
	increase_key(18,8);
	display();
	std::cout<<"\n"<<extract_max()<<"\n";
}