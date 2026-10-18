#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Node {
  string judul;
  int tahun;
  Node *next;
};

Node *head = nullptr;

void insertLast(string judul, int tahun) {
  Node *baru = new Node;
  baru->judul = judul;
  baru->tahun = tahun;
  baru->next = nullptr;
  if (head == nullptr) {
    head = baru;
  } else {
    Node *bantu = head;
    while (bantu->next != nullptr) {
      bantu = bantu->next;
    }
    bantu->next = baru;
  }
}

void deleteLast() {
  if (head == nullptr) {
    return;
  }
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  Node *bantu = head;
  while (bantu->next->next != nullptr) {
    bantu = bantu->next;
  }
  delete bantu->next;
  bantu->next = nullptr;
}

void tampilkanBuku() {
  cout << "Daftar Buku:" << endl;
  Node *bantu = head;
  while (bantu != nullptr) {
    cout << bantu->judul << " (" << bantu->tahun << ")" << endl;
    bantu = bantu->next;
  }
}

int main() {
  int N, tahun;
  string judul;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < N; i++) {
    getline(cin, judul);
    cin >> tahun;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    insertLast(judul, tahun);
  }
  deleteLast();
  tampilkanBuku();
  while (head != nullptr) {
    Node *hapus = head;
    head = head->next;
    delete hapus;
  }
  return 0;
}
