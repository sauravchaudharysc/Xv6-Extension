#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// Function to print free pages with a label
void print_free_pages(const char *label) {
    int free = getNumFreePages();
    printf(1, "%s: Free pages = %d\n", label, free);
}

int main(void)
{
    // Step 1: Initial memory allocation (4 pages)
    char *addr = (char*)sbrk(4 * 4096);  // Allocating 4 pages (16KB)
    
    // Step 2: Initialize allocated memory with a known value
    for (int i = 0; i < 4 * 4096; i++) {
        addr[i] = 'a';  // Filling memory with character 'a'
    }

    // Step 3: Print initial memory state (before fork)
    printf(1, "========================\n");
    printf(1, "Initial Memory State:\n");
    print_free_pages("Before fork");

    // Step 4: Forking to create a child process
    if (fork() == 0) {
        // Child process
        printf(1, "\nChild Process:\n");

        // Step 5: Print memory state in the child process
        print_free_pages("In child after fork");

        // Step 6: Modify memory in the child (trigger COW)
        addr[0] = 'b';  // Modifying the first byte of allocated memory
        
        // Step 7: Verify the child’s memory is copied (COW)
        printf(1, "Child modified memory at addr[0]. Value = %c\n", addr[0]);
        
        // Print the memory state after modification in the child
        print_free_pages("In child after modification");

        exit();
    } else {
        // Parent process
        wait();  // Wait for the child to finish
        printf(1, "\nParent Process:\n");

        // Step 8: Parent checks the memory (should still be unchanged for COW)
        printf(1, "Parent sees addr[0] = %c\n", addr[0]);
        
        // Print the memory state after the child exits
        print_free_pages("In parent after child exit");

        printf(1, "========================\n");

        exit();
    }
}

