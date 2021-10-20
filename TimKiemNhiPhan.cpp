Tim_Kiem_Nhi_Phan(K,t,p,x)
{
    if(t>p)
    {
        return -1;
    }else
    {
        g=(t+p)/2;
        if(x==K[g])
        {
            return g;
        }
        if(x>K[g])
        {
            Tim_Kiem_Nhi_Phan(K,g+1,p,x);
        }
        if(x<K[g])
        {
            Tim_Kiem_Nhi_Phan(K,t,g-1,x);
        }
    }
}
