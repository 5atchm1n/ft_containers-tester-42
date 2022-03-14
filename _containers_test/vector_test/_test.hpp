#include "_test_tools.hpp"

#ifndef _VECTOR_TEST_HPP
#define _VECTOR_TEST_HPP

namespace _test
{
    template <typename _vector>
    void test_constructors(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        switch (std::rand() % 3)
        {
            case (0):
                std::ifstream source("Makefile", std::ios::binary);
                _NAMESPACE::vector<char> Z((std::istreambuf_iterator<char>(source)), std::istreambuf_iterator<char>());
                source.close();
                test_print(Z);
                break;
            case (1):
                _vector Z = _vector(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
                test_print(Z);
            case (2):
                _vector Z = _vector(X.begin(), X.end());
                _vector K = _vector(Y.begin(), Y.end());
                test_print(Z);
                test_print(K);
        }
    }

    template <typename _vector>
    void test_copy(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
        _vector Z(X);
        _vector K(Y);
        test_print(Z);
        test_print(K);
    }

    template <typename _vector>
    void test_assign_op(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
        X = Y;
    }

    template <typename _vector>
    void test_resize(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - RESIZE" << std::endl;
            x.resize(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
            y.resize(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
    }

    template <typename _vector>
    void test_swap(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - RESIZE" << std::endl;
        if (std::rand() % 2)
            X.swap(Y);
        else
            std::swap(Y,X);
    }

    template <typename _vector>
    void test_relational_op(_vector &X, _vector &Y)
    {
        _vector Z;
        Z.insert(Z.begin(), _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        _vector K = _vector(Z);
        std::cout << (Z == K) << std::endl;
        K.pop_back();
        std::cout << (Z != K) << std::endl;
        std::cout << (Z > K) << std::endl;
        std::cout << (Z >= K) << std::endl;
        std::cout << (X < Y) << std::endl;
        std::cout << (X <= Y) << std::endl;
        test_print(Z);
        test_print(K);
    }

    template <typename _vector>
    void test_insert(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        typename _vector::iterator it;
        if (!X.empty())
            it = X.begin() + std::rand() % X.size();
        else
            it = X.end();
        try
            {
                switch (std::rand() % 3)
                {
                case (0):
                    std::cout << *X.insert(it, rdm_val<typename _vector::value_type>()) << std::endl;
                    break;
                case (1):
                    if (!X.empty() && !Y.empty())
                        Y.insert(Y.begin() + (std::rand() % Y.size()), it, it + (std::rand() % (X.size() - (it - X.begin()))));
                    else if (!y.empty())
                        Y.insert(y.begin() + (std::rand() % Y.size()), it, X.end());
                    else
                        Y.insert(Y.begin(), it, X.end());
                    break;
                case (2):
                    if (!Y.empty())
                        Y.insert(Y.begin(), (std::rand() % Y.size()), rdm_val<typename _vector::value_type>());
                    else
                        Y.insert(Y.begin(), std::rand() % 5, rdm_val<typename _vector::value_type>());
                    break;
                }
            }
            catch (std::exception &error)
            {
                std::cout << error.what() << std::endl;
            }
    }
    
    template <typename _vector>
    void test_assign(_vector &X, _vector &Y)
    {
        _vector Z;
        std::cout << "TEST : " << test_no++;
        std::cout << " - ASSIGN" << std::endl;
        switch (std::rand() % 4)
        {
            case (0) :
                Z.assign(0, rdm_val<typename _vector::value_type>());
            case (1) :
                Z.assign(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
            case (2) :
                Z.assign(Y.begin(), Y.end());
            case (3) :
                if (!Y.empty())
                    Z.assign(Y.begin() + (std::rand() % Y.size()), Y.end());
            case (4) :
                if (!Y.empty())
                    Z.assign(Y.begin(), Y.end() - (std::rand() % Y.size()));
            case (5) :
                if (!Z.empty())
                    X.assign(Z.begin(), Z.end() - (std::rand() % Z .size()));
        }
        test_print(Z);
    }
    
    template <typename _vector>
    void test_push(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - PUSH_BACK" << std::endl;
        switch (std::rand() % 3)
        {
            case (0) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    X.push_back(rdm_val<typename _vector::value_type>());
            case (1) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    Y.push_back(rdm_val<typename _vector::value_type>());
            case (2) :
                _vector Z;
                Z.push_back(rdm_val<typename _vector::value_type>());
                test_print(Z);
        }
    }


    template <typename _vector>
    void test_pop(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - POP" << std::endl;
        switch (std::rand() % 2)
        {
            case (0):
                if (!X.empty())
                    for (size_t i = 0; i < std ::rand() % X.size(); i++)
                        X.pop_back();
            case (1):
                if (!Y.empty())
                    for (size_t i = 0; i < std ::rand() % Y.size(); i++)
                        Y.pop_back();
        }
    }
    
    template <typename _vector>
    void test_erase(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - ERASE" << std::endl;
        typename _vector::iterator pos;
        switch (std::rand() % 4)
        {
            case (0):
                if (!X.empty())
                    X.erase(X.begin());
            case (1):
                if (!X.empty())
                    X.erase(X.end() - 1);
            case (2):
                if (!X.empty() && X.size() > 1)
                {   
                    pos = X.begin() + (std::rand() % X.size());
                    X.erase(X.begin(), pos);
                }
            case (3):
                if (!Y.empty() && Y.size() > 1)
                {
                    pos = Y.begin() + (std::rand() % Y.size());
                    Y.erase(Y.begin(), pos);
                }
        }
    }

    template <typename _vector>
    void test_clear(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
        if (std::rand() % 2)
            X.clear();
        else
            Y.clear();
    }

    template <typename _vector>
    void test_reserve(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
        X.reserve(std::rand() % (_MAX_TEST_SIZE * 2));
        Y.reserve(std::rand() % (_MAX_TEST_SIZE * 2));
        std::cout << X.capacity() << "--" << Y.capacity() << std::endl;
    } 
}
}


#endif 