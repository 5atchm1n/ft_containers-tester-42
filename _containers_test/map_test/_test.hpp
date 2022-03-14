#include "_test_tools.hpp"

#ifndef _MAP_TEST_HPP
#define _MAP_TEST_HPP

namespace _test
{

    template <typename _map>
    void test_constructors(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _map W(X.begin(), X.end());
        _map K(Y.begin(), Y.end());
        test_print(W);
        test_print(K);
    }
        
    template <typename _map>
    void test_copy(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
        _map W(X);
        _map K(Y);
        test_print(W);
        test_print(K);
    }

    template <typename _map>
    void test_assign_op(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
        _map W;
        _map K;
        W = X;
        X = Y;
        Y = K;
        K = W;
        test_print(W);
        test_print(K);
    }

    template <typename _map>
    void test_arrindex_op(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR[]" << std::endl;
        try
        {
            if (!X.empty())
                std::cout << X[std::rand() % X.size()] << std::endl; 
            std::cout << Y[Y.size()] << std::endl;
        }
        catch (std::exception &error)
        {
            std::cout << "error" << std::endl;
        }
    }
    
    template <typename _map>
    void test_bounds(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - BOUNDS" << std::endl;
        try
        {
            typename _map::key_type k;
            switch (std::rand() % 4)
            {
            case (0):
                if (!X.empty() && X.size() > 2)
                {    
                    k = (*(--(X.end()))).first;
                    if (X.lower_bound(k) != X.end())
                        std::cout << (*(X.lower_bound(k))).second << std::endl;
                }
                break;
            case (1):
                if (!Y.empty())
                {    
                    k = (*(Y.begin())).first;
                    if (Y.upper_bound(k) != Y.end())
                        std::cout << (*(Y.upper_bound(k))).second << std::endl;
                }
                break;
            case (2):
                k = 0;
                if (X.lower_bound(k) != X.end())
                    std::cout << (*(X.lower_bound(k))).second << std::endl;
                break;
            case (3):
                if (!X.empty())
                {    
                    k = (*(--(X.end()))).first;
                    std::cout << (*(X.equal_range(k).first)).first << std::endl;
                }
                break;   
            }
        }
        catch (std::exception &error)
        {
            std::cout << "error" << std::endl;
        }
        
    }
    
    template <typename _map>
    void test_fakeallocator(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - FAKE ALLOCATOR" << std::endl;
        try
        {
            if(!Y.empty())
            {
                _NAMESPACE::map<int,std::string,std::less<int>,_test::lolocator<_NAMESPACE::pair<const int, std::string> > > K(Y.begin(), Y.end(), std::less<int>(), _test::lolocator<_NAMESPACE::pair<const int, std::string> >());
                test_print(K);
            }
            if(!X.empty())
            {
                _NAMESPACE::map<int,std::string,std::less<int>,_test::lolocator<_NAMESPACE::pair<const int, std::string> > > Z(X.begin(), X.end(), std::less<int>(), _test::lolocator<_NAMESPACE::pair<const int, std::string> >());
                test_print(Z);
            }
        }
        catch (std::exception &error)
        {
            std::cout << "Vade retro fake allocator" << std::endl;
        }
    }

    template <typename _map>
    void test_other_ops(_map &X, _map &Y)
    {
        if (!X.empty())
            std::cout << *(X.find(*(X.begin()).first)).second; << std::endl;
        if (!Y.empty())
            std::cout << *(Y.count(*(X.begin()).first)); << std::endl;
    }
     
    template <typename _map>
    void test_insert(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        try
        {
            switch (std::rand() % 4)
            {
                case (0):
                    for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                        std::cout << "pair<iterator,bool> insert (const value_type& val) test (1 if ok) : " << (X.insert(rdm_val<typename _map::value_type>())).second << std::endl;
                    break;
                case (1):
                    if (!X.empty())
                        std::cout << (X.insert(*(X.begin()))).second << std::endl;
                    if (!Y.empty())
                        std::cout << (Y.insert(*(--(Y.end())))).second << std::endl;
                    break;
                case (2):
                    if (!Y.empty())
                        Y.insert(Y.begin(), --(Y.end()));
                    if (!X.empty())
                        X.insert(X.begin(), X.end());
                    break;
                case (3):
                    if (!Y.empty())
                    {
                        typename _map::key_type test;
                        typename _map::iterator it = Y.begin();
                        test = it->first;
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        {
                            _NAMESPACE::pair<typename _map::key_type, typename _map::mapped_type> pr = _NAMESPACE::make_pair(test, rdm_val<typename _map::mapped_type>());
                            it = Y.insert(it, pr);
                            test++;
                        }
                    }
            }
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
        
    }
    
    template <typename _map>
    void test_erase(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - ERASE" << std::endl;
        try
        {
            switch (std::rand() % 3)
            {
            case (0):
                if (!X.empty())
                    X.erase(X.begin());
                if (!Y.empty())
                    Y.erase((--Y.end()));
                break;
            case (1):
                typename _map::key_type k;
                    k = 0;
                    X.erase(k);
                    Y.erase(k);
                if (!X.empty())
                {
                    k = (*(X.begin())).first;
                    X.erase(k);
                }
                break;
            case (2):
                X.erase(X.begin(), X.end());
                Y.erase(Y.begin(), Y.begin());
                if (!Y.empty())
                {
                    Y.erase(--(--Y.end()), --(Y.end()));
                }
                break;
            }
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
        
    }

    template <typename _map>
    void test_clear(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
        try
        {
            switch (std::rand() % 2)
            {
            case (0):
                X.clear();
                break;
            case (1):
                Y.clear();
                break;
            }
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    
    template <typename _map>
    void test_swap(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - SWAP" << std::endl;
        switch (std::rand() % 2)
        {
            case (0):
                X.swap(Y);
                break;
            case (1):
                std::swap(X,Y);
        }
    }
}

#endif