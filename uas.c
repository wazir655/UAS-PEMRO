#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struktur data alat laboratorium
typedef struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
} Alat;

// Struktur data akun
typedef struct {
    char username[50];
    char password[50];
    char role[10];
} Akun;

Akun loginUser;

// --- Fungsi Prototipe ---
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

// --- FUNGSI UTAMA ---
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

// --- LOGIN ---
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

// --- MENU ADMIN ---
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

// --- MENU USER ---
void menuUser() {
    int pilih;
    do {
        printf("\n=== MENU USER ===\n");
        printf("1. Lihat alat tersedia\n");
        printf("2. Pinjam alat\n");
        printf("3. Lihat alat yang dipinjam\n");
        printf("4. Kembalikan alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: lihatAlat(); break;
            case 2: pinjamAlat(); break;
            case 3: lihatPinjaman(); break;
            case 4: kembalikanAlat(); break;
        }
    } while (pilih != 0);
}

// --- LIHAT ALAT ---
void lihatAlat() {
    FILE *fp = fopen("alat.txt", "r");
    if (!fp) {
        printf("File alat.txt tidak ditemukan!\n");
        return;
    }

    Alat a;
    printf("\nID | Nama | Merek | Model | Tahun | Jumlah\n");
    printf("-------------------------------------------\n");
    while (fscanf(fp, "%u, %49[^,], %49[^,], %49[^,], %u, %u\n", 
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {
        printf("%u | %s | %s | %s | %u | %u\n", a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }
    fclose(fp);
}

// --- TAMBAH ALAT ---
void tambahAlat() {
    FILE *fp = fopen("alat.txt", "a");
    Alat a;
    printf("Masukkan ID Alat: "); scanf("%u", &a.id);
    printf("Nama: "); scanf(" %[^\n]", a.nama);
    printf("Merek: "); scanf(" %[^\n]", a.merek);
    printf("Model: "); scanf(" %[^\n]", a.model);
    printf("Tahun Produksi: "); scanf("%u", &a.tahun);
    printf("Jumlah Unit: "); scanf("%u", &a.jumlah);

    fprintf(fp, "%u, %s, %s, %s, %u, %u\n", a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    fclose(fp);
    printf("Data alat berhasil ditambahkan!\n");
}

// --- EDIT ALAT ---
void editAlat() {
    FILE *fp = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Alat a;
    unsigned int id;
    int found = 0;

    printf("Masukkan ID alat yang ingin diedit: ");
    scanf("%u", &id);

    while (fscanf(fp, "%u, %49[^,], %49[^,], %49[^,], %u, %u\n", 
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {
        if (a.id == id) {
            found = 1;
            printf("Edit nama alat: "); scanf(" %[^\n]", a.nama);
            printf("Edit merek: "); scanf(" %[^\n]", a.merek);
            printf("Edit model: "); scanf(" %[^\n]", a.model);
            printf("Edit tahun: "); scanf("%u", &a.tahun);
            printf("Edit jumlah: "); scanf("%u", &a.jumlah);
        }
        fprintf(temp, "%u, %s, %s, %s, %u, %u\n", a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }
    fclose(fp);
    fclose(temp);
    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if (found) printf("Data alat berhasil diedit!\n");
    else printf("ID alat tidak ditemukan!\n");
}

// --- HAPUS ALAT ---
void hapusAlat() {
    FILE *fp = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Alat a;
    unsigned int id;
    int found = 0;

    printf("Masukkan ID alat yang ingin dihapus: ");
    scanf("%u", &id);

    while (fscanf(fp, "%u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {
        if (a.id != id)
            fprintf(temp, "%u, %s, %s, %s, %u, %u\n", a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
        else found = 1;
    }
    fclose(fp);
    fclose(temp);
    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if (found) printf("Data alat berhasil dihapus!\n");
    else printf("ID alat tidak ditemukan!\n");
}

// --- PINJAM ALAT ---
void pinjamAlat() {
    unsigned int id, jumlah;
    FILE *fp = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *pinjam = fopen("pinjam.txt", "a");
    Alat a;
    int found = 0;

    printf("Masukkan ID alat yang ingin dipinjam: ");
    scanf("%u", &id);
    printf("Masukkan jumlah yang ingin dipinjam: ");
    scanf("%u", &jumlah);

    while (fscanf(fp, "%u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {
        if (a.id == id && a.jumlah >= jumlah) {
            found = 1;
            a.jumlah -= jumlah;
            fprintf(pinjam, "%s, %u, %s, %s, %s, %u, %u\n",
                    loginUser.username, a.id, a.nama, a.merek, a.model, a.tahun, jumlah);
        }
        fprintf(temp, "%u, %s, %s, %s, %u, %u\n", a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(fp); fclose(temp); fclose(pinjam);
    remove("alat.txt"); rename("temp.txt", "alat.txt");

    if (found) printf("Peminjaman berhasil!\n");
    else printf("Alat tidak tersedia atau jumlah tidak cukup!\n");
}

// --- LIHAT PINJAMAN USER ---
void lihatPinjaman() {
    FILE *fp = fopen("pinjam.txt", "r");
    if (!fp) {
        printf("Belum ada data peminjaman.\n");
        return;
    }

    char uname[50];
    Alat a;
    unsigned int jumlah;

    printf("\nAlat yang dipinjam oleh %s:\n", loginUser.username);
    printf("---------------------------------------\n");

    while (fscanf(fp, "%[^,], %u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        uname, &a.id, a.nama, a.merek, a.model, &a.tahun, &jumlah) != EOF) {
        if (strcmp(uname, loginUser.username) == 0) {
            printf("%u | %s | %s | %s | %u | Jumlah: %u\n", a.id, a.nama, a.merek, a.model, a.tahun, jumlah);
        }
    }
    fclose(fp);
}

// --- KEMBALIKAN ALAT ---
void kembalikanAlat() {
    FILE *pinjam = fopen("pinjam.txt", "r");
    FILE *tempPinjam = fopen("temp_pinjam.txt", "w");
    FILE *alatFile = fopen("alat.txt", "r");
    FILE *tempAlat = fopen("temp_alat.txt", "w");

    if (!pinjam || !alatFile) {
        printf("File pinjam.txt atau alat.txt tidak ditemukan!\n");
        return;
    }

    Alat a, alat;
    char uname[50];
    unsigned int id, jumlahPinjam = 0, jumlahKembali = 0;
    int found = 0;

    printf("Masukkan ID alat yang ingin dikembalikan: ");
    scanf("%u", &id);

    // --- 1. Cari dulu berapa jumlah dipinjam user ---
    while (fscanf(pinjam, "%[^,], %u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        uname, &a.id, a.nama, a.merek, a.model, &a.tahun, &jumlahPinjam) != EOF) {

        if (strcmp(uname, loginUser.username) == 0 && a.id == id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Anda tidak meminjam alat dengan ID tersebut!\n");
        fclose(pinjam);
        fclose(alatFile);
        fclose(tempPinjam);
        fclose(tempAlat);
        return;
    }

    printf("Anda meminjam %u unit.\n", jumlahPinjam);
    printf("Berapa unit yang ingin dikembalikan? ");
    scanf("%u", &jumlahKembali);

    if (jumlahKembali > jumlahPinjam) {
        printf("Jumlah pengembalian tidak boleh lebih besar dari yang dipinjam!\n");
        fclose(pinjam);
        fclose(alatFile);
        fclose(tempPinjam);
        fclose(tempAlat);
        return;
    }

    rewind(pinjam);
    rewind(alatFile);

    // --- 2. Tambah stok pada alat ---
    while (fscanf(alatFile, "%u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        &alat.id, alat.nama, alat.merek, alat.model, &alat.tahun, &alat.jumlah) != EOF) {

        if (alat.id == id) {
            alat.jumlah += jumlahKembali;  // tambahkan stok
        }

        fprintf(tempAlat, "%u, %s, %s, %s, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, alat.tahun, alat.jumlah);
    }

    // --- 3. Perbarui file pinjam (kurangi atau hapus baris) ---
    while (fscanf(pinjam, "%[^,], %u, %49[^,], %49[^,], %49[^,], %u, %u\n",
        uname, &a.id, a.nama, a.merek, a.model, &a.tahun, &jumlahPinjam) != EOF) {

        if (strcmp(uname, loginUser.username) == 0 && a.id == id) {
            unsigned int sisa = jumlahPinjam - jumlahKembali;

            if (sisa > 0) {
                // masih punya sisa pinjaman → simpan kembali
                fprintf(tempPinjam, "%s, %u, %s, %s, %s, %u, %u\n",
                    uname, a.id, a.nama, a.merek, a.model, a.tahun, sisa);
            }
            // jika sisa == 0 → baris ini tidak disimpan (artinya pinjaman selesai)
        } else {
            // pinjaman lain tetap ditulis
            fprintf(tempPinjam, "%s, %u, %s, %s, %s, %u, %u\n",
                uname, a.id, a.nama, a.merek, a.model, a.tahun, jumlahPinjam);
        }
    }

    fclose(pinjam);
    fclose(alatFile);
    fclose(tempPinjam);
    fclose(tempAlat);

    remove("pinjam.txt");
    rename("temp_pinjam.txt", "pinjam.txt");

    remove("alat.txt");
    rename("temp_alat.txt", "alat.txt");

    printf("Pengembalian berhasil! Sisa pinjaman Anda diperbarui.\n");
}

