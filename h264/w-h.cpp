#include <stdio.h>
#include <string.h>
 
int main()
{
   FILE *fp;
   char c[] = "This is runoob";
   char buffer[20];
 
   /* ���ļ����ڶ�д */
   fp = fopen("file.txt", "w+");
 
   /* д�����ݵ��ļ� */
   fwrite(c, strlen(c) + 1, 1, fp);
 
   /* �����ļ��Ŀ�ͷ */
   fseek(fp, 0, SEEK_SET);
 
   /* ��ȡ����ʾ���� */
   int a = fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);
   printf("%d\n",a);
   
   return(0);
}