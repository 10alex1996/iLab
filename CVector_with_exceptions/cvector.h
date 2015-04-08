# include <iostream>
# include <cstdlib>


//# define DEBUG

# define STAT           1
# define CONST_LINK     1
# define NON_CONST_LINK 1

#ifdef DEBUG
    # define STAT           cout << __FUNCTION__                      << endl;
    # define CONST_LINK     cout << "this func return const     link" << endl;
    # define NON_CONST_LINK cout << "this func return non-const link" << endl;

#endif


# define FUNC __PRETTY_FUNCTION__
# define LINE cout << "LINE : " << __LINE__ << endl << endl;




//# define ASSERT(operand, value, name)\
    assert (operand ? 1 : (cout << "\n\n" << __PRETTY_FUNCTION__ << endl, cout << "incorrect value "<< name << " = " << value << "\n\n" << endl, 0))

# define EMPTY 0


using namespace std;


# include "exceptions.h"


template <typename Data_T>
class CVector
{
    public :

//constructors and distructors
    CVector  (           );
    CVector  (size_t Size);
    ~CVector (           );

//basic functions
    Data_T & at        (int number_of_element) const;
    Data_T & at        (int number_of_element)      ;
    size_t   size      (                     )      ;

    void     push_back (Data_T elem);
    void     dump      (           );

//operators
    Data_T & operator [] (int number_of_element)      ;
    //Data_T & operator [] (int number_of_element) const;

    CVector <Data_T> & operator += (const CVector <Data_T> & operand_right);

    //CVector <Data_T> & operator +  (const CVector <Data_T> & operand_right);

//exceptions
    void make_exception (const char * exception_place       ,
                         const char * val_name        = NULL,
                         int          val             = NULL );

    private :

//check function
    bool Ok (int number_of_element) const;

//add_new_boxes
    int  add_memory (size_t memory_Size);
    void size_x_2   (                  );

//data
    Data_T * vector_  ;
    int      max_size_;
    int      cur_pos_ ;

    exceptions_t <int> * err;
};


//========================================================================================
//
//constructors and distructors
//
//========================================================================================
template <typename Data_T>
CVector <Data_T> :: CVector () :

                    vector_   (NULL                  ),
                    max_size_ (0                     ),
                    cur_pos_  (0                     ),
                    err       (new exceptions_t <int>)
{
}


template <typename Data_T>
CVector <Data_T> :: CVector (size_t Size) :

                     vector_   (new Data_T [Size]     ),
                     max_size_ (Size                  ),
                     cur_pos_  (0                     ),
                     err       (new exceptions_t <int>)
{
    try
    {
        if (vector_ == NULL)

        {
            err->set_exception_place (FUNC);

            err->set_msg ("critical error! I haven't free memory");

            err->set_val_name (NULL);

            throw * err;
        }
    }

    catch (exceptions_t <int> & error)
    {

#ifdef DEBUG
        error.Stat ();

        LINE;
#endif

        exit (-1);

        throw;
    }

}


template <typename Data_T>
CVector <Data_T> :: ~CVector ()
{
    if (vector_ != NULL)  delete [] vector_;

    vector_ = NULL;

    delete err;
}


//========================================================================================
//
//basic functions
//
//========================================================================================
template <typename Data_T>
Data_T & CVector <Data_T> :: at (int number_of_element)
{
    STAT;

    NON_CONST_LINK;

    try
    {

        if (!Ok (number_of_element))
        {
            make_exception (FUNC, "number_of_element", number_of_element);

            throw * err;
        }
    }

    catch (exceptions_t <int> & error)
    {
        throw;

        //exit (-1);

        return vector_ [0];
    }

    return vector_ [number_of_element];

}


template <typename Data_T>
Data_T & CVector <Data_T> :: at (int number_of_element) const
{
    STAT;

    CONST_LINK;

    try
    {
        if (!Ok (number_of_element))
        {
            make_exception (FUNC, "number_of_element", number_of_element);

            throw err;
        }
    }

    catch (exceptions_t <int> & error)
    {
        throw;

        return -1;
    }

    return vector_ [number_of_element];
}


template <typename Data_T>
size_t CVector <Data_T> :: size ()
{
    STAT;

    return cur_pos_;
}


template <typename Data_T>
void CVector <Data_T> :: push_back (Data_T elem)
{
    STAT;

    if (cur_pos_ == max_size_) size_x_2 ();

    try
    {
        at (cur_pos_) = elem;
    }

    catch (exceptions_t <int> & error)
    {

#ifdef DEBUG
        error.Stat ();

        LINE;
#endif
        throw;

        //abort ();
    }

    cur_pos_++;
}


