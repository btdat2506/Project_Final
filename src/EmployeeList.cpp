#include "main.h"

void init(EmployeeList* list) {
    list->head = NULL;
}

void swap(Employee* a, Employee* b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

Node* partition(Node* low, Node* high) {
    Employee pivot = high->emp;
    Node* i = low->prev;
    for (Node* j = low; j != high; j = j->next) {
        if (j->emp.net_salary < pivot.net_salary) {
            i = (i == NULL) ? low : i->next;
            swap(&(i->emp), &(j->emp));
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(&(i->emp), &(high->emp));
    return i;
}

/* void quickSort(Node* low, Node* high) {
    if (low == NULL || high == NULL || low == high || low == high->next) {
        return;
    }
    Node* pivot = partition(low, high);
    quickSort(low, pivot->prev);
    quickSort(pivot->next, high);
} */

void quickSort(Node* low, Node* high) {
    if (low == NULL || high == NULL || low == high || low == high->next) {
        return;
    }
    Node* l = low;
    Node* h = high;
    queue<Node*> queue;
    queue.push(l);
    queue.push(h);
    while (!queue.empty()) {
        l = queue.front();
        queue.pop();
        h = queue.front();
        queue.pop();

        if (l == NULL || h == NULL || l == h || l == h->next)
            continue;

        Node* p = partition(l, h);
        if (p->prev != NULL && p->prev != l) {
            queue.push(l);
            queue.push(p->prev);
        }
        if (p->next != NULL && p->next != h) {
            queue.push(p->next);
            queue.push(h);
        }
    }
}

void sortEmployees(EmployeeList* list) {
    Node* last = list->head;
    while (last != NULL && last->next != NULL) {
        last = last->next;
    }
    quickSort(list->head, last);
}

void addHead_Employee(EmployeeList* list, Employee emp) {
    Node* newNode = new Node;
    newNode->emp = emp;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void addTail_Employee(EmployeeList* list, Employee emp) {
    Node* newNode = new Node;
    newNode->emp = emp;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
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
                curr->next->prev = prev;
                prev->next = curr->next;
            }
            free(&(curr->emp));
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
        if (strcmp(curr->emp.id, id) == 0)
            return &curr->emp;
        curr = curr->next;
    }
    return NULL;
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

void calculateNetSalary(Employee* emp) {
    emp->net_salary = emp->base_salary;
    if (emp->num_children > 2) {
        emp->net_salary += emp->base_salary * 0.05;
    }
    if (strcmp(emp->education_level, "CH") == 0) {
        emp->net_salary += emp->base_salary * 0.1;
    }
    emp->net_salary += emp->num_overtime_days * emp->base_salary * 0.04;
    emp->net_salary = min(emp->net_salary, 2000000);
}

void calculateAllNetSalaries(EmployeeList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        calculateNetSalary(&(curr->emp));
        curr = curr->next;
    }
}