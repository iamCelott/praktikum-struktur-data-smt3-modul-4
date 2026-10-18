#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
  infotype info;
  address next;
};

struct List {
  address first;
};

void createList(List &L) { L.first = NULL; }

address alokasi(infotype x) {
  address P = new elmlist;
  P->info = x;
  P->next = NULL;
  return P;
}

void dealokasi(address &P) {
  delete P;
  P = NULL;
}

void insertFirst(List &L, address P) {
  P->next = L.first;
  L.first = P;
}

void insertLast(List &L, address P) {
  if (L.first == NULL) {
    insertFirst(L, P);
  } else {
    address Q = L.first;
    while (Q->next != NULL) {
      Q = Q->next;
    }
    Q->next = P;
  }
}

void insertAfter(List &L, address P, address Prec) {
  if (Prec != NULL) {
    P->next = Prec->next;
    Prec->next = P;
  }
}

void deleteFirst(List &L, address &P) {
  if (L.first != NULL) {
    P = L.first;
    L.first = P->next;
    P->next = NULL;
  }
}

void deleteLast(List &L, address &P) {
  if (L.first != NULL) {
    if (L.first->next == NULL) {
      deleteFirst(L, P);
    } else {
      address Q = L.first;
      while (Q->next->next != NULL) {
        Q = Q->next;
      }
      P = Q->next;
      Q->next = NULL;
    }
  }
}

void deleteAfter(List &L, address &P, address Prec) {
  if (Prec != NULL && Prec->next != NULL) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
  }
}

void printInfo(List L) {
  address P = L.first;
  while (P != NULL) {
    cout << P->info << ' ';
    P = P->next;
  }
  cout << '\n';
}

int main() {
  List L;
  address P1, P2, P3, P4, P5;

  createList(L);

  P1 = alokasi(2);
  insertFirst(L, P1);

  P2 = alokasi(0);
  insertFirst(L, P2);

  P3 = alokasi(8);
  insertFirst(L, P3);

  P4 = alokasi(12);
  insertFirst(L, P4);

  P5 = alokasi(9);
  insertFirst(L, P5);

  printInfo(L);

  return 0;
}
