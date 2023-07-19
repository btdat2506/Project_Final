#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 8
#define MAX_NAME_LEN 20

typedef struct {
    char id[MAX_ID_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    char hon_nhan_status;
    int so_con;
    char trinh_do_vh[3];
    int luong_can_ban;
    char nghi_co_phep,
         nghi_khong_phep,
         so_ngay_OT;
    char kq_cong_viec[3];
    int luong_thuc_linh;
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
    emp->luong_thuc_linh = emp->luong_can_ban;
    if (emp->so_con > 2) {
        emp->luong_thuc_linh += emp->luong_can_ban * 0.05;
    }
    if (strcmp(emp->trinh_do_vh, "CH") == 0) {
        emp->luong_thuc_linh += emp->luong_can_ban * 0.1;
    }
    emp->luong_thuc_linh += emp->so_ngay_OT * emp->luong_can_ban * 0.04;
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
    printf("Marital Status: %c\n", emp->hon_nhan_status);
    printf("Number of Children: %d\n", emp->so_con);
    printf("Education Level: %s\n", emp->trinh_do_vh);
    printf("Base Salary: %d\n", emp->luong_can_ban);
    printf("Number of Sick Days: %d\n", emp->nghi_co_phep);
    printf("Number of Unpaid Days: %d\n", emp->nghi_khong_phep);
    printf("Number of Overtime Days: %d\n", emp->so_ngay_OT);
    printf("Job Performance: %s\n", emp->kq_cong_viec);
    printf("Net Salary: %d\n", emp->luong_thuc_linh);
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
        if (j->emp.luong_thuc_linh < pivot.luong_thuc_linh) {
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