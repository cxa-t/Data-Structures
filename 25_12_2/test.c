//#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<locale.h>
//int main()
//{
//	char* ret = setlocale(LC_ALL, NULL);
//	puts(ret);
//	ret = setlocale(LC_ALL, "");//适应本地化环境
//	puts(ret);
//	return 0;
//}

///* setlocale 函数使用示例 */
//#include <stdio.h>      /* 用于 printf 函数 */
//#include <time.h>       /* 用于 time_t, struct tm, time, localtime, strftime 等时间函数 */
//#include <locale.h>     /* 用于 struct lconv, setlocale, localeconv 等本地化函数 */

//int main()
//{
//    /* 声明变量 */
//    time_t rawtime;         // 用于存储从1970年1月1日（UTC）开始的秒数（日历时间）
//    struct tm* timeinfo;   // 指向 tm 结构的指针，用于存储分解后的本地时间信息
//    char buffer[80];       // 字符缓冲区，用于存储格式化后的日期时间字符串
//
//    struct lconv* lc;      // 指向 lconv 结构的指针，用于获取本地化格式信息（如货币符号）
//
//    /* 获取当前的日历时间，存入 rawtime */
//    time(&rawtime);
//    /* 将日历时间 rawtime 转换为本地时间，并用 tm 结构体表示，返回指针赋给 timeinfo */
//    timeinfo = localtime(&rawtime);
//
//    int twice = 0; // 循环控制标志，初始化为0，确保循环执行两次
//
//    /* 开始一个 do...while 循环。循环会执行两次，用于对比设置本地化前后的差异 */
//    do {
//        /* 1. 打印当前的区域设置（Locale）
//         * setlocale(LC_ALL, NULL)：参数为 NULL 时，函数返回当前区域设置的字符串表示，但不改变设置。
//         * 第一次循环，会打印程序启动时的默认区域设置（通常是 "C"）。
//         * 第二次循环，会打印第一次循环末尾设置的新区域设置（通常是系统默认，如 "zh_CN.UTF-8"）。
//         */
//        printf("Locale is: %s\n", setlocale(LC_ALL, NULL));
//
//        /* 2. 格式化并打印时间
//         * strftime：根据格式化字符串将 tm 结构的时间信息格式化为字符串。
//         * "%c"：标准日期和时间表示符。其具体输出格式**取决于当前的区域设置（LC_TIME）**。
//         * 第一次循环（"C"环境）：输出类似 "Thu May 23 14:55:21 2024"。
//         * 第二次循环（本地环境）：输出可能变为 "2024年5月23日 14:55:21" 或 "23/05/24 14:55:21"。
//         */
//        strftime(buffer, 80, "%c", timeinfo);
//        printf("Date is: %s\n", buffer);
//
//        /* 3. 获取并打印货币符号
//         * localeconv()：返回一个指向 lconv 结构的指针，该结构包含了当前区域下的数字、货币格式化规则。
//         * lc->currency_symbol：是该结构中的一个成员，指向表示本地货币符号的字符串（如"$", "¥", "€"）。
//         * 第一次循环（"C"环境）：通常是空字符串 "" 或基本符号 "$"。
//         * 第二次循环（本地环境）：会变为操作系统的默认货币符号（如在中文系统是 "¥"）。
//         */
//        lc = localeconv();
//        printf("Currency symbol is: %s\n-\n", lc->currency_symbol);
//
//        /* 4. 关键操作：设置区域为系统默认
//         * setlocale(LC_ALL, "")：参数为空字符串""时，函数会将所有类别（LC_ALL）的区域设置
//         * 设置为操作系统定义的“本地环境”（通常由环境变量 LANG 等决定）。
//         * **注意**：这个调用在循环的末尾，所以它会影响下一次循环（第二次）的行为。
//         * 它不会立即改变本次循环中 strftime 和 localeconv 的结果，因为它们已经被调用过了。
//         */
//        setlocale(LC_ALL, "");
//
//    } while (!twice++); // 循环条件：当 twice 为 0 时，!0 为真，循环继续。执行完判断后 twice 自增为1。
//    // 第二次判断时，twice 为1，!1 为假，循环结束。
//    // 此写法巧妙保证了循环恰好执行两次（twice=0 和 twice=1 时各一次）。
//
//    return 0;
//}


//int main() 
//{
//	//设置本地化
//	setlocale(LC_ALL, "");
//
//	printf("%c%c\n", 'a', 'b');
//
//	wchar_t ch1 = L'●';
//	wchar_t ch2 = L'储';
//	wchar_t ch3 = L'顺';
//	wchar_t ch4 = L'安';
//	wchar_t ch5 = L'★';
//	wchar_t ch6 = L'◎';
//	wchar_t ch7 = L'◆';
//	
//
//	wprintf(L"%lc\n", ch1);
//	wprintf(L"%lc\n", ch2);
//	wprintf(L"%lc\n", ch3);
//	wprintf(L"%lc\n", ch4);
//	wprintf(L"%lc\n", ch5);
//	wprintf(L"%lc\n", ch6);
//	wprintf(L"%lc\n", ch7);
//	return 0;
//}


//int main()
//{
//	system("mode con cols=20 lines=20");
//}