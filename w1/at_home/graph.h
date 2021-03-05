#ifndef _244_GRAPH_H_
#define _244_GRAPH_H_

#define MAX_NO_OF_SAMPLES 20
namespace sict {
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
	void printBar(int val, int max);
	void printGraph(int samples[], int noOfSamples);
}

#endif