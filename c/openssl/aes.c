#include <stdio.h>  
#include <string.h>  
#include <openssl/aes.h>  
  
#define KEY_LENGTH 128  // AES-128  
#define BLOCK_SIZE 16   // AES block size  
  
// 加密函数  
void aes_ecb_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext) {  
    AES_KEY enc_key;  
    AES_set_encrypt_key(key, KEY_LENGTH, &enc_key);  
  
    int num_blocks = plaintext_len / BLOCK_SIZE;  
    for (int i = 0; i < num_blocks; i++) {  
        AES_ecb_encrypt(plaintext + i * BLOCK_SIZE, ciphertext + i * BLOCK_SIZE, &enc_key, AES_ENCRYPT);  
    }  
  
    // 注意：这里没有处理剩余的字节，因为示例中假设明文长度是块大小的整数倍  
}  
  
// 解密函数  
void aes_ecb_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *plaintext) {  
    AES_KEY dec_key;  
    AES_set_decrypt_key(key, KEY_LENGTH, &dec_key);  
  
    int num_blocks = ciphertext_len / BLOCK_SIZE;  
    for (int i = 0; i < num_blocks; i++) {  
        AES_ecb_encrypt(ciphertext + i * BLOCK_SIZE, plaintext + i * BLOCK_SIZE, &dec_key, AES_DECRYPT);  
    }  
  
    // 注意：这里也没有处理剩余的字节，因为示例中假设密文长度是块大小的整数倍  
}  
  
int main() {  
    // 密钥（硬编码，不安全）  
    unsigned char key[KEY_LENGTH / 8] = "aaaaaaaaaaaaaaaa";  
  
    // 明文  
    unsigned char plaintext[64] = "Hello, OpenSSL AES ECB Encryption!";  
    // 确保明文长度是块大小的整数倍（这里简化了处理）  
    int plaintext_len = strlen((char*)plaintext);  
    if (plaintext_len % BLOCK_SIZE != 0) {  
        plaintext[BLOCK_SIZE * (plaintext_len / BLOCK_SIZE)] = '\0';  
        plaintext_len = BLOCK_SIZE * (plaintext_len / BLOCK_SIZE);  
    }  
  
    // 密文  
    unsigned char ciphertext[64];  
    // 解密后的明文  
    unsigned char decryptedtext[64];  
  
    // 加密  
    aes_ecb_encrypt(plaintext, plaintext_len, key, ciphertext);  
  
    // 输出加密结果（以十六进制形式）  
    printf("Encrypted: ");  
    for (int i = 0; i < plaintext_len; i++) {  
        printf("%02x", ciphertext[i]);  
    }  
    printf("\n");  
  
    // 解密  
    aes_ecb_decrypt(ciphertext, plaintext_len, key, decryptedtext);  
  
    // 输出解密结果  
    printf("Decrypted: %s\n", decryptedtext);  
  
    return 0;  
}
