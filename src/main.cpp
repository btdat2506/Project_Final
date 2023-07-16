#include "main.h"

int main() {
    EmployeeList list;
    init(&list);

    const char* file_path = "employee_details_export.csv";
    
    if (import_employee_details_from_csv(&list, file_path)) {
        printf("Employee details imported from file.\n");
    } else {
        printf("Failed to import employee details from file.\n");
    }
    
    int choice = 0;
    while (choice != 9) {
        printf("1. Add employee\n");
        printf("2. Remove employee\n");
        printf("3. Find employee by ID\n");
        printf("4. Update employee information\n");
        printf("5. Update employee work information\n");
        printf("6. Update all employee net salaries\n");
        printf("7. Sort employees by net salary\n");
        printf("8. Print employee table\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Employee emp;
                bool valid = addEmployeeUI(&list, emp);
                if (valid) addHead_Employee(&list, emp);
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
                char id[MAX_ID_LEN + 1];
                printf("Enter employee ID to update: ");
                scanf("%s", id);
                bool updated = updateEmployeeInfoUI(&list, id);
                if (updated) {
                    printf("Employee information updated.\n");
                }
                else {
                    printf("Employee information not updated.\n");
                }
                break;
            }
            case 5: {
                char id[MAX_ID_LEN + 1];
                printf("Enter employee ID to update work information: ");
                scanf("%s", id);
                bool updated = updateEmployeeWorkInfoUI(&list, id);
                if (updated) {
                    printf("Employee work information updated.\n");
                }
                else {
                    printf("Employee work information not updated.\n");
                }
                break;
            }
            case 6: {
                calculateAllNetSalaries(&list);
                printf("All employee net salaries updated.\n");
                break;
            }
            case 7: {
                sortEmployees(&list);
                printf("Employees sorted by net salary.\n");
                break;
            }
            case 8: {
                printEmployeeTable(&list);
                break;
            }
            case 9: {
                printf("Quitting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
        export_employee_details_to_csv(&list, file_path);
    }
    return 0;
}