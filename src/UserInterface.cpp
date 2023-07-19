#include "main.h"

void flush_input()
{
    /* // Suitable for using on Linux
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard character
    } */ 
    fflush(stdin); //Suitable for using on Windows
}

void printEmployeeTable(EmployeeList* list) {
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");
    printf("| ID       | Ten                  | M/S | #C | VH | Trinh do | CP | KP | OT | KQ | Thuc linh |\n");
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");

    Node* curr = list->head;
    while (curr != NULL) {
        printf("| %-8s | %-20s | %-3c | %-2d | %-3s| %-9d| %-3d| %-3d| %-3d| %-3s| %-10d|\n",
            curr->emp.id, curr->emp.name, curr->emp.hon_nhan_status, curr->emp.so_con,
            curr->emp.trinh_do_vh, curr->emp.luong_can_ban, curr->emp.nghi_co_phep,
            curr->emp.nghi_khong_phep, curr->emp.so_ngay_OT, curr->emp.kq_cong_viec,
            curr->emp.luong_thuc_linh);
        curr = curr->next;
    }
    printf("+----------+----------------------+-----+----+----+----------+----+----+----+----+-----------+\n");
}

bool addEmployeeUI(EmployeeList* list, Employee &emp)
{
    printf("Nhap ID nhan vien (8 ki tu): ");
    while (true)
    {
        if (scanf("%s", emp.id) == 1 && strlen(emp.id) <= 8) {
            if (findEmployee(list, emp.id) != NULL) {
                printf("ID nhan vien %s da ton tai. Xin vui long nhap ID khac: ", emp.id);
            }
            else {
                break;
            }
        }
        else {
            printf("Nhap sai. Vui long nhap ID nhan vien (8 ki tu): ");
        }
        flush_input();
    }
    flush_input();
    printf("Nhap ten nhan vien (toi da 20 ki tu): ");
    while (true)
    {
        if (fgets(emp.name, sizeof(emp.name), stdin) != NULL)
        {
            flush_input();
            emp.name[strcspn(emp.name, "\n")] = '\0'; // remove the newline character at the end
            if (strlen(emp.name) <= 20 && emp.name != NULL && emp.name[0] != '\0') 
                break;
        }
        printf("Nhap sai. Vui long nhap ten nhan vien (8 ki tu): ");
    }
    flush_input();
    printf("Nhap tinh trang hon nhan cua nhan vien (M/S): ");
    while (scanf("%c", &emp.hon_nhan_status) != 1 || (emp.hon_nhan_status != 'M' && emp.hon_nhan_status != 'S')) {
        printf("Nhap sai. Vui long nhap tinh trang hon nhan (M/S):");
        flush_input();
    }
    flush_input();
    printf("Nhap vao so con (toi da 20):");
    while (scanf("%d", &emp.so_con) != 1 || emp.so_con < 0 || emp.so_con > 20) {
        printf("Nhap sai. Vui long nhap vao so con (toi da 20):");
        flush_input();
    }
    flush_input();
    printf("Nhap trinh do giao duc (CH/DH/CD): ");
    while (scanf("%2s", emp.trinh_do_vh) != 1 || (strcmp(emp.trinh_do_vh, "CH") != 0 && strcmp(emp.trinh_do_vh, "DH") != 0 && strcmp(emp.trinh_do_vh, "CD") != 0)) {
        printf("Nhap sai. Vui long nhap trinh do giao duc (CH/DH/CD): ");
        flush_input();
    }
    flush_input();
    printf("Nhap vao muc luong co ban (toi da 1000000): ");
    while (scanf("%d", &emp.luong_can_ban) != 1 || emp.luong_can_ban < 0 || emp.luong_can_ban > 1000000) {
        printf("Nhap sai. Vui long nhap muc luong co ban (toi da 1000000): ");
        flush_input();
    }
    flush_input();
    printf("Nhap so ngay nghi co phep (toi da 28): ");
    while (scanf("%hhd", &emp.nghi_co_phep) != 1 || emp.nghi_co_phep < 0 || emp.nghi_co_phep > 28) {
        printf("Nhap sai. Vui long nhap so ngay nghi co phep (toi da 28): ");
        flush_input();
    }
    flush_input();
    printf("Nhap so ngay nghi khong phep (toi da 28): ");
    while (scanf("%hhd", &emp.nghi_khong_phep) != 1 || emp.nghi_khong_phep < 0 || emp.nghi_khong_phep > 28) {
        printf("Nhap sai. Vui long nhap so ngay nghi khong phep (toi da 28): ");
        flush_input();
    }
    flush_input();
    printf("Nhap so ngay tang ca (toi da 28): ");
    while (scanf("%hhd", &emp.so_ngay_OT) != 1 || emp.so_ngay_OT < 0 || emp.so_ngay_OT > 28) {
        printf("Nhap sai. Vui long nhap so ngay tang ca (toi da 28): ");
        flush_input();
    }
    flush_input();
    printf("Nhap ket qua cong viec (T/TB/K): ");
    while (scanf("%2s", emp.kq_cong_viec) != 1 || (strcmp(emp.kq_cong_viec, "T") != 0 && strcmp(emp.kq_cong_viec, "TB") != 0 && strcmp(emp.kq_cong_viec, "K") != 0)) {
        printf("Nhap sai. Vui long nhap ket qua cong viec (T/TB/K): ");
        flush_input();
    }
    flush_input();
    emp.luong_thuc_linh = 0;
    printf("Vui long xac nhan thong tin sau:\n");
    printEmployee(&emp);
    printf("Thong tin co chinh xac khong? (Y/N): ");
    char choice;
    while (true)
    {
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y') {
            calculateNetSalary(&emp);
            printf("Them nhan vien thanh cong.\n");
            return true;
        }
        else 
        if (choice == 'N' || choice == 'n') {
            printf("Them nhan vien khong thanh cong.\n");
            return false;
        }
        else {
            printf("Nhap sai. Vui long nhap Y/N: ");
            flush_input();
            continue;
        }
    }
}

