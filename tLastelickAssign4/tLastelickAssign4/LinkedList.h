// COSC 2437 - A class template for holding a linked list.
#include <iostream>
#include <string>
using namespace std;


template <class T>
class LinkedList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      T value;
      struct ListNode *next;
   }; 

   ListNode *head;   // List head pointer

public:
   LinkedList();    //constructor
   ~LinkedList(); // Destructor
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList();
   int search(T);    // search function
   T getTotal();
   int numNodes();
   T getAverage();
   T getLargest();
   int getLargestPosition();
   T getSmallest();
   int getSmallestPosition();
   T pop_back();
   T pop_front();
   void push_front(T);
   void push_back(T);
   T atNode(T);  // returns node->value at specific user location
   // recursive functions
   void printListReverse(ListNode *) const; // overloaded function
   void printListReverse() const; 
   void printList(ListNode *);
   void printList();
   void skipPrint(ListNode *);
   void skipPrint();
   int totalNodes(ListNode *);
   int totalNodes();                    
   bool searchNodes(ListNode *, T val);
   bool searchNodes(T val);
   

};

//**************************************************
// LinkedList sets all member data (head) to NULL *
//                                                *
//**************************************************
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************


template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr, *nextNode = nullptr;

   nodePtr = head;
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode *newNode, *nodePtr = nullptr;

   // Allocate a new node & store newValue
   newNode = new ListNode;
   newNode->value = newValue;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Find the last node in the list
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node
      nodePtr->next = newNode;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *newNode, *nodePtr, *previousNode = nullptr;

   // Allocate a new node & store newValue
   newNode = new ListNode;
   newNode->value = newValue;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
	  newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Initialize nodePtr to head of list and
      // previousNode to a null pointer.
      nodePtr = head;
	  previousNode = nullptr;

      // Skip all nodes whose value member is less
      // than newValue.
	  while (nodePtr != nullptr && nodePtr->value < newValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
	  if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise, insert it after the prev. node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode *nodePtr, *previousNode = nullptr;

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == searchValue)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to searchValue.
	  while (nodePtr != nullptr && nodePtr->value != searchValue)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

template <class T>
void LinkedList<T>::displayList()
{
	ListNode *nodePtr = nullptr;

   nodePtr = head;
   while (nodePtr)
   {
      cout << nodePtr->value << endl;
      nodePtr = nodePtr->next;
   }
}

//*****************************************************
// search member function                             *
//This function performs a linear search of the list. *
//*****************************************************

template <class T>
int LinkedList<T>::search(T val)
{
   int count = 1;
   ListNode *nodePtr = nullptr;

   nodePtr = head;
   while (nodePtr)
   {
      if( nodePtr->value == val)
      {
         return count;
      }
      else
      {
         nodePtr = nodePtr->next;
         count++;
      }
   }
   return 0;
}
//***
// IS THERE ANYWAY TO ADD SPACES TO STRING VALUES USING getTOTAL()????
//***
//*************************************************
// The getTotal function returns the total of     *
// all the nodes in the list.                     *
//*************************************************
template <class T>
T LinkedList<T>::getTotal()
{
   T *sum = new T; // must be a ptr to update values in one memory address
   ListNode *nodePtr = nullptr;  // to traverse list
  
   
   nodePtr = head;  // start at beginning of list
   
   //  until the end of the list is traversed
   while(nodePtr)
   {
    *sum += nodePtr->value;
    nodePtr = nodePtr->next;
   }
    
   return *sum;
}

//************************************************
// The numNodes function returns the number of   *
// nodes in the list.                            *
//************************************************
template <class T>
int LinkedList<T>::numNodes()
{
   ListNode *nodePtr = nullptr;    // to traverse the list
   int count = 0;   // to count number of nodes in list
   
   nodePtr = head;  // start at beginning of list
   
   
   // if nodePtr is null, return list is empty 
   if (!head)
    return count;
   
   // traverse list, updating count +1 for each node in list 
   while (nodePtr)
   {
    count++;    
    nodePtr = nodePtr->next;
   }
   
   return count;
        
}

//*****************************************************
// The getAverage function returns the average        *
// of the values in the list.                         *
//*****************************************************
template <class T>
T LinkedList<T>::getAverage()
{

    int count = 0;
    // Only working with numbers
    T avg = 0;
    T sum = 0; 
    ListNode *nodePtr = nullptr;  // to traverse list
  
   
   nodePtr = head;  // start at beginning of list
   
   //  until the end of the list is traversed
   while(nodePtr)
   {
    count++;
    sum += nodePtr->value;
    nodePtr = nodePtr->next;
   }
    //*sum = *sum/count;
    avg = sum/count;
   return avg;
}

//*************************************************
// The getLargest function returns the largest    *
// value in the list.                             *
//*************************************************
template <class T>
T LinkedList<T>::getLargest()
{
   T largest = 0;
   ListNode *nodePtr = nullptr;

    // nodePtr = first node in list   
   nodePtr = head;
   
   // if no nodes in list
   if (!head)
    return largest;
   else
   { largest = nodePtr->value;
   // while the list hasn't accounted for the last node in it
   while (nodePtr)
   {
     if (largest <= nodePtr->value)
        largest = nodePtr->value;
     
      nodePtr = nodePtr->next;
          
   }
   } 
   return largest;

}

//*************************************************
// The getLargestPosition function returns the    *
// position of the largest value in the list.     *
//*************************************************
template <class T>
int LinkedList<T>::getLargestPosition()
{
   T position = 0; 
   T largest = 0;
   int count = 0;
   ListNode *nodePtr = nullptr;

    // nodePtr = first node in list   
   nodePtr = head;
   
   // if list doesn't exist
   if (!head)
    return -1;  // not 0 in case first element is largest
   else
   { 
   largest = nodePtr->value;
   // while haven't reached last node in list
   while (nodePtr)
   {
       // if condition to stop loop to achieve function purpose
     if (largest <= nodePtr->value)
       {
        largest = nodePtr->value;
        position = count; // the current position of the largest value so far
       }
       
      count++;
      nodePtr = nodePtr->next;
          
   }
   } 
   
   return position;		
}

//*************************************************
// The getSmallest function returns the smallest  *
// value in the list.                             *
//*************************************************
template <class T>
T LinkedList<T>::getSmallest()
{
    T smallest = 0;
   ListNode *nodePtr = nullptr;

    // nodePtr = first node in list   
   nodePtr = head;
   
   // if no nodes in list
   if (!head)
    return smallest;
   else
   { smallest = nodePtr->value;
   // while the list hasn't accounted for the last node in it
   while (nodePtr)
   {
     if (smallest >= nodePtr->value)
        smallest = nodePtr->value;
     
      nodePtr = nodePtr->next;
          
   }
   } 
   return smallest;
}

//*************************************************
// The getSmallestPosition function returns the   *
// position of the smallest value in the list.    *
//*************************************************
template <class T>
int LinkedList<T>::getSmallestPosition()
{
   T position = 0;
   T smallest = 0;
   int count = 0;
   ListNode *nodePtr = nullptr;

    // nodePtr = first node in list   
   nodePtr = head;
   
   // if list doesn't exist
   if (!head)
    return -1;  // return -1 because not possible position of a list
   else
   { 
   smallest = nodePtr->value;
   // nodePtr traverses list, node by node, until it reaches the final node,
   // then it stops at the final node. nodePtr->next = null by end of loop. 
   while (nodePtr)
   {
       // give smallest variable the smallest value of the two values compared
     if (smallest <= nodePtr->value)
       {
        smallest = nodePtr->value;
        position = count; // the current position of the largest value so far
       }
       
      count++;
      nodePtr = nodePtr->next;
          
   }
   } 
   
   return position;		
}
//***************************************
// The pop_back() function removes the  *
// last element and returns its value   *
//***************************************

template <class T>
T LinkedList<T>::pop_back()
{
    ListNode *prevNode, *nodePtr = nullptr;
    T hold;
    
    
    if (!head)
        {
        cout << "This is an empty list" << endl;
        return 0;
        }
    else
       {
       // assigns nodePtr to first node in list
       // start at first node in the list
       nodePtr = head;
       
       // if only one node in list
       // Determine if the first node is the one.
       if (nodePtr->next == nullptr)
      {
      hold = nodePtr->value;
      //nodePtr = head->next;   not needed
      delete head;
      head = nullptr;
      nodePtr = nullptr;
      }
       else
       {
       
       // if list has 2+ nodes
       // traverse the list, stopping at the last node
        while (nodePtr->next != nullptr)
            {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            }
        // returns value of last node, deletes last node
        hold = nodePtr->value;
        prevNode->next = nullptr;    
        delete nodePtr;
        }
        
        return hold;
        }
      
}

//***************************************
// The pop_front() function removes the  *
// first element and returns its value   *
//***************************************
template <class T>
T LinkedList<T>::pop_front()
{
    ListNode *nodePtr = nullptr;
    T hold;
    
    if (!head)
    {
        cout << "This is an empty list, returning 0. " << endl;
        return 0;
    }
    
    else
    {
    // assign nodePtr to first node in list
    nodePtr = head;
    
    // if list exists, but only one node in list
        if (nodePtr->next == nullptr)
        {
            hold = nodePtr->value;
            nodePtr = nodePtr->next;
            delete head;
            head = nodePtr;
        }
     
    // nodePtr points to first node in list (head, which is node getting popped)
        else
        {
        
        hold = nodePtr->value;
        nodePtr = nodePtr->next;    // because first node is being removed
        delete head;
        head = nodePtr;     // head of list now accounts for poppped first node
        }
    return hold;    
    }   
        
}    

//***************************************
// The push_front() function inserts an *
// element at the front of the list     *
//***************************************
template <class T>
void LinkedList<T>::push_front(T newValue)
{
   ListNode *nodePtr , *newNode = nullptr;
   newNode = new ListNode;
   newNode->value = newValue;
   newNode->next = nullptr;
  // newNode->next = nullptr; // not necessary, newNode->next is already nullptr
   
   // if list doesn't exist
   if (!head)
    head = newNode; // insert new value as the first node
    
   // if node(s) exist in list
   else
   {
        nodePtr = head;
        newNode->next = nodePtr;
        head = newNode;
   }
}

//***************************************
// The push_back() function inserts an *
// element at the end of the list      *
//***************************************
template <class T>
void LinkedList<T>::push_back(T value)
{
   ListNode *nodePtr, *prevNode, *newNode = nullptr;
   
   // initialize newNode with user value
   newNode = new ListNode;  // or else segmentation core fault
   newNode->value = value;
   newNode->next = nullptr;
   
   // if no nodes in list
   if (!head)
    head = newNode;
    
   else 
   {
    // start at the beginning
    nodePtr = head;
    // traverse to last node in list
    while (nodePtr->next != nullptr)
        nodePtr = nodePtr->next;
   
    // once at last node, make newNode the new last node
    nodePtr->next = newNode;  
    }    
}
//*******************************
//atNode function returns the   *
//value of a node at a specific *
//position that user specifies  *
//*******************************
template <class T>
T LinkedList<T>::atNode(T position)
{
    ListNode *nodePtr = nullptr;

    nodePtr = head; // start at first node
    
    if (position == 0)
        return head->value;
    
    else
    {
    //set NodePtr to node at position indicated by user
    for (int i=0; i<position; i++)
        nodePtr = nodePtr->next;
    }    
    return nodePtr->value;
}
////////////////////////
/////START RECURSIVE FUNCTIONS ////////////////
///////////////////////

//*******************************************
//printListReverse function an              *
//overloaded recursive function that        *
//prints the list in reverse order          *   
//it is not used in the main program        *
//*******************************************
template <class T>        
void LinkedList<T>::printListReverse(ListNode *current) const         
{
    if (current != NULL)
    {
        printListReverse(current->next); // print the trail
        cout << current->value << " "; // print the node
    }
}

//*******************************************
//printListReverse function a               *
//recursive function that                   *
//prints the list in reverse order          *   
//starting from a programmer specified node *
//is used in the main program               *
//*******************************************
template <class T>
void LinkedList<T>::printListReverse() const
{
    printListReverse(head);
    cout << endl;
}

//**************************************************
//printList function an overloaded                 *
//recursive function that prints the list in order *   
//it is not used in the main program               *
//**************************************************
template <class T>        
void LinkedList<T>::printList(ListNode *current)          
{
    if (current != NULL)
    {
        cout << current->value << " "; // print the node
        printList(current->next); // print the trail
    }
}

//*******************************************
//printList function a recursive function   *
//that prints the list in order             *   
//starting from a programmer specified node *
//is used in the main program               *
//*******************************************
template <class T>
void LinkedList<T>::printList() 
{
    printList(head);
    cout << endl;
}

//**************************************************
//skipPrint function is an overloaded              *
//recursive function that prints the list          *
//starting at a programmer specified node and      *
//skipping every other node from the specified node*   
//it is not used in the main program               *
//**************************************************
template <class T>        
void LinkedList<T>::skipPrint(ListNode *current)          
{   
    if (current != NULL)
    {
        cout << current->value << " "; // print the node
        
        if (current->next != NULL)
        skipPrint(current->next->next);
        
        else 
            return;
    }
}

//**************************************************
//skipPrint function is a recursive function       *
//that prints the list starting at a programmer    *
//specified node and skipping every other node     *
//from the specified node                          *   
//it is not used in the main program               *
//**************************************************
template <class T>
void LinkedList<T>::skipPrint() 
{
    skipPrint(head);
    cout << endl;
}

//**************************************************************
//totalNodes function is an overloaded recursive function      *
//that traverses the list incrementing the count for each node *
//it is not used in the main program                           *
//**************************************************************
template <class T>
int LinkedList<T>::totalNodes(ListNode *current)
{
int count=0;

    if (current != NULL)
    {
        count++;
        count += totalNodes(current->next);   
                
    }
    return count;
}

//***********************************************
//totalNodes function is a recursive function   *
//returns the total count of nodes              *
//it is used in the main program                *
//***********************************************
template <class T>
int LinkedList<T>::totalNodes()
{
    int count = 0;
    count = totalNodes(head);
    return count;
}

//**********************************************************
//searchNodes function is an overloaded recursive function *
//that accepts a ListNode pointer and a user value         *
//and returns true if that value is found within the list  *
// false otherwise                                         *
//**********************************************************
template <class T>
bool LinkedList<T>::searchNodes(ListNode *current, T val)
{ 
   if (current != NULL)
   {
        if (current->value == val)
            return true;
        
        else 
            searchNodes(current->next, val);
        
    }
    else
        return false;
}

//**********************************************************
//searchNodes function is a recursive function             *
//that accepts a user value                                *
//and returns true if that value is found within the list  *
//false otherwise                                          *
//**********************************************************
template <class T>
bool LinkedList<T>::searchNodes(T val)
{
    return searchNodes(head, val);
}
