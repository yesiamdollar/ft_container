#ifndef algorithms_hpp
# define algorithms_hpp

namespace ft{
	template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2) { /* equality */
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
	return true;
	}
	
	template <class InputIte1, class InputIte2, class BinaryPredicate>
	bool equal (InputIte1 first1, InputIte1 last1,
				InputIte2 first2, BinaryPredicate pred){ /* predicate */
		while (first1 != last1) {
			if (pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIt1, class InputIt2>
	bool lexicographical_compare (InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		while (first1!=last1){
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1; ++first2;
		}
	return (first2!=last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare (InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2,
									Compare comp) {
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);                                    
	}


}

#endif