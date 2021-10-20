1. Trình bày (bằng ngôn ngữ tựa C) giải thuật bổ sung một nút mới có chứa
dữ liệu X vào trước nút trỏ bởi Q trong danh sách móc nối hai chiều với: Pdau trỏ
vào phần tử đầu, Pcuoi trỏ vào phần tử cuối, mỗi nút có cấu trúc như sau:

P_L Trỏ tới nút bên trái
DATA Chứa dữ liệu
P_R Trỏ tới nút bên phải


Thuật toán:
Bổ sung 1 nút chứa dữ liệu X trỏ bởi Q trong danh sách móc nối 2 chiều:(hàm Insert() bên dưới)
Đầu tiên kiểm tra node đó có phải node cuối không
Node *P_search = Pdau;//Con trỏ tìm kiếm
scanf(X); // Nhập vào giá trị X để tìm kiếm
//Khởi tạo để kiểm tra từ đầu

//Thuật toán kiểm tra:
while(P_search != NULL && P_search->DATA != X){
		P_search = P_search->P_R;
}
//Dừng khi đã kiểm tra hết cả danh sách hoặc tìm thấy phần tử X trong danh sách

if(P_search == NULL){
	cout << "\nKhong ton tai phan tu " << pts << " trong danh sach";
}//Không tồn tại phần tử X

else if(P_search->P_R == NULL && P_search != NULL){
	Pcuoi->P_R = P_n;
	P_n->P_L = Pcuoi;
	Pcuoi = P_n;
}
//Phần tử X nằm cuối danh sách, do đó lúc này X và đó chính là DATA của Pcuoi
// nên chèn sau Pcuoi bằng cách cho phần P_R của P_cuoi = Phần tử cần chèn, phần P_L của phần tử cần chèn
//bằng với Pcuoi, và cuối cùng là cho Pcuoi phần tử mới do nó đang ở cuối danh sách

else{
	P_n->P_R = P_search->P_R;
	P_search->P_R = P_n;
	P_n->P_L = P_search;
}
//Trường hợp phần tử cần chèn nằm sau phần tử giữa danh sách, ta nối phần P_R của phần tử cần chèn
//với phần tử đã tìm được, rồi sau đó cho phần P_R của phần tử đã tìm được = phần tử chèn
//Và P_L của phần tử chèn bằng phần tử tìm được 

/*
2. Trình bày (bằng ngôn ngữ tựa C) giải thuật loại bỏ một nút trỏ bởi Q trong
danh sách móc nối hai chiều với: Pdau trỏ vào phần tử đầu, Pcuoi trỏ vào phần tử
cuối, mỗi nút có cấu trúc như sau:
P_L Trỏ tới nút bên trái
DATA Chứa dữ liệu
P_R Trỏ tới nút bên phải
*/
Thuât toán: delete 1 node trong danh sách liên kết 2 chiều (hàm deletenode)
B1: Kiểm tra Node đó có phải node cuối, hay node đầu không
Node *P_truoc2, *P_search2 = Pdau;
//Thuật toán ktra, khai báo P_truoc2 là Node nằm trước P_search2, cho trường hợp node cần xóa nằm trong thân danh sách
		while(P_search2 != NULL && P_search2->DATA != S){
			P_truoc2 = P_search2;
			P_search2 = P_search2->P_R;
		}
//Thuật toán sẽ dừng khi tìm được phần tử S hoặc tìm hết cả danh sách nhưng không được S

		if(P_search2 == NULL){
			cout << "\nKhong ton tai phan tu " << ptdl << " trong danh sach";
		}//Trường hợp không tìm được S

		else if(P_search2->P_L == NULL && P_search2->P_R != NULL){
			Pdau = Pdau->P_R;
			Pdau->P_L = NULL;
			cout << "\nDa xoa xong";
		}
		//Đầu danh sách, lúc này S là DATA của Pdau, nên xóa đi S chỉ cần cho Pdau = Pdau->P_R, rồi xóa phần P_L đi là được
		else if(P_search2->P_R == NULL && P_search2->P_L != NULL){
			Pcuoi = Pcuoi->P_L;
			Pcuoi->P_R = NULL;
			cout << "\nDa xoa xong";
		}
		//Cuối danh sách, S là Pcuoi, nên xóa S đi chỉ cần cho Pcuoi = Pcuoi->P_L rồi cho phần P_R = NULL là được

		else{
			Node *P_sau = P_search2->P_R;

			P_truoc2->P_R = P_sau;
			P_sau->P_L = P_truoc2;

			cout << "\nDa xoa xong";
		}

		//Trường hợp cuối cùng, S là DATA của phần tử nằm trong thân danh sách (khác Pdau, Pcuoi)
		//Khai báo P_sau trở vào phần tử sau phần tử cần xóa, 
		//Do đã có sẵn P_truoc2 là phần tử nằm trước phần tử cần xóa,
		//Nên chỉ cần cho phần P_R của P_truoc2 bằng với P_sau
		//Và phần P_L của P_sau bằng với P_truoc2 là được