bool updateEmployeeInfoUI(EmployeeList* list, char* id) {
    Employee* emp = findEmployee(list, id);
    if (emp == NULL) {
        printf("Khong tim thay nhan vien voi ID %s.\n", id);
        return false;
    }

    printf("Thong tin ly lich nao can cap nhat?\n");
    printf("1. Ten\n");
    printf("2. Tinh trang hon nha\n");
    printf("3. So con\n");
    printf("4. Trinh do giao duc\n");
    printf("5. Luong co ban\n");
    printf("6. Toan bo\n");
    printf("Nhap vao lua chon (1-6): ");
    int choice;
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
        printf("Nhap sai. Vui long nhap lua chon (1-6): ");
        flush_input();
    }
    flush_input();

    bool updated = false;
    if (choice == 1 || choice == 6) {
        printf("Nhap ten moi cua nhan vien (toi da 20 ki tu): ");
        while (true) {
            if (fgets(emp->name, sizeof(emp->name), stdin) != NULL) {
                emp->name[strcspn(emp->name, "\n")] = '\0'; // remove the newline character at the end
                if (strlen(emp->name) <= 20 && emp->name != NULL && emp->name[0] != '\0')
                    break;
            }
            printf("Nhap sai. Vui long nhap ten moi cua nhan vien (8 ki tu): ");
        }
        updated = true;
    }
    else
    if (choice == 2 || choice == 6) {
        printf("Nhap tinh trang hon nhan cua nhan vien (M/S): ");
        while (scanf("%c", &emp->hon_nhan_status) != 1 || (emp->hon_nhan_status != 'M' && emp->hon_nhan_status != 'S')) {
            printf("Nhap sai. Vui long nhap tinh trang hon nhan (M/S):");
            flush_input();
        }
        flush_input();
        updated = true;
    }
    else
    if (choice == 3 || choice == 6) {
        printf("Nhap vao so con (toi da 20):");
        while (scanf("%d", &emp->so_con) != 1 || emp->so_con < 0 || emp->so_con > 20) {
            printf("Nhap sai. Vui long nhap vao so con (toi da 20):");
            flush_input();
        }
        flush_input();
        updated = true;
    }
    else
    if (choice == 4 || choice == 6) {
        printf("Nhap trinh do giao duc (CH/DH/CD): ");
        while (scanf("%2s", emp->trinh_do_vh) != 1 || (strcmp(emp->trinh_do_vh, "CH") != 0 && strcmp(emp->trinh_do_vh, "DH") != 0 && strcmp(emp->trinh_do_vh, "CD") != 0)) {
            printf("Nhap sai. Vui long nhap trinh do giao duc (CH/DH/CD): ");
            flush_input();
        }
        flush_input();
        updated = true;
    }
    else
    if (choice == 5 || choice == 6) {
        printf("Nhap vao muc luong co ban (toi da 1000000): ");
        while (scanf("%d", &emp->luong_can_ban) != 1 || emp->luong_can_ban < 0 || emp->luong_can_ban > 1000000) {
            printf("Nhap sai. Vui long nhap muc luong co ban (toi da 1000000): ");
            flush_input();
        }
        flush_input();
        updated = true;
    }

    if (updated) {
        printf("Vui long xac nhan thong tin sau:\n");
        printEmployee(emp);
        printf("Thong tin co chinh xac khong? (Y/N): ");
        char choice;
        while (true) {
            scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y') {
                calculateNetSalary(emp);
                printf("Ly lich nhan vien cap nhat thanh cong.\n");
                return true;
            }
            else if (choice == 'N' || choice == 'n') {
                printf("Ly lich nhan vien khong cap nhat thanh cong.\n");
                return false;
            }
            else {
                printf("Nhap sai. Vui long nhap Y/N: ");
                flush_input();
                continue;
            }
        }
    }
    else {
        printf("Khong co thong tin nao duoc cap nhat.\n");
        return false;
    }
}

