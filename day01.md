```c++
#EndBrace.h

}

```

```c++
#Math.cpp

#define INTEGER int
INTEGER Mutiply(INTEGER a, INTEGER b) {
	INTEGER res = a * b;
	return res;		
#include "EndBrace.h"


int f(int a)
{
	//do nothing
	
#include "EndBrace.h"
```

**生成预处理（preprocesser）过后的文件 .i**

* 将其预处理的代码转义一下，空行也算了

* 但注意，使用preprocessor生成文件后，不生成obj文件，只能将预处理output file 关掉，才能恢复（至少visual stdio是这样）

  

```c++
#line 1 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"

int Mutiply(int a, int b) {
	int res = a * b;
	return res;		
#line 1 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\EndBrace.h"
}
#line 6 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"


int f(int a)
{
	
	
#line 1 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\EndBrace.h"
}
#line 13 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"

```

**2.if与endif**

```c++
#Math.cpp


#if 1
int Mutiply(int a, int b) {
	int res = a * b;
	return res;
}
#endif
```

* **Math.i**

```c++
#line 1 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"


int Mutiply(int a, int b) {
	int res = a * b;
	return res;
}
#line 8 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"

```

*****

**2.1.修改if 0**

Math.cpp file

```c++

#if 0
int Mutiply(int a, int b) {
	int res = a * b;
	return res;
}
#endif
```

math.i file

```c++
#line 1 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"






#line 8 "D:\\Dev\\CppSeries\\HelloWorld\\HelloWorld\\Math.cpp"

```

**3.**

.obj里面存的是二进制文件



* c++汇编到运行过程，cpp->.i->.asm(一般编译器给省略了，没有输出文件，实际是有的)->.obj->.exe



**4.Linker**

```
注意点1：注意不要“重定义”
解决办法：1.在头文件内只进行函数声明，在cpp文件中做函数实现。
		2.在头文件中对函数实现，使用static(静态声明)，或者inline(nei'lian)
```

