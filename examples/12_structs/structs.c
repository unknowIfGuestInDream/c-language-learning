#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * C语言结构体示例
 * Structures in C
 * 
 * 结构体是C语言中组织复杂数据的主要方式，类似Java的类但没有方法
 * Structures are the primary way to organize complex data in C, similar to Java classes but without methods
 */

// 1. 简单结构体定义 / Simple struct definition
struct Point {
    int x;
    int y;
};

// 2. 使用typedef简化类型名 / Use typedef to simplify type name
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// 3. 嵌套结构体 / Nested struct
typedef struct {
    struct Point top_left;
    struct Point bottom_right;
} Rectangle;

// 4. 包含指针的结构体 / Struct with pointers
typedef struct {
    char *title;
    char *author;
    int year;
    float price;
} Book;

// 5. 链表节点（自引用结构体）/ Linked list node (self-referential struct)
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 函数：打印点 / Function: print point
void printPoint(struct Point p) {
    printf("Point(%d, %d)", p.x, p.y);
}

// 函数：打印点（通过指针）/ Function: print point (by pointer)
void printPointPtr(struct Point *p) {
    printf("Point(%d, %d)", p->x, p->y);
}

// 函数：打印人员信息 / Function: print person info
void printPerson(Person *p) {
    printf("姓名 / Name: %s\n", p->name);
    printf("年龄 / Age: %d\n", p->age);
    printf("身高 / Height: %.2f\n", p->height);
}

// 函数：创建书籍 / Function: create book
Book* createBook(const char *title, const char *author, int year, float price) {
    Book *book = (Book*)malloc(sizeof(Book));
    book->title = (char*)malloc(strlen(title) + 1);
    book->author = (char*)malloc(strlen(author) + 1);
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->year = year;
    book->price = price;
    return book;
}

