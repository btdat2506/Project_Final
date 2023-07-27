#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "main.h"

void flush_input();
void printEmployeeTable(EmployeeList* list);
bool addEmployeeUI(EmployeeList* list, Employee &emp);
void updateEmployeeInfoUI(EmployeeList* list, char* id);
void updateEmployeeWorkInfoUI(EmployeeList* list, char* id);
#endif // USER_INTERFACE_H
