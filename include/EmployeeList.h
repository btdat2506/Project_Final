#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include "main.h"

#define MAX_ID_LEN 8
#define MAX_NAME_LEN 20

typedef struct {
    char id[MAX_ID_LEN + 1];
    char name[MAX_NAME_LEN + 3];
    char marital_status;
    int  num_children;
    char education_level[3];
    int  base_salary;
    char num_sick_days,
         num_unpaid_days,
         num_overtime_days;
    char job_performance[3];
    int  net_salary;
} Employee;

typedef struct Node {
    Employee emp;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} EmployeeList;

void init(EmployeeList* list);
void sortEmployees(EmployeeList* list);
void addEmployee(EmployeeList* list, Employee emp);
void removeEmployee(EmployeeList* list, char* id);
Employee* findEmployee(EmployeeList* list, char* id);
void printEmployee(Employee* emp);
void printAllEmployees(EmployeeList* list);
void calculateNetSalary(Employee* emp);
void calculateAllNetSalaries(EmployeeList* list);

#endif // EMPLOYEE_LIST_H
