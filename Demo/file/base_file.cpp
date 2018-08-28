#include "base_file.h"

/**
 * ���ֽ�copy�ļ�
 */
int copy_file(string read_path, string write_path) {
	// �����ļ�
	FILE *read_file, *write_file;

	// ���ļ����ж��Ƿ�򿪳ɹ�
	if ((read_file = fopen(read_path.c_str(), "rb+")) == NULL) {
		return -1;
	}

	// ���ļ����ж��Ƿ�򿪳ɹ�
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
 * ͨ��buffcopy�ļ�
 */
int copy_file_from_buffer(string read_path, string write_path) {
	// �����ļ�
	FILE *read_file, *write_file;

	// ���ļ����ж��Ƿ�򿪳ɹ�
	if ((read_file = fopen(read_path.c_str(), "rb+")) == NULL) {
		return -1;
	}

	// ���ļ����ж��Ƿ�򿪳ɹ�
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
