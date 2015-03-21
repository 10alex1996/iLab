# include <iostream>
# include <cassert>
# include <cstdlib>
# include <vector>

# define CRITICAL_SIZE 4000000000    //slightly less than the maximum amount of memory available for the program
# define ORIGINAL_SIZE 20

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
    if (Size > CRITICAL_SIZE || Size < 0) stk = vector <Data_T> (ORIGINAL_SIZE);
    else                                  stk = vector <Data_T> (Size         );
};


template <typename Data_T, int Size>
Stack_t <Data_T, Size> :: ~Stack_t ()
{
    assert (Ok () ? 1 : (Dump (), 0));
}

template <typename Data_T, int Size>
void Stack_t <Data_T, Size> :: Push (Data_T element)
{
    assert (Ok () ? 1 : (Dump (), 0));

    if (Ok () == true)
    {
        if   (stk.size () > current_pos) stk [current_pos] = element ;
        else                             stk.push_back      (element);

        current_pos++;
    }

    else
    {
        cout << "i can'Data_T do this operathion, because Stack is full" << endl;

        assert ((Dump (), 0));

    }

    assert (Ok () ? 1 : (Dump (), 0));
}


template <typename Data_T, int Size>
Data_T Stack_t <Data_T, Size> :: Pop ()
{
    assert (Ok () ? 1 : (Dump (), 0));

    if (Ok () == true && current_pos > 0)
    {
        current_pos--;

        return stk [current_pos];
    }

    else
    {
        cout << "i can'Data_T do this operathion, because Stack is empty" << endl;

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

    cout << "class Stack (" << check_res << ")" << endl;

    cout << "{" << endl;

    int size_buff = stk.size ();

    cout << "size_buff = " << size_buff   << endl;
    cout << "cur_pos   = " << current_pos << endl;

    for (int i = 0; i < size_buff; i++)
    {
        if   (i > current_pos-1)

            cout << "    stk [" << i << "] = " << stk [i] << "*"<< endl;

        else
            cout << "    stk [" << i << "] = " << stk [i] <<       endl;
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
