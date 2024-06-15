#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H
namespace seneca
{
	/// <summary>
	/// Templated custom type Pair<>
	/// </summary>
	/// <typeparam name="T"> Type of first object in Pair </typeparam>
	/// <typeparam name="U"> Type of second object in Pair </typeparam>
	template<typename T, typename U>
	struct Pair
	{
		T first;
		U second;
	};

	/// <summary>
	/// This function template is used to add a Pair element to a dynamically-allocated array of Pair objects
	/// </summary>
	/// <typeparam name="T"> Type of first object in Pair<> </typeparam>
	/// <typeparam name="U"> Type of second object in Pair<> </typeparam>
	/// <param name="pArray"> array containing objects of type Pair<> </param>
	/// <param name="first"> Un-modifiable reference to first object in Pair<> </param>
	/// <param name="second"> Un-modifiable reference to second object in Pair<> </param>
	/// <param name="size"> size of array of type Pair<> </param>
	template<typename T, typename U>
	void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size)
	{
		Pair<T, U>* temp = new Pair<T, U>[size + 1];

		for (int k = 0; pArray && k < size; k++)
			temp[k] = pArray[k];

		temp[size].first = first;
		temp[size].second = second;

		releaseMem(pArray);
		pArray = temp;
		size++;
	}

	/// <summary>
	/// Finds pairs of element matches in two arrays, 
	/// where the two arrays may carry elements of different types
	/// </summary>
	/// <typeparam name="T"> Type of first object in Pair<> </typeparam>
	/// <typeparam name="U"> Type of second object in Pair<> </typeparam>
	/// <param name="arr1"> the address of an array of unmodifiable objects 
	/// of type first object in Pair<> </param>
	/// <param name="arr2"> the address of an array of unmodifiable objects 
	/// of type second object in Pair<> </param>
	/// <param name="size1"> the number of elements in arr1 </param>
	/// <param name="size2"> the number of elements in arr2 </param>
	/// <param name="size3"> a reference to an integer that contains 
	/// the number of matches found in the two arrays.</param>
	/// <returns> the address of the first element of the new dynamic array </returns>
	template<typename T, typename U>
	Pair<T,U>* matches(const T* arr1, const U* arr2, int size1, int size2, int& size3)
	{
		Pair<T, U>* pt = nullptr;
		size3 = 0;
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (arr1[i] == arr2[j])
				{
					addDynamicPairElement(pt, arr1[i], arr2[j], size3);
				}
			}
		}
		return pt; // address of first element in array (&p[0] is the same thing)
	}

	/// <summary>
	/// Templated function for releasing the dynamic memory allocated by matches function
	/// </summary>
	/// <typeparam name="T"> Type of array to be deallocated </typeparam>
	/// <param name="arr"> the address of an array of objects of type T to be deallocated </param>
	template<typename T>
	void releaseMem(T* arr)
	{
		delete[] arr;
	}
}
#endif
