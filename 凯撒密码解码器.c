#include <stdio.h>

int main() {
    char ciphertext[100];

    printf("请输入密文：\a");   
    scanf_s("%99s", ciphertext, (unsigned)sizeof(ciphertext));
    {
        for (int i = 0; ciphertext[i] != '\0'; ++i)     
        {
            char c = ciphertext[i];
            if (c >= 'A' && c <= 'Z')
            {
                // 解密：向左移位 1 位，A -> Z
                ciphertext[i] = (char)((c - 'A' + 25) % 26 + 'A');
            }
            else if (c >= 'a' && c <= 'z')
            {
                ciphertext[i] = (char)((c - 'a' + 25) % 26 + 'a');
            }
            // 非字母字符保持不变
        }

        printf("解密为：%s\n", ciphertext);
    }

    return 0;
}