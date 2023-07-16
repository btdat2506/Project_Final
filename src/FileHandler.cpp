#include "main.h"

bool import_employee_details_from_csv(EmployeeList* list, const char* file_path) {
    FILE* fp = fopen(file_path, "r");
    while (fp == NULL) {
        printf("Failed to open input file. Do you want to create a new file? (y/n) ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
            fp = fopen(file_path, "w");
            if (fp == NULL) {
                printf("Failed to create new file. Exiting program.\n");
                return false;
            }
            fclose(fp);
            return true;
        } else {
            printf("Exiting program.\n");
            return false;
        }
    }

    char line[1000];
    fgets(line, 1000, fp); // skip the header line
    while (fgets(line, 1000, fp)) {
        Employee emp;
        sscanf(line, "%[^,],%[^,],%c,%d,%[^,],%d,%hhd,%hhd,%hhd,%[^,],%d\n",
            emp.id, emp.name, &emp.marital_status, &emp.num_children,
            emp.education_level, &emp.base_salary, &emp.num_sick_days,
            &emp.num_unpaid_days, &emp.num_overtime_days, emp.job_performance,
            &emp.net_salary);
        addEmployee(list, emp);
    }

    fclose(fp);
    return true;
}

void export_employee_details_to_csv(EmployeeList* list, const char* file_path) {
    FILE* csv_file = fopen(file_path, "w");

    fprintf(csv_file, "ID,Name,Marital Status,Number of Children,Education Level,Base Salary,Number of Sick Days,Number of Unpaid Days,Number of Overtime Days,Job Performance,Net Salary\n");
    Node* curr = list->head;
    while (curr != NULL) {
        fprintf(csv_file, "%s,%s,%c,%d,%s,%d,%hhd,%hhd,%hhd,%s,%d\n",
            curr->emp.id, curr->emp.name, curr->emp.marital_status, curr->emp.num_children,
            curr->emp.education_level, curr->emp.base_salary, curr->emp.num_sick_days,
            curr->emp.num_unpaid_days, curr->emp.num_overtime_days, curr->emp.job_performance,
            curr->emp.net_salary);
        curr = curr->next;
    }

    fclose(csv_file);
}