/*
Code Instructions:
Create a C++ application that will exhibit concurrency concepts.
Your application should create two threads that will act as counters.
One thread should count up to 20.
Once thread one reaches 20, then a second thread should be used to count down to 0.

Program Analysis Instructions:
For your created code, provide a detailed analysis of appropriate concepts that could impact your application including:
performance issues with concurrency, vulnerabilities exhibited with use of strings, and security of the data types exhibited.

Pseudocode:
First we should include iostream for output to the end user and thread so we can make use of threads
next we should make an increment and decrement function to to respectively increment and decrement values and display them to the user
finally in our main function with the executable code we shouldcreate a thread that increments, call the join function (which waits until one thread is finished to run the next
(its kind of ironic since the point of threads is to run things concurrently but this allows us to ensure that both threads are able to finish))

Program Analysis:
While concurrency allows for multiple tasks to run at the same time, it often comes at the cost of speed.
However due to the join function (and the programs small size) this is less of a factor. 
One of the biggest issues when working with strings are buffer overfllows. 
This is when more data is entered than is expected and the buffer that holds the data cannot hold it all. 
In this program however, this is not an issue as strings are not used.
As for  security of the data types exhibited, this program only uses the built in int datatype for c++ and is locally stored. 
There could however be issues if i were to use a datatype from an unsafe library allowing for manipulations and updates to that library to affect my code. 
*/

#include <iostream>
// library for end user input and output
#include <thread>
// c++ threading library that allows for the use managment of threads

using namespace std;
// standard namespace

void increment()
// function called increment
{
    for (int i = 0; i <= 20; i++)
    {
        cout << "Increment: " << i << endl;
    }
    // i = 0, increment i while i is less than 20
    // output to user what is happening and i (which has been incremented)
}

void decrement()
// function called decrement
{
    for (int i = 20; i >= 0; i--)
    {
        cout << "Decrement: " << i << endl;
    }
    // i = 0, decrement i while i is more than 0
    // output to user what is happening and i (which has been decremented)
}

int main()
// main function
{
    std::thread incrementThread(increment);
    // create a new thread called incrementThread that calls the increment function
    incrementThread.join();
    // waits for incrementThread to finish before starting to run next thread
    std::thread decrementThread(decrement);
    // create a new thread called decrementThread that calls the decrement function
    decrementThread.join();
    // waits for previous decrementThread to finish before starting to run
    return 0;
    // end program
}

/*
Recources:
https://stackoverflow.com/questions/266168/simple-example-of-threading-in-c#:~:text=The%20Code,(C++11)%20feature. form
https://www.geeksforgeeks.org/cpp/multithreading-in-cpp/
very good recourse makes use of chrono to slow down appearence of numbers printed to the screen to better mimic counting but dont want to copy this directly
https://en.cppreference.com/w/cpp/thread/thread.html good for deffinitions
*/