#include<iostream>
using namespace std;
/**
 * Split Left and Right channel of 16LE PCM file.
 * @param url  Location of PCM file.
 *
 */
int simplest_pcm16le_split(char *url){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_l.pcm","wb+");
	FILE *fp2=fopen("output_r.pcm","wb+");
 
	unsigned char *sample=(unsigned char *)malloc(4);
 
	while(!feof(fp)){
		fread(sample,1,4,fp);
		//L
		fwrite(sample,1,2,fp1);
		//R
		fwrite(sample+2,1,2,fp2);
	}
 
	free(sample);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
int main()
{
    simplest_pcm16le_split("../tonghua1.pcm");
    return 0;
}