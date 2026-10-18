#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertLast(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;
    if (head == nullptr) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void insertAfter(int cari, int nilaiBaru) {
    Node* bantu = head;
    while (bantu != nullptr && bantu->data != cari) {
        bantu = bantu->next;
    }
    if (bantu != nullptr) {
        Node* baru = new Node;
        baru->data = nilaiBaru;
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void tampilkanList() {
    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->data;
        if (bantu->next != nullptr) {
            cout << " -> ";
        }
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int N, nilai, cari, nilaiBaru;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nilai;
        insertLast(nilai);
    }
    cin >> cari;
    cin >> nilaiBaru;
    insertAfter(cari, nilaiBaru);
    tampilkanList();
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
    return 0;
}
