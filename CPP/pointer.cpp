A pointer in C++ is used to share a memory address among different contexts (primarily functions). They are used whenever a function needs to modify the content of a variable, but it does not have ownership.

In order to access the memory address of a variable, , prepend it with  sign. For example, &val returns the memory address of .

This memory address is assigned to a pointer and can be shared among functions. For example,  assigns the memory address of  to pointer . To access the content of the memory pointed to, prepend the variable name with a *. For example, *p will return the value stored in  and any modification to it will be performed on .

void increment(int *v) {
    (*v)++;
}

int main() {
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d", a);
    return 0;
}  

the description says that pointer is uesd to share memory among mostly functions, but actually in reallife
coding environment, we use reference. 
*b can change the value to poitner points to within a functioin and keep the change at the outer
space also, it is pass by reference. not pass by value.