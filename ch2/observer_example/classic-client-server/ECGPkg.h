#ifndef ECGPkg_H
#define ECGPkg_H

#include <stdio.h>

/* forware declarations */
struct ArrthmiaDetector;
struct ECG_Module;
struct HistogramDisplay;
struct QRSDetector;
struct TMDQueue;
struct TestBuilder;
struct TimeMarkedData;
struct WaveformDisplay;

typedef unsigned char boolean;
#define QUEUE_SIZE 20000

#endif