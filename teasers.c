#include <stdio.h>

#define bool 	char
#define true 	1
#define false 	0

unsigned int reverseInt(unsigned int);
unsigned int reverseInt(unsigned int n) {
	int retVal = 0;
	while (n) {
		retVal = retVal * 10 + n % 10;
		n /= 10;
	}
	
	return retVal;
}

bool mystrcmp(char*, char*);
bool mystrcmp(char* str1, char* str2) {
	while (*str1++ == *str2++ && *str1);
	
	return *str1 != *str2;
}

int myatoi(char*);
int myatoi(char* n) {
	int retVal = 0;
	int sign = 1;
	while(*n++ == ' ');
	--n;
	if (*n == '-') {
		sign = -1;
		++n;
	}
	while (*n) {
		retVal = retVal * 10 + (*n++ - '0');
	}
	
	return retVal * sign;
}

#define tolerance	0.000001
float mysqrt(float);
float mysqrt(float n) {
	float sqroot = n / 2;
	float squared = sqroot*sqroot;
	float low = 0;
	float high = sqroot;
	while (squared  <= n - tolerance || squared >= n + tolerance) { // i.e. for 9 if (sq*sq <= 8.999 || sq*sq >= 9.001) then keep computing
		if (squared > n) {
			// must be less than high, greater than low
			high = sqroot;
		} else {
			// must be greater than low, less than high
			low = sqroot;
		}
		sqroot = (low + high) / 2.0;
		squared = sqroot*sqroot;
	}
	
	return sqroot;
}

// i, j = i*width + j
int indexOf(int, int, int);
inline int indexOf(int i, int j, int width) {
	return i*width + j;
}

void matrixspiral(int*, int, int);
void matrixspiral(int* array, int height, int width) {
	for (int w = width-1, h = height-1, j = 0; w > 0 && h > 0; --w, --h, ++j) {
		// print top
		for (int k = j; k < w; ++k) {
			int index = indexOf(j, k, width);
			printf("%d ", array[index]);
		}
		// print right
		for(int k = j; k < h; ++k) {
			int index = indexOf(k, w, width);
			printf("%d ", array[index]);
		}
		// print bottom
		for(int k = w; k > j; --k) {
			int index = indexOf(h, k, width);
			printf("%d ", array[index]);
		}
		// print left
		for(int k = h; k > j; --k) {
			int index = indexOf(k, j, width);
			printf("%d ", array[index]);
		}
	}
	
	// if square, print center
	if (width == height) {
		int index = width*width/2;
		printf("%d ", array[index]);
	}
	
}

void bestTrade(int*, int);
void bestTrade(int* array, int n) {
	// current maxValue;
	int maxValue = 0;
	// current minValue;
	int minValue = 0;
	// current maxDifference (between maxValue and minValue)
	int maxDifference = 0;
	
	// we can walk backwards to make sure our min and max values don't cross
	for (int i = n - 1; i >= 0; --i) {
		// find our current max value
		if(maxValue < array[i]) {
			maxValue = array[i];
		}
		
		// find our local difference
		int difference = maxValue - array[i];
		// is this a global difference?
		if(maxDifference < difference) {
			maxDifference = difference;
			// so this must be our current min value
			minValue = array[i];
		}
	}
		
	printf("Buy at: %d\n", minValue);
	printf("Sell at: %d\n", maxValue);
	printf("Price gain: %d\n", maxDifference);
}

int main(int argc, char *argv[]) {
	printf("%d\n", reverseInt(123456));
	
	char* str1 = "Christian";
	char* str2 = "Christian";
	char* str3 = "Christia";
	printf("%d\n", mystrcmp(str1, str3));
	
	char* n = "  -123";
	printf("%d\n", myatoi(n));
	
	printf("%f\n", mysqrt(11.0));
	
	// 123
	// 456
	// 789
	int array[] = {1,2,3, 5,6,7, 9,10,11};
	matrixspiral(array, 3, 3);
}
