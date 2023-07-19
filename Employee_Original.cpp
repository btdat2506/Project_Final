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

void saveEmployees(EmployeeList* list) {
    FILE* fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    Node* curr = list->head;
    while (curr != NULL) {
        fprintf(fp, "%s %s %c %d %s %d %hhd %hhd %hhd %s %d\n",
                curr->emp.id, curr->emp.name, curr->emp.hon_nhan_status,
                curr->emp.so_con, curr->emp.trinh_do_vh,
                curr->emp.luong_can_ban, curr->emp.nghi_co_phep,
                curr->emp.nghi_khong_phep, curr->emp.so_ngay_OT,
                curr->emp.kq_cong_viec, curr->emp.luong_thuc_linh);
        curr = curr->next;
    }

    fclose(fp);
}

void flush_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard character
    }
}

int main() {
    EmployeeList list;
    init(&list);

    FILE* fp = fopen("employees.txt", "r");
    while (fp == NULL) {
        printf("Failed to open input file. Do you want to create a new file? (y/n) ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
            fp = fopen("employees.txt", "w");
            if (fp == NULL) {
                printf("Failed to create new file. Exiting program.\n");
                return 1;
            }
        } else {
            printf("Exiting program.\n");
            return 1;
        }
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        Employee emp;
        sscanf(line, "%s %s %c %d %s %d %hhd %hhd %hhd %s",
            emp.id, emp.name, &emp.hon_nhan_status, &emp.so_con,
            emp.trinh_do_vh, &emp.luong_can_ban, &emp.nghi_co_phep,
            &emp.nghi_khong_phep, &emp.so_ngay_OT, emp.kq_cong_viec);
        emp.luong_thuc_linh = 0;
        addEmployee(&list, emp);
    }

    fclose(fp);

    int choice = 0;
    while (choice != 6) {
        printf("1. Add employee\n");
        printf("2. Remove employee\n");
        printf("3. Find employee\n");
        printf("4. Calculate net salaries\n");
        printf("5. Sort employees by net salary\n");
        printf("6. Quit\n");
        printf("Enter lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Employee emp;
                printf("Nhap ID nhan vien: ");
                scanf("%s", emp.id);
                flush_input();
                printf("Enter employee name: ");
                fgets(emp.name, sizeof(emp.name), stdin);
                emp.name[strcspn(emp.name, "\n")] = '\0'; // remove the newline character at the end
                printf("Enter employee marital status (M/S): ");
                scanf(" %c", &emp.hon_nhan_status);
                flush_input();
                printf("Enter number of children: ");
                scanf("%d", &emp.so_con);
                flush_input();
                printf("Enter education level (CH/ĐH/CĐ): ");
                scanf("%s", emp.trinh_do_vh);
                flush_input();
                printf("Enter base salary: ");
                scanf("%d", &emp.luong_can_ban);
                flush_input();
                printf("Enter number of sick days: ");
                scanf("%hhd", &emp.nghi_co_phep);
                flush_input();
                printf("Nhap so ngay nghi khong phep: ");
                scanf("%hhd", &emp.nghi_khong_phep);
                flush_input();
                printf("Nhap so ngay tang ca: ");
                scanf("%hhd", &emp.so_ngay_OT);
                flush_input();
                printf("Enter job performance (K/TB/G/KX): ");
                scanf("%s", emp.kq_cong_viec);
                flush_input();
                emp.luong_thuc_linh = 0;
                addEmployee(&list, emp);
                break;
            }
            case 2: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien to remove: ");
                scanf("%s", id);
                removeEmployee(&list, id);
                break;
            }
            case 3: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien to find: ");
                scanf("%s", id);
                Employee* emp = findEmployee(&list, id);
                if (emp != NULL) {
                    printf("Employee found:\n");
                    printEmployee(emp);
                }
                else {
                    printf("Employee not found.\n");
                }
                break;
            }
            case 4: {
                calculateAllNetSalaries(&list);
                printf("Net salaries calculated.\n");
                break;
            }
            case 5: {
                sortEmployees(&list);
                printf("Employees sorted by net salary.\n");
                break;
            }
            case 6: {
                printf("Quitting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
        saveEmployees(&list);
    }

    return 0;
}