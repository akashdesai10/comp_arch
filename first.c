#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* head; //global

void insert(int x){
	//traverse thru the ll-->if bigger move along//if less then insert (make all the connection)
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	//struct Node* current = head->link;
	//struct Node* previous = head;
	temp->data = x;
	temp->link = head;
	head = temp;
}

void delete(int x){

	struct Node* temp2 = head;
	struct Node* temp  = temp2->link;


	if(head->data == x){
		//printf("Deleting .... %d\n", head->data);
		head = head->link;
		free(temp2);
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data == x){
			temp2->link  = temp->link;
		}
		temp = temp->link;
		temp2 = temp2->link;	
	}
}

int find(int x){
	//returns 1 if true 0 for false
	//for finding duplicates while inserting --> if found skip, if not found insert
	//for finding number while deleting --> if found, delete or if not found, move alond

	struct Node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data == x){
			return 1;
		}
		temp = temp->link;
	}
	return 0;
}

void print(){
	struct Node* temp = head;

	while(temp->link!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->link;
	}
	printf("%d\n", temp->data);
}

int count(){
	struct Node* temp = head;
	int count = 0;
	while(temp!=NULL){
		count++;
		temp = temp->link;
	}
	return count;
}

int main(int argc, char** argv){
	
	//checking to see if the filename was entered
	if(argc<2){
		printf("error\n");
		exit(0);
	}
  	head = NULL;
	FILE * fPointer;
	fPointer = fopen(argv[1],"r");
	if(fPointer ==NULL){
		printf("error\n");
		 exit(0);
	}
	char name[10];
	//char name;
	int num;
	if(feof(fPointer)){
		printf("0\n");
		printf("\t");
	}
    while(!feof(fPointer)){
    	fscanf(fPointer, "%s\t%d", name , &num);
		if (strcmp(name, "i") == 0){
			//name->&mname and change strcmp
    		if(find(num) == 0 ){
    			insert(num);
    		}
   		 }
   		 if(strcmp(name, "d") == 0){
   		 	if(find(num) == 1){
   		 		delete(num);
   		 	}
   		 	
   		 	/*
   		 	****test case 7*****
   		 	else if(find(num==0) && head){
   		 		printf("0\n");
				printf("\t");
   		 	}
   		 	*/
   		 }
    	//printf("%s %d\n", name, num);
    	//linked implementatio in c
    }
    printf("%d\n",count());
    sort();
    print();
    fclose(fPointer);
    return 0;
}
