#ifndef PIMPLE_HPP
#define PIMPLE_HPP

#include <memory>

#define PIMPL_M(__FUNC__, __ARGS_DCL__, __ARGS__)        \
void PIMPLE_CLASS :: __FUNC__ __ARGS_DCL__ {             \
	pimpl< PIMPLE_CLASS >::pImpl -> __FUNC__ __ARGS__;   \
}

#define PIMPL_F(__TYPE__, __FUNC__, __ARGS_DCL__, __ARGS__)   \
__TYPE__ PIMPLE_CLASS :: __FUNC__ __ARGS_DCL__ {              \
	return pimpl< PIMPLE_CLASS >::pImpl -> __FUNC__ __ARGS__; \
}

#define PIMPL_IMPL pimpl< PIMPLE_CLASS >::Impl

template<typename T>
class pimpl {
protected:
	struct Impl;
	template<typename... Ts> pimpl(Ts... args) 
		: pImpl(
			new Impl(args...),
			[] (Impl *impl) { delete impl; }
		) {}
	std::unique_ptr<Impl, void (*)(Impl *)> pImpl;
};

#endif  // PIMPLE_HPP
