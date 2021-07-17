#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//
// WORKING WITH POINTERS
//
void pointers()
{
    int a = 10;
    int b = 20;
    int* p = &a;        // &a = address of a
    printf("pointer value = %p\n", p);
    printf("value pointed = %d\n", *p); // *p = value at adress ponted by p
    printf("a address = %p\n", &a);
    *p = 12;    // dereferencing and assingn
    printf("value pointed modified by deferencing p = %d\n", *p);
    p = &b;     // reassing pointer value
    printf("new pointer value = %p\n", p);
}
//
// POINTER ARITHMETIC
//
void pointers_arithmetic()
{
    int a = 10;
    int* p = &a;
    printf("Address p is %d\n", p);      // e.g. p is 2002
    printf("size of integer is %d bytes\n", sizeof(p));
    printf("Address p+1 is %d\n", p+1);  // e.g. p + 1 is 2006
    printf("value at address p+1 is %d\n", *(p+2));   // garbage value
    // * binds tighter than + so *p+2 = dereference 10 + 2 = 12
    // *(p+2) address p + 2 and after dereference a garbage value
}
//
// POINTER TYPES
//
void pointer_types_1()
{
    // int* -> int
    // dounble* -> double
    double da = 1.0;
    double* pda = & da;
    int a = 10;
    int* pa = &a;
    printf("value of da = %f\n", da);
    printf("value of pda = %p\n", pda);
    printf("value of a = %d\n", a);
    printf("value of pa = %p\n", pa);
}

void pointer_types_2()
{
    int a = 1025;
    int* p = &a;
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address of p = %p, value of p = %d\n", p, *p);
    printf("Address of p+1 = %p, value of p+1 = %d\n", p+1, *(p+1));
    char *p0;
    p0 = (char*)p;     // p0 = p; compilation error p is a int * and p0 char *
    // typecasting
    printf("size of integer is %d bytes\n", sizeof(char));
    printf("Address of p0 = %p, value of p0 = %d\n", p0, *p0);
    printf("Address of p0+1 = %p, value of p0+1 = %d\n", p0+1, *(p0+1));
    // int a = 1025 = 00000000 00000000 00000100 00000001
}
//
// VOID POINTERS
//
void void_pointer()
{
    int a = 1025;
    int* p = &a;
    void *p0;
    p0 = p;     // doesn't need type casting
    // this void pointer doesn't have a type is just an address
    // so this pointer cannot do ointer arithmatic operations or dereference
}
//
// POINTERS TO POINTERS
//
void pointers_to_pointers()
{
    int x = 5;
    int *p = &x;
    *p = 6;
    int **q = &p;   // this pointer only accept int*
    int ***r = &q;  // this pointer only accept int**
    printf("%d\n", *p);
    printf("%p\n", *q);     // value in p (pointer)
    printf("%d\n", **q);    // value in x (int)
    printf("%d\n", **r);    // value in p (pointer)
    printf("%d\n", ***r);    // value in x (int)
    ***r = 10;
    printf("x = %d\n", x);
    **q = *p + 2;
    printf("x = %d\n", x);
}
//
// POINTERS AS FUNCTION ARGUMENTS - CALL BY REFERENCE
//
void increment_cp(int x)
{
    // call by value, creates a copy of the parameter
    x = x+1;
    printf("Address of variable a in increment = %d\n", &x);
}

void increment_ref(int* p)
{
    // call by reference, points to the variable outsize of the function
    *p = *p+1;
}

void increment_ref2(int &r)
{
    // another and simples way to call by reference
    r = r+1;
}

