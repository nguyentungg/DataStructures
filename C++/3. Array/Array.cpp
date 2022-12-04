#include <iostream>
#include <cstdlib>
#include <vector>
#include <assert.h> 
using namespace std;

// simple declaration
int array[] = {1, 2, 3, 4, 5 };
// in pointer form (refers to an object stored in heap)
int * array = new int[5];


// vector<T>
class DynamicArray
{
private:
    int size_;
    int max_;
    int *arrayholder_;

public:
    DynamicArray()
    {
        this->size_ = 0;
        this->max_ = 5;
        this->arrayholder_ = new int[5];
    }

    ~DynamicArray()
    {
        delete[] this->arrayholder_;
    }

    int size()
    {
        return this->size_;
    }

    int& operator[](int i) 
    {
        assert(i < this->size_);
        return this->arrayholder_[i];
    }

    void add(int n)
    {
        if (this->max_ < this->size_ + 1)
        {
            this->max_ *= 2;
            int *tmp_ = new int[this->max_];

            for (size_t i = 0; i < this->size_; i++)
            {
                tmp_[i] = this->arrayholder_[i];
                
            }
            delete[] this->arrayholder_;
            this->arrayholder_ = tmp_;
            this->arrayholder_[this->size_] = n;
            this->size_ += 1;
        }
        else 
        {
            this->arrayholder_[this->size_] = n;
            this->size_ += 1;
        }
    }
};

int main(int argc, char **argv)
{
    DynamicArray darray;
    vector<int> varray;

    for (size_t i = 0; i <= 15; i++)
    {
        darray.add(i);
    }
    return 0;
}