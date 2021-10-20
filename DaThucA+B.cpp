//HSO: Ghi he so
//MU: Ghi so mu
//NEXT: Ghi dia chi den phan tu tiep theo

ATTACH(H, M, D)
    {
    T=malloc();
    T->COEF=H;
    T->EXP=M;
    if (C == NULL) //Chua co duoi
        C=Y;
    else            //Da co duoi
        D->NEXT=T;  //Gan T vao duoi
    D=T;            //Nut moi nay tro thanh duoi
    }
    
PADD(A, B, C)
    {
    C=NULL;
    //Ca hai da thuc van con phan tu
    while (P!=NULL && Q!=NULL)
        //Co cung so mu
        if (P->EXP == Q->EXP)
            { H = P->COEF + Q->COEF;
                if (H!=0)
                    ATTACH(H, P->EXP, D);
                P = P->NEXT; Q = Q->NEXT;
            }
        else        //So mu cua P lon hon
            if (P->EXP > Q->EXP)
            {
                ATTACH(P->COEF,P->EXP,D)
                P=P->NEXT;
            }
            else    //So mu cua Q lon hon
            {
                ATTACH(Q->COEF,Q->EXP,D);
                Q=Q->NEXT;
            }
    }