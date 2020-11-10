#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char word[50];
    struct node *next;
};

void insert(struct node* node, char *word)
{
	while(node->next != NULL)
		  node = node->next;
		
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	strcpy(new_node->word, word);
	new_node->next = NULL;
	node->next = new_node;
	
}

void printList(struct node *node) 
{ 
  while (node != NULL) 
  { 
     printf("> %s \n", node->word); 
     node = node->next; 
  } 
}

void push(struct node** head_ref, char *word)
{ 
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    strcpy(new_node->word, word);
  
    new_node->next = (*head_ref); 
  
    (*head_ref)    = new_node; 
} 

static void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    
    while (current != NULL) {
        next = current->next;

        current->next = prev;
 
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void inputText(struct node* head, int* status){
	char ch;
	char *word = malloc(50 * sizeof(char));
	int  i = 0;
	while((ch = getchar()) != EOF){
		if(ch == '"')
			while((ch = getchar()) != '"')
				word[i++] = ch;
			
	}
	push(&head, word);
	free(word);
	status = 0;
}

int main() {
	
	int status = 1;
	while(status){
    	struct node* head = NULL;
    	inputText(head, &status);
    	printf("\nCommands: \n"); 
    	reverse(&head);
    	printList(head); 
    	free(head);
	}
    return 0; 
}
  
