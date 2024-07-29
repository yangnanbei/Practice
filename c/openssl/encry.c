#include "common_header.h"
#include "util.h"

int main(int argc, char* argv[])
{
	// 存放填充字节数的数组
	char offset[4] = { '0' };

	char* src = nullptr, *dst = nullptr;
	int inlen, outlen, size;
	FILE* srcFile, *dstFile;

	// 打开被加密源文件
	srcFile = fopen("./src.txt", "rb");

	// 加密后写出文件
	dstFile = fopen("./output.txt", "wb+");

	// 获取文件大小
	fseek(srcFile, 0, SEEK_END);
	inlen = ftell(srcFile);
	if (inlen < 0)
	{
		return 0;
	}
	fseek(srcFile, 0, SEEK_SET);

	// -------------------------------------------------------
	// 开始加密
	src = (char*)calloc(inlen, 1);
	size = fread(src, 1, inlen, srcFile);
	std::cout << "读入字节: " << size << std::endl;

	// 输出变量申请的空间额外增加16字节
	outlen = (inlen / 16 + 1) * 16;
	dst = (char*)calloc(outlen, 1);

	// ECB加密
	size = openssl_aes_ecb_enrypt(src, inlen, dst);
	sprintf(offset, "%d", size - inlen);
	fwrite(offset, sizeof(char), 4, dstFile);

	// -------------------------------------------------------
	// 输出加密后的文件或者解密后的文件，文件大小应与原始文件一致
	size = fwrite(dst, 1, size, dstFile);
	std::cout << "输出文件大小: " << size << std::endl;

	fcloseall();
	free(src);
	free(dst);
	system("pause");
	return 0;
}

