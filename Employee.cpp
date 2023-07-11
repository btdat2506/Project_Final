#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 8
#define MAX_NAME_LEN 20

typedef struct {
    char id[MAX_ID_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    char marital_status;
    int num_children;
    char education_level[3];
    int base_salary;
    char num_sick_days,
         num_unpaid_days,
         num_overtime_days;
    char job_performance[3];
    int net_salary;
} Employee;

typedef struct Node {
    Employee emp;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} EmployeeList;

void init(EmployeeList* list) {
    list->head = NULL;
}

void addEmployee(EmployeeList* list, Employee emp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->emp = emp;
    newNode->next = list->head;
    list->head = newNode;
}

void removeEmployee(EmployeeList* list, char* id) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->emp.id, id) == 0) {
            if (prev == NULL) {
                list->head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Employee* findEmployee(EmployeeList* list, char* id) {
    Node* curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->emp.id, id) == 0) {
            return &curr->emp;
        }
        curr = curr->next;
    }
    return NULL;
}

void calculateNetSalary(Employee* emp) {
    emp->net_salary = emp->base_salary;
    if (emp->num_children > 2) {
        emp->net_salary += emp->base_salary * 0.05;
    }
    if (strcmp(emp->education_level, "CH") == 0) {
        emp->net_salary += emp->base_salary * 0.1;
    }
    emp->net_salary += emp->num_overtime_days * emp->base_salary * 0.04;
}

void calculateAllNetSalaries(EmployeeList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        calculateNetSalary(&curr->emp);
        curr = curr->next;
    }
}

void printEmployee(Employee* emp) {
    printf("ID: %s\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Marital Status: %c\n", emp->marital_status);
    printf("Number of Children: %d\n", emp->num_children);
    printf("Education Level: %s\n", emp->education_level);
    printf("Base Salary: %d\n", emp->base_salary);
    printf("Number of Sick Days: %d\n", emp->num_sick_days);
    printf("Number of Unpaid Days: %d\n", emp->num_unpaid_days);
    printf("Number of Overtime Days: %d\n", emp->num_overtime_days);
    printf("Job Performance: %s\n", emp->job_performance);
    printf("Net Salary: %d\n", emp->net_salary);
    printf("\n");
}

void printAllEmployees(EmployeeList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        printEmployee(&curr->emp);
        curr = curr->next;
    }
}

void swap(Employee* a, Employee* b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

Node* partition(Node* low, Node* high) {
    Employee pivot = high->emp;
    Node* i = low->next;
    for (Node* j = low; j != high; j = j->next) {
        if (j->emp.net_salary < pivot.net_salary) {
            swap(&i->emp, &j->emp);
            i = i->next;
        }
    }
    swap(&i->emp, &high->emp);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->next);
        quickSort(p->next, high);
    }
}

void sortEmployees(EmployeeList* list) {
    Node* last = list->head;
    while (last != NULL && last->next != NULL) {
        last = last->next;
    }
    quickSort(list->head, last);
}

int main() {
    EmployeeList list;
    init(&list);

    Employee emp1 = {"00000001", "John Doe", 'M', 2, "CH", 500000, 2, 0, 3, "T", 0};
    Employee emp2 = {"00000002", "Jane Smith", 'S', 1, "ĐH", 400000, 1, 1, 2, "TB", 0};
    Employee emp3 = {"00000003", "Bob Johnson", 'M', 0, "C3", 300000, 0, 2, 1, "K", 0};

    addEmployee(&list, emp1);
    addEmployee(&list, emp2);
    addEmployee(&list, emp3);

    calculateAllNetSalaries(&list);
    printAllEmployees(&list);

    sortEmployees(&list);
    printf("Sorted by net salary:\n");
    printAllEmployees(&list);

    removeEmployee(&list, "00000002");
    printf("After removing employee with ID 00000002:\n");
    printAllEmployees(&list);

    Employee* emp = findEmployee(&list, "00000003");
    if (emp != NULL) {
        printf("Found employee with ID 00000003:\n");
        printEmployee(emp);
    }
    else {
        printf("Employee with ID 00000003 not found.\n");
    }

    return 0;
}