#include <packageneric/pre-compiled.private.hpp>

#define BOOST_LIB_NAME boost_unit_test_framework
#include <boost/version.hpp>
#if !defined _MSC_VER || BOOST_VERSION >= 103400 // looks like for boost version 1.33 there's no dll for the unit test framework on msvc
	#define BOOST_DYN_LINK
#endif
#include <boost/config/auto_link.hpp>

#include <boost/version.hpp>
#if !defined _MSC_VER || BOOST_VERSION >= 103400 // looks like for boost version 1.33 there's no dll for the unit test framework on msvc
	#define BOOST_TEST_DYN_LINK
#endif
#define BOOST_AUTO_TEST_MAIN
#include <boost/test/auto_unit_test.hpp>

#if 0 // some dummy test case that always fail (to test failure)
	BOOST_AUTO_TEST_CASE(dummy_failure)
	{
		BOOST_CHECK(false);
	}
#else
	BOOST_AUTO_TEST_CASE(dummy_success)
	{
		BOOST_CHECK(true);
	}
#endif

