#include <iostream>

template <typename T>
class GenericArray
{
	private:
		T *value;
		int size;
	public:
		GenericArray() {size = 0; value = nullptr;}
		void addElement(T newVal);
		T at(int location);
		int getSize() {return size;}
		T sum();
		T max();
		T min();
		void print();
		GenericArray<T> slice(int begin, int end);
};

template <typename T>
void GenericArray<T>::print()
{
	std::cout << "Printing array: ";
	for(int i = 0; i < size; i++)
	{
		std::cout << value[i] << "  "; 
	}
	std::cout << "\n";
}

template <typename T>
void GenericArray<T>::addElement(T newVal)
{
	if(size == 0)
	{
		value = new T[size + 1];
		value[0] = newVal;
		size++;
	}
	else
	{
		T *temp = new T[size + 1];
		for(int i = 0; i < size; i++)
			temp[i] = value[i];
		temp[size] = newVal;

		delete value;
		value = temp;
		size++;
	}
}

template <typename T>
T GenericArray<T>::at(int location)
{
	T locVal;
	if(location < 0 || location > size)
	{
		std::cout << "Location does not fit parameters of the array" << std::endl;
		exit(0);

	}
	else
	{
		locVal = value[location - 1];
	}
	return locVal;
}


template <typename T>
T GenericArray<T>::sum()
{
	T sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum += value[i];
	}
	return sum;
}

template <typename T>
T GenericArray<T>::max()
{
	T tempMax;
	for(int i = 0; i < size; i++){
		if(i == 0)
		{
			tempMax = value[i];
		}
		else if(value[i] > tempMax)
		{
			tempMax = value[i];
		}
		else
		{

		}
	}
		return tempMax;
}

template <typename T>
T GenericArray<T>::min()
{
	T tempMin;
	for(int i = 0; i < size; i++){
		if(i == 0)
		{
			tempMin = value[i];
		}
		else if(value[i] < tempMin)
		{
			tempMin = value[i];
		}
		else
		{

		}
	}
		return tempMin;
}

template <typename T>
GenericArray<T> GenericArray<T>::slice(int begin, int end)
{
	GenericArray<T> newArray;
	if(begin <= 0 || begin > size)
	{
		std::cout << "Range does not fit parameters of the array" << std::endl;
		exit(0);
	}
	else if(end <= 0 || end > size)
	{
		std::cout << "Range does not fit parameters of the array" << std::endl;
		exit(0);
	}
	else if (begin>=end)
	{
		std::cout << "Incorrect range!" << std::endl;
		exit(0);
	}
	else
	{
		newArray.value = new T[end - begin];
		int j = 0;
		for(int i = (begin - 1); i < end; i++)
		{
			newArray.value[j] = value[i];
			j++;
			newArray.size++;
		}
	}
	return newArray;
}

int main()
{
	GenericArray<int> array;
	std::cout << "Size of the array before adding elements: " << array.getSize() << std::endl;
	array.addElement(10);
	array.addElement(56);
	array.addElement(20);
	array.addElement(34);
	array.addElement(-3);
	array.addElement(1);
	array.addElement(102);
	array.print();
	std::cout << "Size after adding elements: " << array.getSize() << std::endl;
	std::cout << "Returning the sum of the array: " << array.sum() << std::endl;
	std::cout << "Element at location 2 in the array: " << array.at(2) << std::endl;
	std::cout << "Max: " << array.max() << ", Min:" << array.min() << std::endl;
	GenericArray<int> arraySliced;
	std::cout << "Slicing (2, 5)..." << std::endl;
	arraySliced = array.slice(2, 5);
	std::cout << "Size of the sliced array: " << arraySliced.getSize() << std::endl;
	arraySliced.print();

	return 0;
}