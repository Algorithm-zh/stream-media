#include<stdio.h>
#include <stdlib.h>
/**
 * Add border for YUV420P file
 * @param url     Location of Input YUV file.
 * @param w       Width of Input YUV file.
 * @param h       Height of Input YUV file.
 * @param border  Width of Border.
 * @param num     Number of frames to process.
 */
int simplest_yuv420_border(char *url, int w, int h,int border,int num){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_border.yuv","wb+");
 
	unsigned char *pic=(unsigned char *)malloc(w*h*3/2);
 
	for(int i=0;i<num;i++){
		fread(pic,1,w*h*3/2,fp);
		//Y
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				if(k<border||k>(w-border)||j<border||j>(h-border)){
					pic[j*w+k]=255;
					//pic[j*w+k]=0;
				}
			}
		}
		fwrite(pic,1,w*h*3/2,fp1);
	}
 
	free(pic);
	fclose(fp);
	fclose(fp1);
 
	return 0;
}

int main()
{

    simplest_yuv420_border("../out.yuv",176,144,20,1);
    return 0;
}