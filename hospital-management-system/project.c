#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.H"
#include "project.h"



patient* head = NULL;        
Timeslots T[5] = {0};        
u32 next_id = 1; 

void Addnewpatientrecord(u32 id1, u8 name1[], u32 age1, u8 gender1[]) {
    patient* p = (patient*)malloc(sizeof(patient));
    p->id = id1;
    strcpy(p->name, name1);
    p->age = age1;
    strcpy(p->gender, gender1);
    p->next = head;
    head = p;
}

void viewpatientrecord(u32 id) {
    patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("The name of the patient is %s\n", temp->name);
            printf("The gender of the patient is %s\n", temp->gender);
            printf("The age of the patient is %d\n", temp->age);
            return;
        } else {
            temp = temp->next;
        }
    }
    printf("Patient with ID %u not found.\n", id);
}
void editpatientrecord(u32 id) {
    patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", temp->name);
            printf("Enter new age: ");
            scanf("%u", &temp->age);
            printf("Enter new gender: ");
            scanf("%s", temp->gender);
            printf("Record updated successfully.\n");
            return;
        } else {
            temp = temp->next;
        }
    }
    printf("Patient with ID %u not found.\n", id);
}
void ReserveSlot(u32 id) {
    printf("Available slots:\n");
    for (int i = 0; i < 5; i++) {
        if (!T[i].isReserved) {
            printf("%d. %02d:%02d - %02d:%02d\n", i + 1, T[i].Starthours, T[i].Startminutes, T[i].Endhours, T[i].Endminutes);
        }
    }

    u32 choice;
    printf("Enter the slot number to reserve: ");
    scanf("%u", &choice);
    if (choice < 1 || choice > 5 || T[choice - 1].isReserved) {
        printf("Invalid choice or slot already reserved.\n");
        return;
    }

    T[choice - 1].isReserved = 1;
    T[choice - 1].patientID = id;
    printf("Slot reserved successfully.\n");
}
void CancelReservation(u32 id) {
    for (int i = 0; i < 5; i++) {
        if (T[i].isReserved && T[i].patientID == id) {
            T[i].isReserved = 0;
            T[i].patientID = 0;
            printf("Reservation canceled successfully.\n");
            return;
        }
    }
    printf("No reservation found for patient with ID %u.\n", id);
}

void ViewReservations() {
    printf("Today's reservations:\n");
    for (int i = 0; i < 5; i++) {
        if (T[i].isReserved) {
            printf("%02d:%02d - %02d:%02d: Patient ID %u\n", T[i].Starthours, T[i].Startminutes, T[i].Endhours, T[i].Endminutes, T[i].patientID);
        } else {
            printf("%02d:%02d - %02d:%02d: Available\n", T[i].Starthours, T[i].Startminutes, T[i].Endhours, T[i].Endminutes);
        }
    }
}
u32 checkId(u32 id) {
    patient* temp = head;
    while (temp != NULL) {
        if (id == temp->id) {
            printf("Invalid ID, enter another one: ");
            scanf("%u", &id);
            temp = head; 
        } else {
            temp = temp->next;
        }
    }
    return id;
}