16. Trình bày (bằng ngôn ngữ tự nhiên và ngôn ngữ tựa C) giải thuật kiểm tra
cây nhị phân T có phải là "cây nhị phân tìm kiếm" hay không? Mỗi nút trên cây có cấu trúc như sau:
P_L
Trỏ tới cây con trái
KEY 
Chứa giá trị khoá
P_R
Trỏ tới cây con phải

Định nghĩa: Cây nhị phân tìm kiếm là cây nhị phân mà mỗi nút trên cây đều thỏa mãn tính chất:
- Mọi khóa thuộc cây con trái nút đó đều nhỏ hơn khóa tương ứng với nút.
- Mọi khóa thuộc cây con phải nút đó đều lớn hơn khóa tương ứng với nút.
Giải thuật bằng ngôn ngữ tự nhiên:
Tạo 3 hàm sau:
+ Hàm tìm nút có giá trị lớn nhất của 1 cây (Max)
+ Hàm tìm nút có giá trị nhỏ nhất của 1 cây (Min)
+ Hàm kiểm tra xem cây có phải là cây tìm kiếm nhị phân hay không (kiemtra)
- Nếu cây rỗng, đây là cây nhị phân tìm kiếm
- Nếu cây không rỗng, thực hiện các bước:
Bước 1: Kiểm tra cây con trái có phải cây nhị phân tìm kiếm hay không?
    + Nếu đúng, chuyển sang bước tiếp theo
    + Nếu sai, return false;
Bước 2: Kiểm tra cây nhị phân đang xét
    TH1: Cây đang xét có cả 2 cây con trái và phải
    + Tìm max của cây con trái (MaxL), min của cây con phải(MinR) sau đó so sánh với khóa tại nút gốc.
    + Xét điều kiện (MaxL < key) && (key < MinR) Nếu không thỏa mãn, không phải là nhị phân tìm kiếm.
    TH2: Cây đang xét chỉ có cây con phải
    + Tìm min cây con phải (MinR) sau đó so sánh với khóa tại nút.
    + Nếu không thỏa mãn (key < MinR) thì cây đó không phải cây nhị phân tìm kiếm.
    TH3: Cây đang xét chỉ có cây con trái
    + Tìm max cây con trái (MaxL) sau đó so sánh với khóa tại nút.
    + Nếu không thỏa mãn (MaxL < key) thì cây đó không phải cây nhị phân tìm kiếm.
Bước 3: Tiếp tục chạy hàm kiemtra với cây con phải.

Ngôn ngữ tựa C: 
TimMax(T, Max) // Tìm giá trị khoá Max của cây T
{
    if ( T==NULL )  
        return; 
    if (T->P_L != NULL) 
        if(MAX < (T->P_L)->KEY) //so sánh với giá trị của con trái T
            MAX = (T->P_L)->KEY; // cập nhật lại giá trị cho biến MAX
    if (T->P_R != NULL) 
        if(MAX < (T->P_R)->KEY) //so sánh với giá trị của con phải T
            MAX = (T->P_R)->KEY;  // cập nhật lại giá trị cho biến MAX
    if (MAX < T-> KEY) //so sánh với giá trị của T
        MAX = T->KEY; // cập nhật lại giá trị cho biến MAX
    TimMax(T->P_L, Max);  //đệ quy, duyệt xuống con trái của T
    TimMax(T->P_R, Max); 
     //duyệt toàn bộ số nút trên cây T
} 
TimMin(T, Min) // Tìm giá trị khoá Min của cây T
{
    if (T==NULL) 
    return; 
    if (T->P_L != NULL)
        if(Min < T->P_L->KEY)
            Min = (T->P_L)->KEY
    if (T->P_R != NULL)
        if(Min < T->P_R->KEY)
            Min = (T->P_R)->KEY
    if(Min < T->KEY)
        Min = T->KEY;
    TimMin(T->P_L, Min); 
    TimMin(T->P_R, Min); 
} 
KiemTra(T)// Nếu kết quả là 0 thì T là cây nhị phân tìm kiếm
{
    if (T==NULL)
        return 0; 
    Left = KiemTra(T->P_L); 
    If  (Left) // Cây con trái không là cây nhị phân tìm kiếm
        return 1; 
    if (T->P_L != NULL && T->P_R != NULL) // T Có 2 con
    {
        TimMax(T->P_L, MaxL);
        TimMin(T->P_R, MinR); 
        if (!(MaxL  <  T->KEY   &&   T->KEY  <  MinR))  
            return 1; 
        //if(! (điều kiện)) là hàm “không thỏa mãn”
    } 
    else if (T->P_L == NULL && T->P_R != NULL)// Chỉ có con phải
    {
        TimMin(T->P_R, MinR); 
        if (!(T->KEY < MinR)) 
            return 1;
    } 
    else if (T->P_L != NULL && T->P_R == NULL)//Chỉ có con trái
    { 
        TimMax(T->P_L, MaxL);
        if (!(MaxL < T->KEY)) 
            return 1; 
    } 
    Right = KiemTra(T->P_R); 
    return Left + Right; //Nếu L + R = 0 + 0 = 0 thì là cây nhị phân tìm kiếm
}
