#ifndef KARYAWAN_H
#define KARYAWAN_H

#include"Hadiah.h"
using namespace std;

struct Karyawan {
    Karyawan *next, *prev;
    Hadiah *dapatHadiah = NULL;
    string nama;
    string jenisKelamin;
    string jabatan;
};

int isKaryawanEmpty(Karyawan *headKaryawan);
void inputKaryawan(Karyawan **headKaryawan);
void searchKaryawan(Karyawan *headKaryawan);
void addHadiahToKaryawan(Karyawan **headKaryawan, Hadiah *headHadiah);
void searchHadiahInKaryawan(Karyawan *headKaryawan);
void deleteHadiahInKaryawan(Karyawan **headKaryawan);
void deleteKaryawanWhenHaveHadiah(Karyawan **headKaryawan);
void printKaryawan(Karyawan *headKaryawan);
void deleteKaryawan(Karyawan **headKaryawan, string nama);
void countKaryawan(Karyawan *headKaryawan);
void hadiahTerbanyak(Karyawan *headKaryawan, Hadiah **headHadiah);

int isKaryawanEmpty(Karyawan *headKaryawan) {
    if (headKaryawan == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void inputKaryawan(Karyawan **headKaryawan) {
    cout<<"============================== Input Karyawan =============================="<<endl;
    Karyawan *newKaryawan, *cur, *prev;
    prev = NULL;
    cur = *headKaryawan;
    string nama, jenisKelamin, jabatan;
    bool flag = false;

    fgetc(stdin);
    cout<<"Masukan nama : ";
    getline(cin, nama);
    cout<<"Jenis kelamin : ";
    getline(cin, jenisKelamin);
    cout<<"Jabatan : ";
    getline(cin, jabatan);

    newKaryawan = new Karyawan;
    newKaryawan->nama = nama;
    newKaryawan->jenisKelamin = jenisKelamin;
    newKaryawan->jabatan = jabatan;
    newKaryawan->next = NULL;
    newKaryawan->prev = NULL;

    if (isKaryawanEmpty(*headKaryawan) == 1) {
        *headKaryawan = newKaryawan;
        (*headKaryawan)->prev = NULL;
        (*headKaryawan)->next = NULL;
        cout<<"Data masuk"<<endl;
    } else {
        while((cur != NULL)) {
            if(cur->nama == nama) {
               flag = true;
            }
            prev = cur;
            cur = cur->next;
        }
        if(flag) {
            cout<<"Nama "<<nama<<" telah terdaftar di data karyawan. Nama tidak bisa sama."<<endl;
        } else {
            prev->next = newKaryawan;
            newKaryawan->next = NULL;
            newKaryawan->prev = prev;
            cout<<"Data masuk"<<endl;
        }
    }
}

void searchKaryawan(Karyawan *headKaryawan) {
    cout<<"============================== Search Karyawan ============================="<<endl;
    Karyawan *cur;
    string nama;
    bool flag = false;

    cur = headKaryawan;
    if(isKaryawanEmpty(headKaryawan)) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        fgetc(stdin);
        cout<<"Masukan nama yang ingin dicari : ";
        getline(cin, nama);
        while(cur != NULL) {
            if(cur->nama == nama) {
                flag = true;
                break;
            }
            cur = cur->next;
        }

        if(flag) {
            cout<<"Data ditemukan"<<endl;
            cout<<"Nama : "<<cur->nama<<endl;
            cout<<"Jenis Kelamin : "<<cur->jenisKelamin<<endl;
            cout<<"Jabatan : "<<cur->jabatan<<endl;
            cout<<"Hadiah yang dimiliki : ";
            Hadiah *helpHadiah;
            helpHadiah = cur->dapatHadiah;

            if(helpHadiah == NULL) {
                cout<<"Tidak memiliki hadiah"<<endl;
            } else {
                cout<<endl;
                while(helpHadiah != NULL) {
                    cout<<" - "<<helpHadiah->hadiah<<endl;
                    helpHadiah = helpHadiah->next;
                }
            }
        } else {
            cout<<"Tidak ada data karyawan dengan nama "<<nama<<endl;
        }
    }
}

void addHadiahToKaryawan(Karyawan **headKaryawan, Hadiah *headHadiah) {
    cout<<"=========================== Add Hadiah To Karyawan ========================="<<endl;
    Karyawan *curKaryawan;
    Hadiah *curHadiah;
    string nama;
    bool flag = false;
    curKaryawan = *headKaryawan;

    if(isKaryawanEmpty(*headKaryawan)) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        fgetc(stdin);
        cout<<"Masukan nama karyawan yang ingin diberi hadiah : ";
        getline(cin, nama);
        while(curKaryawan != NULL) {
            if(curKaryawan->nama == nama) {
                flag = true;
                break;
            }
            curKaryawan = curKaryawan->next;
        }

        if(flag) {
            string hadiah;
            if(printHadiah(headHadiah)) {
                curHadiah = headHadiah;
                cout<<"Masukan hadiah yang ingin ditambahkan : ";
                getline(cin, hadiah);
                while(curHadiah != NULL && (curHadiah->hadiah != hadiah)) {
                    curHadiah = curHadiah->next;
                }

                Hadiah *hadiahBaru = new Hadiah;
                Hadiah *helpAdd = curKaryawan->dapatHadiah;
                Hadiah *prevHadiah = NULL;

                hadiahBaru->hadiah = curHadiah->hadiah;
                hadiahBaru->next = NULL;

                //ketika belum memiliki hadiah
                if(curKaryawan->dapatHadiah == NULL) {
                    curKaryawan->dapatHadiah = hadiahBaru;
                } else {
                    while(helpAdd != NULL) {
                        prevHadiah = helpAdd;
                        helpAdd = helpAdd->next;
                    }
                    prevHadiah->next = hadiahBaru;
                }
            }
        } else {
            cout<<"Tidak ada data karyawan dengan nama "<<nama<<endl;
        }
    }
}

