class node_float_t : public shell_of_node_t//private shell_of_node_t
{
    public: 
    
//        node_float_t ();
        
        node_float_t (/*shell_of_node_t * parent,*/ Float_t data);
        
        ~node_float_t ();
        
        virtual ret_type execute ();

    private :
    
        Float_t _data;
        
        int _node_type;
};


/*
node_float_t  :: node_float_t () : shell_of_node_t ()
{
    _node_type = EMPTY;
    
    /*std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "level      = " << level     << std::endl;
    std::cout << "_node_float_type = " << _node_float_type << std::endl;
    
    std::cout << std::endl;
}
*/


node_float_t  :: node_float_t (/*shell_of_node_t * parent,*/ Float_t data) : 
                    
                    //shell_of_node_t (parent),
                    _data   (data  )
{
    _node_type = FLOAT;
    
    //parent->add (this);
    
    //shell_of_node_t * l = parent->left  ();
    
    /*std::cout << "l          = " << l                << std::endl;
    
    std::cout << "parent     = " << parent           << std::endl;
    std::cout << "parent->l  = " << parent->left  () << std::endl;
    std::cout << "parent->r  = " << parent->right () << std::endl;
    
    std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "_level     = " << _level     << std::endl;
    std::cout << "_node_float_type = " << _node_float_type << std::endl;*/
    
}



node_float_t  :: ~node_float_t ()
{
}


ret_type node_float_t :: execute ()
{
    //std::cout << "float, type = " << _node_type << " float_type = " << FLOAT <<std::endl;

    return _data;
}


