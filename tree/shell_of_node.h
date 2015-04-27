# include <cassert>

# include <iostream>
# include <vector>

//template <typename Data_T>
//class node_t;

typedef float ret_type;


class shell_of_node_t
{
    public :
    
        shell_of_node_t ();
        
        shell_of_node_t (shell_of_node_t * parent);
        
        ~shell_of_node_t ();
        
        shell_of_node_t * right ();
        shell_of_node_t * left  ();
        shell_of_node_t * up    ();
               
        virtual ret_type execute () = 0;
        
        bool isroot ();
        
        void add       (shell_of_node_t * element);
        void add_above (                         );
    
    private :
    
        shell_of_node_t * _right ;
        shell_of_node_t * _left  ;
        shell_of_node_t * _parent;
    
};


shell_of_node_t :: shell_of_node_t () :
            
            _right  (NULL),
            _left   (NULL),
            _parent (NULL)
{
}
    

shell_of_node_t :: shell_of_node_t (shell_of_node_t * parent) :
            
            _right  (NULL  ),
            _left   (NULL  ),
            _parent (parent)
{
}


shell_of_node_t :: ~shell_of_node_t ()
{
}


shell_of_node_t * shell_of_node_t :: right ()
{
    //std::cout << "this   = " << this   << std::endl;
    //std::cout << "_right = " << _right << std::endl;

    return _right;
}


shell_of_node_t * shell_of_node_t :: left ()
{
    //std::cout << "this  = " << this  << std::endl;
    //std::cout << "_left = " << _left << std::endl;

    return _left;
}


shell_of_node_t * shell_of_node_t :: up ()
{
    return _parent;
}


bool shell_of_node_t :: isroot ()
{
    if (_parent == NULL) return true;
    
    return false;
}


void shell_of_node_t :: add (shell_of_node_t * element)
{
    assert (element);
    
    if   (_left == NULL) _left  = element;
    else                 _right = element;      
    
    element->_parent = this;
    
    /*std::cout << std::endl << "element = " << element << std::endl;
    std::cout <<              "this    = " << this << std::endl;
    std::cout <<              "_left   = " << this->_left   << std::endl;
    std::cout <<              "_right  = " << this->_right  << std::endl;
    
    std::cout << std::endl;*/
}


void shell_of_node_t :: add_above ()
{
//    shell_of_node_t * hight_node = new shell_of_node_t;
    
  //  hight_node->add (this);
}
