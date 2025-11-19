#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
} Alat;

typedef struct {
    char username[50];
    char password[50];
    char role[10];
} Akun;

Akun loginUser;

int login();
void menuAdmin();
void menuUser();
void lihatAlat();
void tambahAlat();
void editAlat();
void hapusAlat();
void pinjamAlat();
void lihatPinjaman();
void kembalikanAlat();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Cara penggunaan: %s <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(loginUser.username, argv[1]);
    strcpy(loginUser.password, argv[2]);

    if (login() == 1) {
        if (strcmp(loginUser.role, "admin") == 0) {
            menuAdmin();
        } else if (strcmp(loginUser.role, "user") == 0) {
            menuUser();
        }
    } else {
        printf("Login gagal. Periksa username dan password.\n");
    }

    return 0;
}

int login() {
    FILE *fp = fopen("akun.txt", "r");
    if (!fp) {
        printf("File akun.txt tidak ditemukan!\n");
        return 0;
    }

    Akun a;
    while (fscanf(fp, "%s %s %s", a.username, a.password, a.role) != EOF) {
        if (strcmp(a.username, loginUser.username) == 0 && strcmp(a.password, loginUser.password) == 0) {
            strcpy(loginUser.role, a.role);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void menuAdmin() {
    int pilih;
    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Lihat daftar alat\n");
        printf("2. Tambah alat\n");
        printf("3. Edit alat\n");
        printf("4. Hapus alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: lihatAlat(); break;
            case 2: tambahAlat(); break;
            case 3: editAlat(); break;
            case 4: hapusAlat(); break;
        }
    } while (pilih != 0);
}
