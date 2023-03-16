//
//  2023年 实验2
//  dev.betax.edu
//
//  Created by Skay on 2023/3/16.
//

// 运行某题目请先将函数名改为main

#include <stdio.h>

// 题目1.1 键盘输入任意一个小写字母，将其转换成大写字母，然后输出
int main1() {
    char c1,c2;
    c1 = getchar();
    if (c1 >= 'a' && c1 <= 'z') c2 = c1 - ('a' - 'A');
    else c2 = c1;
    putchar('\n');
    putchar('\'' );
    putchar(c2);
    putchar('\'' );
    return 0;
}

// 题目1.2 用switch 结构编写一个处理四则运算的程序
int main2() {
    float v1, v2; char op;
    printf("please type your expression:\n");
    scanf("%f%c%f",&v1,&op,&v2);
    switch (op){
        case '+': printf("%1.0f+%1.0f=%1.0f\n", v1, v2, v1 + v2); break;
        case '-': printf("%1.0f-%1.0f=%1.0f\n", v1, v2, v1 - v2); break;
        case '*': printf("%1.0f*%1.0f=%1.0f\n", v1, v2, v1 * v2); break;
        case '/':
            if (v2 == 0) printf("除数为零\n");
            else printf("%1.0f/%1.0f=%1.0f\n",v1,v2,v1/v2);
            break;
        default: printf("运算符错误\n");
    }
    return 0;
}

// 题目2 输入一个三位数，然后进行个位和百位的置换并输出
int main3(){
    int num;
    printf("Please type three digits:\n");
    // 接收入参
    scanf("%i",&num);
    // 判断是否传入三位数值
    if (num < 100 || num > 999) {
        printf("Are these three digits?\n");
    } else {
        // 运用取10余截取末位数的方式
        num = (( num % 10 ) * 100 ) + ( num / 10 % 10 * 10) + ( num / 100 );
        printf("%i\n",num);
    }
    return 0;
}

// 题目3 输入某年某月某日，判断这一天是这一年的第几天
int main4(){
    int y,m,d,num=0;
    printf("Please yyyy-mm-dd:\n");
    // 接收入参
    scanf("%i-%i-%i",&y,&m,&d);
    switch(m){
        case 12: num = num + 31;
        case 11: num = num + 30;
        case 10: num = num + 31;
        case 9: num = num + 30;
        case 8: num = num + 31;
        case 7: num = num + 31;
        case 6: num = num + 30;
        case 5: num = num + 31;
        case 4: num = num + 30;
        case 3: num = num + 31;
        case 2: num = num + (( y % 400 == 0 || ( y % 4 == 0 && y % 100 != 0 )) ? 29:28);
        case 1: num = num + d; break;
        default:printf("Invalid input date"); break;
    }
    printf("%i\n",num);
    return 0;
}


// 题目4 输入3个整数，按从小到大方式将它们依次输出
int main5(){
    int num[3], i;
    printf("Please type three integers:\n");
    // 接收3个整数
    for ( i = 0; i < 3; i++ ) {
        scanf("%d", &num[i]);
    }
    // 计算数组长度
    int size = sizeof(num) / sizeof(num[0]);
    // 判断是否传入3个整数
    if (size != 3) {
        printf("Are these three digits?\n");
    } else {
        // 冒泡排序
        for (i = 0; i < size - 1; i++) {
            int j = 0;
            for (j = 0; j < size - 1 - i; j++) {
                if (num[j] > num[j + 1]) {
                    int tmp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = tmp;
                }
            }
        }
        printf("After positive sort:\n");
        // 依次输出
        for (i = 0; i < size; i++) {
            printf("%i\n",num[i]);
        }
    }
    
    return 0;
}

// 题目5 输入3个整数，输出其中最小的那个
int main6(){
    int num[3], i;
    printf("Please type three integers:\n");
    // 接收3个整数
    for ( i = 0; i < 3; i++ ) {
        scanf("%d", &num[i]);
    }
    
    // 计算数组长度
    int size = sizeof(num) / sizeof(num[0]);
    // 判断是否传入3个整数
    if (size != 3) {
        printf("Are these three digits?\n");
    } else {
        int min = num[0];
        for (i = 0; i < size; i++) {
            if (min > num[i]) min = num[i];
        }
        printf("Minimum:\t%i\n", min);
    }
    return 0;
}

// 题目6 依次读入一个整数的各个数字字符，得到该整数并输出
int main7(){
    int tmp,num = 0;
    printf("Please type your number:\n");
    // 循环读取, 只要没有输入回车
    while((tmp = getchar()) != '\n') {
        // 判断输入是否为数值, 不是的忽略
        if(tmp >= '0' && tmp <= '9') {
            // 原始值进一位加上输入值
            // 减去字符0, 不然输出不是数值
            num = num * 10 + tmp - '0';
        }
    }
    printf("Your number：%d\n",num);
    return 0;
}
