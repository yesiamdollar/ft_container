#ifndef pair_hpp
# define pair_hpp

namespace ft{

	template <class T1, class T2>
	struct pair
	{
		typedef T1		first_type;
		typedef	T2		second_type;

		pair() /* Default Constructor */ {}
		pair( const T1& lhs, const T2& rhs ) /* initialization (3) */ : first(lhs), second(rhs) {}
		template<class U1, class U2> 
		pair (const pair<U1, U2>& p) /* COPY */  :first(p.first), second(p.second) {}


		pair&	operator=(const pair& other) { first = other.first; second = other.second; return *this;}

		T1		first;
		T2		second;
	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u ){
		return pair<T1,T2>(t, u);
	};
	
	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return rhs<lhs;
	}
	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(lhs<rhs);
	}
}

#endif