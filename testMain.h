/////////////////////////////////////////////////////////
// testMain.h
//
// main test, testing all functions of the polynomial datatype
//
/////////////////////////////////////////////////////////

// always use include guards
#ifndef TESTMAIN_H
#define TESTMAIN_H

//include headers
#include <stdio.h>
#include <stdlib.h>
#include "polynomial/calculations/calculations.h"
#include "polynomial/polynomial.h"
#include "polynomial/visualization/visualization.h"
#include "polynomial/creation/creation.h"

// declare "public" function interfaces
int testCreation();
int testAddition();
int testSubtraction();
int testMultiplication();
int testDivision();
int testNormalization();
int testGetOrder();

// close include guard
#endif
 
