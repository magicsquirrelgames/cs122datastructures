#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vector;

    for(int i = 0; i < 10; i++)
    {
        vector.push_back(i);
    }

    std::cout << "Size of vector: " << vector.size() << std::endl;
    std::cout << "Capacity of vector: " << vector.capacity() << std::endl;
    std::cout << "Max size of vector: " << vector.max_size() << std::endl;

    for(auto element : vector)
    {
        std::cout << element << std::endl;
    }

    return 0;
}