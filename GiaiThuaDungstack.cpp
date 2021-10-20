 GiaiThua(){
    /*
    Giải thuật sử dụng stack, mỗi phần từ của Stack có 2 thành phần: số N là giá trị của n ở mức hiện tại, và địa chỉ quay về 
    TEMREC:  là biến trung chuyển, chứa PARA (N)(phần tử tạm / biến tạm temrec) và address ứng với lời gọi chính của chương trình (ĐCC)
    Top.N : giá trị N ở trên đỉnh
    */
    -Bước 1
    Push(S, Top, TEMREC);
 
    -Bước 2. //kiểm tra điều kiện cơ sở Top.N ==0, 
    if(Top.N == 0){ // nếu đúng thì ra bước tính giai thừa
        GIAI_THUA = 1;
        goto Bước 4;
    }else//không thì gán thông tin cho biến temrec để push 
        {
  PARA = Top.N - 1;
        ADDRESS = Bước 3; 
      goto Bước 1;
    }
    
 
    -Bước 3. Tính giai thừa sau khi Top.N ==0
    GIAI_THUA = GIAI_THUA * Top.N;
 
    -Bước 4. Khôi phục địa chỉ quay về và N
    TEMREC = POP(S, Top);
    goto ADDRESS; //có thể là địa chỉ chính (với N đầu tiên) hoặc Bước 3    
    return GIAI_THUA;
}


1
Số mức
Các bước thực hiện
Nội dung stack
2
Vào mức 1
(Lời gọi chính)
Bước 1:
Push(A, -1, (3, ĐCC)
Bước 2:
Top.N != 0 -> Para = Top.N - 1 =
                                           3 – 1 = 2
                ADDRESS = Buoc 3
goto Buoc 1;
3 | DCC <- TOP
____________
3
Vào mức 2 
(Đệ quy lần 1)
Bước 1: 
Push(A, 0, (2, Bước 3)
Bước 2:
Top.N != 0 -> Para = Top.N – 1 =
                                           2 – 1 = 1
                         Address = Bước 3
2 | Bước 3 <- TOP
3 | ĐCC
______________
4
Vào mức 3
(Đệ quy lần 2)
Bước 1:
Push(A, 1, (1, Bước 3)
Bước 2:
Top.N != 0 -> Para = Top.N – 1 =
                                            1 – 1 = 0
                ADDRESS = Buoc 3
goto Buoc 1;
1 | Bước 3<- TOP
2 | Bước 3
3 | ĐCC
______________
5
Vào mức 4
(Đệ quy lần 3)
Bước 1: 
Push(A, 2, (0, Bước 3)
Bước 2:
Top.N == 0 -> Giai_thua = 1
Goto Bước 4;
0 | Bước 3 <- TOP
1 | Bước 3
2 | Bước 3
3 | ĐCC
_______________
6
Quay lại mức 3
Bước 4:
TEMREC = POP(A,Top)=POP(A,3)
Goto Address Bước 3;
Bước 3
Giai_thua = Giai_thua* Top.N =
                                  1*1          = 1
1 | Bước 3<- TOP
2 | Bước 3
3 | ĐCC
______________
7
Quay lại mức 2
Bước 4 (sau Bước 3)
TEMREC= POP(A, Top)=POP(A,2)
Goto Address Bước 3;
Bước 3: 
Giai_Thua = Giai_thua * Top.N = 
                                   1 *2           = 2
2 | Bước 3 <- TOP
3 | ĐCC
______________
8
Quay lại mức 1
Bước 4 (sau Bước 3)
TEMREC =POP(A, Top)=POP(A,1)
Goto Bước 3;
Bước 3: 
Giai_Thua = Giai_thua * Top.N = 
                                   2 * 3         = 6
3 | DCC <- TOP
____________
9
Quay lại địa chỉ chính
Bước 4:
TEMREC = POP(A,Top)=POP(A,0)
Goto Address (ĐCC);
Stack trống


