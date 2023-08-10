/*
Qs: is it possible to make vector of constructor and methods

ChatGPT:
Yes, you can create a vector of constructor and method pointers in C++. Here's how you can do it for
the NumArray class:
*/

#include <iostream>
#include <vector>
#include <functional>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        prefix_sum.push_back(0);
        for (int num : nums) {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
    }

    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }

private:
    std::vector<int> prefix_sum;
};

int main() {
    using Method = std::function<int(NumArray&, int, int)>;

    std::vector<Method> methods;
    methods.push_back([](NumArray& obj, int left, int right) { return obj.sumRange(left, right); });

    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    std::vector<std::vector<int>> queries = {{0, 2}, {2, 5}, {0, 5}};

    std::vector<int> results;
    NumArray numArray(nums);
    for (const auto& query : queries) {
        int left = query[0];
        int right = query[1];
        int result = methods[0](numArray, left, right);
        results.push_back(result);
    }

    for (int result : results) {
        std::cout << result << " ";
    }

    return 0;
}
/*
In this code, we're using std::function to create a type alias Method for function pointers. We then
create a vector methods to hold the constructor and method pointers. In this example, we're only
storing the sumRange method, but you can extend it to include the constructor as well.

The lambda function inside the methods vector calls the respective method on the NumArray object. This
approach allows you to store and invoke methods dynamically using function pointers.
//Response Ends........



Qs: The following is the complete description of the problem 
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 10^4 calls will be made to sumRange.

the definition of the class is like the following
class NumArray {
public:
    vector<int> &n; //reference has been used, so the vector will not be copied
    NumArray(vector<int>& nums):n(nums){ //this is how to assign value in variable taken as reference
        for(int i = 1; i < n.size(); i++){
            n[i] += n[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return n[right];
        return n[right]-n[left-1];
    }
};


 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 

my question is how would i give this "["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]" as input,
//Qustions Ends............


ChatGPT:
To simulate the given input and test the NumArray class, you would perform the following steps in C++:

- Include the necessary headers.
- Define the NumArray class.
- Implement the constructor and methods as described.
- In the main function, instantiate the NumArray object and call its methods with the given input.
Here's how you can do that:
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> &n;

    NumArray(vector<int>& nums) : n(nums) {
        for(int i = 1; i < n.size(); i++){
            n[i] += n[i-1];
        }
    }

    int sumRange(int left, int right) {
        if(left == 0) return n[right];
        return n[right] - n[left-1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    vector<vector<int>> queries = {{0, 2}, {2, 5}, {0, 5}};

    vector<int> results;
    NumArray* numArray = new NumArray(nums);

    for (const auto& query : queries) {
        int left = query[0];
        int right = query[1];
        int result = numArray->sumRange(left, right);
        results.push_back(result);
    }

    for (int result : results) {
        cout << result << " ";
    }

    delete numArray; // Don't forget to free the memory

    return 0;
}
/*
In this code, we've implemented the NumArray class as given and then simulated the provided input by
creating the NumArray object and calling its sumRange method with the query indices. Finally, the
results are printed to the console. Remember to use new to create the NumArray object and delete to
free the allocated memory to avoid memory leaks.
*/
//Responde Ends

/*
Qs:
why did we not initialize the object like this "NumArray numArray(nums);"
is there a particular reason?

ChatGPT:
Yes, you can certainly initialize the NumArray object like this: NumArray numArray(nums);. In fact, that's
a common and more straightforward way of creating an object in C++. The reason I used new and delete in the
previous example was to mimic the example you provided where the object is instantiated using pointers.

Here's how you would use direct object instantiation without pointers:
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> &n;

    NumArray(vector<int>& nums) : n(nums) {
        for(int i = 1; i < n.size(); i++){
            n[i] += n[i-1];
        }
    }

    int sumRange(int left, int right) {
        if(left == 0) return n[right];
        return n[right] - n[left-1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    vector<vector<int>> queries = {{0, 2}, {2, 5}, {0, 5}};

    vector<int> results;
    NumArray numArray(nums);

    for (const auto& query : queries) {
        int left = query[0];
        int right = query[1];
        int result = numArray.sumRange(left, right);
        results.push_back(result);
    }

    for (int result : results) {
        cout << result << " ";
    }

    return 0;
}
/*
Both approaches are valid, but using direct object instantiation is generally simpler and more intuitive.
*/
//Responde ends.........


/*
Qs: is there some use cases where initializing object with new keyword is necessary? is there any
convenience in doing so?

ChatGPT:
Yes, there are certain cases where using the new keyword and dynamic memory allocation (i.e., creating
objects on the heap) can be necessary or provide convenience:

 - Lifetime Control: Objects created with new live until they are explicitly deallocated using delete.
    This can be useful when you need an object to persist beyond the scope where it was created. For example,
    when you want an object to exist throughout the entire lifetime of an application, not just within a
    single function.

 - Dynamic Object Count: If you need to create objects dynamically based on runtime conditions or user input,
    dynamic memory allocation is necessary. For instance, if you want to create an unknown number of objects in
    response to user interactions.

 - Object Sharing: If multiple parts of your program need access to the same object and their lifetimes are
    different, you might create the object with new to ensure it remains available until it's no longer needed.

 - Polymorphism: When working with polymorphism (e.g., using base classes and derived classes), you often create
    objects using pointers (base class pointers that can point to derived class objects). In such cases, dynamic
    memory allocation ensures proper object destruction and avoids object slicing.

 - Objects with Non-Trivial Initialization: Sometimes, an object's construction requires complex initialization
    logic that can't be done during object creation. Creating the object with new allows you to construct it
    incrementally, setting up its state as needed.

 - Returning Objects from Functions: If you want to return an object from a function and its lifetime needs to
    extend beyond the function scope, you would allocate it with new.

It's worth noting that using new also introduces the responsibility of memory management. You must remember to
delete the allocated object when you're done with it to prevent memory leaks.

In modern C++, it's recommended to use dynamic memory allocation only when necessary, and to prefer using automatic
storage (stack) for objects whenever possible. Smart pointers like std::unique_ptr and std::shared_ptr provide
safer alternatives to raw pointers when dynamic memory allocation is required. They automatically manage memory
deallocation when the object is no longer needed, reducing the likelihood of memory leaks.
*/