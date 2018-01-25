// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

// prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);

// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);

// finds the largest sample in the samples array, if it is larger than 70,
// otherwise it will return 70. 
int findMax(int samples[], int noOfSamples);