#ifndef type_traits_hpp

# define type_traits_hpp

namespace ft{
	template < bool B, class T = void>
	struct	enable_if{ typedef	T type;};

	template < class T>
	struct enable_if<true, T> {typedef T type; };
	
	template <class T>
	struct is_integral
	{
		/* data */
	};
	

}

#endif