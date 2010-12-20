#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // someFunctionMember does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_someFunctionMember,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<short>,
                      boost::mpl::identity<double>,
                      boost::mpl::identity<int>,
                      boost::mpl::identity<long>
                      >
                  ));
  
  return 0;

  }
