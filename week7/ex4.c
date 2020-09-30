#include <stdlib.h>
#include <stdio.h>

void* myRealloc(void* ptr, size_t oldLength, size_t newLength) {
	if (!ptr) {
		return malloc(newLength);
	}
	else if (newLength == 0) {
		free(ptr);
		return NULL;
	}
	else if (newLength <= oldLength)
	{
		return ptr;
	}
	else
	{
		void* ptrNew = malloc(newLength);
		memcpy(ptrNew, ptr, oldLength);
		free(ptr);
		return ptrNew;
	}

}

int main() {

	return 0;
}
