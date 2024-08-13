#include<stdio.h>
#include <stdlib.h>
/**
 * ���� YUV420P ��ʽ�ĻҶ�����ͼ��
 * 
 * @param width    ��� YUV �ļ��Ŀ�ȣ����أ���
 * @param height   ��� YUV �ļ��ĸ߶ȣ����أ���
 * @param ymin     Y ��������Сֵ��
 * @param ymax     Y ���������ֵ��
 * @param barnum   ���Ƶ�������
 * @param url_out  ��� YUV �ļ���λ�á�
 */

int simplest_yuv420_graybar(int width, int height, int ymin, int ymax, int barnum, char *url_out) {
    int barwidth;            // ÿ�����ƵĿ��
    float lum_inc;           // Y ����������
    unsigned char lum_temp;  // ��ǰ Y ����ֵ
    int uv_width, uv_height; // U �� V �����Ŀ�Ⱥ͸߶�

    FILE *fp = NULL;         // �ļ�ָ��
    unsigned char *data_y = NULL; // Y ��������
    unsigned char *data_u = NULL; // U ��������
    unsigned char *data_v = NULL; // V ��������

    int t = 0, i = 0, j = 0;

    // ����ÿ�����ƵĿ��
    barwidth = width / barnum;
    // ���� Y ����������
    lum_inc = ((float)(ymax - ymin)) / ((float)(barnum - 1));
    // U �� V �����ĳߴ�
    uv_width = width / 2;
    uv_height = height / 2;

    // �����ڴ�
    data_y = (unsigned char *)malloc(width * height);
    data_u = (unsigned char *)malloc(uv_width * uv_height);
    data_v = (unsigned char *)malloc(uv_width * uv_height);

    // ������ļ�
    if ((fp = fopen(url_out, "wb+")) == NULL) {
        printf("����: �޷������ļ�!\n");
        return -1;
    }

    // �����Ϣ
    printf("�����ҵ� Y, U, V ֵ:\n");
    for (t = 0; t < (width / barwidth); t++) {
        lum_temp = ymin + (char)(t * lum_inc);
        printf("%3d, 128, 128\n", lum_temp);
    }

    // ���� Y ��������
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            t = i / barwidth;
            lum_temp = ymin + (char)(t * lum_inc);
            data_y[j * width + i] = lum_temp;
        }
    }

    // ���� U ��������
    for (j = 0; j < uv_height; j++) {
        for (i = 0; i < uv_width; i++) {
            data_u[j * uv_width + i] = 128;
        }
    }

    // ���� V ��������
    for (j = 0; j < uv_height; j++) {
        for (i = 0; i < uv_width; i++) {
            data_v[j * uv_width + i] = 128;
        }
    }

    // д���ļ�
    fwrite(data_y, width * height, 1, fp);
    fwrite(data_u, uv_width * uv_height, 1, fp);
    fwrite(data_v, uv_width * uv_height, 1, fp);

    // �ر��ļ����ͷ��ڴ�
    fclose(fp);
    free(data_y);
    free(data_u);
    free(data_v);

    return 0;
}

int main()
{

	simplest_yuv420_graybar(176, 144,0,255,10,"../out1.yuv");
    return 0;
}