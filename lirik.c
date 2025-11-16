#include <stdio.h>
#include <windows.h>

void keluar(const char *teks, int delay){
    for (int i = 0; teks[i] != '\0'; i++){
        printf("%c", teks[i]);
        fflush(stdout);
        Sleep(delay);
    }
}

int main(){
    keluar("I got my driver's license last week\n",90);
        Sleep(1500);
    keluar("just like we always talked about\n",40);
        Sleep(3000);
    keluar("'Cause you to excited for me\n", 20);\
        Sleep(2000);
    keluar("To finally drive up to your house\n", 20);\
        Sleep(2000);
    keluar("But today i drove through the surbubs\n", 20);\
        Sleep(2000);
    keluar("Cryin 'cause you weren't around\n", 20);\
        Sleep(2000);
return 0;

}
