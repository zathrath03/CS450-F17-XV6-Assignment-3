#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "memlayout.h"
#define MAX_SIZE 5

int main (void)
{
		// Testing uv2p(*p), by passing array values pointers as virtual address.
    	int arr[MAX_SIZE] = {9999, 99999, 999999, 9999999, 99999999};
		int i = 0;
		int physicalAddr;
		printf(1, "***testing user space addresses***\n");
    	printf(1, "Array Base Address: %p\n", arr);
    	do{
            	printf(1,"Virtual Address: 0x%p\n", (void *)(&arr[i]));
            	printf(1, "Array Element: %d\n", arr[i]);
            	printf(1, "Passing value to uv2p system call\n");
				physicalAddr = uv2p((void *)(&arr[i]));
				printf(1, "Physical Address: 0x%x\n", physicalAddr);
            	i++;
            	printf(1, "-----------------------------------------\n");   	 
		} while(i<MAX_SIZE);
		
		// Testing Kernel space address -> will give an error 
		//unsigned int address = 2147483648;
		printf(1, "***testing kernel space address***\n");
		printf(1,"Virtual Address: %d\n", KERNBASE);
		physicalAddr = uv2p((char*)(KERNBASE));
		printf(1, "Physical Address: 0x%x\n", physicalAddr);
		printf(1, "kernel test complete\n-----------------------------------------\n");
		// Testing Present bit
		// We were unable to test the present bit and the user bit from this program
		// All attempts from here to change the address to reference a PTE that wasn't
		// present were caught when the argument was passed to the system call and
		// couldn't make it through to uv2p(). Actually testing for those bits was done
		// by modifying the uv2p() function in proc.c to shift the valid VA at that point
		// and the code we used to test couldn't be left due to defeating the functionality
		long *addrPtr = (long*)&i;
		long arrayAddr = *addrPtr;
		long shiftAddr = arrayAddr<<18;
		printf(1, "***testing present bit***\n");
		printf(1,"Virtual Address: %d\n", shiftAddr);
		physicalAddr = uv2p((void*)(shiftAddr));
		printf(1, "Physical Address: 0x%x\n", physicalAddr);
		printf(1, "present bit test complete\n-----------------------------------------\n");

		exit();
}