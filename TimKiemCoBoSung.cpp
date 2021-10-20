Trình bày (bằng ngôn ngữ tựa C) giải thuật tìm kiếm có bổ sung trên cây
nhị phân tìm kiếm. Mỗi nút trên cây có cấu trúc như sau:
P_L 
Trỏ tới cây con trái
KEY
Chứa giá trị khoá
P_R
Trỏ tới cây con phải

BTS (T,x,P)
{   
/* Hàm này thực hiện tìm kiếm trên cây nhị phân tìm kiếm, có gốc được trỏ bởi T, khoá tìm kiếm là x. Nếu tìm thấy thì trỏ P vào, nếu không tìm thấy thì tạo thêm nút rồi trỏ P vào kèm theo thông báo.  */
    P=T; Q=NULL;
    While (P!=NULL) // Tìm kiếm, với con trỏ Q đặt vào nút cha của P
    {
        if (x== P->KEY)
            return; //Đã tìm thấy điểm trùng, ngưng tìm kiếm
        Q=P; 
        if ( x < P->KEY) // bắt đầu tìm kiếm ở cây con trái
            P = P -> P_L;
        else // bắt đầu tìm kiếm ở cây con phải 
            P = P -> P_R;
    }
    P = malloc();//Khóa x chưa có trên cây, thực hiện bổ sung
    P->KEY = x;
    P -> P_L = NULL; P -> P_R = NULL;
    If (T=NULL) //Cây rỗng
        T=P; //Nút mới chính là gốc
    Else //Cây không rỗng, nối nút mới vào với cây vừa tìm kiếm
        if( x < Q->KEY)
            Q-> P_L = P;
        else
            Q-> P_R = P;
    Printf(“Không tìm thấy, đã bổ sung”);
}
