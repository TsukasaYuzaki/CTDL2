PUSH(S,T,X)
{
    if(T>=n-1)
    {
        printf("ngan xep tran");
    }else
    {
        T++;
        S[T]=X;
    }
}
POP(S,T)
{
    if(T<0)
    {
        printf("ngan xep can");
    }else
    {
        T--;
        return S[T+1];
    }
}
DINH_GIA_BIEU_THUC()
{
    do
    {
        if(X: toan hang)
        {
            PUSH(S,X,T);
        }else
        {
            Y=POP(S,T);
            Z=POP(S,T);
            W=Z:X:Y;
            PUSH(S,T,W);
        }
    }
    while(chua ket thuc);
    R=POP(S,T);
    printf(R);
}