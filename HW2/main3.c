#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *input_file = fopen(__FILE__, "r"); 
    FILE *output_file = fopen("main2.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("無法打開文件。\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int line_number = 1;
    int main_line = 0;

    
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        if (main_line == 0 && strstr(buffer, "int main()") != NULL) {
            main_line = line_number;
        }
        fprintf(output_file, "%s", buffer);
        line_number++;
    }

    
    if (main_line != 0) {
        fprintf(output_file, "\n%dint main() {\n", main_line);
    } else {
        fprintf(output_file, "\n找不到 int main() 函数\n");
    }
    
    
    fclose(input_file);
    fclose(output_file);

    printf("程式已複製到 main2.txt。\n");

    return 0;
}
