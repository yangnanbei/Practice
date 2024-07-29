#ifndef _UTIL_HEADER_H_
#define _UTIL_HEADER_H_


int openssl_aes_ecb_enrypt(char* in, size_t len, char* out);
int openssl_aes_ecb_decrypt(char* in, size_t len, char* out);

#endif /* _UTIL_HEADER_H_ */
