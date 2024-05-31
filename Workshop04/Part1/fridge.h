#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <iostream>
#include "food.h"

namespace seneca
{
	/// <summary>
	/// Class that contains information about the Fridge
	/// </summary>
	class Fridge
	{
		/// <summary>
		/// Maximum storage capacity of the Fridge in kgs
		/// </summary>
		int m_capacity;

		/// <summary>
		/// Name of the Fridge model 
		/// </summary>
		char* m_model;

		/// <summary>
		/// Dynamically-allocated array of Food objects inside the Fridge
		/// </summary>
		Food* m_food;

		/// <summary>
		/// Number of Food objects in the Fridge 
		/// </summary>
		int m_cntFoods;

	public:
		/// <summary>
		/// Default Fridge Constructor (Special Member Function)
		/// </summary>
		Fridge(); 
		
		/// <summary>
		/// Custom Parameterized Fridge Constructor (Special Member Function)
		/// </summary>
		/// <param name="model">Name of Fridge Model</param>
		/// <param name="capacity">Capacity of Fridge</param>
		Fridge(const char* model, int capacity);

		/// <summary>
		/// Custom Parameterized Fridge Constructor (Special Member Function)
		/// </summary>
		/// <param name="foods">Address of array of type Food</param>
		/// <param name="cntFoods">Number of Food from Food array to put in the Fridge</param>
		/// <param name="model">Name of Fridge Model</param>
		/// <param name="capacity">Capacity of Fridge</param>
		Fridge(const Food* foods, int cntFoods, const char* model, int capacity);

		/// <summary>
		/// Fridge Destructor (Special Member Function)
		/// </summary>
		~Fridge();

		/// <summary>
		///  Query that calculates the total weight of all foods stored in the fridge
		/// </summary>
		/// <returns>total weight of food in the fridge</returns>
		int getContentWeight() const;

		/// <summary>
		/// Modifier that adds a new Food object to the fridge if there is capacity available
		/// </summary>
		/// <param name="aFood">Reference to a Food object</param>
		/// <returns>true if food item sucessfully added or false if not added</returns>
		bool addFood(const Food &aFood);
		
		/// <summary>
		/// Modifier that sets the model and capacity of a fridge.
		/// </summary>
		/// <param name="model">Name of Fridge Model</param>
		/// <param name="capacity">Capacity of Fridge</param>
		void setModel(const char* model, int capacity);

		/// <summary>
		/// Query that returns true if the fridge is at least at 90% capacity, false otherwise
		/// </summary>
		/// <returns>true if the fridge is at least at 90% capacity, false otherwise</returns>
		bool isFull() const;

		/// <summary>
		/// Query that returns true if the fridge contains the food received as parameter, 
		/// false otherwise.
		/// </summary>
		/// <param name="theFood">address of an unmodifiable C-string 
		/// with the name of the food to be checked. This is set to NULL by default</param>
		/// <returns>true if the fridge contains the food received as parameter, 
		/// false otherwise</returns>
		bool hasFood(const char* theFood = NULL) const;

		/// <summary>
		/// Query that inserts into the parameter the content of the current instance
		/// </summary>
		/// <param name="out">a reference to an object of type std::ostream. By default, 
		/// this parameter is std::cout</param>
		void display(std::ostream &out = std::cout) const;
	};
}

#endif
