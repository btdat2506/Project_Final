#include "main.h"

bool import_CSDL(EmployeeList* list, const char* file_path) {
    FILE* fp = fopen(file_path, "r");
    while (fp == NULL) {
        printf("Khong the mo file CSDl. Co muon tao file CSDL moi? (y/n) ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
            fp = fopen(file_path, "w");
            if (fp == NULL) {
                printf("Error: Khong the tao file. Thoat chuong trinh...\n");
                return false;
            }
            fclose(fp);
            return true;
        } else {
            printf("Thoat chuong trinh.\n");
            return false;
        }
    }

    char line[1000];
    fgets(line, 1000, fp); // bỏ qua header
    while (fgets(line, 1000, fp)) {
        Employee emp;
        sscanf(line, "%[^,],%[^,],%c,%d,%[^,],%d,%hhd,%hhd,%hhd,%[^,],%d\n",
            emp.id, emp.name, &emp.hon_nhan_status, &emp.so_con,
            emp.trinh_do_vh, &emp.luong_can_ban, &emp.nghi_co_phep,
            &emp.nghi_khong_phep, &emp.so_ngay_OT, emp.kq_cong_viec,
            &emp.luong_thuc_linh);
        addTail_Employee(list, emp);
    }

    fclose(fp);
    return true;
}

void export_CSDL(EmployeeList* list, const char* file_path) {
    FILE* csv_file = fopen(file_path, "w");
    if (csv_file == NULL) {
        printf("Error: Khong the luu file %s\n", file_path);
        return;
    }

    fprintf(csv_file, "ID,Name,Tinh trang hon nhan,So con,Trinh do giao duc,Luong can ban,So ngay nghi co phep,So ngay nghi khong phep,So ngay tang ca,Ket qua cong viec,Luong thuc linh\n");
    Node* curr = list->head;
    while (curr != NULL) {
        fprintf(csv_file, "%s,%s,%c,%d,%s,%d,%hhd,%hhd,%hhd,%s,%d\n",
            curr->emp.id, curr->emp.name, curr->emp.hon_nhan_status, curr->emp.so_con,
            curr->emp.trinh_do_vh, curr->emp.luong_can_ban, curr->emp.nghi_co_phep,
            curr->emp.nghi_khong_phep, curr->emp.so_ngay_OT, curr->emp.kq_cong_viec,
            curr->emp.luong_thuc_linh);
        curr = curr->next;
    }

    fclose(csv_file);
}