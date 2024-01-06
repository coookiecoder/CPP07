#ifndef ITER_HPP
# define ITER_HPP

template<class type_tab, class type_len> void iter(type_tab *tab, type_len len, void function(type_tab))
{
	for (int iteration = 0; iteration < len; iteration++)
		function(tab[iteration]);
}

#endif
