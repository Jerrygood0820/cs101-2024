#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *input_file = fopen("main3.c", "r"); 
    char buffer[BUFFER_SIZE];
	int line_number = 1;
    int main_line = 0;

    if (input_file == NULL) {
        printf("無法打開文件。\n");
        return 1;
    }
    
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
		if (main_line == 0 && strstr(buffer, "int main()") != NULL) {
            main_line = line_number;
			break;
        }
        line_number++;
    } // end of while (fgets(buffer, bufSize, input_file) != NULL)

    
    if (main_line != 0) {
        printf( "\n%d int main() {\n", main_line);
    } else {
        printf( "\n找不到 int main() 函数\n");
    }
    fclose(input_file);
    return 0;
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
