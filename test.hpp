#include <memory>
#include <exception>

namespace lol{

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
      lolocator(const lolocator& __a) throw()
      : std::allocator<_Tp>(__a) { }
      ~lolocator() throw() { }

        pointer allocate (size_type n, std::allocator<void>::const_pointer hint=0)
        {
            throw (lolexception());
            return NULL;
        }

        class lolexception : public std::exception
        {
            public:
            lolexception() {};
            const char* what() const throw()
            {
                return "lol c cassé";
            }
        };
    };
}
