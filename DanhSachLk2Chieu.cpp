#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct DanhsachLK{
    int DATA;
    struct DanhsachLK *P_L;
    struct DanhsachLK *P_R;
}Node;

Node *P, *first = NULL, *last = NULL;

void makelist(){
	int data2, i, choice = 1;
	first = NULL;
	do{
		cout << "\nNhap vao data thu " << i << ": ";
		i+=1;
		cin >> data2;
		P = new Node;

		P->DATA = data2;
		P->P_L = NULL;
		P->P_R = NULL;
		
		if(first == NULL){
			first = P;
			last  = P;
		}

		else{
			last->P_R = P;
			P->P_L = last;
			last = P;
		}

		cout << "\nNhap tiep?(Nhap 0 neu khong muon nhap nua): ";
		cin >> choice;
	}
	while(choice);
/*
	cout << "\n";
	Node *P_try = first;
	while(P_try != NULL){
		cout << P_try->DATA << " ";
		P_try = P_try->P_R;
	}
*/

}

void insert(){
	int choice;
	if(first == NULL){
		cout << "\nDanh sach rong";
	}
	else{
		int data2;
		Node *P_t;
		
		P_t = new Node;
		
		P_t->P_L = NULL;
		P_t->P_R = NULL;

		cout << "\nChon:" << " ";
		cout << "\n1.Insert Dau danh sach";
		cout << "\n2.Insert sau 1 phan tu nao do trong danh sach";
		cout << "\n3.Insert vao cuoi danh sach";
		cout << "\nChon: ";
		cin >> choice;

		if(choice == 1){

			cout << "\nNhap vao data muon insert:";
			cin >> data2;
			P_t->DATA = data2;

			first->P_L = P_t;
			P_t->P_R = first;
			first = P_t;

			cout << "\nInsert thanh cong";
		}
		else if(choice == 2){
			Node *P_search = first;
			
			Node *P_n = new Node;
	
			P_n->P_R = NULL;
			P_n->P_L = NULL;

			Node *P_truoc = new Node;

			P_truoc->P_R = NULL;
			P_truoc->P_L = NULL;

			cout << "\nNhap vao data muon insert: ";
			
			int isdata; cin >> isdata; P_n->DATA = isdata;

			cout << "\nInsert sau phan tu: ";
			int pts; cin >> pts;

			while(P_search != NULL && P_search->DATA != pts){
				P_truoc = P_search;
				P_search = P_search->P_R;
			}
//Chia 3 TH
			if(P_search == NULL){
				cout << "\nKhong ton tai phan tu " << pts << " trong danh sach";
			}

			else if(P_search->P_R == NULL && P_search != NULL){
				last->P_R = P_n;
				P_n->P_L = last;
				last = P_n;
			}
			else{
				P_n->P_R = P_search->P_R;
				P_search->P_R = P_n;
				P_n->P_L = P_search;
			}
		}

			//free(P_s);
		else if(choice == 3){

			cout << "\nNhap vao data muon insert:";
			cin >> data2;
			P_t->DATA = data2;

			last->P_R = P_t;
			P_t->P_L = last;
			last = P_t;

			cout << "\nInsert thanh cong";
		}
		else{
			cout << "\nCC";
		}
	}
}

void inra(){
	cout << "\n";
	Node *P_try = first;
	
	while(P_try != NULL){
		cout << P_try->DATA << " ";
		P_try = P_try->P_R;
	}
	
}

void deletenode(){
	int choice;
	cout << "\nChon: ";
	cout << "\n1.Delete phan tu dau danh sach";
	cout << "\n2.Detele phan tu cuoi danh sach";
	cout << "\n3.Nhap vao phan tu de detele khoi danh sach";
	cout << "\nChon: "; cin >> choice;

	if(choice == 1){
		cout << "\nXoa phan tu dau danh sach";
		first = first->P_R;
		first->P_L = NULL;
		cout << "\nDa xoa xong";
	}
	else if(choice == 2){
		cout << "\nXoa phan tu cuoi danh sach";
		last = last->P_L;
		last->P_R = NULL;
		cout << "\nDa xoa xong";
	}
	else if(choice == 3){
		int ptdl;
		cout << "\nNhap vao phan tu muon delete: ";
		cin >> ptdl;
		Node *P_truoc2, *P_search2 = first;
		while(P_search2 != NULL && P_search2->DATA != ptdl){
			P_truoc2 = P_search2;
			P_search2 = P_search2->P_R;
		//	P_sau = P_search2;
		}

		if(P_search2 == NULL){
			cout << "\nKhong ton tai phan tu " << ptdl << " trong danh sach";
		}
		else if(P_search2->P_L == NULL && P_search2->P_R != NULL){
			first = first->P_R;
			first->P_L = NULL;
			cout << "\nDa xoa xong";
		}
		else if(P_search2->P_R == NULL && P_search2->P_L != NULL){
			last = last->P_L;
			last->P_R = NULL;
			cout << "\nDa xoa xong";
		}
		else{
			Node *P_sau = P_search2->P_R;

			P_truoc2->P_R = P_sau;
			P_sau->P_L = P_truoc2;

			cout << "\nDa xoa xong";
		}
	}
	else{
		cout << "\nCC";
	}
}

int main(){
	makelist();
	inra();
	deletenode();
	inra();
	deletenode();
	inra();
	deletenode();
	inra();
	return 0;
}
