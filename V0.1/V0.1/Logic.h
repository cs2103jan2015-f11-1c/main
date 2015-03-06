#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Parser.h"
#include "Storage.h"
#include "UI.h"

using namespace std;

class TaskSotong{

private:

vector<string*> taskList;

public:

	TaskSotong();

	void runProgram();
};

#endif