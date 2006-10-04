/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_private_ctor.cpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <sstream>

#include <boost/test/test_exec_monitor.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/vector.hpp>

class V {
    int m_i;    
    friend class boost::serialization::access;
    V() {}
    template<class Archive>
    void serialize(Archive& ar, unsigned version)
    {
        ar & m_i;
    }    
};

int test_main(int /* argc */, char * /* argv */[])
{
    std::stringstream ss;
    const std::vector<V> v;
    {
        boost::archive::text_oarchive oa(ss);
        oa << v;
    }
    std::vector<V> v1;
    {
        boost::archive::text_iarchive ia(ss);
        ia >> v1;
    }
    //BOOST_CHECK(v == v1);
    return EXIT_SUCCESS;
}
