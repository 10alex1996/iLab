# include <iostream>
# include <cassert>
# include <cstdlib>
# include <vector>

# define DEFAULT_SIZE 20                //default size

using std :: vector;
using namespace std;


template <typename Data_T, int Size = 0>
class Stack_t
{
private:

    vector <Data_T> stk;

    int current_pos;

    bool Ok ();

public:


    Stack_t  ();
    ~Stack_t ();

    void   Push  (Data_T element);
    Data_T Pop   (              );
    void   Dump  (              );
    void   Clear (              );

};


template <typename Data_T, int Size>
Stack_t <Data_T, Size> :: Stack_t () :

                        stk          ( ),
                        current_pos  (0)
{
    if   (Size < 0) stk = vector <Data_T> (DEFAULT_SIZE);
    else            stk = vector <Data_T> (Size        );
};


template <typename Data_T, int Size>
Stack_t <Data_T, Size> :: ~Stack_t ()
{
}


template <typename Data_T, int Size>
void Stack_t <Data_T, Size> :: Push (Data_T element)
{
    assert (Ok () ? 1 : (Dump (), 0));

    if   (stk.size () > current_pos) stk [current_pos] = element ;
    else                             stk.push_back      (element);

    current_pos++;

    assert (Ok () ? 1 : (Dump (), 0));
}


template <typename Data_T, int Size>
Data_T Stack_t <Data_T, Size> :: Pop ()
{
    assert (Ok () ? 1 : (Dump (), 0));

    if (current_pos > 0)
    {
        current_pos--;

        return stk [current_pos];
    }

    else
    {
        cout << "i can't do this operathion, because Stack is empty" << endl;

        assert ((Dump (), 0));

        current_pos = 0;

    }

    assert (Ok () ? 1 : (Dump (), 0));

    return 0;
}


template <typename Data_T, int Size>
bool Stack_t <Data_T, Size> :: Ok ()
{
    if   (stk.max_size () > current_pos && current_pos >= 0) return true ;
    else                                                     return false;
}


template <typename Data_T, int Size>
void Stack_t <Data_T, Size> :: Dump ()
{
    int check_res = Ok ();

    cout << "class Stack ( state of stack is    " << check_res << ")" << endl;

    cout << "{" << endl;

    int size_buff = stk.size ();

    cout << "size_buff = " << size_buff   << endl;
    cout << "cur_pos   = " << current_pos << endl;

    for (int i = 0; i < size_buff; i++)
    {
        if   (i > current_pos-1)

             cout << "    stk [" << i << "] = " << stk [i] << "*" << endl; //if type of stk doesn't a basic type, function cout
                                                                           //have to overload
        else
             cout << "    stk [" << i << "] = " << stk [i] <<        endl;
    }

    cout << "}" << endl;
}


template <typename Data_T, int Size>
void Stack_t <Data_T, Size> :: Clear ()
{
    assert (Ok () ? 1 : (Dump (), 0));

    if (Ok () == true && current_pos > 0) current_pos = 0;

    assert (Ok () ? 1 : (Dump (), 0));
}
