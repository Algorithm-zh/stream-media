#include<iostream>
using namespace std;
/**
 * Re-sample to double the speed of 16LE PCM file
 * @param url  Location of PCM file.
 */
int simplest_pcm16le_doublespeed(char *url){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_doublespeed.pcm","wb+");
 
	int cnt=0;
 
	unsigned char *sample=(unsigned char *)malloc(4);
 
	while(!feof(fp)){
 
		fread(sample,1,4,fp);
 
		if(cnt%2!=0){//只去采样奇数点的值，时间会减半
			//L
			fwrite(sample,1,2,fp1);
			//R
			fwrite(sample+2,1,2,fp1);
		}
		cnt++;
	}
	printf("Sample Cnt:%d\n",cnt);
 
	free(sample);
	fclose(fp);
	fclose(fp1);
	return 0;
}
int main()
{
    simplest_pcm16le_doublespeed("../tonghua1.pcm");
    return 0;
}