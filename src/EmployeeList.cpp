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
        if (j->emp.luong_thuc_linh < pivot.luong_thuc_linh) {
            i = (i == NULL) ? low : i->next;
            swap(&(i->emp), &(j->emp));
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(&(i->emp), &(high->emp));
    return i;
}

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
/*    Node* last = list->head;
    while (last != NULL && last->next != NULL) {
        last = last->next;
    } */
    quickSort(list->head, list->tail);
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

bool removeEmployee(EmployeeList* list, char* id) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->emp.id, id) == 0) {
            if (prev == NULL) {
                list->head = curr->next;
            }
            else 
            if (curr->next == NULL) {
                list->tail = curr->prev;
                curr->prev->next = NULL;
            }
            else
            {
                curr->next->prev = prev;
                prev->next = curr->next;
            }
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
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
    printf("Ten: %s\n", emp->name);
    printf("Tinh trang hon nhan: %c\n", emp->hon_nhan_status);
    printf("So con: %d\n", emp->so_con);
    printf("Trinh do giao duc: %s\n", emp->trinh_do_vh);
    printf("Luong can ban: %d\n", emp->luong_can_ban);
    printf("So ngay nghi co phep: %d\n", emp->nghi_co_phep);
    printf("So ngay nghi khong phep: %d\n", emp->nghi_khong_phep);
    printf("So ngay tang ca: %d\n", emp->so_ngay_OT);
    printf("Ket qua cong viec: %s\n", emp->kq_cong_viec);
    printf("Luong thuc linh: %d\n", emp->luong_thuc_linh);
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
    emp->luong_thuc_linh = emp->luong_can_ban;
    if (emp->so_con > 2) {
        emp->luong_thuc_linh += emp->luong_can_ban * 0.05;
    }
    if (strcmp(emp->trinh_do_vh, "CH") == 0) {
        emp->luong_thuc_linh += emp->luong_can_ban * 0.1;
    }
    emp->luong_thuc_linh += emp->so_ngay_OT * emp->luong_can_ban * 0.04;
    emp->luong_thuc_linh = max(emp->luong_thuc_linh, 0);
    emp->luong_thuc_linh = min(emp->luong_thuc_linh, 2000000);
}

void calculateAllNetSalaries(EmployeeList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        calculateNetSalary(&(curr->emp));
        curr = curr->next;
    }
}