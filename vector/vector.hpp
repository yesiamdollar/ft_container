#ifndef VECTOR_HPP

# define VECTOR_HPP


# include <iostream>
namespace ft {
    template <typename _Tp,
        typename _Allocator = std::allocator<_Tp> >
    class vector
    {
    public:
        typedef	_Tp											value_type;
        typedef	_Allocator									allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator

		vector(const allocator_type& alloc = allocator_type()){
			_size = 0;
			_capacity = 0;
		}

		vector(size_type n, const value_type & val = value_type(), const allocator_type& alloc = allocator_type()){
			_size = n;
			_capacity = n;
			_mem = alloc;
			buff = _mem.allocate(n);
			for (int z = 0; z < _size; z++)
				_mem.construct();
		}

		size_type	size() const{
			return _size;
		}
		size_type	capacity() const{
			return _capacity;
		}
    
	
	private:
		allocator_type 	_mem;
		size_type		_size;
		size_type		_capacity;
		value_type		*buff;
    };
   
    
    
}

#endif