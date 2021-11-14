#ifndef iterator_traits_hpp

#define iterator_traits_hpp

namespace ft{
	template <typename P>
	struct iterator_traits
	{
		typedef typename P::iterator_category		iterator_category;
		typedef typename P::value_type				value_type;
		typedef	typename P::pointer					pointer;
		typedef typename P::reference				reference;
		typedef typename P::difference_type			difference_type;
	};

	template <typename T>
	struct iterator_traits<T*>{
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef	T*									pointer;
		typedef T&									reference;
		typedef std::ptrdiff_t						difference_type;
	};

	template <typename T>
	struct iterator_traits<const T*>{
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef	const T*							pointer;
		typedef const T&							reference;
		typedef std::ptrdiff_t						difference_type;
	};

	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};


}

#endif