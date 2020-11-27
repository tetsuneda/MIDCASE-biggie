#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../UTS/model.h"

node *createNode(pasien n){
    node *temp = (node*)malloc (sizeof(node));
    temp->n.tgl = n.tgl;
    temp->n.tahun = n.tahun;
    strcpy(temp->n.name, n.name);
    strcpy(temp->n.bulan, n.bulan);
    
    temp->next = temp->prev = NULL;

    return temp;
}

void pushHead(pasien n){
    node *temp = createNode(n);

    if(!head){
        head = tail = temp;
    }
    else{
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    //klo tgl selanjutnya lebih awal, push lebih ke depan.
    //klo bulan selanjutnya lebih awal, push lebih awal dr tgl.
    //klo tahun selanjutnya lebih awal, push lebih awal dr tgl dan bulan.
}

void pushTail(pasien n){
    node *temp = createNode(n);

    if(!head){
        head = tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(pasien n){
    node *temp = createNode(n);

    if(!head){
        head = tail = temp;
    }
    else if(n < head->n){
        pushHead(n);
    }
    else if(n > tail->n){
        pushTail(n);
    }
}

/* If (*head)->priority > p then,
      Set temp->next = *head
      Set (*head) = temp
   Else
   Loop While start->next != NULL && start->next->priority < p
      Set start = start->next
      Set temp->next = start->next
      Set start->next = temp /*