// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int a = 8;
//     int *p = malloc(sizeof(int));

//     int sum = 0;
//     sum += printf("%p\n", "abcd");
//     sum += printf("%p\n", &a);
//     sum += printf("%p\n", p);

//     sum += printf("%x\n", 123);

//     sum += printf("%p\n", NULL);

//     sum += printf("|%-3c|\n", 'a');
//     sum += printf("|%03c|\n", 'a');
//     sum += printf("|%3.2c|\n", 'a');
//     sum += printf("|%#3c|\n", 'a');
//     sum += printf("|% 3c|\n", 'a');
//     sum += printf("|%+3c|\n", 'a');

//     sum += printf("|%-3%|\n");
//     sum += printf("|%03%|\n");
//     sum += printf("|%3.2%|\n");
//     sum += printf("|%#3%|\n");
//     sum += printf("|% 3%|\n");
//     sum += printf("|%+3%|\n");

//     sum += printf("|%-5s|\n", "abc");
//     sum += printf("|%05s|\n", "abc");
//     sum += printf("|%10.2s|\n", "abc");
//     sum += printf("|%#5s|\n", "abc");
//     sum += printf("|% 5s|\n", "abc");
//     sum += printf("|%+5s|\n", "abc");
//     sum += printf("|%0.3s|\n", "abc");
//     sum += printf("|%2s|\n", "abc");

//     char *str = "abc";
//     sum += printf("|%-16p|\n", str);
//     sum += printf("|%-5p|\n", str);
//     sum += printf("|%016p|\n", str);
//     sum += printf("|%16.4p|\n", str);
//     sum += printf("|%#16p|\n", str);
//     sum += printf("|% 14p|\n", str);
//     sum += printf("|%+16p|\n", str);

//     int num = 123456;
//     sum += printf("|%-10d|\n", num);
//     sum += printf("|%4d|\n", num);
//     sum += printf("|%010d|\n", num);
//     sum += printf("|%10.4d|\n", num);
//     sum += printf("|%10.8d|\n", num);
//     sum += printf("|%#10d|\n", num);
//     sum += printf("|% 6d|\n", num);
//     sum += printf("|% 9d|\n", num);
//     sum += printf("|%+10d|\n", num);


//     sum += printf("0:|%-10u|\n", num);
//     sum += printf("1:|%4u|\n", num);
//     sum += printf("2:|%010u|\n", num);
//     sum += printf("!!!3:|%10.4u|\n", num);
//     sum += printf("4:|%10.8u|\n", num);
//     sum += printf("5:|%#10u|\n", num);
//     sum += printf("6:|% 6u|\n", num);
//     sum += printf("7:|% 9u|\n", num);
//     sum += printf("8:|%+10u|\n", num);

//     sum += printf("0:|%-10x|\n", num);
//     sum += printf("1:|%4x|\n", num);
//     sum += printf("2:|%010x|\n", num);
//     sum += printf("3:|%10.4x|\n", num);
//     sum += printf("4:|%10.8x|\n", num);
//     sum += printf("5:|%#10x|\n", num);
//     sum += printf("6:|% 5x|\n", num);
//     sum += printf("7:|% 9x|\n", num);
//     sum += printf("8:|%+10x|\n", num);

//     sum += printf("0:|%10%|\n");
//     sum += printf("1:|%#%|\n");
//     sum += printf("2:|% %|\n");
//     sum += printf("3:|%+%|\n");



//     sum += printf("0:|%-010d|\n", 12345);
//     sum += printf("0:|%0-10d|\n", 12345);

//     sum += printf("0:|%-10.4d|\n", 12345);
//     sum += printf("0:|%-10.6d|\n", 12345);

//     sum += printf("0:|%010.4d|\n", 12345);
//     sum += printf("0:|%010.6d|\n", 12345);

//     sum += printf("0:|% +d|\n", 12345);
//     sum += printf("0:|%+ d|\n", 12345);


//     sum += printf("|%0-10d|\n", 12345);


//     sum += printf("|%-10s|\n", "abc");
//     sum += printf("|%-3.1s|\n", "abc");
//     sum += printf("|% 3.1s|\n", "abc");

//     printf("NULL : %d\n",  printf("%s\n", NULL));
//     return 0;
// }
