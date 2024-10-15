#ifndef PROJECT_H_
#define PROJECT_H_

#include "STD_TYPES.H" 


typedef struct patient {
    u32 id;
    u8 name[50];
    u32 age;
    u8 gender[50];
    struct patient* next;
} patient;

typedef struct Timeslots {
    u32 Starthours;
    u32 Startminutes;
    u32 Endhours;
    u32 Endminutes;
    u8 isReserved;
    u32 patientID; 
} Timeslots;


extern patient* head;
extern Timeslots T[5];
extern u32 next_id;


void Addnewpatientrecord(u32 id1, u8 name1[], u32 age1, u8 gender1[]);
void viewpatientrecord(u32 id);
void editpatientrecord(u32 id);
void ReserveSlot(u32 id);
void CancelReservation(u32 id);
void ViewReservations();
u32 checkId(u32 id);

#endif 
