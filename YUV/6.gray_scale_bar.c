#include<stdio.h>
#include <stdlib.h>
/**
 * 生成 YUV420P 格式的灰度条纹图像。
 * 
 * @param width    输出 YUV 文件的宽度（像素）。
 * @param height   输出 YUV 文件的高度（像素）。
 * @param ymin     Y 分量的最小值。
 * @param ymax     Y 分量的最大值。
 * @param barnum   条纹的数量。
 * @param url_out  输出 YUV 文件的位置。
 */

int simplest_yuv420_graybar(int width, int height, int ymin, int ymax, int barnum, char *url_out) {
    int barwidth;            // 每个条纹的宽度
    float lum_inc;           // Y 分量的增量
    unsigned char lum_temp;  // 当前 Y 分量值
    int uv_width, uv_height; // U 和 V 分量的宽度和高度

    FILE *fp = NULL;         // 文件指针
    unsigned char *data_y = NULL; // Y 分量数据
    unsigned char *data_u = NULL; // U 分量数据
    unsigned char *data_v = NULL; // V 分量数据

    int t = 0, i = 0, j = 0;

    // 计算每个条纹的宽度
    barwidth = width / barnum;
    // 计算 Y 分量的增量
    lum_inc = ((float)(ymax - ymin)) / ((float)(barnum - 1));
    // U 和 V 分量的尺寸
    uv_width = width / 2;
    uv_height = height / 2;

    // 分配内存
    data_y = (unsigned char *)malloc(width * height);
    data_u = (unsigned char *)malloc(uv_width * uv_height);
    data_v = (unsigned char *)malloc(uv_width * uv_height);

    // 打开输出文件
    if ((fp = fopen(url_out, "wb+")) == NULL) {
        printf("错误: 无法创建文件!\n");
        return -1;
    }

    // 输出信息
    printf("从左到右的 Y, U, V 值:\n");
    for (t = 0; t < (width / barwidth); t++) {
        lum_temp = ymin + (char)(t * lum_inc);
        printf("%3d, 128, 128\n", lum_temp);
    }

    // 生成 Y 分量数据
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            t = i / barwidth;
            lum_temp = ymin + (char)(t * lum_inc);
            data_y[j * width + i] = lum_temp;
        }
    }

    // 生成 U 分量数据
    for (j = 0; j < uv_height; j++) {
        for (i = 0; i < uv_width; i++) {
            data_u[j * uv_width + i] = 128;
        }
    }

    // 生成 V 分量数据
    for (j = 0; j < uv_height; j++) {
        for (i = 0; i < uv_width; i++) {
            data_v[j * uv_width + i] = 128;
        }
    }

    // 写入文件
    fwrite(data_y, width * height, 1, fp);
    fwrite(data_u, uv_width * uv_height, 1, fp);
    fwrite(data_v, uv_width * uv_height, 1, fp);

    // 关闭文件并释放内存
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