//
//  main.c
//  listaEncadeada
//
//  Created by Gabriel Freitas on 15/09/17.
//  Copyright © 2017 Gabriel Freitas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int code;
    //char name[50];
} REGISTER;

typedef struct {
    REGISTER info;
    struct LIST *next;
}LIST;

void createList(LIST **l);
void insertBeginning(LIST **l);
void insertEnd(LIST **l);
void showList(LIST *l);
void createRegister(LIST *reg);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    LIST *l;
    
    int op;
    
    while(1) {
        printf("\n[M E N U]");
        printf("\n[1]  Create List");
        printf("\n[2]  Insert register in the beginning");
        printf("\n[3]  Insert register in the end");
        printf("\n[13] Show List");
        
        printf("\n\n-> Chose your option: ");
        fflush(stdin);
        scanf("%i", &op);
        
        switch(op) {
            case 1:
                createList(&l);
                break;
                
            case 2:
                insertBeginning(&l);
                break;
                
            case 3:
                insertEnd(&l);
                break;
                
            case 13:
                showList(l);
                break;
                
            default:
                printf("\n\n...>Wrong option! Try again.");
                break;
        }
    }
    
    return 0;
}

void createList(LIST **l) {
    *l = NULL;
    printf("\n...>List created!\n");
}

void createRegister(LIST *reg) {
    printf("\n-> Put the register code: ");
    fflush(stdin);
    scanf("%i", &reg->info.code);
    
    //printf("\n-> Put the register name: ");
    //fflush(stdin);
    //gets(reg->info.name);
}

void insertBeginning(LIST **l) {
    LIST *lNode = (LIST *) malloc (sizeof(LIST));
    
    if(lNode != NULL) {
        createRegister(lNode);
        lNode->next = *l;
        *l = lNode;
        
        printf("\n...>Register created at beginning successffully!\n");
    }
}

void insertEnd(LIST **l) {
    
    LIST *p;
    LIST *lNode = (LIST*) malloc (sizeof(LIST*));
    
    createRegister(lNode);
    
    if(lNode != NULL) {
        if(*l == NULL) {
            lNode->next = *l;
            *l = lNode;
        } else {
            p = *l;
            
            while(p->next != NULL) {
                p = p->next;
            }
            
            p->next = lNode;
            lNode->next = NULL;
        }
        
        printf("\n...>Register created at the ending successffully!\n");
    } else {
        printf("\n...>List is full!\n");
    }
}

void showList(LIST *l) {
    
    if(l == NULL) {
        printf("\n...>List is empty.\n");
    } else {
        printf("\n[ L I S T ]");
        //printf("\n...>List...\n");
        while(l != NULL) {
            printf("\nCode: %d", l->info.code);
            printf("\n");
            l = l->next;
        }
    }
}
