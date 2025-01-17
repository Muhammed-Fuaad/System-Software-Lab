#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 FILE *fp1,*fp2,*fp3,*fp4;
 
 int len,locctr,start;
 char label[10],opcode[10],operand[10],code[10],mnemonic[10];
 
 fp1=fopen("input.txt","r");
 fp2=fopen("optab.txt","r");
 fp3=fopen("intermediate.txt","w");
 fp4=fopen("symtab.txt","w");
 
 fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
 if(strcmp(opcode,"START")==0)
 {
  start=atoi(operand);
  locctr=start;
  fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
  fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
 }
 else
 {
  locctr=0;
 }
 while(strcmp(opcode,"END")!=0)
 {
  fprintf(fp3,"%d\t",locctr);
  if(strcmp(label,"**")!=0)
  {
   fprintf(fp4,"%s\t%d\n",label,locctr);
  }
  fscanf(fp2,"%s\t%s",code,mnemonic);
  while(strcmp(code,"END")!=0)
  {
   if(strcmp(opcode,code)==0)
   {
    locctr += 3;
    break;
   }
   fscanf(fp2,"%s\t%s",code,mnemonic);
  }
  if(strcmp(opcode,"WORD")==0)
   locctr +=3;
  else if(strcmp(opcode,"RESW")==0)
   locctr += (3*(atoi(operand)));
  else if(strcmp(opcode,"RESB")==0)
   locctr += (atoi(operand));
  else if(strcmp(opcode,"BYTE")==0)
   ++locctr;
  fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
  fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
 }
 fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
 len=locctr-start;
 printf("length of program : %d",len);
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 fclose(fp4);
}
 
   
