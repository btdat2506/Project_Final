#include "main.h"
//#include <windows.h>

int main() {
    //SetConsoleOutputCP(CP_UTF8);

    EmployeeList list;
    init(&list);

    const char* file_path = "employee_details_export.csv";
    
    if (import_CSDL(&list, file_path)) {
        printf("CSDL nhan vien da duoc import thanh cong.\n");
    } else {
        printf("Khong import duoc CSDL.\n");
    }
    
    int choice = 0;
    while (choice != 9) {
        printf("\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Tim nhan vien bang ID\n");
        printf("4. Cap nhat ly lich cua nhan vien\n");
        printf("5. Cap nhat thong tin cham cong cua nhan vien\n");
        printf("6. Cap nhat luong thuc linh cua toan bo nhan vien\n");
        printf("7. Sap xep luong nhan vien tang dan\n");
        printf("8. In thong tin nhan vien\n");
        printf("9. Exit\n");
        printf("Nhap vao lua chon: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: {
                Employee emp;
                bool valid = addEmployeeUI(&list, emp);
                if (valid) addHead_Employee(&list, emp);
                break;
            }
            case 2: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien can xoa: ");
                scanf("%s", id);
                bool success = removeEmployee(&list, id);
                if (success) {
                    printf("Xoa nhan vien ID %s thanh cong.\n", id);
                }
                else {
                    printf("Xoa nhan vien ID %s khong thanh cong.\n", id);
                }
                break;
            }
            case 3: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien can tim: ");
                scanf("%s", id);
                Employee* emp = findEmployee(&list, id);
                if (emp != NULL) {
                    printf("Da tim thay nhan vien:\n");
                    printEmployee(emp);
                }
                else {
                    printf("Nhan vien khong tim thay.\n");
                }
                break;
            }
            case 4: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien can cap nhat ly lich: ");
                scanf("%s", id);
                updateEmployeeInfoUI(&list, id);
                break;
            }
            case 5: {
                char id[MAX_ID_LEN + 1];
                printf("Nhap ID nhan vien can cap nhat thong tin cham cong: ");
                scanf("%s", id);
                updateEmployeeWorkInfoUI(&list, id);
                break;
            }
            case 6: {
                calculateAllNetSalaries(&list);
                printf("Cap nhat luong thuc linh cua toan bo nhan vien thanh cong.\n");
                break;
            }
            case 7: {
                sortEmployees(&list);
                printf("Sap xep luong nhan vien tang dan thanh cong.\n");
                break;
            }
            case 8: {
                printEmployeeTable(&list);
                break;
            }
            case 9: {
                printf("Thoat chuong trinh...\n");
                break;
            }
            default: {
                printf("Vui long nhap lai.\n");
                break;
            }
        }
        export_CSDL(&list, file_path);
    }
    return 0;
}