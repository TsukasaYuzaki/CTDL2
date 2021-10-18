

/* ------------------------ */
#include <stdio.h>
#include<conio.h>

int dong[8], cot[8], cheoxuoi[15], cheonguoc[15];
//
void print (){
   int i;
   printf("\n");
   for (i=0; i<8; i++)
     printf("%3d", cot[i]);
}
//
void thu(int j){
   int i;
   for (i=0; i<8; i++) {
    if(dong[i]==1&&cheoxuoi[i+j]==1&&cheonguoc[i-j+7]==1)
    {
      cot[j] = i;
      dong[i] = 0;
      cheoxuoi[i+j] = 0;
      cheonguoc[i-j+7] = 0;
      if (j<7)
        thu(j+1);
      else
         print();
      dong[i] = 1;
      cheoxuoi[i+j] = 1;
      cheonguoc[i-j+7] = 1;
      }
    }
}



// Hàm chính
void main(){
    int i, q;
	for (i=0; i<8; i++)
	{
	dong[i] = 1; 
	cot[i] = -1;
	}
	for (i=0; i<15; i++)
	{
	cheoxuoi[i] = 1;
	cheonguoc[i] = 1;
	}
	thu(0);
    getch();
}

