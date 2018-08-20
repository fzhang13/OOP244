/**********************************************************
 * Name: Xin Song Felix Zhang
 * Student ID: 111976171
 * Seneca email: xszhang3@myseneca.ca
 * Date of Completion: May 14th, 2018
*********************************************************/ 


#include <iostream>
#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H
#define MAX_NO_OF_SAMPLES 20

namespace sict {
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually
void printGraph(int samples[], int noOfSamples);
void getSamples(int samples[], int noOfSamples);

}
#endif /* graph_h */
