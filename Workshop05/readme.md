# Workshop #5: Member Operators and Helper Functions

In this workshop, you will have the opportunity to implement a bank account class which uses overloaded operators and type conversion operators. In addition, you will make use of helper functions, and generate formatted output.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create unary member operator
- define and create binary member operator
- define and create a type conversion operator
- define and create helper binary operator



## General Instructions

### Submission Policy

This workshop is divided into two coding parts and one non-coding part.

- **Part 1** (*LAB*): A *step-by-step* guided workshop, worth 50% of the workshop's total mark.
  Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **Part 2** (*DIY*): A *do-it-yourself* type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of "Part 2" mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions of **Part 2** that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates

The due dates depend on your section. The due date for *Part #1* is at the end of they when your lab is scheduled; the due date for *Part #2* is at the end of the day that is 5 days after the day with the lab.

Please choose the `-due` option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS -due
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]



### Late penalties

You are allowed to submit your work up to 2 days after the due date with 30% penalty for each day. After that, the submission will be closed, and the mark will be zero. If the reflection is missing when the submission closes, the mark for **Part 2** will be set to 0.



### Citation

Every file that you submit must contain (as a comment) at the top:

- **your name**,
- **your Seneca email**,
- **Seneca Student ID**,
- the **date** when you completed the work.


#### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#### For work that is done partially by you

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from**.  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

- Add the citation to the file in which you have the borrowed code (make sure to clearly mark the code that is not created by you and where did you get it from).
- In the `reflect.txt` file, add a summary of the files/portions of code that is not yours (the source files should un-ambiguously identify the portions of code that are not yours).

> ⚠️ This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.


#### If you have helped someone with your code

If you have helped someone with your code, let them know of these regulations and, in your `reflect.txt` file, write exactly which part of your code was copied and who was the recipient of this code. By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.



### Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.





## Part 1 (50%)

In part one of the workshop, you will create a custom type named `BankAccount` that represents a checking or saving account a person can open at a bank.  This custom type will support some simple operations like adding funds to the account, withdrawing funds, comparing the balance with some number, and conversion to some primitive types.

This part of the workshop has three modules:

- `bankAccount` - represents an account (you must fully implement this module in `*.h`/`*.cpp` files)
- `w5_p1` - which contains the `main()` function (already provided, do not change it)

Your task is to implement the `bankAccount` module.



### The `bankAccount` Module

Design and implement a class named `BankAccount` that stores some data about an account a person can open at a bank, and allows some simple operations with the account.  The class will not expose the data to clients, validate the parameters before storing them into the attributes.  The client will interact with the object only through the public members (also known as *public interface*, or just *interface*).


#### Private Members

The class `BankAccount` will store the following information about a single account:

- `m_userName` - as a statically allocated array of 100 characters representing the person who own the account.  If the username has the empty string, then we consider that is account is not open yet and cannot be used for any operations.
- `m_balance` - a floating point number in double precision that hold how much money are deposited in the account.
- `m_checking` - a Boolean value that is `true` if this is a checking account, or `false` if this is a savings account.
- `m_transactions` - an integer that records how many transactions (deposits and withdrawals) have been performed on this account; every time a transaction is performed, this number is incremented.

#### Public Members

The class `BankAccount` will provide to clients the following public functions:

- a custom constructor with two parameters that initializes the current instance with the values of the parameters.

    **📌Parameters**:
    - `name` - the address of an unmodifiable C-string representing the account owner. *By default, this parameter is null!*
    - `checking` - a Boolean value that stores if this account is a checking or savings account. *By default, this parameter is false!*

    **🔍Implementation**:
    - set the numeric attributes to 0 and the Boolean attribute to the value of the parameter `checking`.
    - if the parameter `name` is not null and the string is not empty, copy with `std::strcpy` this parameter into the attribute `m_userName`; otherwise store the empty string into `m_userName` to signal that this object is in an empty state and should not be used (the account is not open).



- `display()` - a **query** that prints to screen the content of the current instance.

  **📌Return**:
  - nothing

  **🔍Implementation**:
  - if the account is open, print to screen the information stored in the current instance in the format: `NAME -> $BALANCE in ACCOUNT_TYPE account.`
  - else do nothing

  **Hint**: use the conversion-to-bool operator implemented above to check if the account is open;



- `operator bool()` - the conversion-to-bool operator is a **query** that returns `true` if the account is open, `false` otherwise.