void run_call_by_reference()
{
    int a;
    a = 10;
    increment_cp(a);
    // diferente address a in run_call_by_reference is diferent
    // in the increment_cp. because calls by value
    printf("Address of variable a in run_call_by_reference = %d\n", &a);
    increment_ref(&a);
    increment_ref2(a);
    printf("2x increment\na = %d", a);
    
}
//
// POINTERS AND ARRAYS
//
void pointers_and_arrays()
{
    int A[] = { 2, 4, 5, 8, 1 };
    int* p = &A[0];     // will give the address of the first element of the array
    p = A;  // another way to get the address of the first element of the array
    p++;    // if we try A++ will give a compilation error, when we assign a pointer we can increment
    // so &A[i] is equal to A+i
    // then A[i] is equal to *A+i
    for(int i = 0; i < 5; i++)
    {
        printf("%p\n", &A[0]);
        printf("%p\n", A+i);
        printf("%d\n", A[0]);
        printf("%d\n", *(A+i));
    }
}
//
// ARRAY AS FUNCTION ARGUMENTS
//
int sum_of_elements_error(int A[])
{
    // int A[] copy the A pointer, that's is the first
    // element of the array and doesn't copy the array
    // int A[] it's the same as int* A
    // so we cannot know the size of the array we need to paste it
    printf("A = %p\n", A);
    int i, sum = 0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("SOE - size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));   
    for(int i = 0; i < size; i++)
        sum += A[i];
    return sum;
}

int sum_of_elements(int* A, int size)
{
    int i, sum = 0;
    printf("SOE - size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));   
    for(int i = 0; i < size; i++)
        sum += A[i];
    return sum;
}

void run_array_arguments()
{
    int A[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(A)/sizeof(A[0]);
    int total = sum_of_elements_error(A);
    printf("Sum of elements error = %d\n", total);
    int total2 = sum_of_elements(A, size);
    printf("Sum of elements = %d\n", total2);
}
//
// CHARACTER ARRAYS AND POINTERS
//
void string_eg()
{
    // how to store stringstream
    // size of array > no. of char in string + 1
    // string need be termineted in a null char (\0)
    char C[20];
    C[0] = 'J';
    C[1] = 'o';
    C[2] = 'h';
    C[3] = 'n';
    C[4] = '\0';    // this char terminate the string no metter how
    // long is the char array
    // coment this char and the string break or you get a undefiened behaviour
    int len = strlen(C);    // calculate the string length not the actual 
    // array length (string + null char)
    printf("%s\n", C);
    printf("Length = %d\n", len);
    
    char C2[] = "JOHN";   // string literal are defined by double quotes
    // this will automatic put a null char termination
    // you can define the size before the definition or leave it empty
    // leave empty and that will be allocated automatically like any other array
    // if you define a size smaller than the string literal definition
    // will give a compilation error (array overflow) or will narrow the string
    // remember that the size needs to take into account the null char
    
    printf("%s", C2); 
}

void array_and_pointers_differ()
{
    // arrays and pointers are differrent types that are used in similar manner
    char C1[6] = "Hello";
    char* C2 = C1;      // this is valid, but C1 = C2 are invalid
    // C1 = C1+1 is invalid, cannot be incremented or decremented
    // this limitetions are overcomed by pointers
    printf("%c\n", C2[1]);  // e, C2[i] is *(C2+1)
    C2[0] = 'A';
    printf("%s\n", C2); // "Aello"
}

void my_print(char* C)
{
    // arrays are always passed to function by reference
    // the C pointer is a address copy of the parameter
    // that leave in this function scope
    int i = 0;
    C[0] = 'A'; // in this function we can modify the array
    bool alternative = true;
    if (!alternative){
        // this function knows only the base address of the array
        while(C[i] != '\0') // *(C+i) is the same C[i]
        {
            printf("%c", C[i]);
            i++;
        }
    }
    else{
        printf("alternative:\n");
        while(*C != '\0')   // alternative
        {
            printf("%c", *C);
            C++;
        }
    }
    printf("\n");   // print end of line
}

void ts_my_print(const char* C)
{
    // type safety
    // to garanty that the function will not modify our string
    // we use const
    int i = 0;
        while(*C != '\0') // *(C+i) is the same C[i]
    {
        printf("%c", *C);
        C++;    // we can increment our pointer
    }
    printf("\n");
}

void run_my_print()
{
    char C[20] = "Hello";   // string gets stored in the space for array
    char* C2 = "Hello constant"; // string gets stored as compile time constant
    printf("Hello, World!\n");    // here the same occours
    // so C2[0] = 'A' is invalid
    ts_my_print(C);
    ts_my_print(C2);
    my_print(C);
    my_print(C2);
}
//
// POINTERS, 2D ARRAYS, AND MULTI-DIMENSIONAL ARRAYS
//
void pointers_2d_array()
{
    int B[2][3] = {{2, 3, 6}, {4, 5, 8}};    // 1 dimention array of 3 int
    printf("size of B[0] = %d bytes\n", sizeof(B[0]));    // 12 bytes or 3 * int size
    // int* p = B; this is invalid
    // will return a pointer to 1 d array of 3 int to a int * pointer
    int (*p)[3] = B;  // this is valid
    printf("B[0] value = %p\n", B[0]);  // B[0] is a pointer to the int[3] array
    printf("B = %d\n", B);
    printf("B+1 = %d\n", B+1);  // increment 12 bytes to the address value
    printf("B = %p\n", *(B));
    printf("*(B+1) = %p\n", *(B+1));    // *(B+1) == B[1] == &B[1][0]
    printf("*(B+1)+2 %p\n", *(B+1)+2);  // *(B+1)+2 == B[1]+2 == &B[1][2]
    printf("*(*B+1) %d", *(*B+1));      // 3
    // for 2-D array
    // B[i][j] == *(B[i]+j) == *(*(B+i)+j)
}

void multidimensional_array()
{
    int B[2][3] = {{2, 3, 6}, {4, 5, 8}};    // 1 dimention array of 3 int
    int (*p)[3] = B;  // this is valid
    printf("B = %p\n", B);      // return a pointer of type int (*)[3] (array)
    printf("*B = %p\n", *B);    // return a pointer of type int *
    printf("*B = %p\n", B[0]);  // return a pointer of type int *
    // the above values will be the same, BUT THE BEHAVIOUR WILL NOT
    // the dereference and arithmetic will be completly different
}

void pointers_3d_array()
{
    int C[3][2][2] = {
        {{2, 5}, {7, 9}},
        {{3, 4}, {6, 1}},
        {{0, 8}, {11, 13}}
    };
    int (*p)[2][2] = C;
    printf("p = %p\n", p);
    printf("*C = %p\n", C);    // *C == C[0] == &C[0][0] == int (*)[2]
    // C[i][j][k] == *(C[i][j]+k) == *(*(c[i]+j)+k) == *(*(*(c+i)+j)+k)
    printf("*(C[0][1]+1) = %d\n", *(C[0][1]+1));   // 5 == C[0][1][1]
    printf("*(C[1]+1) = %p\n", *(C[1]+1));  // == C[1][1] or &C[1][1][0]
    printf("%p, %p, %p, %p\n", C, *C, C[0], &C[0][0]);
}

// pass multidimensional array argument
void d1multdim_a_parameter(int A[]){}     // one-D array pointer
void d1multdim_a_parameter2(int *A){}      // A[] parameter == *A

void d2multdim_a_parameter(int (*A)[3]){}   // 2-D array pointer
void d2multdim_a_parameter2(int A[][3]){}   // A[][3] == (*)A[3]
// the first dimention must be left empty, the other dimentions need to be specified
// the caller needs to pass a array of the same size of other dimentions

void d3multdim_a_parameter(int (*A)[2][2]){}    // 3-D array pointer
void d3multdim_a_parameter2(int *A[][2][2]){}    // 3-D array pointer

void run_multdim_array_parameter()
{
    int A[2] = {1, 2};   // A returns int*
    int B[2][3] = {{2, 4, 6}, {5, 7, 8}};   // returns int (*)[3]
    int C[3][2][2] = {
        {{2, 5}, {7, 9}},
        {{3, 4}, {6, 1}},
        {{0, 8}, {11, 13}}
    };
    
}
//
// POINTERS AND DYNAMIC MEMORY - STACK VS HEAP
//
void heap_alloc()
{
    int a;      // goes on stack
    int*p;
    p = (int*)malloc(sizeof(int));
    // malloc will allocate a memory on the heap and return a void pointer
    // to the start address of the block
    // sizeof(int) will pass the size of the memory we need
    // (int*) type casting will covert the return void * to int *
    // p is in the stack with a address value or pointer to the heap
    // that is 4 bytes(int)
    *p = 10;
    // this dereference will assign a value to the heap memory
    // the only way to access a memory on the heap is to reference
    // using pointers
    free(p);    // will free the memory
    p = (int*)malloc(sizeof(int));
    // another malloc call will allocate another 4 bytes on the heap
    // the p pointer is overriten
    // so that's is invalid, we need to free the heap memory before
    // if we will not use anymore
    // if don't the memory will be locked until the need computer restart
    // we need call free()
    // is the responsability of the program clear his own data on the heap
    *p = 20;
    free(p);
}

void array_on_the_heap()
{
    int *p = (int*)malloc(20*sizeof(int));  // array of 20 int on the heap
    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    printf("%d, %d, %d", p[0], p[1], p[2]);
    free(p);
    // if malloc doesn't find the space needed to allocate will return null
}

void cpp_heap_alloc()
{
    // heap allocation in cpp
    int *p;
    p = new int;    // new inted of malloc()
    *p = 10;
    delete p;       // delete intead of free()
    p = new int[20];// allocation of an array
    delete[] p;     // deletion of an array delete[] var;
}   
//
// DYNAMIC MEMORY ALLOCATION - MALLOC, CALLOC, REALLOC, FREE
//
void fill_array(int *A, int size)
{
    for(int i = 0; i < size; ++i)
    {
        A[i] = i + 1;
    }
}

void show_array(int *A, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void dyn_mem_alloc()
{
    int s;
    printf("enter size of array\n");
    scanf("%d", &s);
    int *A = (int*)malloc(s*sizeof(int));    // dynamically allocated array
    //fill_array(A, s);
    int *B = (int*)calloc(s, sizeof(int));   // calloc fills the bytes of the
    // heap with 0s, malloc doesn't do this initialization
    show_array(A, s);
    show_array(B, s);
    
    free(A);
    free(B);
    fill_array(B, s);
    show_array(B, s);
    // ever though we have freeing the memory we can still modify
    // or use depending on the system or compiler, or compiler config
    // but that memory is not allocated to us, so the system can overrite our
    // data and we can overrite some data that can break our program
    // our somewhere else, that's dangerous!
    
    A = (int*)malloc(s*sizeof(int));
    B = (int*)realloc(A, 2*s*sizeof(int));  // equivalent to free(A)
    // relloc copy the values of a block of memory and free the
    // previous block, and can modify the size, if the memory cannot
    // fit or be extended he will copy somewhere else
    // if the first argument of realloc is NULL is equivalent to call malloc
    
    printf("previous block address = %p, new address = %p\n", A, B);
    fill_array(B, s);
    show_array(B, s);
    
}
//
// POINTERS AS FUNCTION RETURNS
//
int add(int a, int b)  // called function
{
    int c = a+b;
    return c;
}

int add_p(int *a, int *b)
{
    printf("address of a in add_p  = %p\n", &a);
    printf("value in a of add_p (address of x of main) = %p\n", a);
    printf("value at address stored in a of add_p  = %d\n", *a);
    int c = (*a) + (*b);
    return c;
}

int* add_p2(int *a, int *b)      // pointer as function return
{
    int c = (*a) + (*b);
    return &c;
}

void print_hello_world()
{
    printf("Hello World\n");
}

int *add_p_heap(int *a, int *b)
{
    int *c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
    // this is safe because points to a heap allocation
    // but that's need's to be clean up manually
}

void run_add()  // calling function
{
    int x = 2, y = 4;
    int z = add(x, y);  // value in x of run_add() is copied to a of add()
                        // value in y of run_add() is copied to b of add()
                        // call by value
    printf("add(x, y) = %d\n", z);
    z = add_p(&x, &y);
    printf("address of x in main = %p\n", &x);
    int *ptr = add_p2(&x, &y);  // this is a problem, the data is not
    // garanty to be in memory after the function scope ends
    print_hello_world();    // this overriten the data of the last function
    // breaking the code, ptr nows points to a garbage value
    printf("add_p2 = %d\n", *ptr);
    // it's ok to pass pointer of the calling scope, but return a pointer
    // of a function can break the code easily
    // so the usecase of return a pointer of a function is if that
    // memory is in the heap, so that can be deallocated manualy after the use
    // or pointer to a static/global variable
    ptr = add_p_heap(&x, &y);
    printf("add_p_heap = %d\n", *ptr);
    free(ptr);  // deallocation heap memory
}
//
// FUNCTION POINTERS IN C
//
int mult(int a, int b)
{
    return a*b;
}

void print_hi()
{
    printf("Hi!\n");
}

void print_hi_compl(const char *complement)
{
    printf("Hi!, %s\n", complement);
}

void run_mult()
{
    int c;
    int (*p)(int, int) = &mult; // &mult == mult
    // the type of the func and arguments must match
    // int (*p)(int, int) != double (*p)(int, int)
    // int (*p)(int, int) != int (*p)(int)
    c = (*p)(2, 2);     // (*p) == p
    printf("%d\n", p(3, 3));
    printf("%d\n", c);
    void (*p2)() = print_hi;
    p2();
    void (*p3)(const char*) = print_hi_compl;
    p3("marina");
}
//
// FUNCTION POINTERS AND CALLBACKS
//
void A() {printf("Hello!\n");}  // A is callback function
void B(void (*ptr)()) {ptr();}  // function pointer as argument

// callback function should compare two integers, should return 1 if first
// element has higher rank, 0 if elements are wqual and -1 if second element
// has higher rank

bool compare_inc(int a, int b)
{
    // compare increase order
    if(a > b) return true;
    else return false;
}
bool compare_dec(int a, int b)
{
    // compare decrease order
    if(a < b) return true;
    else return false;
}
bool compare_abs_inc(int a, int b)
{
    // absolute increase order
    if(abs(a) > abs(b)) return true;
    else return false;
}
bool compare_abs_dec(int a, int b)
{
    // absolute decrease order
    if(abs(a) < abs(b)) return true;
    else return false;
}

void bubble_sort(int *A, int n, bool (*compare)(int, int))
{
    int i, j, temp;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n-1; ++j){
            if(compare(A[j], A[j+1]) != false){  // compare A[j] with A[j+1] and SWAP if needed
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
}

void run_fn_callbacks()
{
    B(A);   // A is a callback function
    int i, A[] = {
        3, 2, 1, 5, 6, 9, 8, 4, 7,
        -3, -2, -1, -5, -6, -9, -8, -4, -7
        };
    int size = sizeof(A) / sizeof(A[0]);
    bubble_sort(A, size, compare_dec);
    for(i = 0; i < size; ++i) printf("%d ", A[i]);
}
//
// MEMORY LEAK IN C
//
int cash = 100;
void play(int bet)
{
    char C[3] = { 'J', 'Q', 'K' };
    printf("shuffling ...\n");
    srand(time(NULL));      // seeding random number generator
    for(int i  = 0; i < 5; ++i){
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;    // swaps characters at position x and you
    }
    int player_guess;
    printf("What's the position of Queen - 1, 2 or 3? ");
    scanf("%d", &player_guess);
    if(C[player_guess - 1] == 'Q') {
        cash += 3*bet;
        printf("You Win! Result = %c %c %c, Total cash %d\n", C[0], C[1], C[2], cash);
    }
    else {
        cash -= bet;
        printf("You Loose! Result = %c %c %c, Total cash %d\n", C[0], C[1], C[2], cash);
    }
}

void play_ml(int bet)
{
    // memory leak example C in the heap memory
    // comment free(C) to see memory leak occour
    char *C = (char*)malloc(3*sizeof(char));
    C[0] = 'J';
    C[1] = 'Q';
    C[2] = 'K';
    printf("shuffling ...\n");
    srand(time(NULL));      // seeding random number generator
    for(int i  = 0; i < 5; ++i){
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;    // swaps characters at position x and you
    }
    int player_guess;
    printf("What's the position of Queen - 1, 2 or 3? ");
    scanf("%d", &player_guess);
    if(C[player_guess - 1] == 'Q') {
        cash += 3*bet;
        printf("You Win! Result = %c %c %c, Total cash %d\n", C[0], C[1], C[2], cash);
    }
    else {
        cash -= bet;
        printf("You Loose! Result = %c %c %c, Total cash %d\n", C[0], C[1], C[2], cash);
    }
    free(C);    // if we don't deallocate a memory leak occour
    // comment free and see the memory leak in the memory consuption
    // of the program
}

void run_casino()
{
    int bet;
    printf("**Welcome to the Virtual Casino**\n\n");
    printf("Total cash = $%d\n", cash);
    while(cash > 0){
        printf("What's your bet? $");
        scanf("%d", &bet);
        if(bet == 0 || bet > cash) break;
        play_ml(bet);
        printf("\n**********************************\n");
    }
}
// memory leak is dangerous make a program increase memory
// over a period of time, only occour when the heap are not deallocated
// the memory used will be blocked until te restart of the program


int main()
{
    run_casino();
}