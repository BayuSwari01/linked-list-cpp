#ifndef HADIAH_H
#define HADIAH_H
#include<iostream>
#include<string>
using namespace std;

struct Hadiah {
    Hadiah *next;
    string hadiah;
    int qty = 0;
};

int isHadiahEmpty(Hadiah *headHadiah) {
    if (headHadiah == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void inputHadiah(Hadiah **headHadiah) {
    cout<<"=============================== Input Hadiah ==============================="<<endl;
    Hadiah *newHadiah, *cur, *prev;
    prev = NULL;
    cur = *headHadiah;
    string hadiah;
    bool flag = false;

    fgetc(stdin);
    cout<<"Masukan hadiah : ";
    getline(cin, hadiah);

    newHadiah = new Hadiah;
    newHadiah->hadiah = hadiah;
    newHadiah->next = NULL;

    if (isHadiahEmpty(*headHadiah) == 1) {
        *headHadiah = newHadiah;
        (*headHadiah)->next = NULL;
        cout<<"Data masuk"<<endl;
    } else {
        while((cur != NULL)) {
            if(cur->hadiah == hadiah) {
               flag = true;
            }
            prev = cur;
            cur = cur->next;
        }
        if(flag) {
            cout<<"Hadiah "<<hadiah<<" telah terdaftar di data hadiah. Hadiah tidak bisa sama.";
        } else {
            prev->next = newHadiah;
            newHadiah->next = NULL;
            cout<<"Data masuk"<<endl;
        }
    }
}

bool printHadiah(Hadiah *headHadiah) {
    Hadiah *help;
    help = headHadiah;
    if(isHadiahEmpty(headHadiah)) {
        cout<<"Data hadiah kosong"<<endl;
        return false;
    } else {
        cout<<"Daftar Hadiah"<<endl;
        while(help != NULL) {
            cout<<" - "<<help->hadiah<<endl;
            help = help->next;
        }
        return true;
    }
}

#endif
