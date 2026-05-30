template <typename T>
Array<T>::Array(): _arr(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_arr = new T[n]();
}

template <typename T>
Array<T>::~Array()
{
	delete []_arr;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	*this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (this == &src)
	{
		this->setArray(src.size());
		for (unsigned int i = 0; i < src.size(); ++i)
			_arr[i] = src[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size)
		throw std::exception();
	return (_arr[idx]);
}

template <typename T>
void	Array<T>::setSize(unsigned int n)
{
	_size = n;
}

template <typename T>
void	Array<T>::setArray(unsigned int n)
{
	delete	[]_arr;
	_arr = new T[n]();
	setSize(n);
}

template <typename T>
unsigned int	Array<T>::size() const { return _size; }

//std::ostream&	operator<<(std::ostream& out, const Array<T>& src)
//{
//	return (out);
//}
