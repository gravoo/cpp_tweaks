#include <iostream>
#include <csignal>

// void signalHandler(int signum) {
//     std::cout << "Błąd segmentacji (SIGSEGV) złapany! Zakończenie programu." << std::endl;
//     exit(signum);
// }
class Test
{
    public:
    Test(std::string name) : name(name)
    {
        std::cout<<"Test constructed " << name << "\n";
        tab = new std::string[4];
        tab[0] = name;
    }
    ~Test()
    {
        std::cout<<"Test destructed " << name << "\n";
        delete[] tab;
    }
    void operator()()
    {
        std::cout<<name<<"\n";
    }
    // Test& operator=(const Test& other)
    // {
    //     std::cout<<"Test assigned " << name << "\n";
    //     // if (this != &other) {
    //     //     // delete[] tab;  // Zwolnij istniejącą pamięć

    //     //     tab = new std::string[4];  // Przydziel nową pamięć dla `tab`
    //     //     std::copy(other.tab, other.tab + 4, tab);  // Skopiuj zawartość tablicy
    //     // }
    //     return *this;
    // }
    private:
    std::string name;
    std::string *tab;
};

int main(int argc, char *argv[], char* envp[])
{
    // std::signal(SIGSEGV, signalHandler);
    std::cout<<"Hello Seg Fault\n";   
    // char *test = 0x0;
    // std::cout<<*test<<"\n";
    // std::cout<<&test<<"\n";
    // std::cout<<argv[2]<<"\n";
    // std::cout<<envp[0]<<"\n";
    

    char *test = new char('5');
    delete test;
    delete test;
    char test2 = *test;
    std::cout<<test2<<"\n";
  

    // int tab[4];
    // int a = tab[10];
    // std::cout<<a<<"\n";

    // Test t1("t1");
    // Test &t_ref = t1;
    // t_ref();
    // Test t2("t2");
    // t_ref = t2;

    std::cout<<"koniec"<<"\n";


}