#include <iostream>
#include <string>
using namespace std;

struct Node {
  string nama;
  Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void insertLast(string nama) {
  Node *baru = new Node;
  baru->nama = nama;
  baru->next = nullptr;
  if (head == nullptr) {
    head = baru;
    tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
}

void deleteFirst() {
  if (head == nullptr) {
    cout << "Antrean kosong" << endl;
    return;
  }
  Node *hapus = head;
  cout << "Melayani: " << hapus->nama << endl;
  head = head->next;
  if (head == nullptr) {
    tail = nullptr;
  }
  delete hapus;
}

void tampilkanAntrean() {
  if (head == nullptr) {
    cout << "Antrean kosong" << endl;
    return;
  }
  cout << "Antrean: ";
  Node *bantu = head;
  while (bantu != nullptr) {
    cout << bantu->nama;
    if (bantu->next != nullptr) {
      cout << " -> ";
    }
    bantu = bantu->next;
  }
  cout << endl;
}

int main() {
  int pilihan;
  string nama;
  do {
    cin >> pilihan;
    switch (pilihan) {
    case 1:
      cin.ignore();
      getline(cin, nama);

      insertLast(nama);
      tampilkanAntrean();
      break;
    case 2:
      deleteFirst();
      if (head != nullptr) {
        tampilkanAntrean();
      }
      break;
    case 3:
      break;
    default:
      cout << "Pilihan tidak valid" << endl;
    }
  } while (pilihan != 3);
  while (head != nullptr) {
    Node *hapus = head;
    head = head->next;
    delete hapus;
  }
  tail = nullptr;
  return 0;
}
