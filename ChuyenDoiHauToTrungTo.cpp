11.Trình bày (bằng ngôn ngữ tự nhiên và ngôn ngữ tựa C) giải thuật chuyển đổi biểu thức dạng trung tố sang dạng hậu tố.
1. Khởi tạo một ngăn xếp rỗng.
2. Đọc lần lượt các thành phần X trong biểu thức dạng trung tố: 
2.1.  Nếu X là toán hạng thì viết nó vào biểu thức dạng hậu tố. 
2.2.  Nếu X là phép toán (phép toán hiện thời), thì thực hiện các bước sau: 
- Nếu ngăn xếp không rỗng thì: nếu phép toán ở đỉnh ngăn xếp có quyền cao hơn hay bằng phép toán hiện thời, thì phép toán đó được kéo ra khỏi ngăn xếp và viết vào biểu thức dạng hậu tố. Lặp lại bước này. 
- Nếu ngăn xếp rỗng hoặc phần tử ở đỉnh ngăn xếp là dấu mở ngoặc hoặc phép toán ở đỉnh ngăn xếp có quyền ưu tiên thấp hơn X, thì X được đẩy vào ngăn xếp.
2.3 Nếu X là dấu là dấu mở ngoặc thì nó được đẩy vào ngăn xếp. 
2.4. Nếu X là dấu đóng ngoặc thì thực hiện các bước sau: 
- (Bước lặp) Loại các phép toán ở đỉnh ngăn xếp và viết vào biểu thức dạng hậu tố cho tới khi đỉnh ngăn xếp là dấu mở ngoặc. 
- Loại dấu mở ngoặc khỏi ngăn xếp.
3. Sau khi toàn bộ biểu thức dạng trung tố được đọc, loại các phép toán ở đỉnh ngăn xếp và viết vào biểu thức dạng hậu tố cho tới khi ngăn xếp rỗng.
Giải thuật:
Trung_to_sang_hau_to ()
{   //Giải thuật này sử dụng 1 stack S, trỏ bởi top T, lúc đầu T = -1
    // Biểu thức trung tố gồm có: số, toán tử, 2 dấu ‘(‘ và ’)’
    //Các phép * / có độ ưu tiên cao hơn + - (nhân chia trước cộng trừ sau)
 do
{
Đọc thành phần X tiếp theo trong biểu thức;
if  (X là toán hạng)
{
printf(X);
}
else if (X là phép toán)
{
            do
                {
                        if ((T>-1) && (S[T] là phép toán có độ ưu tiên cao hơn hay bằng X))
            {
                            printf( POP( S, T ) ); //in phép toán được đỉnh ngăn xếp
                        }
                            if ((Top==-1) || (S[T]=="(") || (S[T] là phép toán có độ ưu tiên thấp hơn X))
{
                                PUSH (S, T, X);
                        }
                }while (phép toán X chưa được đưa vào S);      
}
else if (X là dấu "(")
{
                PUSH (S, T, X);
    }
else if (X là dấu ")")
    {
                do
    {
                printf(POP(S, Top)); // in ra các phép toán 
                }while (Top != "(");
                POP(S, Top); // loại dấu ‘(’ ra khỏi S
    }
}while (chưa gặp dấu kết thúc biểu thức)
do
{
    printf(POP(S, Top)); // in ra các phép toán còn lại trong ngăn xếp
 }while (T>-1);
 
}


