
#include <string>
using namespace std;


#define READ_PATH "C:\\Users\\ubt\\Desktop\\e5_191.png"
#define WRITE_PATH "C:\\Users\\ubt\\Desktop\\e5_192.png"

#define BUFF_SIZE 1024

/**
 * 返回0代表成功
 */
int copy_file(string read_path,string write_path);

/**
 * 返回0代表成功
 */
int copy_file_from_buffer(string read_path,string write_path);
