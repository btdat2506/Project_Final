#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "main.h"

void flush_input();
void printEmployeeTable(EmployeeList* list);
bool addEmployeeUI(EmployeeList* list, Employee &emp);

#endif // USER_INTERFACE_H
