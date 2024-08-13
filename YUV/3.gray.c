#include<stdio.h>
#include <stdlib.h>
/**
 * Convert YUV420P file to gray picture
 * @param url     Location of Input YUV file.
 * @param w       Width of Input YUV file.
 * @param h       Height of Input YUV file.
 * @param num     Number of frames to process.
 */
int simplest_yuv420_gray(char *url, int w, int h,int num){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_gray.yuv","wb+");
	unsigned char *pic=(unsigned char *)malloc(w*h*3/2);
 
	for(int i=0;i<num;i++){
		fread(pic,1,w*h*3/2,fp);
		//Gray
		memset(pic+w*h,128,w*h/2);//����128��pic+w*h��������ǰw*h/2���ֽڣ�w*hǰ�洢����y������w*h/2��uv�����Ĵ洢������uv������������ǻҶ�ͼ
		fwrite(pic,1,w*h*3/2,fp1);
	}
 
	free(pic);
	fclose(fp);
	fclose(fp1);
	return 0;
}
int main()
{

    simplest_yuv420_gray("../out.yuv",176,144,1);
    return 0;
}