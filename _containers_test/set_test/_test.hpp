#include "_test_tools.hpp"

#ifndef _SET_TEST_HPP
#define _SET_TEST_HPP

namespace _test
{

    template <typename _set>
    void test_constructors(_set &X, _set &Y)
    {
        std::cout << "TEST - CONSTRUCTORS" << std::endl;
        _set W(X.begin(), X.end());
        _set K(Y.begin(), Y.end());
        test_print(W);
        test_print(K);
    }
        
    template <typename _set>
    void test_copy(_set &X, _set &Y)
    {
        std::cout << "TEST - COPY CONSTRUCTOR" << std::endl;
        _set W(X);
        _set K(Y);
        test_print(W);
        test_print(K);
    }

    template <typename _set>
    void test_assign_op(_set &X, _set &Y)
    {
        std::cout << "TEST - OPERATOR=" << std::endl;
        _set W;
        _set K;
        W = X;
        X = Y;
        Y = K;
        K = W;
        test_print(W);
        test_print(K);
    }

    template <typename _set>
    void test_bounds(_set &X, _set &Y)
    {
        std::cout << "TEST - BOUNDS" << std::endl;
        try
        {
            typename _set::key_type k;
            switch (std::rand() % 4)
            {
            case (0):
                if (!X.empty() && X.size() > 2)
                {    
                    k = (*(--(X.end())));
                    if (X.lower_bound(k) != X.end())
                        std::cout << (*(X.lower_bound(k))) << std::endl;
                }
                break;
            case (1):
                if (!Y.empty())
                {    
                    k = (*(Y.begin()));
                    if (Y.upper_bound(k) != Y.end())
                        std::cout << (*(Y.upper_bound(k))) << std::endl;
                }
                break;
            case (2):
                k = 0;
                if (X.lower_bound(k) != X.end())
                    std::cout << (*(X.lower_bound(k))) << std::endl;
                break;
            case (3):
                if (!X.empty())
                {    
                    k = (*(--(X.end())));
                    std::cout << *(X.equal_range(k).first) << std::endl;
                }
                break;   
            }
        }
        catch (std::exception &error)
        {
            std::cout << "error" << std::endl;
        }
        
    }
    
    template <typename _set>
    void test_other_ops(_set &X, _set &Y)
    {
        std::cout << "TEST - OTHER OPS" << std::endl;
        if (!X.empty())
            std::cout << *(X.find((*(X.begin())))) << std::endl;
        if (!Y.empty())
            std::cout << Y.count(*(X.begin())) << std::endl;
    }
     
    template <typename _set>
    void test_insert(_set &X, _set &Y)
    {
        std::cout << "TEST - INSERT" << std::endl;
        try
        {
            switch (std::rand() % 3)
            {
                case (0):
                    if (!X.empty())
                        std::cout << *((X.insert(*(X.begin()))).first) << std::endl;
                    if (!Y.empty())
                        std::cout << *((Y.insert(*(--(Y.end())))).first) << std::endl;
                    for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                    {
                        X.insert(rdm_val<int>());
                        Y.insert(rdm_val<int>());
                    }
                    break;
                case (1):
                    if (!Y.empty())
                        X.insert(Y.begin(), --(Y.end()));
                    else
                    for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        X.insert(rdm_val<int>());
                    if (!X.empty())
                    for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        Y.insert(X.begin(), X.end());
                    else
                        Y.insert(rdm_val<int>());
                    break;
                case (2):
                    {    
                        typename _set::iterator it = Y.begin();
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        {
                            int pr = rdm_val<int>();
                            it = Y.insert(it, pr);
                        }
                        break;
                    }
            }
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
        
    }
    
    template <typename _set>
    void test_erase(_set &X, _set &Y)
    {
        std::cout << "TEST - ERASE" << std::endl;
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
                typename _set::key_type k;
                    k = 0;
                    X.erase(k);
                    Y.erase(k);
                if (!X.empty())
                {
                    k = *(X.begin());
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

    template <typename _set>
    void test_clear(_set &X, _set &Y)
    {
        std::cout << "TEST - CLEAR" << std::endl;
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
    
    template <typename _set>
    void test_swap(_set &X, _set &Y)
    {
        std::cout << "TEST - SWAP" << std::endl;
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