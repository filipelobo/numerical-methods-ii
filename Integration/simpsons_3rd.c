#include "simpsons_3rd.h"

float simpsonsThird(int m, float* x, float* y) {
	float it = 0;
	if (m % 2 != 0) {
		printf("Warning: Number of divisions (m) must be even.\n");
		return;
	}
	float h = (x[m] - x[0]) / (float) m;

	int i;
	for (i = 0; i <= m; i++) {
		if (i == 0 || i == m)
			it = it + y[i];
		else {
			if (i % 2 == 0)
				it = it + 2 * y[i];
			else
				it = it + 4 * y[i];
		}
	}
	it = it * h / (float) 3;

	return it;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	float i = 0;
	float j = 0;
	int counter = 0;
	Variables v;

	fscanf(file, "%f", &i);
	v.m = i;

	float auxX[v.m];
	float auxY[v.m];

	while (!feof(file)) {
		fscanf(file, "%f\t%f", &i, &j);
		auxX[counter] = i;
		auxY[counter] = j;
		counter++;
	}

	v.x = auxX;
	v.y = auxY;

	fclose(file);

	return v;
}

int main(int argc, char* argv[]) {
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Result: %f", simpsonsThird(v.m, v.x, v.y));
	}
	return 1;
}
