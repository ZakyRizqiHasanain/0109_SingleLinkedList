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
    do{
        cout << "Menu" << endl;
        cout << endl
             << "1. Menambahkan data kedalam list" << endl
             << "2. Menghapus data dari dalam list" << endl
             << "3. Menampilkan semua data dialam list" << endl
             << "4. Mencari data dalam list" << endl
             << "5. Keluar" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;
        switch (ch){
            case '1':
            {
                mhs.addnode();
                break;
            }
            case '2':
            {
                if (mhs.listempty())
                {
                    cout << endl
                         << "List Kosong" << endl;
                         break;
                }
                cout << endl
                     << "\nMasukkan no mahasiswa yang akan dihapus : ";
                     cin >> nim;
                     if (mhs.delnode(nim) == false)
                     cout << endl
                          << "Data tidak ditemukan" << endl;
                    else 
                    cout << endl
                         << "Data dengan nomor mahasiswa " << nim << "berhasil dihapus" << endl;
            }
            break;
            case '3':
            {
                mhs.traverse();
            }
            break;
            case '4':
            {
                if (mhs.listempty() == true)
                {
                    cout << "\nList Kosong";
                    break;
                }
                node *previous, *current;
                cout << endl
                     << "Masukkan no mahasiswa yang di cari : ";
                cin >> nim;
                if (mhs.Search(nim, &previous, &current) == false)
                cout << endl
                     << "Data tidak ditemukan" << endl;
                else
                {
                    cout << endl
                         << "Data ditemukan" << endl;
                    cout << "\nNo Mahasiswa : " << current->noMhs << endl;
                    cout << "\n";
                }
            }
            break;
            case '5':
            {
            }
            break;
            default:
            {
                cout << "Pilihan salah !." << endl;
            }
            break;
        }
    }while (ch != '5');
}