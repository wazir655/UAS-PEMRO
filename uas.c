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