void searchHadiahInKaryawan(Karyawan *headKaryawan) {
    cout<<"========================= Search Hadiah In Karyawan ========================"<<endl;
    Karyawan *curKaryawan;
    string nama;
    bool flag = false, flagHadiah = false;
    curKaryawan = headKaryawan;

    if (isKaryawanEmpty(headKaryawan) == 1) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        fgetc(stdin);
        cout<<"Masukan nama karyawan yang ingin dicari hadiahnya : ";
        getline(cin, nama);
        while(curKaryawan != NULL) {
            if(curKaryawan->nama == nama) {
                flag = true;
                break;
            }
            curKaryawan = curKaryawan->next;
        }

        if(flag) {
            string hadiah;
            cout<<"Masukan hadiah yang ingin dicari : ";
            getline(cin, hadiah);
            Hadiah *helpHadiah;
            helpHadiah = curKaryawan->dapatHadiah;

            if(helpHadiah == NULL) {
                cout<<nama<<" tidak memiliki hadiah"<<endl;
            } else {
                while(helpHadiah != NULL) {
                    if(helpHadiah->hadiah == hadiah) {
                        flagHadiah = true;
                        break;
                    }
                    helpHadiah = helpHadiah->next;
                }
                if(flagHadiah) {
                    cout<<nama<<" memiliki hadiah "<<helpHadiah->hadiah<<endl;
                } else {
                    cout<<nama<<" tidak memiliki hadiah "<<hadiah<<endl;
                }
            }
        } else {
            cout<<"Tidak ada data karyawan dengan nama "<<nama<<endl;
        }
    }
}

void deleteHadiahInKaryawan(Karyawan **headKaryawan) {
    cout<<"========================= Delete Hadiah In Karyawan ========================"<<endl;
    Karyawan *curKaryawan;
    string nama;
    bool flag = false, flagHadiah = false;
    curKaryawan = *headKaryawan;

    if (isKaryawanEmpty(*headKaryawan) == 1) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        fgetc(stdin);
        cout<<"Masukan nama karyawan yang ingin dihapus hadiahnya : ";
        getline(cin, nama);
        while(curKaryawan != NULL) {
            if(curKaryawan->nama == nama) {
                flag = true;
                break;
            }
            curKaryawan = curKaryawan->next;
        }

        if(flag) {
            string hadiah;
            cout<<"Masukan hadiah yang ingin dihapus : ";
            getline(cin, hadiah);
            Hadiah *helpHadiah, *prevHadiah = NULL;
            helpHadiah = curKaryawan->dapatHadiah;

            if(helpHadiah == NULL) {
                cout<<nama<<" tidak memiliki hadiah"<<endl;
            } else {
                while(helpHadiah != NULL) {
                    if(helpHadiah->hadiah == hadiah) {
                        flagHadiah = true;
                        break;
                    }
                    prevHadiah = helpHadiah;
                    helpHadiah = helpHadiah->next;
                }
                if(flagHadiah) {
                    if(prevHadiah != NULL) {
                        prevHadiah->next = helpHadiah->next;
                    } else {
                        curKaryawan->dapatHadiah = helpHadiah->next;
                    }

                    delete helpHadiah;
                    cout<<hadiah<<" telah dihapus dari data hadiah karyawan "<<nama<<endl;
                } else {
                    cout<<nama<<" tidak memiliki hadiah "<<hadiah<<endl;
                }
            }
        } else {
            cout<<"Tidak ada data karyawan dengan nama "<<nama<<endl;
        }
    }
}

