// Author:                      Jane Doe
// Assignment Number:           Lab 10
// File Name:                   L10_doe.cpp
// Course/Section:              COSC 1337 Section <number>
// Due Date:                    <date goes here>
// Instructor:                  Dr. B. Hohlt
//
//  Statistics class 
//   - using a dynamic array
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// class declaration
class Statistics
{
  private:  
    int length;
    int *numbers;
    
    void bubbleSort(int *) const;   // private utility
    
  public:
    Statistics();
    Statistics(int, int);
    ~Statistics();
    
    double getAverage() const;
    double getMedian() const;
    void displayNumbers() const;
};

// main
int main()
{
    int num = 0, max = 0;
    
    srand(time(0));		// seed the random number generator
    
    cout << "Enter number of values: ";
    cin >> num;
    cout << "Enter max value: ";
    cin >> max;
    
    Statistics arrayNum(num, max);
    
    arrayNum.displayNumbers();
    cout << endl;
    
    cout << "The average is " << arrayNum.getAverage() << endl;
    cout << "The median is " << arrayNum.getMedian() << endl;
    
    return 0;
}

// bubbleSort
//  a private utility for sorting a temporary array
//  does not allow sorting of the actual numbers array class member
void Statistics::bubbleSort(int *array) const
{
	int temp;
	bool swap;
    
    // do not allow self sort
    if (array == numbers)
        return;

	do
	{
		swap = false;
		for (int count = 0; count < length - 1; count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

Statistics::Statistics()
{
	length = 0;
	numbers = nullptr;
}

Statistics::Statistics(int num, int max)
{
	if (num > 0)
	{
		length = num;
		numbers = new int[length];
		for (int count=0; count < length; count++)
		{
			numbers[count] = rand()%max + 1;
		}
	}	
	else
	{
		length = 0;
		numbers = nullptr;
	}
}

Statistics::~Statistics()
{
	delete [] numbers;
	numbers = nullptr;
}

void Statistics::displayNumbers() const
{
	for (int count = 0; count < length; count++)
		{
			cout << *(numbers + count) << " ";
		}
	cout << endl;
}

double Statistics::getAverage() const
{
	double sum = 0;
	for (int count = 0; count < length; count++)
	{
		sum += numbers[count];
	}
	return sum/(double)length;
}

double Statistics::getMedian() const
{
	int *temp = new int[length];
	
	for (int count = 0; count < length; count++)
	{
		temp[count] = numbers[count];
	}
	
	bubbleSort(temp);
	
	if (length%2 != 0)
		return (double)temp[length/2];
	
	return (double)(temp[(length-1)/2] + temp[length/2])/2.0;
	
	delete [] temp;
}
