#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
char icode[10][30],str[20],opr[20];
int i=0;
printf("Enter the intermediate code(terminated by exit) : \n");
do {
   scanf("%5s",icode[i]);
   }while(strcmp(icode[i++],"exit")!=0);
  printf("Target code generation\n");
  printf("---------------------\n");
  i=0;
  do{
   strcpy(str,icode[i]);
   switch(str[3])
   {
   case '+' : strcpy(opr,"ADD");
              break;
   case '-' : strcpy(opr,"SUB");
              break;
   case '*' : strcpy(opr,"MUL");
              break;
   case '/' : strcpy(opr,"DIV");
              break;
   }
   printf("\n\tMOV %c,R%d",str[2],i);
   printf("\n\t%s %c,R%d",opr,str[4],i);
   printf("\n\tMOV R%d,%c",i,str[0]);
   }  
   while(strcmp(icode[i++],"exit")!=0);
   }
/*Enter the intermediate code(terminated by exit) : 
a=b+c
c=c+y
t=1-0
d=c-t
exit
Target code generation
---------------------

	MOV b,R0
	ADD c,R0
	MOV R0,a
	MOV c,R1
	ADD y,R1
	MOV R1,c
	MOV 1,R2
	SUB 0,R2
	MOV R2,t
	MOV c,R3
	SUB t,R3
	MOV R3,d
	MOV i,R4
	SUB ,R4
	MOV R4,e
      */
