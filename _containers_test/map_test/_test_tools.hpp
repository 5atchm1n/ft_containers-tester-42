#include <string>
#include <climits>

#ifndef _MAP_TEST_TOOLS_HPP
#define _MAP_TEST_TOOLS_HPP

namespace _test
{
    template <typename _map>
    void test_print(const _map &M)
    {
        std::cout << "empty : " << M.empty() << std::endl;
        std::cout << "size : " << M.size() << std::endl;
        if (!M.empty())
        {
            std::cout << "content : " << std::endl;
            for (typename _map::const_iterator it = M.begin(); it != M.end(); it++)
                std::cout << it->first << " => " << it->second << std::endl;
            std::cout << "reverse content : " << std::endl;
            for (typename _map::const_reverse_iterator it = M.rbegin(); it != M.rend(); it++)
                std::cout << it->first << " => " << it->second << std::endl;
        }
    }

    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }
    template <>
    std::string rdm_val<std::string>()
    {
        std::string default_val[18] =
            {
                "This is a test",
                "there are many tests",
                "all tests should pass",
                "Lorem ipsum dolor sit amet",
                "consectetur adipiscing elit.",
                "Phasellus ut rutrum ante.",
                "Sed vehicula tellus eu erat",
                "congue dictum. Fusce a ultrices",
                "",
                "magna. Morbi fringilla ullamcorper",
                "nisi id scelerisque.",
                "Curabitur elementum enim",
                "a mi vestibulum eleifend.",
                "Pellentesque eget risus efficitur",
                "euismod mi ut, tristique lorem.",
                "Praesent ullamcorper venenatis augue,",
                "\t",
                "eget pretium velit vehicula et."};
        return (std::string(default_val[std::rand() % 18]));
    }

    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }

    template <>
    std::pair<const int, std::string>
    rdm_val<std::pair<const int, std::string> >()
    {
        return std::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
    }
    
    template <>
    ft::pair<const int, std::string>
    rdm_val<ft::pair<const int, std::string> >()
    {
        return ft::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
    }

    template<typename _Tp>
    class lolocator : public std::allocator<_Tp>
    {
   public:
      typedef size_t     size_type;
      typedef ptrdiff_t  difference_type;
      typedef _Tp*       pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp&       reference;
      typedef const _Tp& const_reference;
      typedef _Tp        value_type;
      template<typename _Tp1>
        struct rebind
        { typedef lolocator<_Tp1> other; };
      
      lolocator() throw() { }
      lolocator(const lolocator& __a) throw() : std::allocator<_Tp>(__a) { }
      template <class _U>
      lolocator (const lolocator<_U>& __a) throw() : std::allocator<_Tp>(std::allocator<_U>(__a)) {}
      ~lolocator() throw() { }

        pointer allocate (size_type n, std::allocator<void>::const_pointer hint=0)
        {
            throw (lolexception());
            n++;
            hint = NULL;
            return NULL;
        }

        class lolexception : public std::exception
        {
            public:
            lolexception() {};
            const char* what() const throw()
            {
                return "lolocator";
            }
        };
    };

}

#endif