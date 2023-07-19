#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "main.h"

bool import_CSDL(EmployeeList* list, const char* file_path);
void export_CSDL(EmployeeList* list, const char* file_path);

#endif // FILE_HANDLER_H
