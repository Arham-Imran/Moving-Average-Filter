#include <iostream>
#include <cstdlib>

#define BUFFER_SIZE 100
#define WINDOW_SIZE 10

using namespace std;

int main(void)
{
    srand(0);
    float buffer[BUFFER_SIZE]; 
    float current_output = 0.0f;
    float filtered_buffer[BUFFER_SIZE - WINDOW_SIZE] = {};
    int current_index = WINDOW_SIZE - 1;

    for(int i = 0; i < BUFFER_SIZE; i++)
        buffer[i] = rand() % 50;

    while(current_index < BUFFER_SIZE)
    {
        for(int i = 0; i < WINDOW_SIZE; i++)
            current_output += buffer[current_index - i] / WINDOW_SIZE;

        filtered_buffer[current_index - WINDOW_SIZE + 1] = current_output;
        current_output = 0.0f;
        current_index++;
    }

    for(int i = 0; i < BUFFER_SIZE; i++)
        cout << buffer[i] << ", ";
    cout << endl << endl << endl;

     for(int i = 0; i < BUFFER_SIZE - WINDOW_SIZE; i++)
        cout << filtered_buffer[i] << ", ";
    cout << endl;
}
