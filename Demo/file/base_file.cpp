#include "base_file.h"

/**
 * 单字节copy文件
 */
int copy_file(string read_path, string write_path) {
	// 声明文件
	FILE *read_file, *write_file;

	// 打开文件并判断是否打开成功
	if ((read_file = fopen(read_path.c_str(), "rb+")) == NULL) {
		return -1;
	}

	// 打开文件并判断是否打开成功
	if ((write_file = fopen(write_path.c_str(), "wb+")) == NULL) {
		return -1;
	}

	char c;

	while (!feof(read_file)) {
		c = fgetc(read_file);
		fputc(c, write_file);
	}

	fclose(read_file);
	fclose(write_file);
	return 0;
}

/**
 * 通过buffcopy文件
 */
int copy_file_from_buffer(string read_path, string write_path) {
	// 声明文件
	FILE *read_file, *write_file;

	// 打开文件并判断是否打开成功
	if ((read_file = fopen(read_path.c_str(), "rb+")) == NULL) {
		return -1;
	}

	// 打开文件并判断是否打开成功
	if ((write_file = fopen(write_path.c_str(), "wb+")) == NULL) {
		return -1;
	}

	char buff[BUFF_SIZE];

	while (fread(buff, BUFF_SIZE, sizeof(char), read_file)) {
		fwrite(buff,  BUFF_SIZE, sizeof(char), write_file);
	}

	fclose (read_file);
	fclose (write_file);

	return 0;
}
