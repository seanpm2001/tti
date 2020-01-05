
//  (C) Copyright Edward Diener 2019
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP)
#define BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/list/enum.hpp>
#include <boost/tti/detail/dftclass.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/tti/gen/namespace_gen.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(__SUNPRO_CC)

#define BOOST_TTI_DETAIL_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T> \
  struct BOOST_PP_CAT(trait,_detail_hcmft) \
    { \
    template<class BOOST_TTI_DETAIL_TP_F> \
    struct cl_type : \
      boost::remove_const \
        < \
        typename BOOST_TTI_NAMESPACE::detail::class_type<BOOST_TTI_DETAIL_TP_F>::type \
        > \
      { \
      }; \
    \
    template<BOOST_TTI_DETAIL_TP_T> \
    struct helper {}; \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::boost::type_traits::yes_type check(helper<&BOOST_TTI_DETAIL_TP_U::template name<BOOST_PP_LIST_ENUM(tplst)> > *); \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::boost::type_traits::no_type check(...); \
    \
    typedef boost::mpl::bool_<sizeof(check<typename cl_type<BOOST_TTI_DETAIL_TP_T>::type>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::boost::type_traits::yes_type)> type; \
    }; \
/**/

#else

#define BOOST_TTI_DETAIL_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T> \
  struct BOOST_PP_CAT(trait,_detail_hcmft) \
    { \
    template<class BOOST_TTI_DETAIL_TP_F> \
    struct cl_type : \
      boost::remove_const \
        < \
        typename BOOST_TTI_NAMESPACE::detail::class_type<BOOST_TTI_DETAIL_TP_F>::type \
        > \
      { \
      }; \
    \
    template<BOOST_TTI_DETAIL_TP_T> \
    struct helper; \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::boost::type_traits::yes_type check(helper<&BOOST_TTI_DETAIL_TP_U::template name<BOOST_PP_LIST_ENUM(tplst)> > *); \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::boost::type_traits::no_type check(...); \
    \
    typedef boost::mpl::bool_<sizeof(check<typename cl_type<BOOST_TTI_DETAIL_TP_T>::type>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::boost::type_traits::yes_type)> type; \
    }; \
/**/

#endif

#endif // BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP