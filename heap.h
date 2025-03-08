#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator comp;
  std::vector<T> vect;

  void heapifyAftPush(size_t i); // heapify the heap after a push (from the bottom)
  void heapifyAftPop(size_t i); // heapify after a pop (from the root)

};

// Add implementation of member functions here
// cotr
template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comp(c){
}

// dtor 
template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}

// empty
template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return vect.empty();
}

// size
template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return vect.size();
}

// heapfiy from bottom
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyAftPush(size_t i){
  if(i == 0){
    return; // base case
  }
  size_t parentI = (i - 1)/ m; // works for m-ary trees
  if(comp(vect[i], vect[parentI])){
    std::swap(vect[i], vect[parentI]);
    heapifyAftPush(parentI);
  }
}

// heapify from root
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyAftPop(size_t i){
  size_t tempI = i;
  for(int id = 0; id <= m; id++){ // loop thru all children
    size_t childI = m * i + id;
    if(childI < vect.size() && comp(vect[childI], vect[tempI])){
      tempI = childI;
    }
  }

  if(tempI != i){
    std::swap(vect[i], vect[tempI]);
    heapifyAftPop(tempI);
  }
}

// push
template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  vect.push_back(item);
  heapifyAftPush(vect.size() - 1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap underflow");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vect.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap underflow");

  }

  std::swap(vect.front(), vect.back());
  vect.pop_back();
  if(!empty()){
    heapifyAftPop(0);
  }


}



#endif

