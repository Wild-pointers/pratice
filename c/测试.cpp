#include <stdio.h>
#define MaxSize 10 //喘薩徭協吶
　　typedef int DataType; //喘薩徭協吶
　　typedef struct
　　　{ //協吶眉圷怏
　　　　int i,j;
　　　　DataType v;
　　　}TriTupleNode;

　　typedef struct
　　　{ //協吶眉圷怏燕
　　　　TriTupleNode data[MaxSize];
　　　　int m,n,t;//裳專佩��双式眉圷怏燕海業
　　　}TriTupleTable;

　　//參和葎裳專紗麻隈 
　　void AddTriTuple( TriTupleTable *A, TriTupleTable *B, TriTupleTable *C)
　　　{//眉圷怏燕燕幣議蓮墓裳專A,B�犲�
　　　　int k,l;
　　　　DataType temp;
　　　　C->m=A->m;//裳專佩方
　　　　C->n=A->n;//裳專双方
　　　　C->t=0; //眉圷怏燕海業
　　　　k=0; l=0;
　　　　while (k<A->t&&l<B->t)
　　　　　{if((A->data[k].i==B->data[l].i)&&(A->data[k].j==B->data[l].j))
　　　　　　　{temp=A->data[k].v+B->data[l].v;
　　　　　　　　if (!temp)//�犲啣士�巣��紗秘C
　　　　　　　　　{C->data[c->t].i=A->data[k].i;
　　　　　　　　　　C->data[c->t].j=A->data[k].j;
　　　　　　　　　　C->data[c->t++].v=temp;
　　　　　　　　　}
　　　　　　　　k++;l++;　
　　　　　　　}
　　　　　if ((A->data[k].i==B->data[l].i)&&(A->data[k].j<B->data[l].j))
　　　　　　　||(A->data[k].i<B->data[l].i)//繍A嶄眉圷怏紗秘C
　　　　　　{C->data[c->t].i=A->data[k].i;
　　　　　　　C->data[c->t].j=A->data[k].j;
　　　　　　　C->data[c->t++].v=A->data[k].v;
　　　　　　　k++;
　　　　　　}
　　　　　if ((A->data[k].i==B->data[l].i)&&(A->data[k].j>B->data[l].j))
　　　　　　　||(A->data[k].i>B->data[l].i)//繍B嶄眉圷怏紗秘C
　　　　　　{C->data[c->t].i=B->data[l].i;
　　　　　　　C->data[c->t].j=B->data[l].j;
　　　　　　　C->data[c->t++].v=B->data[l].v;
　　　　　　　l++;　
　　　　　　}
　　　　　}
　　　　while (k<A->t)//繍A嶄複噫眉圷怏紗秘C
　　　　　{C->data[c->t].i=A->data[k].i;
　　　　　　C->data[c->t].j=A->data[k].j;
　　　　　　C->data[c->t++].v=A->data[k].v;
　　　　　　k++;
　　　　　}
　　　　while (l<B->t)//繍B嶄複噫眉圷怏紗秘C
　　　　　{C->data[c->t].i=B->data[l].i;
　　　　　　C->data[c->t].j=B->data[l].j;
　　　　　　C->data[c->t++].v=B->data[l].v;
　　　　　　l++;
　　　　　}
　　　} 
