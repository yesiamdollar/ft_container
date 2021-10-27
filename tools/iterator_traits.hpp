#ifndef iterator_traits_hpp

#define iterator_traits_hpp

namespace ft{
	template <typename T>
	struct iterator_traits
	{
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::value_type				value_type;
		typedef	typename T::pointer					pointer;
		typedef typename T::reference				reference;
		typedef typename T::difference_type			difference_type;
	};

	template <typename T>
	struct iterator_traits<T*>{
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::value_type				value_type;
		typedef	typename T::pointer					pointer;
		typedef typename T::reference				reference;
		typedef typename T::difference_type			difference_type;
	};

	template <typename T>
	struct iterator_traits<const T*>{
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::value_type				value_type;
		typedef	typename T::pointer					pointer;
		typedef typename T::reference				reference;
		typedef typename T::difference_type			difference_type;
	};
}

#endif