void deleteKaryawanWhenHaveHadiah(Karyawan **headKaryawan) {
    cout<<"============================== Delete Karyawan ============================="<<endl;
    string hadiah, nama;
    Karyawan *help;

    help = *headKaryawan;
    if(isKaryawanEmpty(*headKaryawan)) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        fgetc(stdin);
        cout<<"Masukan data hadiah : ";
        getline(cin, hadiah);
        cout<<"Karyawan yang memiliki hadiah "<<hadiah<<" : "<<endl;
        while(help != NULL) {
            bool flagHaveHadiah = false;
            Hadiah *helpHadiah = help->dapatHadiah;
            while(helpHadiah != NULL) {
                if(helpHadiah->hadiah == hadiah) {
                    flagHaveHadiah = true;
                    break;
                }
                helpHadiah = helpHadiah->next;
            }
            if(flagHaveHadiah) {
                cout<<" - "<<help->nama<<endl;
            }

            help = help->next;
        }
        cout<<"Masukan nama karyawan yang ingin dihapus : ";
        getline(cin, nama);
        deleteKaryawan(headKaryawan, nama);
    }
}

void deleteKaryawan(Karyawan **headKaryawan, string nama) {
    Karyawan *cur, *prev;
    bool flag = false;

    cur = *headKaryawan;
    prev = NULL;

    if(isKaryawanEmpty(*headKaryawan) == 1) {
        cout<<"Tidak ada data karyawan";
    } else {
        while (cur != NULL) {
            if(cur->nama == nama) {
                flag = true;
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (flag) {
            if (prev != NULL) {
                prev->next = cur->next;
                if(cur->next != NULL) {
                    cur->next->prev = prev;
                }
            } else {
                *headKaryawan = cur->next;
                cur->next->prev = NULL;
            }
            delete cur;
            cout<<"Data karyawan dengan nama "<<nama<<" sudah dihapus"<<endl;
        } else {
            cout<<"Tidak ada karyawan dengan nama "<<nama<<endl;
        }
    }
}

void printKaryawan(Karyawan *headKaryawan) {
    cout<<"============================== Print Karyawan =============================="<<endl;
    Karyawan *help;
    help = headKaryawan;
    if(isKaryawanEmpty(headKaryawan)) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        int iKaryawan = 1;
        while(help != NULL) {
            cout<<"Karyawan "<<iKaryawan<<" : "<<endl;
            cout<<"\tNama : "<<help->nama<<endl;
            cout<<"\tJenis kelamin : "<<help->jenisKelamin<<endl;
            cout<<"\tJabatan : "<<help->jabatan<<endl;
            cout<<"\tHadiah yang dimiliki : ";
            Hadiah *helpHadiah;
            helpHadiah = help->dapatHadiah;

            if(helpHadiah == NULL) {
                cout<<"Tidak memiliki hadiah"<<endl;
            } else {
                cout<<endl;
                while(helpHadiah != NULL) {
                    cout<<"\t\t- "<<helpHadiah->hadiah<<endl;
                    helpHadiah = helpHadiah->next;
                }
            }
            help = help->next;
        }
    }
}

void countKaryawan (Karyawan *headKaryawan) {
    cout<<"============================== Hitung Karyawan =============================="<<endl;
    Karyawan *help;
    string hadiah;
    int count = 0;
    help = headKaryawan;
    if(isKaryawanEmpty(headKaryawan)) {
        cout<<"Data karyawan kosong"<<endl;
    } else {
        int iKaryawan = 1;
        fgetc(stdin);
        cout<<"Masukan data hadiah : ";
        getline(cin, hadiah);

        while(help != NULL) {
            Hadiah *helpHadiah;
            helpHadiah = help->dapatHadiah;

            if(helpHadiah == NULL) {
            } else {
                while(helpHadiah != NULL) {
                    if(helpHadiah->hadiah == hadiah) {
                        count++;
                        break;
                    }
                    helpHadiah = helpHadiah->next;
                }
            }
            help = help->next;
        }

        cout<<"Jumlah karyawan yang memiliki hadiah "<<hadiah<<" adalah "<<count<<" karyawan "<<endl;
    }
}

void hadiahTerbanyak(Karyawan *headKaryawan, Hadiah **headHadiah) {
    string hadiahTerbanyak;
    int qty = 0;
    Hadiah *help;
    Karyawan *helpKaryawan;
    help = *headHadiah;
    if(isHadiahEmpty(*headHadiah)) {
        cout<<"Data hadiah kosong"<<endl;
    } else {
        while(help != NULL) {
            helpKaryawan = headKaryawan;
            help->qty = 0;
            while(helpKaryawan != NULL) {
                Hadiah *helpHadiah;
                helpHadiah = helpKaryawan->dapatHadiah;

                if(helpHadiah == NULL) {
                    break;
                } else {
                    while(helpHadiah != NULL) {
                        if(help->hadiah == helpHadiah->hadiah) {
                            help->qty++;
                        }
                        helpHadiah = helpHadiah->next;
                    }
                }
                helpKaryawan = helpKaryawan->next;
            }
            if(qty < help->qty) {
                qty = help->qty;
                hadiahTerbanyak = help->hadiah;
            }
            help = help->next;
        }
    }

    cout<<"Hadiah yang paling banyak diperoleh oleh karyawan adalah "<<hadiahTerbanyak<<". Terdapat "<<qty<<" karyawan yang memiliki hadiah "<<hadiahTerbanyak<<endl;
}

#endif
