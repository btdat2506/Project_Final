#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "main.h"

void import_employee_details_from_csv(EmployeeList* list, const char* file_path);
void export_employee_details_to_csv(EmployeeList* list, const char* file_path);

#endif // FILE_HANDLER_H