- `operator double()` - the conversion-to-double operator is a **query** that returns the balance from the current account if the account is open, or `std::nan("")` (this is a special value that means *Not-a-Number*) if the account is not open.

  **Hint**: use the conversion-to-bool operator implemented above to check if the account is open; include `<cmath>` to have access to `std::nan("")`



- `operator const char*()` - the conversion-to-string operator is a **query** that returns address of the account owner attribute if the account is open, or `"Not Open"` if the account is not open.



- `operator int()` - the conversion-to-int operator is a **query** that returns the number of transactions performed in this account if the account is open, or `-1` if the account is not open.



- `operator+=()` - a **modifier** that adds to the balance the amount received as parameter

  **📌Parameters**:
  - `amount` - a floating point number in double precision that represents how much money should be added to the balance.

  **📌Return**:
  - a reference to the current instance

  **🔍Implementation**:
  - if the account is open, add to the balance the value received as parameter and increment the `m_transactions` attribute
  - if the account is not open, do nothing.



- `operator-=()` - a **modifier** that withdraws from the balance the amount received as parameter

  **📌Parameters**:
  - `amount` - a floating point number in double precision that represents how much money should be removed from the balance.

  **📌Return**:
  - a reference to the current instance

  **🔍Implementation**:
  - call `operator+=` implemented above with the parameter `-1 * amount`



- `operator+()` - a **query** that creates a new account and adds to it the amount specified as parameter.

  **📌Parameters**:
  - `amount` - a floating point number in double precision that represents how much money should be added to the balance of the new account.

  **📌Return**:
  - an object of type `BankAccount`

  **🔍Implementation**:
  - create a local variable of type `BankAccount` called `result`.
  - copy into `result` the current instance (copy means *"use the assignment operator"*).
  - use overloaded `operator+=` implemented above to add `amount` to `result`
  - return `result`;



- `operator++()` - the prefix increment is a **modifier** that adds the interest to the account balance.

  **📌Return**:
  - a reference to the current instance

  **🔍Implementation**:
  - if the current account is open and the balance is a positive number (only accounts with positive balance can receive interest) then add to the balance 2.5% for savings account or 0.5% for checking account.
  - return the current instance;



- `operator++()` - the postfix increment is a **modifier** that adds the interest to the account balance.

  **📌Parameters**:
  - `???` - an un-named parameter of type `int`; this parameter helps us distinguish between prefix/post fix verions of the operator.

  **📌Return**:
  - an object of type `BankAccount` (this is different from the prefix version)

  **🔍Implementation**:
  - create a local variable of type `BankAccount` called `result`.
  - copy into `result` the current instance.
  - use overloaded prefix `operator++` implemented above on the current instance (do not change `result` in any way)
  - return `result`;



- `operator>()` - the greater-than comparison operator is a **query** compares the balance from current instance with the amount specified as parameter.

  **📌Parameters**:
  - `amount` - a floating point number in double precision.

  **📌Return**:
  - `true` if the balance is greater than the parameter, `false` otherwise

  **🔍Implementation**:
  - if the account is open compare the balance with the parameter; otherwise return `false`.



#### Free Helpers

- `operator>()` - the greater-than comparison operator compares amount specified in the first parameter with the balance of the account specified in the second parameter.

  **📌Parameters**:
  - `amount` - a floating point number in double precision.
  - `account` - an un-modifiable reference to an object of type `BankAccount`.

  **📌Return**:
  - `true` if the first parameter is greater than the balance of the second parameter, `false` otherwise

  **🔍Implementation**:
  - seems obvious





### The `w5_p1` Module (Provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.




### Submission

Upload the header files (`*.h`), and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and test that everything works properly.  Using the provided tester module, a correct implementation will produce the output as shown in `sample_output.txt`.

Then, run the following command from your `matrix` account:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty!







## Part 2 (50%)

This part of the workshop will involve creating two classes named `Ability` and `Hero` representing a character in a fictional universe with extraordinaries abilities.

This part of the workshop has three modules:

- `ability` - represents a single supernatural ability that a hero can have (you must fully implement this module in `*.h`/`*.cpp` files)
- `hero` - represents a character with extraordinary abilities that fights evil (you must fully implement this module in `*.h`/`*.cpp` files)
- `w5_p2` - which contains the `main()` function (already provided, do not change it)

Your task is to implement the `ability`/`hero` modules.



### The `ability` Module

Design and implement a class named `Ability` that stores information about a single supernatural ability a hero can have. Your class must store at least the name of the ability as a statically allocated C-string with 100 characters, and the strength of the ability as an integer.

