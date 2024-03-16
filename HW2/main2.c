#include <stdio.h>

int main() {
    FILE *input_file = fopen(__FILE__, "r"); 
    FILE *output_file = fopen("main2.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("無法打開文件。\n");
        return 1;
    }

    int ch;

    
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch, output_file);
    }

    
    fclose(input_file);
    fclose(output_file);

    printf("程式已複製到 main2.txt。\n");

    return 0;
}