bool updateEmployeeWorkInfoUI(EmployeeList* list, char* id) {
    Employee* emp = findEmployee(list, id);
    if (emp == NULL) {
        printf("Khong tim thay nhan vien co ID %s.\n", id);
        return false;
    }

    printf("Thong tin lam viec nao cua nhan vien can duoc cap nhat?\n");
    printf("1. Ket qua cong viec\n");
    printf("2. So ngay nghi co phep\n");
    printf("3. So ngay nghi khong phep\n");
    printf("4. So ngay tang ca\n");
    printf("5. Toan bo\n");
    printf("Nhap lua chon (1-5): ");
    int choice;
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Nhap sai. Vui long nhap lua chon (1-5): ");
        flush_input();
    }
    flush_input();

    bool updated = false;
    if (choice == 1 || choice == 5) {
        printf("Nhap ket qua cong viec (T/TB/K): ");
        while (scanf("%2s", emp->kq_cong_viec) != 1 || (strcmp(emp->kq_cong_viec, "T") != 0 && strcmp(emp->kq_cong_viec, "TB") != 0 && strcmp(emp->kq_cong_viec, "K") != 0)) {
            printf("Nhap sai. Vui long nhap ket qua cong viec (T/TB/K): ");
            flush_input();
        }
        updated = true;
    }
    if (choice == 2 || choice == 5) {
        printf("Nhap so ngay nghi co phep (toi da 20): ");
        while (scanf("%d", &emp->nghi_co_phep) != 1 || emp->nghi_co_phep < 0 || emp->nghi_co_phep > 20) {
            printf("Nhap sai. Vui long nhap so ngay nghi co phep (toi da 20): ");
            flush_input();
        }
        flush_input();
        updated = true;
    }
    if (choice == 3 || choice == 5) {
        printf("Nhap so ngay nghi khong phep (toi da 20): ");
        while (scanf("%d", &emp->nghi_khong_phep) != 1 || emp->nghi_khong_phep < 0 || emp->nghi_khong_phep > 20) {
            printf("Nhap sai. Vui long nhap so ngay nghi khong phep (toi da 20): ");
            flush_input();
        }
        flush_input();
        updated = true;
    }
    if (choice == 4 || choice == 5) {
        printf("Nhap so ngay tang ca (toi da 20): ");
        while (scanf("%d", &emp->so_ngay_OT) != 1 || emp->so_ngay_OT < 0 || emp->so_ngay_OT > 20) {
            printf("Nhap sai. Vui long nhap so ngay tang ca (toi da 20): ");
            flush_input();
        }
        flush_input();
        updated = true;
    }

    if (updated) {
        printf("Vui long xac nhan thong tin sau:\n");
        printEmployee(emp);
        printf("Thong tin co chinh xac khong? (Y/N): ");
        char choice;
        while (true) {
            scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y') {
                calculateNetSalary(emp);
                printf("Thong tin lam viec cua cap nhat thanh cong.\n");
                return true;
            }
            else if (choice == 'N' || choice == 'n') {
                printf("Thong tin lam viec cua nhan vien khong cap nhat thanh cong.\n");
                return false;
            }
            else {
                printf("Nhap sai. Vui long nhap Y/N: ");
                flush_input();
                continue;
            }
        }
    }
    else {
        printf("Khong co thong tin nao duoc cap nhat.\n");
        return false;
    }
}