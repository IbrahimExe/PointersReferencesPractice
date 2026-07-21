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
    std::string name;
    int studentID;

    Student(std::string inputName, int inputID)
    {
        name = inputName;
        studentID = inputID;
    }

    bool isEqual(const Student& other)
    {
        if (name == other.name && studentID == other.studentID)
        {
            return true;
        }

        return false;
    }
};

class StudentList 
{
private:
    struct Node 
    {
        Student data;
        Node* next;

        Node(const Student& student) : data(student), next(nullptr) {}
    };

    Node* head;

public:
    StudentList() : head(nullptr) {}

    ~StudentList() 
    {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Add(const Student& student) 
    {
        Node* newNode = new Node(student);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void Add(const Student& student, int index) 
    {
        if (index < 0) 
        {
            std::cout << "Invalid index: " << index << "\n";
            return;
        }

        Node* newNode = new Node(student);

        if (index == 0) 
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int currentIndex = 0;

        while (temp != nullptr && currentIndex < index - 1) 
        {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == nullptr) 
        {
            std::cout << "Index " << index << " is out of bounds.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Remove(int index) 
    {
        if (head == nullptr || index < 0) 
        {
            std::cout << "Invalid index or empty list.\n";
            return;
        }

        if (index == 0) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int currentIndex = 0;

        while (temp->next != nullptr && currentIndex < index - 1) 
        {
            temp = temp->next;
            currentIndex++;
        }

        if (temp->next == nullptr) 
        {
            std::cout << "Index " << index << " is out of bounds.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void Remove(const Student& student)
    {
        if (head == nullptr) return;

        if (head->data.isEqual(student))
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) 
        {
            if (temp->next->data.isEqual(student))
            {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void PopBack() 
    {
        if (head == nullptr) 
        {
            return;
        }

        if (head->next == nullptr) 
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) 
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void Print() const 
    {
        if (head == nullptr) 
        {
            std::cout << "empty list\n";
            return;
        }

        Node* temp = head;
        int index = 0;
        while (temp != nullptr) 
        {
            std::cout << "  [" << index << "] ID: " << temp->data.studentID
                << " | Name: " << temp->data.name << "\n";
            temp = temp->next;
            index++;
        }
        std::cout << "\n";
    }
};

/*
Part 3:
    Create new list class.
    - have it use a double linked list s its storing method
    - include functions:
        - Add(<test object>) >> will add the test object created prior to the list
        - Add(<test object>, int index) >> will add the test object created
          prior to a specific index (should handle if index is invalid)
    - Remove(int index) >> will remove at a specific index
    - Remove(<test object>)
    - PopBack() >> will remove the last item in the list
    - Print() >> iterate through the list and print all elements
    - PrintReverse() >> iterate through the list in reverse order and print all elements


    - add 5 items to the list, then print as well as print reverse
    - remove item at index 3, then print s well as print reverse
    - remove item at index 0, then print as well as print reverse
    - PopBack then print as well as print reverse
*/

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

    // Part 2
    std::cout << "PART 2:\n\n";

    StudentList list;

    // add 5 items to the list, then print
    list.Add(Student("Ibi", 101));
    list.Add(Student("Santiago", 102));
    list.Add(Student("Salmon", 103));
    list.Add(Student("Gustavo", 104));
    list.Add(Student("Craig", 105));
    list.Print();

    // remove item at index 3, then print
    list.Remove(3);
    list.Print();

    // remove item at index 0, then print
    list.Remove(0);
    list.Print();

    // PopBack then print
    list.PopBack();
    list.Print();

    return 0;
}