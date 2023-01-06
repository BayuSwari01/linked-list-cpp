#include <iostream>
#include"Karyawan.h"
using namespace std;

void inisialisasi(Karyawan **headKaryawan, Hadiah **headHadiah)
{
    *headKaryawan = NULL;
    *headHadiah = NULL;
}

void menu(Karyawan **headKaryawan, Hadiah **headHadiah) {
    while(true) {
        int menu;
        cout<<"=================================== Menu ==================================="<<endl;
        cout<<"1. Menambah data karyawan"<<endl;
        cout<<"2. Menambah data hadiah"<<endl;
        cout<<"3. Mencari data karyawan"<<endl;
        cout<<"4. Menambah relasi data karyawan dan hadiah yang diperoleh"<<endl;
        cout<<"5. Mencari data hadiah yang didapat karyawan tertentu"<<endl;
        cout<<"6. Menghapus data hadiah yang diperoleh karyawan tertentu"<<endl;
        cout<<"7. Menghapus data karyawan yang memperoleh hadiah tertentu"<<endl;
        cout<<"8. Menampilkan data seluruh karyawan beserta semua hadiah yang diperoleh"<<endl;
        cout<<"9. Menghitung banyaknya karyawan yang mendapatkan hadiah tertentu"<<endl;
        cout<<"10. Menampilkan hadiah yang paling banyak diperoleh karyawan"<<endl;
        cout<<"11. Exit"<<endl;
        cout<<"Masukan pilihan menu : ";
        cin>>menu;
        cout<<"============================================================================"<<endl;
        switch(menu) {
        case 1:
            inputKaryawan(headKaryawan);
            break;
        case 2:
            inputHadiah(headHadiah);
            break;
        case 3:
            searchKaryawan(*headKaryawan);
            break;
        case 4:
            addHadiahToKaryawan(headKaryawan, *headHadiah);
            break;
        case 5:
            searchHadiahInKaryawan(*headKaryawan);
            break;
        case 6:
            deleteHadiahInKaryawan(headKaryawan);
            break;
        case 7:
            deleteKaryawanWhenHaveHadiah(headKaryawan);
            break;
        case 8:
            printKaryawan(*headKaryawan);
            break;
        case 9:
            countKaryawan(*headKaryawan);
            break;
        case 10:
            hadiahTerbanyak(*headKaryawan, headHadiah);
            break;
        case 11:
            cout<<"Terimakasih telah menggunakan aplikasi GIFT"<<endl;
            return;
            break;
        default:
            cout<<"Harap masukan pilihan sesuai dengan menu yang ada!"<<endl;
            break;
        }
    }

}

int main()
{
    Karyawan *headKaryawan;
    Hadiah *headHadiah;
    inisialisasi(&headKaryawan, &headHadiah);

    menu(&headKaryawan, &headHadiah);
    return 0;
}
