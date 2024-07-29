#include "common_header.h"

// AES ECB 模式加密
// 参数：
// - in: 待加密的数据
// - len: 待加密数据的长度
// - out: 存放加密结果的缓冲区
// 返回值：
// - 成功返回填充后加密数据的长度，失败返回-1
int openssl_aes_ecb_enrypt(char* in, size_t len, char* out)
{
	int i;
	int blockNum;
	int aesInLen;
	char* aesIn;
	AES_KEY aes;

	// 设置加密密钥
	if (AES_set_encrypt_key(key, 128, &aes) < 0)
		return -1;
	// 判断原始数据长度是否AES_BLOCK_SIZE的整数倍
	if ((len % AES_BLOCK_SIZE) != 0)
	{
		blockNum = len / AES_BLOCK_SIZE + 1;
		aesInLen = blockNum * AES_BLOCK_SIZE;
		aesIn = (char*)calloc(aesInLen, 1);
		memcpy(aesIn, in, len);
	}
	else
	{
		blockNum = len / AES_BLOCK_SIZE;
		aesInLen = len;
		aesIn = (char*)calloc(aesInLen, 1);
		memcpy(aesIn, in, len);
	}

	// 由于ECB每次只处理AES_BLOCK_SIZE大小的数据，所以通过循环完成所有数据的加密
	for (i = 0; i < blockNum; i++)
	{
		AES_ecb_encrypt((unsigned char*)aesIn, (unsigned char*)out, &aes, AES_ENCRYPT);
		aesIn += AES_BLOCK_SIZE;
		out += AES_BLOCK_SIZE;
	}

	// 释放内存
	// free(aesIn);
	// 返回填充后加密数据的长度
	return aesInLen;
}

// AES ECB 模式解密
// 参数：
// - in: 待解密的数据
// - len: 待解密数据的长度
// - out: 存放解密结果的缓冲区
// 返回值：
// - 成功返回0，失败返回-1
int openssl_aes_ecb_decrypt(char* in, size_t len, char* out)
{
	unsigned int i;
	AES_KEY aes;
	// 设置解密密钥
	if (AES_set_decrypt_key(key, 128, &aes) < 0)
	{
		return -1;
	}
	// 循环解密每个数据块
	for (i = 0; i < len / AES_BLOCK_SIZE; i++)
	{
		AES_ecb_encrypt((unsigned char*)in, (unsigned char*)out, &aes, AES_DECRYPT);
		in += AES_BLOCK_SIZE;
		out += AES_BLOCK_SIZE;
	}
	// 返回成功
	return 0;
}

