#ifndef iterator_hpp

# define iterator_hpp
# include <iterator>
// # include 
namespace ft{
	template <typename _Tp>
	class iterator
	{
		private:
			typedef	typename	ft::vector::value_type	value_type;
			typedef 			pointer_type			value_type*;
			typedef				reference_type			value_type&;
			pointer_type						_ptr;
		public:
			iterator(pointer_type ptr) : _ptr(ptr) {};
			~iterator();
	};
}

#endif