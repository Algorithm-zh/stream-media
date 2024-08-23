#include<iostream>
using namespace std;
/**
 * Convert PCM-16 data to PCM-8 data.
 * @param url  Location of PCM file.
 */
int simplest_pcm16le_to_pcm8(char *url){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_8.pcm","wb+");
 
	int cnt=0;
 
	unsigned char *sample=(unsigned char *)malloc(4);
 
	while(!feof(fp)){
 
		short *samplenum16=NULL;
		char samplenum8=0;
		unsigned char samplenum8_u=0;
		fread(sample,1,4,fp);
		//(-32768-32767)
		samplenum16=(short *)sample;
		samplenum8=(*samplenum16)>>8;
		//(0-255)
		samplenum8_u=samplenum8+128;
		//L
		fwrite(&samplenum8_u,1,1,fp1);
 
		samplenum16=(short *)(sample+2);
		samplenum8=(*samplenum16)>>8;
		samplenum8_u=samplenum8+128;
		//R
		fwrite(&samplenum8_u,1,1,fp1);
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
	simplest_pcm16le_to_pcm8("../tonghua1.pcm");
    return 0;
}