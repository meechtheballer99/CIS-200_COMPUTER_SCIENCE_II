#include "state.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

State::State()
{
	string stateAbrv = "State Abbreviation Not Found";
	string stateName = "OR";
	string capital = "No Year Found";
	int population = 0;
	int year = 0;
	int numCongress = 0;
}

void State::setStateAbrv(string abrv)
{
	stateAbrv = abrv;
}


void State::setStateName(string sName)
{
	stateName = sName;
}

void State::setCapital(string cap)
{
	capital = cap;
}

void State::setPopulation(int pop)
{
	population = pop;
}

void State::setYear(int y)
{
	year = y;
}

void State::setNumCongress(int num)
{
	numCongress = num;
}


string State::getStateAbrv()
{
	return stateAbrv;
}


string State::getStateName()
{
	return stateName;
}


string State::getCapital()
{
	return capital;
}


int State::getPopulation()
{
	return population;
}



int State::getYear()
{
	return year;
}


int State::getNumCongress()
{
	return numCongress;
}


int State::computeResidentsPerRep()
{
	return population / numCongress;
}


void State::displayStateInfo()
{
	cout << endl;

	cout << right << setw(20) << stateAbrv << setw(20) << stateName << setw(20) << capital
		<< setw(20) << population << setw(11) << year << setw(15) << numCongress << endl;

	cout << endl;

}






