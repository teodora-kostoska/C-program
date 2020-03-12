#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct list{
	int num;
	struct list *next;
} *head;

void createList(int);
void addValueToEnding(int, int);
void deleteLastNode(int);
void list_values(struct list *);
void delete(int);

void createList(int number){
	int value = 1;
	struct list *end = NULL, *val;
	for(int i = 0; i < number; i++){
		val = (struct list*)malloc(sizeof(struct list)); 
		if(val == NULL){
			perror("Memory allocation failed.\n");
			exit(1);
		}
		val->num = value; 
		val->next = NULL;
		if (head == NULL){ //if the numbers list is empty
    			head = val;
    			end = val;
			value++;
    		}else{
    			end->next = val;
    			end = val;
			value++;
    		}
	}
}

void list_values(struct list *numbers){
	numbers = head;
    	if(numbers == NULL){ // if list is empty, then return back to main
    		return;
    	}
	while(numbers != NULL){	//go through each node in the list and print the value in the node
    		printf("%d " ,numbers->num);
    		numbers = numbers->next;
    	}
    	printf("\n");
}

void delete(int number){
	struct list *val;
	val = head;
    	while(val != NULL){
        	head = val->next;
        	free(val);
		val = head;
	}
}

void addValueToEnding(int addNumber, int sizeOfList){
	struct list *val,*a,*end = NULL;
	val = (struct list *)malloc(sizeof(struct list));
	end = head;
	val->num = addNumber;
	val->next = NULL;
	if(head == NULL){
		head = val;
		end = val;
		return;
	}
    	for(int i = 1; i < sizeOfList; i++){
    		a = end;
    		end = end->next;
    	}
    	val->num = addNumber;
    	a->next = val;
    	a = val;
    	a->next = end;
    	return;
}

void deleteLastNode(int number){
	struct list *val; 
	val = head;
	if(val == NULL){
		printf("The list is already empty\n");
		return;
	}else if(val->next == NULL){
		free(val);
		return;
	}

    	while (val->next->next != NULL) {
        val = val->next;
    	}

	free(val->next);
    	val->next = NULL;
}

int main(void){
	struct list *current_list;
	head = NULL;
	int count = 1;
	printf("This program controls a list and it's nodes.\n");
	while(1){
		int memory;
		int values;
		int choice;
		printf("1) Create list \n2) Add a value to the ending of the list \n3) Empty the list \n4) Print list \n5) Delete node from end of list \n0) End \n");
		printf("Your choice: ");
		scanf("%d", &choice);
		if(choice == 1){
			delete(memory);
			memory=0;
			count = 0;
			printf("Length of list: ");
			scanf("%d", &memory);
			count = count + memory;
			if(memory < 0){
				printf("The list can't be negative.\n");
			}else{
				createList(memory);
				list_values(current_list);
				count = count + 1;
			}

		}else if(choice == 2){
			printf("The value that will be added: ");
			scanf("%d", &values);
			addValueToEnding(values, count);
			memory++;
			printf("Value %d was added to the end of the list.\n", values);
		}else if(choice == 3){
			delete(memory);
			memory = 0;
			printf("List is empty!\n");
		}else if(choice == 4){
			if(head == NULL){
				printf("\n");
			}else{
				list_values(current_list);
			}
		}else if(choice == 5){
			deleteLastNode(memory);
			memory--;
			printf("Last node was deleted from list.\n");
		}else if(choice == 0){
			break;
		}else{

		}
	}
}

