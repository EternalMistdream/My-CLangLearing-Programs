#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// 将 clear_input_buffer 声明为静态函数以修复 VCR003
static void clear_input_buffer() {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		// 继续读取直到遇到换行符或文件结束
	}
}

int main() {
	char choice;
	bool in_word = 0;
	bool last_was_letter = 0;
	bool last_was_punct = 0; // 标记上一个字符是否为单引号或连字符，用于回退一次符号计数
	bool last_was_space = 0;
	unsigned int alpha_num = 0;
	unsigned int int_num = 0;
	unsigned int punct_num = 0;
	unsigned int word_num = 0;
	unsigned int space_num = 0;
	int ch;

	printf("1.\t统计文本\n");
	printf("2.\t规范化空白\n");
	printf("3.\tROT13 转换\n");
	printf("Q) 退出\n");
	do
	{
		printf("\n请选择操作: ");
		scanf_s("%c", &choice, 1);
		clear_input_buffer();
		switch (choice)
		{
		case '1':		//1.统计文本
			printf("现在开始统计文本，结果将输出在下方，请在此处输入文本:");
			while ((ch = getchar()) != '\n' && ch != EOF)
			{
				// 字母数字计数
				if (isalnum(ch))
				{ 
					// 如果上一字符是被视为词中符号（' 或 -），在遇到字母/数字时回退一次符号计数
					if (last_was_punct) {
						if (punct_num > 0) {
							punct_num--;
						}
						last_was_punct = 0;
					}

					in_word = 1;
					last_was_letter = 1;

					if (isalpha(ch)) {
						alpha_num++;
					} else {
						int_num++;
					}
					continue;
				}
				// 符号计数
				else
				{
					if (ispunct(ch))
					{
						// 词中允许的连字符或撇号：先计作符号一次，若下一个字符是字母/数字则回退
						if ((in_word && last_was_letter) && (ch == '\'' || ch == '-'))
						{
							punct_num++;        // 暂计一次符号
							last_was_letter = 0;
							last_was_punct = 1; // 标记以便下一次遇到字母/数字回退
							continue;
						}

						// 其他符号处理：正常计数并清除 last_was_punct，避免误回退
						if (in_word && (last_was_letter == 0))
						{
							in_word = 0;
							punct_num++;
							last_was_punct = 0;
							continue;
						}
						else
						{
							in_word = 0;
							last_was_letter = 0;
							punct_num++;
							last_was_punct = 0;
						}
					}
					else if (isspace(ch))
					{
						in_word = 0;
						last_was_letter = 0;
						last_was_punct = 0; // 空白打断单词，清除回退标记
						space_num++;
						continue;
					}
				}
			}

			printf("符号数量:%u\n", punct_num);
			printf("数字数量:%u\n", int_num);
			printf("字母数量:%u\n", alpha_num);
			printf("空格数量:%u\n", space_num);

			// 重置计数与状态
			alpha_num = 0;
			int_num = 0;
			punct_num = 0;
			word_num = 0;
			space_num = 0;
			in_word = 0;
			last_was_letter = 0;
			last_was_punct = 0;
			break;
		case '2':
			printf("现在开始规范化空白，结果将输出在下方，请在此处输入文本:");
			while ((ch = getchar()) != '\n' && ch != EOF)
			{
				if (isspace(ch))
				{
					if (last_was_space)
					{
						ch = NULL;
					}
					last_was_space = 1;
				}
				else 
				{
					last_was_space = 0;
				}
				putchar(ch);
			}
			break;
		case '3':
			printf("现在开始ROT13 转换，结果将输出在下方，请在此处输入文本:");
			while ((ch = getchar()) != '\n' && ch != EOF)
			{
				if (ch >= 'A' && ch <= 'Z')
				{
					ch = (ch - 'A' + 13) % 26 + 'A';
				}
				if (ch >= 'a' && ch <= 'z')
				{
					ch = (ch - 'a' + 13) % 26 + 'a';
				}
				putchar(ch);
			}
			break;
		default:
			break;
		}
	} while (choice != 'Q' && choice != 'q');
	printf("程序已退出\n");
	return 0;
}