The only mandatory function in this class is a custom constructor that receives as parameters the name of the ability and the strength of the ability and stores them into the attributes. You can add any other members to this class as your design requires; make all data-members to be private. **Do not use dynamic memory for this class!**

The client will interact with an object of type `Ability` only through the public members (also known as *public interface*, or just *interface*).





### The `hero` Module

Design and implement a class named `Hero` that stores information about a single person that has supernatural abilities.

#### Private Members

The class `Hero` will store the following information about a hero:

- `m_name` - a statically allocated C-string with 100 characters.
- `m_abilities` - a pointer that stores the address of a dynamically-allocated array of `Ability` objects.  This are the abilities that the hero has and can use when fighting crime.
- `m_cntAbilities` - as an object of type `int` that stores the number of `Ability` objects that are in the array.
- `m_level` - as an object of type `int` that stores the level of the hero: the higher the level, the stronger the hero is. This value cannot be less than `1` for a valid hero.

#### Public Members

The class `Hero` will provide to clients the following public functions:

- a default constructor

- a custom constructor with three parameters that initializes the current instance with the values of the parameters if they are valid. The hero will start at level 1.
  **📌Parameters**:
  - `name` - the address of an unmodifiable C-style string with the name of the hero.  A valid name is any string with at least one character.
  - `abilities` - the address of an unmodifiable array of objects of type `Ability`. These are the abilities that the hero has.
  - `cntAbilities` - the number of objects in the array with abilities received as second parameter.


- a destructor


- a conversion to `const char*` operator that returns the name of the hero.


- a conversion to `int` operator that returns the total strength a hero has.  The total strengh of a hero is the sum the strength of all abilities a hero has, multiplied by the level of the hero.



- `operator+=` - a **modifier** that adds a new ability to the array of abilities a hero has (resize the array whose address is stored in `m_abilities`)

  **📌Parameters**:
  - `ability` - an unmodifiable reference to an object of type `Ability`


  **📌Return**:
  - a reference to an object of type `Hero`



- `operator+=()` - a **modifier** that changes the level of the hero by the value received as parameter.  If the parameter is negative, the new level of the hero cannot go below 1.

  **📌Parameters**:
  - `lvlChange` - an object of type `int` representing the number of levels to be added to the hero's level.

  **📌Return**:
  - a reference to an object of type `Hero`



- `operator++()` - a **modifier** that increases the level of the hero by 1.

  **📌Return**:
  - a reference to an object of type `Hero`



- `display()` - a **query** that prints to the screen the content of the current instance in the format:

  ```txt
  HERO_NAME (lvl: HERO_LEVEL, str: TOTAL_HERO_STRENGTH)
    - ABILITY_1 (ABILITY_1_STRENGTH)
    - ABILITY_2 (ABILITY_2_STRENGTH)
    - ...
  ```






#### Free Helpers

Add the following operator overloads as free helpers:

- `operator<` - returns `true` if the strength of the hero received as the first parameter is smaller than the strength of the hero received as the second parameter; `false` otherwise.

  **📌Parameters**:
  - `h1` - an unmodifiable reference to an object of type `Hero`
  - `h2` - an unmodifiable reference to an object of type `Hero`



- `operator>` - returns `true` if the strength of the hero received as the first parameter is greater than the strength of the hero received as the second parameter; `false` otherwise.

  **📌Parameters**:
  - `h1` - an unmodifiable reference to an object of type `Hero`
  - `h2` - an unmodifiable reference to an object of type `Hero`

  Notice that both comparison operators above return `false` if the two heroes have equal strength.



- `operator>>` - adds to the hero received as the second parameter the ability received as the first parameter.

  **📌Parameters**:
  - `ability` - an unmodifiable reference to an object of type `Ability`
  - `hero` - a reference to an object of type `Hero`



- `operator<<` - adds to the hero received as the first parameter the ability received as the second parameter.

  **📌Parameters**:
  - `hero` - a reference to an object of type `Hero`
  - `ability` - an unmodifiable reference to an object of type `Ability`






### The `w5_p2` Module (Provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.





### Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- in part 2, you were asked to overload the comparison operators as free helpers; although these operators are not modifying anything, they are not marked as queries. Explain why we don't make them queries.

To avoid deductions, refer to code in your solution as examples to support your explanations.

You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`), and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and test that everything works properly.  Using the provided tester module, a correct implementation will produce the output as shown in `sample_output.txt`.

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



<!--🔜 COMING SOON-->