// 函数：释放书籍内存 / Function: free book memory
void freeBook(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// 函数：打印书籍 / Function: print book
void printBook(Book *book) {
    printf("《%s》\n", book->title);
    printf("  作者 / Author: %s\n", book->author);
    printf("  年份 / Year: %d\n", book->year);
    printf("  价格 / Price: $%.2f\n", book->price);
}

// 函数：向链表添加节点 / Function: add node to linked list
Node* addNode(Node *head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// 函数：打印链表 / Function: print linked list
void printList(Node *head) {
    Node *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}

// 函数：释放链表 / Function: free linked list
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    printf("=== C语言结构体 / Structures in C ===\n\n");
    
    // 1. 简单结构体使用 / Simple struct usage
    printf("1. 简单结构体 / Simple Struct:\n");
    struct Point p1;
    p1.x = 10;
    p1.y = 20;
    printf("  p1 = ");
    printPoint(p1);
    printf("\n");
    
    // 结构体初始化 / Struct initialization
    struct Point p2 = {30, 40};
    printf("  p2 = ");
    printPoint(p2);
    printf("\n");
    
    // 指定成员初始化 / Designated initializer
    struct Point p3 = {.y = 60, .x = 50};
    printf("  p3 = ");
    printPoint(p3);
    printf("\n\n");
    
    // 2. 使用typedef的结构体 / Struct with typedef
    printf("2. 使用typedef的结构体 / Struct with typedef:\n");
    Person person1;
    strcpy(person1.name, "张三 / Zhang San");
    person1.age = 25;
    person1.height = 175.5;
    printf("  ");
    printPerson(&person1);
    printf("\n");
    
    // 3. 结构体赋值 / Struct assignment
    printf("3. 结构体赋值 / Struct Assignment:\n");
    Person person2 = person1;  // 结构体可以直接赋值 / Structs can be directly assigned
    strcpy(person2.name, "李四 / Li Si");
    printf("  person1: ");
    printPerson(&person1);
    printf("  person2: ");
    printPerson(&person2);
    printf("\n");
    
    // 4. 嵌套结构体 / Nested struct
    printf("4. 嵌套结构体 / Nested Struct:\n");
    Rectangle rect = {
        .top_left = {0, 100},
        .bottom_right = {50, 0}
    };
    printf("  矩形 / Rectangle:\n");
    printf("    左上角 / Top-left: ");
    printPoint(rect.top_left);
    printf("\n");
    printf("    右下角 / Bottom-right: ");
    printPoint(rect.bottom_right);
    printf("\n\n");
    
    // 5. 结构体指针 / Struct pointer
    printf("5. 结构体指针 / Struct Pointer:\n");
    struct Point *pPtr = &p1;
    printf("  使用 -> 访问成员 / Using -> to access members:\n");
    printf("    pPtr->x = %d\n", pPtr->x);
    printf("    pPtr->y = %d\n", pPtr->y);
    printf("  等价于 / Equivalent to:\n");
    printf("    (*pPtr).x = %d\n", (*pPtr).x);
    printf("    (*pPtr).y = %d\n", (*pPtr).y);
    printf("\n");
    
    // 6. 动态分配结构体 / Dynamic struct allocation
    printf("6. 动态分配结构体 / Dynamic Struct Allocation:\n");
    Person *personPtr = (Person*)malloc(sizeof(Person));
    strcpy(personPtr->name, "王五 / Wang Wu");
    personPtr->age = 30;
    personPtr->height = 180.0;
    printf("  ");
    printPerson(personPtr);
    free(personPtr);
    printf("\n");
    
    // 7. 包含动态内存的结构体 / Struct with dynamic memory
    printf("7. 包含动态内存的结构体 / Struct with Dynamic Memory:\n");
    Book *book1 = createBook("C Programming", "Dennis Ritchie", 1978, 49.99);
    Book *book2 = createBook("The C Programming Language", "K&R", 1988, 59.99);
    printf("  书籍1 / Book 1:\n  ");
    printBook(book1);
    printf("  书籍2 / Book 2:\n  ");
    printBook(book2);
    freeBook(book1);
    freeBook(book2);
    printf("\n");
    
    // 8. 结构体数组 / Array of structs
    printf("8. 结构体数组 / Array of Structs:\n");
    struct Point points[3] = {
        {10, 20},
        {30, 40},
        {50, 60}
    };
    printf("  点数组 / Array of points:\n");
    for (int i = 0; i < 3; i++) {
        printf("    points[%d] = ", i);
        printPoint(points[i]);
        printf("\n");
    }
    printf("\n");
    
    // 9. 链表示例 / Linked list example
    printf("9. 链表示例（自引用结构体）/ Linked List (Self-referential Struct):\n");
    Node *list = NULL;
    list = addNode(list, 10);
    list = addNode(list, 20);
    list = addNode(list, 30);
    list = addNode(list, 40);
    printf("  链表 / Linked list: ");
    printList(list);
    freeList(list);
    printf("\n");
    
    // 10. 结构体大小 / Struct size
    printf("10. 结构体大小 / Struct Size:\n");
    printf("  sizeof(struct Point) = %zu 字节 / bytes\n", sizeof(struct Point));
    printf("  sizeof(Person) = %zu 字节 / bytes\n", sizeof(Person));
    printf("  sizeof(Rectangle) = %zu 字节 / bytes\n", sizeof(Rectangle));
    printf("  sizeof(Book) = %zu 字节 / bytes\n", sizeof(Book));
    printf("  sizeof(Node) = %zu 字节 / bytes\n", sizeof(Node));
    printf("  注意 / Note: 结构体大小可能因内存对齐而大于成员大小之和\n");
    printf("  Note: Struct size may be larger than sum of members due to alignment\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("结构体特性 / Struct Features:\n");
    printf("  1. 使用 . 访问成员（对象）/ Use . to access members (object)\n");
    printf("  2. 使用 -> 访问成员（指针）/ Use -> to access members (pointer)\n");
    printf("  3. 可以直接赋值 / Can be directly assigned\n");
    printf("  4. 可以作为函数参数和返回值 / Can be function parameters and return values\n");
    printf("  5. 可以包含指针和动态内存 / Can contain pointers and dynamic memory\n");
    printf("  6. 可以自引用（链表、树等）/ Can be self-referential (lists, trees, etc.)\n");
    printf("\n");
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C的struct类似Java的类，但没有方法 / C struct is like Java class but without methods\n");
    printf("  - C的struct没有继承和多态 / C struct has no inheritance or polymorphism\n");
    printf("  - C的struct可以在栈或堆上分配 / C struct can be allocated on stack or heap\n");
    printf("  - C使用指针传递，Java使用引用传递 / C uses pointers, Java uses references\n");
    
    return 0;
}
