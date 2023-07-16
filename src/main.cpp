#include "main.h"

int main() {
    EmployeeList list;
    init(&list);
    
    if (import_employee_details_from_csv(&list, "employee_details_export.csv")) {
        printf("Employee details imported from file.\n");
    } else {
        printf("Failed to import employee details from file.\n");
    }
    
    int choice = 0;

    choice = 0;
    while (choice != 8) {
        printf("1. Add employee\n");
        printf("2. Remove employee\n");
        printf("3. Find employee\n");
        printf("4. Recalculate net salaries\n");
        printf("5. Sort employees by net salary\n");
        printf("6.  \n");
        printf("7. Print employee table\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Employee emp;
                bool valid = addEmployeeUI(&list, emp);
                if (valid) addEmployee(&list, emp);
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
                break;
            }
            case 7: {
                printEmployeeTable(&list);
                break;
            }
            case 8: {
                printf("Quitting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
        export_employee_details_to_csv(&list, "employee_details_export.csv");
    }
    return 0;
}