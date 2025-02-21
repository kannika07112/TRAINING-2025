
// `3. Hospital Patient Management System`  
// `Scenario:`  
// A `hospital` maintains patient records using a `doubly linked list`. The system should:  
// - Add `new patients`  
// - Allow `forward and backward navigation`  
// - Remove `discharged patients`  

// `Operations Example:`  
// ```
// New Patient Admitted: John (ID 201)  
// New Patient Admitted: Mary (ID 202)  
// New Patient Admitted: David (ID 203)  

// Discharging: Mary  
// Remaining Patients: John ↔ David  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Patient {
    int id;
    char name[30];
    struct Patient* next;
    struct Patient* prev;
} Patient;

Patient* createPatient(int id, const char* name);
void addPatient(Patient** head, int id, const char* name);
void dischargePatient(Patient** head, int id);
void displayPatientsForward(Patient* head);
void displayPatientsBackward(Patient* head);

int main() {
    Patient* head = NULL;

    addPatient(&head, 201, "John");
    addPatient(&head, 202, "Mary");
    addPatient(&head, 203, "David");

    printf("Initial Patient List:\n");
    displayPatientsForward(head);

    dischargePatient(&head, 202);

    printf("\nAfter Discharging Mary:\n");
    displayPatientsForward(head);

    printf("\nRemaining Patients in Reverse Order:\n");
    displayPatientsBackward(head);

    return 0;
}

Patient* createPatient(int id, const char* name) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->next = NULL;
    newPatient->prev = NULL;
    return newPatient;
}

void addPatient(Patient** head, int id, const char* name) {
    Patient* newPatient = createPatient(id, name);
    if (*head == NULL) {
        *head = newPatient;
    } else {
        Patient* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
        newPatient->prev = temp;
    }
    printf("New Patient Admitted: %s (ID %d)\n", name, id);
}

void dischargePatient(Patient** head, int id) {
    Patient* temp = *head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Discharging: %s\n", temp->name);
    free(temp);
}

void displayPatientsForward(Patient* head) {
    Patient* temp = head;
    while (temp != NULL) {
        printf("Patient %s (ID %d)\n", temp->name, temp->id);
        temp = temp->next;
    }
}

void displayPatientsBackward(Patient* head) {
    Patient* temp = head;
    if (temp == NULL) return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("Patient %s (ID %d)\n", temp->name, temp->id);
        temp = temp->prev;
    }
}
