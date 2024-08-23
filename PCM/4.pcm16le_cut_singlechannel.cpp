#include<iostream>
using namespace std;
/**
 * Cut a 16LE PCM single channel file.
 * @param url        Location of PCM file.
 * @param start_num  start point
 * @param dur_num    how much point to cut
 */
int simplest_pcm16le_cut_singlechannel(char *url,int start_num,int dur_num){
	FILE *fp=fopen(url,"rb+");
	FILE *fp1=fopen("output_cut.pcm","wb+");
	FILE *fp_stat=fopen("output_cut.txt","wb+");
 
	unsigned char *sample=(unsigned char *)malloc(2);
 
	int cnt=0;
	while(!feof(fp)){
		fread(sample,1,2,fp);
		if(cnt>start_num&&cnt<=(start_num+dur_num)){
			fwrite(sample,1,2,fp1);
 
			short samplenum=sample[1];
			samplenum=samplenum*256;
			samplenum=samplenum+sample[0];
 
			fprintf(fp_stat,"%6d,",samplenum);
			if(cnt%10==0)
				fprintf(fp_stat,"\n",samplenum);
		}
		cnt++;
	}
 
	free(sample);
	fclose(fp);
	fclose(fp1);
	fclose(fp_stat);
	return 0;
}
int main()
{
	simplest_pcm16le_cut_singlechannel("../tonghua1.pcm",50000,120);
    return 0;
}