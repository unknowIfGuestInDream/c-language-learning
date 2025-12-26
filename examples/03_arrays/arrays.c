#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * C语言数组操作示例
 * Array Operations in C
 * 
 * C语言没有像Java的ArrayList那样的动态数组，但可以使用动态内存分配实现类似功能
 * C doesn't have Java-like ArrayList, but we can achieve similar functionality with dynamic memory allocation
 */

// 打印数组 / Print array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// 动态数组结构 / Dynamic array structure (类似Java的ArrayList / Similar to Java's ArrayList)
typedef struct {
    int *data;      // 数据数组 / Data array
    int size;       // 当前元素个数 / Current number of elements
    int capacity;   // 容量 / Capacity
} ArrayList;

// 初始化动态数组 / Initialize dynamic array
ArrayList* createArrayList(int initialCapacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

// 添加元素 / Add element (类似Java的add / Similar to Java's add)
void add(ArrayList *list, int value) {
    // 如果容量不足，扩容 / If capacity is not enough, expand
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
        printf("  扩容到 / Expanded to capacity: %d\n", list->capacity);
    }
    list->data[list->size++] = value;
}

// 获取元素 / Get element (类似Java的get / Similar to Java's get)
int get(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("错误：索引越界 / Error: Index out of bounds\n");
        return -1;
    }
    return list->data[index];
}

// 设置元素 / Set element (类似Java的set / Similar to Java's set)
void set(ArrayList *list, int index, int value) {
    if (index < 0 || index >= list->size) {
        printf("错误：索引越界 / Error: Index out of bounds\n");
        return;
    }
    list->data[index] = value;
}

// 删除元素 / Remove element (类似Java的remove / Similar to Java's remove)
void removeAt(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("错误：索引越界 / Error: Index out of bounds\n");
        return;
    }
    // 将后面的元素前移 / Shift elements forward
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

// 获取大小 / Get size (类似Java的size / Similar to Java's size)
int size(ArrayList *list) {
    return list->size;
}

// 清空 / Clear (类似Java的clear / Similar to Java's clear)
void clear(ArrayList *list) {
    list->size = 0;
}

// 打印动态数组 / Print dynamic array
void printArrayList(ArrayList *list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) printf(", ");
    }
    printf("] (size=%d, capacity=%d)\n", list->size, list->capacity);
}

// 释放动态数组 / Free dynamic array
void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

int main() {
    printf("=== C语言数组操作 / Array Operations in C ===\n\n");
    
    // 1. 静态数组 / Static Array
    printf("1. 静态数组 / Static Array:\n");
    int staticArr[5] = {1, 2, 3, 4, 5};
    printf("  初始化 / Initialized: ");
    printArray(staticArr, 5);
    
    // 访问和修改 / Access and modify
    printf("  staticArr[2] = %d\n", staticArr[2]);
    staticArr[2] = 99;
    printf("  修改后 / After modification: ");
    printArray(staticArr, 5);
    
    // 数组大小 / Array size
    int arrSize = sizeof(staticArr) / sizeof(staticArr[0]);
    printf("  数组大小 / Array size: %d\n", arrSize);
    printf("\n");
    
    // 2. 动态数组（使用malloc）/ Dynamic Array (using malloc)
    printf("2. 动态数组 / Dynamic Array (using malloc):\n");
    int *dynamicArr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        dynamicArr[i] = i * 10;
    }
    printf("  动态数组 / Dynamic array: ");
    printArray(dynamicArr, 5);
    
    // 重新分配大小 / Reallocate
    dynamicArr = (int*)realloc(dynamicArr, 10 * sizeof(int));
    for (int i = 5; i < 10; i++) {
        dynamicArr[i] = i * 10;
    }
    printf("  扩容后 / After reallocation: ");
    printArray(dynamicArr, 10);
    free(dynamicArr);  // 记得释放内存 / Remember to free memory
    printf("\n");
    
    // 3. 自定义ArrayList（类似Java）/ Custom ArrayList (similar to Java)
    printf("3. 自定义ArrayList（类似Java的ArrayList）:\n");
    printf("   Custom ArrayList (similar to Java's ArrayList):\n\n");
    
    ArrayList *list = createArrayList(2);  // 初始容量为2 / Initial capacity 2
    printf("  创建ArrayList，初始容量 / Created ArrayList with initial capacity: 2\n");
    
    // 添加元素 / Add elements
    printf("\n  添加元素 / Adding elements:\n");
    add(list, 10);
    printf("  add(10): ");
    printArrayList(list);
    
    add(list, 20);
    printf("  add(20): ");
    printArrayList(list);
    
    add(list, 30);  // 这里会触发扩容 / This will trigger expansion
    printf("  add(30): ");
    printArrayList(list);
    
    add(list, 40);
    printf("  add(40): ");
    printArrayList(list);
    
    add(list, 50);  // 再次扩容 / Expand again
    printf("  add(50): ");
    printArrayList(list);
    
    // 获取元素 / Get element
    printf("\n  获取元素 / Get element:\n");
    printf("  get(2) = %d\n", get(list, 2));
    
    // 修改元素 / Set element
    printf("\n  修改元素 / Set element:\n");
    set(list, 2, 99);
    printf("  set(2, 99): ");
    printArrayList(list);
    
    // 删除元素 / Remove element
    printf("\n  删除元素 / Remove element:\n");
    removeAt(list, 1);
    printf("  removeAt(1): ");
    printArrayList(list);
    
    // 获取大小 / Get size
    printf("\n  当前大小 / Current size: %d\n", size(list));
    
    // 清空 / Clear
    printf("\n  清空 / Clear:\n");
    clear(list);
    printf("  clear(): ");
    printArrayList(list);
    
    freeArrayList(list);  // 释放内存 / Free memory
    printf("\n");
    
    // 4. 多维数组 / Multi-dimensional Array
    printf("4. 多维数组 / Multi-dimensional Array:\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("  3x4矩阵 / 3x4 Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 5. 数组排序 / Array Sorting
    printf("5. 数组排序 / Array Sorting:\n");
    int unsorted[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("  排序前 / Before sorting: ");
    printArray(unsorted, n);
    
    // 简单的冒泡排序 / Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (unsorted[j] > unsorted[j + 1]) {
                int temp = unsorted[j];
                unsorted[j] = unsorted[j + 1];
                unsorted[j + 1] = temp;
            }
        }
    }
    printf("  排序后 / After sorting: ");
    printArray(unsorted, n);
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("1. C语言有静态数组和动态数组 / C has static and dynamic arrays\n");
    printf("2. 静态数组大小固定 / Static arrays have fixed size\n");
    printf("3. 动态数组需要malloc/realloc/free / Dynamic arrays need malloc/realloc/free\n");
    printf("4. 可以封装ArrayList结构模拟Java的ArrayList / Can encapsulate ArrayList structure to simulate Java's ArrayList\n");
    printf("5. C数组不做边界检查，需要程序员自己注意 / C arrays don't do bounds checking, programmer must be careful\n");
    
    return 0;
}
