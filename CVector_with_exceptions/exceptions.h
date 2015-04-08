template <typename Vallue_T>
class exceptions_t
{
    public :

    exceptions_t  () {}

    exceptions_t  (const char * exception_place       ,
                   const char * msg                   ,
                   const char * val_name        = NULL,
                   Vallue_T     val             = NULL );

    ~exceptions_t () {}

    void what  () {cout << msg_             << endl;}
    void where () {cout << exception_place_ << endl;}
    void name  () {cout << val_name_        << endl;}
    void val   () {cout << val_             << endl;}

    void Stat ();

    void set_exception_place (const char * exception_place) {exception_place_ = exception_place;}
    void set_msg             (const char * msg            ) {msg_             = msg            ;}
    void set_val_name        (const char * val_name       ) {val_name_        = val_name       ;}
    void set_val             (Vallue_T     val            ) {val_             = val            ;}


    private :

    const char * exception_place_;
    const char * msg_            ;
    const char * val_name_       ;
    Vallue_T     val_            ;
};


template <typename Vallue_T>
exceptions_t <Vallue_T> :: exceptions_t  (const char * exception_place,
                                          const char * msg            ,
                                          const char * val_name       ,
                                          Vallue_T     val             )
{
    assert (exception_place);
    assert (msg            );

    exception_place = exception_place;
    msg             = msg            ;
    val_name        = val_name       ;
    val             = val            ;
}


template <typename Vallue_T>
void exceptions_t <Vallue_T> :: Stat ()
{
    cout << endl << "ATTENTION catch exception" << endl;

    cout << "{" << endl;

    cout << "   " << exception_place_ << " " << endl;
    cout << "   " << msg_             << " "        ;

    if (!val_name_) cout << endl;

    else
    {
        cout << val_name_  << " = "     ;
        cout << val_       <<       endl;
    }
    cout << "}" << endl;
}
