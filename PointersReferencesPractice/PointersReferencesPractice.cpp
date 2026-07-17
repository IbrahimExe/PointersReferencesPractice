#include <iostream>
#include <string>

/*
Part 1:
    Write a function that returns the length of a const char*
    
    Check to see if a const char* string is a palindrome (Same in both directions)
*/ 
int getStringLength(const char* str)
{
    int length = 0;
    const char* temp = str; // start at the beginning of the string

    if (str == nullptr)
    {
        return 0;
    }

    while (*temp != '\0') // \0 is the null terminator that marks the end of a string in C++
    {
        length++;   // a character is added
        temp++;     // move address forward by 1 byte to next character
    }

    return length; 
}

bool PalindromeChecker(const char* str)
{
    int length = getStringLength(str);

    const char* start = str; // pointer to the start of the string
    const char* end = str + length - 1;

    if (length == 0 || length == 1)
    {
        return true; // A string of length 0 or 1 is a palindrome
    }

    while (start < end)
    {
        if (*start != *end)
        {
            return false;
        }

        start++;    // move right
        end--;      // move left
    }

    return true; // if middle is reached with all characters matching = palindrome
}

/*
Part 2: 
    - Create a class object to test.
    example:
    - class Student 
    - string Name;
    - int StudentId;
    - operator overloads for:
    - comparison to see if two objects are the same

    Create list class.
    - Have it use a linked list as its storing method
    - Include functions:
    - Add(<test object>) >> will add the test object created prior to 
    specific index (should handle if index is invalid)
    - Remove(int index) >> will remove at a specific index
    - Remove(<test object>)
    - PopBack() >> will remove the last item in the list
    - Print() >> iterate through the list and print all elements

    - Add 5 items to the list, then print
    - Remove item at index 3, then print
    - Remove item at index 0, then print
    - PopBack then print
*/

class Student
{
public:

private:
    std::string name;

    int studentID;
};

class StudentList
{
public:

private:

};

int main()
{
    const char* racecar = "racecar";
    const char* test  = "test";
    const char* longTest = "testtesttesttesttesttsettsettsettsettset";

    std::cout << racecar << " : " << getStringLength(racecar) << "\n";
    std::cout << racecar << " : " << (PalindromeChecker(racecar)
        ? "Palindrome" : "Not Palindrome") << "\n";

    std::cout << test << " : " << getStringLength(test) << "\n";
    std::cout << test << " : " << (PalindromeChecker(test)
        ? "Palindrome" : "Not Palindrome") << "\n";

    std::cout << longTest << " : " << getStringLength(longTest) << "\n";
    std::cout << longTest << " : " << (PalindromeChecker(longTest)
        ? "Palindrome" : "Not Palindrome") << "\n";

    return 0;
}