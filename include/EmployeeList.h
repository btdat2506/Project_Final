#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include "main.h"

#define MAX_ID_LEN 8
#define MAX_NAME_LEN 20

typedef struct {
    char id[MAX_ID_LEN + 1];
    char name[MAX_NAME_LEN + 3];
    char hon_nhan_status;
    int  so_con;
    char trinh_do_vh[3];
    int  luong_can_ban;
    char nghi_co_phep,
         nghi_khong_phep,
         so_ngay_OT;
    char kq_cong_viec[3];
    int  luong_thuc_linh;
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
void addHead_Employee(EmployeeList* list, Employee emp);
void addTail_Employee(EmployeeList* list, Employee emp);
bool removeEmployee(EmployeeList* list, char* id);
Employee* findEmployee(EmployeeList* list, char* id);
void printEmployee(Employee* emp);
void printAllEmployees(EmployeeList* list);
void calculateNetSalary(Employee* emp);
void calculateAllNetSalaries(EmployeeList* list);

#endif // EMPLOYEE_LIST_H
