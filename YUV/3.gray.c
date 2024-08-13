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
		memset(pic+w*h,128,w*h/2);//复制128到pic+w*h缓冲区的前w*h/2个字节，w*h前存储的是y分量，w*h/2是uv分量的存储区，给uv分量都减半就是灰度图
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