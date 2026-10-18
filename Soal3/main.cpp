#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = nullptr;

void insertLast(int nilai) {
  Node *baru = new Node;
  baru->data = nilai;
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

int hitungSum() {
  int total = 0;
  Node *bantu = head;
  while (bantu != nullptr) {
    total += bantu->data;
    bantu = bantu->next;
  }
  return total;
}

int main() {
  int N, nilai;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> nilai;
    insertLast(nilai);
  }
  cout << hitungSum() << endl;
  while (head != nullptr) {
    Node *hapus = head;
    head = head->next;
    delete hapus;
  }
  return 0;
}
