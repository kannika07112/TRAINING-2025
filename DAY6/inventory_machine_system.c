// `2. Inventory Management System`  
// `Scenario:`  
// A `retail store` manages products in stock using sorting techniques. The system should:  
// - Sort `items based on quantity available` (ascending)  
// - Search `for an item by name` using `binary search`  
// - Display `items running low on stock (< 5 units)`  

// `Operations Example:`  
// ```
// Inventory: 
// [{"Item": "Sugar", "Quantity": 50}, 
//  {"Item": "Salt", "Quantity": 3}, 
//  {"Item": "Oil", "Quantity": 10}]

// Sorted by Quantity: Salt (3), Oil (10), Sugar (50)
// Search 'Oil': Found (Quantity: 10)
// Low Stock Items: Salt (3)


#include <stdio.h>
#include <string.h>

typedef struct {
    char item[50];
    int quantity;
} InventoryItem;

void bubbleSort(InventoryItem* items, int size);
void printInventory(InventoryItem* items, int size);
void swap(InventoryItem* first, InventoryItem* second);
int searchBinary(InventoryItem* items, int size, char* searchItem);
void displayLowStockItems(InventoryItem* items, int size, int threshold);

int main() {
    InventoryItem items[] = {
        {"Sugar", 50},
        {"Salt", 3},
        {"Oil", 10}
    };
    int itemsCount = 3;
    char searchItem[] = "Oil";

    printf("Before Sort:\n");
    printInventory(items, itemsCount);

    bubbleSort(items, itemsCount);

    printf("After Sort:\n");
    printInventory(items, itemsCount);

    int index = searchBinary(items, itemsCount, searchItem);
    if (index != -1) {
        printf("Search '%s': Found (Quantity: %d)\n", searchItem, items[index].quantity);
    } else {
        printf("Search '%s': Not Found\n", searchItem);
    }

    displayLowStockItems(items, itemsCount, 5);

    return 0;
}

void printInventory(InventoryItem* items, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (Quantity: %d)\n", items[i].item, items[i].quantity);
    }
    printf("\n");
}

void swap(InventoryItem* first, InventoryItem* second) {
    InventoryItem temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(InventoryItem* items, int size) {
    int isSwapped;
    do {
        isSwapped = 0;
        for (int i = 0; i < (size - 1); i++) {
            if (items[i].quantity > items[i + 1].quantity) {
                swap(&items[i], &items[i + 1]);
                isSwapped = 1;
            }
        }
        size--;
    } while (isSwapped);
}

int searchBinary(InventoryItem* items, int size, char* searchItem) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(items[mid].item, searchItem);
        if (cmp == 0) {
            return mid;
        } else if (cmp > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void displayLowStockItems(InventoryItem* items, int size, int threshold) {
    printf("Low Stock Items (< %d units):\n", threshold);
    for (int i = 0; i < size; i++) {
        if (items[i].quantity < threshold) {
            printf("%s (Quantity: %d)\n", items[i].item, items[i].quantity);
        }
    }
}
