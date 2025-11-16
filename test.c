#include "ft_printf.h"
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int g_pass = 0;
int g_fail = 0;

// マクロでテストケースを定義
#define TEST(name, ...) do { \
    int ft_ret, printf_ret; \
    printf("\n[TEST] %s\n", name); \
    printf("ft_printf: "); \
    ft_ret = ft_printf(__VA_ARGS__); \
    printf("\n   printf: "); \
    printf_ret = printf(__VA_ARGS__); \
    printf("\n"); \
    if (ft_ret == printf_ret) { \
        printf(GREEN "✓ PASS" RESET " (ret: %d)\n", ft_ret); \
        g_pass++; \
    } else { \
        printf(RED "✗ FAIL" RESET " (ft: %d, printf: %d)\n", ft_ret, printf_ret); \
        g_fail++; \
    } \
} while(0)

int main(void)
{
    printf("========== ft_printf Test Suite ==========\n");
    
    // 基本テスト
    TEST("Char", "%c", 'A');
    TEST("String", "%s", "Hello");
    TEST("Decimal", "%d", 42);
    TEST("Integer", "%i", -42);
    TEST("Unsigned", "%u", 4294967295U);
    TEST("Hex lower", "%x", 255);
    TEST("Hex upper", "%X", 255);
    TEST("Percent", "%%");
    TEST("Pointer", "%p", (void *)0x12345678);
    
    // Width
    TEST("Width char", "|%5c|", 'A');
    TEST("Width string", "|%10s|", "test");
    TEST("Width int", "|%8d|", 42);
    
    // Precision
    TEST("Precision string", "|%.3s|", "Hello");
    TEST("Precision int", "|%.5d|", 42);
    TEST("Width + Precision", "|%10.5d|", 42);
    
    // Flag: '-'
    TEST("Left align", "|%-8d|", 42);
    
    // Flag: '0'
    TEST("Zero padding", "|%08d|", 42);
    TEST("Zero negative", "|%08d|", -42);
    
    // Flag: '+'
    TEST("Plus positive", "|%+d|", 42);
    TEST("Plus negative", "|%+d|", -42);
    TEST("Plus width", "|%+8d|", 42);
    
    // Flag: ' '
    TEST("Space positive", "|% d|", 42);
    TEST("Space width", "|% 8d|", 42);
    
    // Flag: '#'
    TEST("Hash hex", "|%#x|", 0x42);
    TEST("Hash width", "|%#10x|", 0x42);
    TEST("Hash zero pad", "|%#010x|", 0x42);
    TEST("Hash precision", "|%#10.8x|", 0x1234);
    
    // 組み合わせ
    TEST("'-' + '0'", "|%-08d|", 42);
    TEST("'+' + ' '", "|%+ d|", 42);
    TEST("'0' + precision", "|%08.5d|", 42);
    TEST("Zero + plus", "|%+08d|", 42);
    TEST("Left + hash", "|%-#10x|", 0x42);
    
    // エッジケース
    TEST("Zero value", "%d", 0);
    TEST("NULL string", "%s", (char *)NULL);
    TEST("Empty string", "%s", "");
    TEST("Multiple", "%d %s %c", 42, "test", 'A');
    
    // まとめ
    printf("\n========== Summary ==========\n");
    printf("Total: %d\n", g_pass + g_fail);
    printf(GREEN "Pass: %d\n" RESET, g_pass);
    printf(RED "Fail: %d\n" RESET, g_fail);
    
    return (g_fail > 0 ? 1 : 0);
}