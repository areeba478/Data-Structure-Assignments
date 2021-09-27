#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void deleteKey(struct Node **head_ref, int key) 
{ 
    
    struct Node* temp = *head_ref, *prev; 
   
    while (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        temp = *head_ref;         // Change Temp 
    } 
 
    while (temp != NULL) 
    { 
      
        while (temp != NULL && temp->data != key) 
        { 
            prev = temp; 
            temp = temp->next; 
        } 
       
        if (temp == NULL) return; 
       
        prev->next = temp->next; 
        free(temp);  // Free memory 
       
        temp = prev->next; 
    } 
} 


void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 
   
int main() 
{ 
    
    struct Node* head = NULL; 
    push(&head, 7); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 2); 
    int key = 2; // key to delete 
    puts("Created Linked List: "); 
    printList(head); 
    deleteKey(&head, key); 
    puts("\nLinked List after Deletion: "); 
    printList(head); 
    return 0; 
}
