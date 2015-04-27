class node_root_t : public shell_of_node_t//private shell_of_node_t
{
    public: 
    
        node_root_t ();
        
        ~node_root_t ();
        
        virtual ret_type execute ();

    private :
    
        Root_t _data;
        
        int _node_type;
};



node_root_t  :: node_root_t () : shell_of_node_t ()
{
    _node_type = ROOT;
    
    /*std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "level      = " << level     << std::endl;
    std::cout << "_node_root_type = " << _node_root_type << std::endl;
    
    std::cout << std::endl;*/
}


node_root_t  :: ~node_root_t ()
{
}


ret_type node_root_t :: execute ()
{
    //std::cout << "root, type = " << _node_type << "root_type = " << ROOT <<std::endl;

    try
    {
        throw & _node_type;
    }
    
    catch (int * arg)
    {
        throw;
    }
}

