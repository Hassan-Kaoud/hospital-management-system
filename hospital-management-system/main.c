#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "STD_TYPES.H"
#include "project.h"
















int main() {
    T[0].Starthours = 14; T[0].Startminutes = 0; T[0].Endhours = 14; T[0].Endminutes = 30;
    T[1].Starthours = 14; T[1].Startminutes = 30; T[1].Endhours = 15; T[1].Endminutes = 0;
    T[2].Starthours = 15; T[2].Startminutes = 0; T[2].Endhours = 15; T[2].Endminutes = 30;
    T[3].Starthours = 16; T[3].Startminutes = 0; T[3].Endhours = 16; T[3].Endminutes = 30;
    T[4].Starthours = 16; T[4].Startminutes = 30; T[4].Endhours = 17; T[4].Endminutes = 0;

    u32 mode, password, counter = 3, operation;

    printf("Welcome to the clinic management system\n");
    printf("Enter 1 for admin mode\nEnter 2 for user mode\n");
    scanf("%d", &mode);

    switch (mode) {
        case 1: {
            printf("You are in admin mode. Please enter password: ");
            while (counter) {
                scanf("%d", &password);
                if (password == 1234) {
                    printf("Correct password\n");
                    break;
                } else {
                    counter--;
                    printf("Incorrect password, you have %d attempts left\n", counter);
                }
                if (counter == 0) {
                    return 0;
                }
            }

            u8 patientname[50];
            u8 patientgender[50];
            u32 patientid, patientage;

            while (1) {
                printf("Please enter the operation you want to perform:\n1. Add new patient record\n2. Edit patient record\n3. Reserve a slot with the doctor\n4. Cancel reservation\n");
                scanf("%d", &operation);

                switch (operation) {
                    case 1:
                        printf("Please enter the patient ID: ");
                        scanf("%u", &patientid);
                        patientid = checkId(patientid);
                        printf("Please enter the patient name: ");
                        scanf(" %[^\n]", patientname);
                        printf("Please enter the patient gender: ");
                        scanf("%s", patientgender);
                        printf("Please enter the patient age: ");
                        scanf("%u", &patientage);
                        Addnewpatientrecord(patientid, patientname, patientage, patientgender);
                        break;

                    case 2:
                        printf("Enter patient ID to edit: ");
                        scanf("%u", &patientid);
                        editpatientrecord(patientid);
                        break;

                    case 3:
                        printf("Enter patient ID to reserve a slot: ");
                        scanf("%u", &patientid);
                        ReserveSlot(patientid);
                        break;

                    case 4:
                        printf("Enter patient ID to cancel reservation: ");
                        scanf("%u", &patientid);
                        CancelReservation(patientid);
                        break;

                    default:
                        printf("Invalid operation\n");
                        break;
                }
            }
        } break;

        case 2: {
            u32 patientid;

            printf("You are in user mode\n");
            printf("Please enter the operation you want to perform:\n1. View patient record\n2. View today’s reservations\n");
            scanf("%d", &operation);

            switch (operation) {
                case 1:
                    printf("Enter patient ID to view record: ");
                    scanf("%u", &patientid);
                    viewpatientrecord(patientid);
                    break;

                case 2:
                    ViewReservations();
                    break;

                default:
                    printf("Invalid operation\n");
                    break;
            }
        } break;

        default:
            printf("Invalid mode selected\n");
            break;
    }

    return 0;
}
