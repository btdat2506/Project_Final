#include "main.h"

void flush_input()
{
    /* // Suitable for using on Linux
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard character
    } */ 
    fflush(stdin); //Suitable for using on Windows
}

void printEmployeeTable(EmployeeList* list) {
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");
    printf("| ID       | Name                 | M/S | #C | EL | Base     | SD | UD | OT | JP | Net       |\n");
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");

    Node* curr = list->head;
    while (curr != NULL) {
        printf("| %-8s | %-20s | %-3c | %-2d | %-3s| %-9d| %-3d| %-3d| %-3d| %-3s| %-10d|\n",
            curr->emp.id, curr->emp.name, curr->emp.marital_status, curr->emp.num_children,
            curr->emp.education_level, curr->emp.base_salary, curr->emp.num_sick_days,
            curr->emp.num_unpaid_days, curr->emp.num_overtime_days, curr->emp.job_performance,
            curr->emp.net_salary);
        curr = curr->next;
    }
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");
}

bool addEmployeeUI(EmployeeList* list, Employee &emp)
{
    printf("Enter employee ID (8 characters): ");
    while (true)
    {
        if (scanf("%s", emp.id) == 1 && strlen(emp.id) <= 8) {
            if (findEmployee(list, emp.id) != NULL) {
                printf("Employee with ID %s already exists. Please enter a different ID: ", emp.id);
            }
            else {
                break;
            }
        }
        else {
            printf("Invalid input. Please enter employee ID (8 characters): ");
        }
        flush_input();
    }
    flush_input();
    printf("Enter employee name (up to 20 characters): ");
    while (true)
    {
        if (fgets(emp.name, sizeof(emp.name), stdin) != NULL)
        {
            flush_input();
            emp.name[strcspn(emp.name, "\n")] = '\0'; // remove the newline character at the end
            if (strlen(emp.name) <= 20 && emp.name != NULL && emp.name[0] != '\0') 
                break;
        }
        printf("Invalid input. Please enter employee name (up to 20 characters): ");
    }
    flush_input();
    printf("Enter employee marital status (M/S): ");
    while (scanf("%c", &emp.marital_status) != 1 || (emp.marital_status != 'M' && emp.marital_status != 'S')) {
        printf("Invalid input. Please enter employee marital status (M/S): ");
        flush_input();
    }
    flush_input();
    printf("Enter number of children (up to 20): ");
    while (scanf("%d", &emp.num_children) != 1 || emp.num_children < 0 || emp.num_children > 20) {
        printf("Invalid input. Please enter number of children (up to 20): ");
        flush_input();
    }
    flush_input();
    printf("Enter education level (CH/DH/CD): ");
    while (scanf("%2s", emp.education_level) != 1 || (strcmp(emp.education_level, "CH") != 0 && strcmp(emp.education_level, "DH") != 0 && strcmp(emp.education_level, "CD") != 0)) {
        printf("Invalid input. Please enter education level (CH/DH/CD): ");
        flush_input();
    }
    flush_input();
    printf("Enter base salary (up to 1000000): ");
    while (scanf("%d", &emp.base_salary) != 1 || emp.base_salary < 0 || emp.base_salary > 1000000) {
        printf("Invalid input. Please enter base salary (up to 1000000): ");
        flush_input();
    }
    flush_input();
    printf("Enter number of sick days (up to 28): ");
    while (scanf("%hhd", &emp.num_sick_days) != 1 || emp.num_sick_days < 0 || emp.num_sick_days > 28) {
        printf("Invalid input. Please enter number of sick days (up to 28): ");
        flush_input();
    }
    flush_input();
    printf("Enter number of unpaid days (up to 28): ");
    while (scanf("%hhd", &emp.num_unpaid_days) != 1 || emp.num_unpaid_days < 0 || emp.num_unpaid_days > 28) {
        printf("Invalid input. Please enter number of unpaid days (up to 28): ");
        flush_input();
    }
    flush_input();
    printf("Enter number of overtime days (up to 28): ");
    while (scanf("%hhd", &emp.num_overtime_days) != 1 || emp.num_overtime_days < 0 || emp.num_overtime_days > 28) {
        printf("Invalid input. Please enter number of overtime days (up to 28): ");
        flush_input();
    }
    flush_input();
    printf("Enter job performance (T/TB/K): ");
    while (scanf("%2s", emp.job_performance) != 1 || (strcmp(emp.job_performance, "T") != 0 && strcmp(emp.job_performance, "TB") != 0 && strcmp(emp.job_performance, "K") != 0)) {
        printf("Invalid input. Please enter job performance (T/TB/K): ");
        flush_input();
    }
    flush_input();
    emp.net_salary = 0;
    printf("Please verify the following information:\n");
    printEmployee(&emp);
    printf("Is this correct? (Y/N): ");
    char choice;
    while (true)
    {
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y') {
            calculateNetSalary(&emp);
            printf("Employee added.\n");
            return true;
        }
        else 
        if (choice == 'N' || choice == 'n') {
            printf("Employee not added.\n");
            return false;
        }
        else {
            printf("Invalid input. Please enter Y/N: ");
            flush_input();
            continue;
        }
    }
}