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

void saveEmployees(EmployeeList* list) {
    FILE* fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    Node* curr = list->head;
    while (curr != NULL) {
        fprintf(fp, "%s %s %c %d %s %d %hhd %hhd %hhd %s %d\n",
                curr->emp.id, curr->emp.name, curr->emp.marital_status,
                curr->emp.num_children, curr->emp.education_level,
                curr->emp.base_salary, curr->emp.num_sick_days,
                curr->emp.num_unpaid_days, curr->emp.num_overtime_days,
                curr->emp.job_performance, curr->emp.net_salary);
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
            emp.id, emp.name, &emp.marital_status, &emp.num_children,
            emp.education_level, &emp.base_salary, &emp.num_sick_days,
            &emp.num_unpaid_days, &emp.num_overtime_days, emp.job_performance);
        emp.net_salary = 0;
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
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Employee emp;
                printf("Enter employee ID: ");
                scanf("%s", emp.id);
                flush_input();
                printf("Enter employee name: ");
                fgets(emp.name, sizeof(emp.name), stdin);
                emp.name[strcspn(emp.name, "\n")] = '\0'; // remove the newline character at the end
                printf("Enter employee marital status (M/S): ");
                scanf(" %c", &emp.marital_status);
                flush_input();
                printf("Enter number of children: ");
                scanf("%d", &emp.num_children);
                flush_input();
                printf("Enter education level (CH/ĐH/CĐ): ");
                scanf("%s", emp.education_level);
                flush_input();
                printf("Enter base salary: ");
                scanf("%d", &emp.base_salary);
                flush_input();
                printf("Enter number of sick days: ");
                scanf("%hhd", &emp.num_sick_days);
                flush_input();
                printf("Enter number of unpaid days: ");
                scanf("%hhd", &emp.num_unpaid_days);
                flush_input();
                printf("Enter number of overtime days: ");
                scanf("%hhd", &emp.num_overtime_days);
                flush_input();
                printf("Enter job performance (K/TB/G/KX): ");
                scanf("%s", emp.job_performance);
                flush_input();
                emp.net_salary = 0;
                addEmployee(&list, emp);
                break;
            }
            case 2: {
                char id[MAX_ID_LEN + 1];
                printf("Enter employee ID to remove: ");
                scanf("%s", id);
                removeEmployee(&list, id);
                break;
            }
            case 3: {
                char id[MAX_ID_LEN + 1];
                printf("Enter employee ID to find: ");
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