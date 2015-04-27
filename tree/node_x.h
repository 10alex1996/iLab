class node_x_t : public shell_of_node_t//private shell_of_node_t
{
    public: 
    
        node_x_t ();
        
        //node_x_t (shell_of_node_t * parent);
        
        ~node_x_t ();
        
        virtual ret_type execute ();

    private :
    
//        Data_T _data;
        
        int _node_type;
};


node_x_t  :: node_x_t () : shell_of_node_t ()
{
    _node_type = VARIABLE;
    
     //parent->add (this);
    
    /*std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "level      = " << level     << std::endl;
    std::cout << "_node_x_type = " << _node_x_type << std::endl;
    
    std::cout << std::endl;*/
}



/*node_x_t  :: node_x_t (shell_of_node_t * parent) : 
                    
                    shell_of_node_t (parent)
{
    _node_type = VARIABLE;

    parent->add (this);
    
    //shell_of_node_t * l = parent->left  ();
    
    /*std::cout << "l          = " << l                << std::endl;
    
    std::cout << "parent     = " << parent           << std::endl;
    std::cout << "parent->l  = " << parent->left  () << std::endl;
    std::cout << "parent->r  = " << parent->right () << std::endl;
    
    std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "_level     = " << _level     << std::endl;
    std::cout << "_node_x_type = " << _node_x_type << std::endl;
    
}
*/


node_x_t  :: ~node_x_t ()
{
}


ret_type node_x_t :: execute ()
{
    //std::cout << "x, type = " << _node_type << "x_type = " << VARIABLE <<std::endl;

    try
    {
        throw & _node_type;
    }
    
    catch (int * arg)
    {
        throw;
    }
}
