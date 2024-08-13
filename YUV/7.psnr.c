#include<stdio.h>
#include <stdlib.h>
/**
 * Calculate PSNR between 2 YUV420P file
 * @param url1     Location of first Input YUV file.
 * @param url2     Location of another Input YUV file.
 * @param w        Width of Input YUV file.
 * @param h        Height of Input YUV file.
 * @param num      Number of frames to process.
 */
int simplest_yuv420_psnr(char *url1,char *url2,int w,int h,int num){
	FILE *fp1=fopen(url1,"rb+");
	FILE *fp2=fopen(url2,"rb+");
	unsigned char *pic1=(unsigned char *)malloc(w*h);
	unsigned char *pic2=(unsigned char *)malloc(w*h);
 
	for(int i=0;i<num;i++){
		fread(pic1,1,w*h,fp1);
		fread(pic2,1,w*h,fp2);
 
		double mse_sum=0,mse=0,psnr=0;
		for(int j=0;j<w*h;j++){
			mse_sum+=pow((double)(pic1[j]-pic2[j]),2);
		}
		mse=mse_sum/(w*h);
		psnr=10*log10(255.0*255.0/mse);
		printf("%5.3f\n",psnr);
 
		fseek(fp1,w*h/2,SEEK_CUR);
		fseek(fp2,w*h/2,SEEK_CUR);
 
	}
 
	free(pic1);
	free(pic2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main()
{

	simplest_yuv420_psnr("../out.yuv","../out1.yuv",176,144,1);
    return 0;
}