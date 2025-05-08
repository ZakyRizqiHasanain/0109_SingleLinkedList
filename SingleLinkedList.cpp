#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
    int noMhs;
    node *next;
};

class list{
    node *start;
    
    
    public:
    list(){
        start = NULL;
    }
    
    void addnode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;
        node *nodebaru = new node;
        nodebaru->noMhs = nim;
    
        if (start == NULL || nim <= start->noMhs){
            if ((start != NULL) && (nim == start->noMhs)){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = start;
            start = nodebaru;
            return;
        }

        node *previous = start;
        node *current = start;

        while ((current != NULL) && (nim >= current->noMhs)){
            if (nim == current->noMhs){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listempty(){
        return (start == NULL);
    }

    bool Search(int nim, node **previous, node **current){
        *previous = start;
        *current = start;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delnode(int nim){
        node *current, *previous;
        if (!Search(nim, &previous, &current))
        return false;

        if (current == start)
        start = start->next;
        else 
        previous->next = current->next;

        delete current;
        return true;
    }

    void traverse(){
        if (listempty()){
            cout << "\nList Kosong\n";
        }
        else{
            cout << " \nData didalam list adalah:\n";
            node *currentnode = start;
            while (currentnode != NULL){
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout << endl;
        }
    }
};

int main(){
    list mhs;
    int nim;
    char ch;
    while (1){
        cout << "Menu" << endl;
        cout << endl
             << "1. Menambahkan data kedalam list" << endl
             << "2. Menghapus data dari dalam list" << endl
             << "3. Menampilkan semua data dialam list" << endl
             << "4. Mencari data dalam list" << endl
             << "5. Keluar" ;
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;
    }
}