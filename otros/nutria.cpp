#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class MaxStack
{
  //Ill save the numbers in a vector and the position of the greatest element
  private:
    vector<int> maxStack;
    vector<int> orden;
  
  
public:
    MaxStack()
    {
        //Since we dont have elements, there's no ans
        //maxElement = -1;
    }

    int size()
    {
        //Return the size of the vector pila
        return maxStack.size();
    }

    bool isEmpty()
    {
        if(maxStack.empty()){
          return true;
        }
        else{
          return false;
        }
    }

    int peek()
    {
        // Emty vector
        if(maxStack.empty()){
          return -1;
        }
        else{
          //Last element of the vector
          return maxStack.back();
        }
        
    }

    int max()
    {
        // Emty vector
        if(maxStack.empty()){
          return -1;
        }
        else{
          //Return the max Element
          return orden.back();
        }
    }

    void push(int i)
    {
        if(maxStack.empty()){
            orden.push_back(i);
        }
        else{
            if(i>orden.back()){
                orden.push_back(i);
            }
            else{
                orden.push_back(orden.back());
            }
        }
      
        maxStack.push_back(i);

    }

    int pop()
    {
        if(maxStack.empty()){
          return -1;
        }
        else{
            int last = maxStack.back();
            maxStack.pop_back();
            orden.pop_back();
            return last;
        }
    }
};

int main()
{
    MaxStack maxStack;

    for(int i=10; i>=0; i--){
        maxStack.push(i);
    }

    cout << maxStack.max() << endl;

    maxStack.push(50);

    for(int i=0; i<10; i++){
        maxStack.push(i);
    }

    cout << maxStack.max() << endl;
    int x = 10;
    while(x--){
        maxStack.pop();
    }

    maxStack.pop();
    cout << maxStack.max() << endl;
    maxStack.pop();
    cout << maxStack.max() << endl;
}