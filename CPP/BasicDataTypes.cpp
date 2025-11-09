    int v1;
    long v2;
    char v3;
    float v4;
    double v5;
    scanf("%d %ld %c %f %lf", &v1,&v2,&v3,&v4,&v5); scanf 不能有位数，全部读入
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", v1,v2,v3,v4,v5);

   c++ 格式化输出小数点后三位
   在 C++ 中，如果你想格式化输出 小数点后三位，可以使用 <iomanip> 头文件里的 std::fixed 和 std::setprecision()。

   #include <iostream>
   #include <iomanip>  // 需要这个头文件
   using namespace std;

int main() {
    double x = 3.1415926535;

    cout << fixed << setprecision(3) << x << endl;

    return 0;
}
3.142


cout << setprecision(3) << x;	3.14	默认会输出 总共 3 位有效数字（非固定小数）
cout << fixed << setprecision(3) << x;	3.142	固定小数点后 3 位
cout << fixed << setprecision(0) << x;	3	四舍五入到整数

printf
#include <cstdio>
using namespace std;

int main() {
    double x = 3.1415926535;

    printf("%.3f\n", x);

    return 0;
}


%.3f 表示输出浮点数（f），保留小数点后三位。

. 后的数字控制小数位数。
例如：

%.2f → 保留两位小数

%.5f → 保留五位小数

double x = 1.23456;

printf("%10.3f\n", x);   // 右对齐，总宽度10，小数3位
printf("%-10.3f\n", x);  // 左对齐，总宽度10，小数3位

scanf 也可以这样.3f吗
非常好问题 👍
—— 不可以。

scanf() 和 printf() 在格式说明上虽然长得很像，但它们的 用途完全相反。

✅ 总结一句话：

printf("%.3f", x) 控制“输出格式”；
scanf() 只负责“输入读取”，不能控制精度或位数。

double x;
scanf("%lf", &x);  // ✅ 正确：读取一个 double


scanf("%.3lf", &x);  // ❌ 错误：scanf 不认识 “.3”