template <typename Data_T>
void CVector <Data_T> :: dump ()
{
    cout << "class CVector " << endl;

    cout << "{" << endl;

    cout << "size_buff   = " << max_size_        << endl;
    cout << "cur_pos_    = " << cur_pos_         << endl;

    for (int i = 0; i < max_size_; i++)
    {
        if   (i > cur_pos_-1)

            cout << "    vector_ [" << i << "] = " << vector_ [i] << "*" << endl;//if you used your
                                                                                 //own type of stk,
        else                                                                     //you have to overfloat
            cout << "    vector_ [" << i << "] = " << vector_ [i] <<        endl;//printing function
    }

    cout << "}" << endl;
}


//========================================================================================
//
//operators
//
//========================================================================================
template <typename Data_T>
Data_T & CVector <Data_T> :: operator [] (int number_of_element)
{
    STAT;

    NON_CONST_LINK;

    Data_T value_of_cell;

    try
    {
         value_of_cell = at (number_of_element);
    }

    catch (exceptions_t <int> & error)
    {
        error.Stat ();

        LINE;

        exit (-1);
    }

    return value_of_cell;
}

/*template <typename Data_T>
Data_T & CVector <Data_T> :: operator [] (int number_of_element) const
{
    STAT;

    CONST_LINK;

    return at (number_of_element);
}
*/

template <typename Data_T>
CVector <Data_T> & CVector <Data_T> :: operator += (const CVector <Data_T> & operand_right )
{
    STAT;

    try
    {
        if (operand_right.vector_ == 0)
        {
            make_exception (FUNC, "operand_right.vector_", NULL);

            throw * err;
        }
    }

    catch (exceptions_t <int> & error)
    {
#ifdef DEBUG
        error.Stat ();

        LINE;
#endif
        exit (-1);
    }

    try
    {
        add_memory (max_size_ + operand_right.max_size_);
    }

    catch (exceptions_t <int> & error)
    {
        error.Stat ();

        LINE;

        exit (-1);
    }

    for (int i = 0; cur_pos_ < max_size_; cur_pos_++, i++)
    {
        vector_ [cur_pos_] = operand_right.vector_ [i];
    }

    return * this;

}


/*template <typename Data_T>
CVector <Data_T> & CVector <Data_T> :: operator + (const CVector <Data_T> & operand_right)
{
    (* this) += operand_right;

    return *this;
}*/

template <typename Data_T>
void CVector <Data_T> :: make_exception (const char * exception_place,
                                         const char * val_name       ,
                                         int          val             )
{
    STAT;

    err->set_exception_place (exception_place  );
    err->set_msg             ("incorrect value");


    if (val_name != NULL)
    {
        err->set_val_name (val_name);
        err->set_val      (val     );
    }
}


//========================================================================================
//
//check function
//
//========================================================================================
template <typename Data_T>
bool CVector <Data_T> :: Ok (int number_of_element) const
{
    if (max_size_ >= 0 && max_size_ > number_of_element && number_of_element >= 0) return true;

    return false;
}


//========================================================================================
//
//add_new_boxes
//
//========================================================================================
template <typename Data_T>
int CVector <Data_T> :: add_memory (size_t memory_Size)
{
    STAT;

    try
    {
        if (memory_Size <= max_size_)
        {
            make_exception (FUNC, "memory_Size", memory_Size);

            throw * err;
        }
    }

    catch (exceptions_t <int> & error)
    {
#ifdef DEBUG
        error.Stat ();

        LINE;
#endif
        throw;

        return -1;
    }

    size_t old_size = max_size_;

    if (max_size_ == 0)
    {
        cout << "max_size == 0" << endl;

        max_size_ = 1;

        vector_ =  new Data_T;
    }

    else
    {

        max_size_ = memory_Size;

        Data_T * new_data = new Data_T [max_size_];

        for (int i = 0; i < old_size; i++)
        {
            new_data [i] = vector_ [i];
        }

        delete [] vector_;

        vector_ = new_data;
    }
}


template <typename Data_T>
void CVector <Data_T> :: size_x_2 ()
{

    STAT;

    if (max_size_ == 0)
    {
        max_size_ = 1;

        vector_ =  new Data_T;
    }

    else
    {
        try
        {
            add_memory (max_size_ * 2);
        }

        catch (exceptions_t <int> & error)
        {
            error.Stat ();

            LINE;
        }
    }
}
